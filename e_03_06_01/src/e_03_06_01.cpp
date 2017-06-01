/* 演習03－06 配列ver.
 * bsearch関数を用いて文字列の配列から探索を行うプログラムの作成
 * 配列の文字列とポインタの文字列の両方の配列ver.をつくる
 * 作成日：5月31日
 * 作成者：成田修之
 */

#include<iostream>
using namespace std;

//比較関数
int int_cmpr(const char* a, const char*b)
{
	return *a < *b ? -1 : *a > *b ? 1 : 0;
}

int main()
{
	int nArrayNumber = 3;		//文字列配列の要素数
	int nStringNumber = 5;		//文字列の要素数
	char chrArray[nArrayNumber][nStringNumber];		//文字列の配列
	int count = 0;				//NULLポインタの個数をカウントする変数

	//各文字列に文字列の要素分の文字の入力を促す
	cout << "各要素に"<< nArrayNumber << "個の文字を小さい順に入力せよ。\n";

	//各文字列に入力
	for(int i = 0; i < nArrayNumber; i++) {
		cout << "chr[" << i << "]：";
		cin  >> chrArray[i];
	}

	//探索する文字を入力する変数
	char key;
	//探索する文字の入力を促す
	cout << "探索する文字：";
	cin >> key;


	//文字列の個数分のポインタを用意
	char *p[nArrayNumber];
	//文字列の個数分繰り返す
	for(int i = 0; i < nArrayNumber; i++) {
		//文字列へのポインタに対してbsearch関数を用いて探索された値を格納
		p[i] = reinterpret_cast<char*>(bsearch(&key,chrArray[i],nStringNumber,sizeof(char),
				reinterpret_cast<int (*)(const void*, const void*)>(int_cmpr)));
	}

	//文字列配列の要素分繰り返す
	for(int i = 0; i < nArrayNumber; i++) {
		//NULLポインタではない時
		if(p[i] != NULL) {
			cout <<"chrArray[" << i << "][" << (p[i] - chrArray[i]) << "]が一致します。\n";
		//NULLポインタの時はその個数をカウントする
		} else {
			count++;
		}
	}
	//bsearch関数から返却されたすべての要素がNULLポインタの時見つからなかったことを表示
	if(count == nArrayNumber) {
		cout << "見つかりませんでした。\n";
	}

	//main関数の返却値
	return 0;
}
