/* 演習09-05
 * クラスArray<bool>型に対してvelemのゲッターの働きを持つメンバ関数の追加
 * 作成日：6月8日
 * 作成者：成田修之
 */


#include<iostream>
#include"Array.h"
#include"boolArray.h"

using namespace std;

int main()
{
	//Array<bool>型オブジェクトを生成
	Array<bool> a(34);
	//配列の真偽を表すのに必要なビットベクトルの要素数を表示
	cout << a.get_vsize();

	//main関数の返却値
	return 0;

}
