/* 演習03-10
 * list03-16の関数binsearchxを利用するプログラムの作成
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
void* binsearchx(const void* key, const void* base, size_t nmemb,size_t size,
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
		while(1) {
			//探したい値と探索範囲中央の要素を関数comparによって比較して
			//返却された値を格納する変数の宣言
			int comp = compar(key,reinterpret_cast<const void*>(&x[(pc = (pl+pr) / 2) * size]));

			//返却された値が0、一致したとき
			if(comp == 0) {
				//中央の添字が先頭側より大きい限り続ける
				for( ; pc >= pl; pc--) {
					//探してる値と違う値の時ループを抜ける
					if(compar(key,reinterpret_cast<const void*>(&x[pc * size]))){
						break;
					}
					//一致するときはポインタを更新
					vptrReturn = const_cast<void*>(reinterpret_cast<const void*>(&x[pc * size]));
				}
				//更新し終わったらループを抜けてポインタを返却
				break;
			//先頭と末尾が一致して探索範囲がなくなったとき
			} else if (pl == pr) {
				//NULLポインタを格納してループを抜ける
				vptrReturn = NULL;
				break;
			//探している値のほうが中央より大きいとき
			} else if (comp > 0) {
				//先頭を中央の一つ右にして中央を更新
				pl = pc + 1;
				pc = (pl+pr) / 2;
			//探している値のほうが中央より小さいとき
			} else {
				//末尾を中央の一つ左にして中央を更新
				pr = pc - 1;
				pc = (pl+pr) / 2;
			}
		}
	}
	return vptrReturn;
}


int main()
{
	int nArrayNumber = 11;		//要素数を入力する変数
	int nSearch = 7;			//探したい値を入力する変数

	//要素数の入力
	cout << "要素数：";
	cin >> nArrayNumber;

	//入力された要素数分の領域を確保
	int* nArray = new int[nArrayNumber];

	//一つ前の値以上になるように入力することを表示
	cout << nArrayNumber << "個の整数を昇順に入力せよ（同じ値は可）\n";
	//先頭の要素は縛りを受けないので単体で入力
	cout << "nArray[0] = ";
	cin  >> nArray[0];
	//先頭以降はその一つ前の値より大きい値を入力
	for(int i = 1; i < nArrayNumber; i++) {
		//小さい値が入力される限り再入力を促す
		do {
			cout << "nArray[" << i << "] = ";
			cin  >> nArray[i];
		}while(nArray[i] < nArray[i - 1]);
	}


	//配列に入力された値から探したい値の入力
	cout << "探したい数：";
	cin  >> nSearch;

	//binsearchxを使って返却された探したい値を指すポインタを格納
	int* p = reinterpret_cast<int*>(binsearchx(&nSearch,nArray,nArrayNumber,
			sizeof(int),reinterpret_cast<int (*)(const void*,const void*)>(compar)));

	//返却されたのがNULLポインタではない時
	if(p != NULL) {
		//返却されたポインタから先頭のポインタを引いて添字を計算してどの要素が一致したか表示
		cout << "一致した中で先頭の要素はnArray[" << (p - nArray) << "]です。\n";
	//NULLポインタの時見つからなかったことを表示
	} else {
		cout << "見つかりませんでした。\n";
	}

	//main関数の返却値
	return 0;
}
