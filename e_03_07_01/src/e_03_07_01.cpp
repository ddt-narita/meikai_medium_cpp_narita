/* 演習03-07-01 配列の文字列の配列ver.
 * qsort関数を用いて文字列の配列、文字列へのポインタの配列それぞれ昇順にソートする
 * プログラムの作成
 * 作成日：6月1日
 * 作成者：成田修之
 */

#include<iostream>
#include<cstring>
using namespace std;

//関数strcmpを使って文字列の比較を行う関数
int strCmp(const char* stringA, const char* stringB) {
	return strcmp(stringA,stringB);
}

int main()
{
	//演習で示された文字列配列
	char chrArray[][8] = {"LISP\0","C\0","Ada\0","Pascal\0"};
	//文字列の個数を求める
	int nArrayNumber = sizeof(chrArray) / sizeof(chrArray[0]);

	//ソート前を表示することを明示
	cout << "ソート前\n";

	//ソート前の並びを表示
	for(int i = 0; i < nArrayNumber; i++) {
		cout << chrArray[i] << "\n";
	}

	//クイックソート関数で文字列をソートする
	qsort(chrArray,nArrayNumber,sizeof(char**),reinterpret_cast<int(*)(const void*, const void*)>(strCmp));

	//クイックソート関数を使ってソートしたことを表示
	cout << "ソートしました。\n";

	//それぞれの文字列を表示
	for(int i = 0; i < nArrayNumber; i++) {
		cout << chrArray[i] << "\n";
	}

	//main関数の返却値
	return 0;
}
