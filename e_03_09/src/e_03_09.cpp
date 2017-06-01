/* 演習03-09
 * list03-15の関数binsearch関数を利用するプログラムの作成
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

//2分探索関数
void* binsearch(const void* key, const void* base, size_t nmemb,size_t size,
		int (*compar)(const void*, const void*))
{
	//返却する探した要素をさすポインタ
	void* vptrReturn;

	//要素数が正の時
	if(nmemb > 0) {
		//先頭へのポインタを1バイトごとであらわせるようにconst char*型にキャスト
		const char* x = reinterpret_cast<const char*>(base);
		size_t pl = 0;	//探索範囲先頭の添字
		size_t pr = nmemb - 1;	//探索範囲末尾の添字
		size_t pc;		//探索範囲中央の添字


		//breakされるまで繰り返す
		while(true) {
			//探したい値と探索範囲中央の要素を関数comparによって比較して
			//返却された値を格納する変数の宣言
			int comp = compar(key,reinterpret_cast<const void*>(&x[(pc = (pl+pr) / 2) * size]));

			//返却された値が0、一致したとき
			if(comp == 0) {
				//探したい要素へのポインタを格納してループを抜ける
				vptrReturn = const_cast<void*>(reinterpret_cast<const void*>(&x[pc * size]));
				break;
			//
			} else if (pl == pr) {
				vptrReturn = NULL;
				break;
			//
			} else if (comp > 0) {
				pl = pc + 1;
			//
			} else {
				pr = pc - 1;
			}
		}
	}
	return vptrReturn;
}



int main()
{
	int nArrayNumber = 6;		//要素数を入力する変数
	int nSearch = 4;			//探したい値を入力する変数

	//要素数の入力
	cout << "要素数：";
	cin >> nArrayNumber;

	//入力された要素数分の領域を確保
	int* nArray = new int[nArrayNumber];

	for(int i = 0; i < 6; i++) {
		nArray[i] = i;
	}

	//
	cout << "nArray[0] = ";
	cin  >> nArray[0];
	//確保した各領域に入力
	for(int i = 1; i < nArrayNumber; i++) {
		do {
			cout << "nArray[" << i << "] = ";
			cin  >> nArray[i];
		//
		}while(nArray[i] < nArray[i - 1]);
	}


	//配列に入力された値から探したい値の入力
	cout << "探したい数：";
	cin  >> nSearch;

	//seqsearchを使って返却された探したい値を指すポインタを格納
	int* p = reinterpret_cast<int*>(binsearch(&nSearch,nArray,nArrayNumber,
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
