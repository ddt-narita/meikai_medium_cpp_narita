/* 演習09-07
 * 9章1節のクラステンプレートTwin<>をインクルードモデルで実現したプログラムの作成
 * 作成日：6月8日
 * 作成者：成田修之
 */

#include<iostream>
#include"Twin.h"

using namespace std;

int main()
{
	//Twin型オブジェクトを生成
	Twin<int> a(43,56);

	//オブジェクトを表示
	cout << a;

	//main関数の返却値
	return 0;
}
