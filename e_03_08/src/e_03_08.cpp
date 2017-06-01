/* 演習03-08
 * list3-14の関数seqsearchを利用するプログラムの作成
 * 作成日：6月1日
 * 作成者：成田修之
 */

#include<iostream>
#include<cstdlib>
using namespace std;

//seqsearch関数で使う比較関数
int compar(const int* a,const int* b) {
	return *a < *b ? -1 : *a > *b ? 1 : 0;
}

//線形探索して探したい値へのポインタを返す関数
void* seqsearch(const void* key, const void* base, size_t nmemb, size_t size,
		int(*compar)(const void*, const void*))
{
	//1バイトごとで計算できるようにconst char*型へキャスト
	const char* x = reinterpret_cast<const char*>(base);
	//返却するポインタを格納する変数
	void* vReturn;

	//引数として受け取った要素数分繰り返す
	for(size_t i = 0; i < nmemb; i++) {
		//探索す文字と要素を比較し一致したとき
		if(!compar(key,reinterpret_cast<const void*>(&x[i * size]))) {
			//その時の要素へのポインタを格納してループを抜ける
			vReturn = const_cast<void*>(reinterpret_cast<const void*>(&x[i * size]));
			break;
		//一致しない時はNULLポインタを格納
		} else {
			vReturn = NULL;
		}
	}

	return vReturn;
}

int main()
{
	int nArrayNumber;		//要素数を入力する変数
	int nSearch;			//探したい値を入力する変数

	//要素数の入力
	cout << "要素数：";
	cin >> nArrayNumber;

	//入力された要素数分の領域を確保
	int* nArray = new int[nArrayNumber];

	//確保した各領域に入力
	for(int i = 0; i < nArrayNumber; i++) {
		cout << "nArray[" << i << "] = ";
		cin  >> nArray[i];
	}

	//配列に入力された値から探したい値の入力
	cout << "探したい数：";
	cin  >> nSearch;

	//seqsearchを使って返却された探したい値を指すポインタを格納
	int* p = reinterpret_cast<int*>(seqsearch(&nSearch,nArray,nArrayNumber,
			sizeof(int),reinterpret_cast<int (*)(const void*,const void*)>(compar)));

	//返却されたのがNULLポインタではない時
	if(p != NULL) {
		//返却されたポインタから先頭のポインタを引いて添字を計算してどの要素が一致したか表示
		cout << "nArray[" << (p - nArray) << "]が一致しました。\n";
	//NULLポインタの時見つからなかったことを表示
	} else {
		cout << "見つかりませんでした。\n";
	}

	//main関数の返却値
	return 0;
}
