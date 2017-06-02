/* 演習04-03
 * list4-12のクラスBase型とDerived型にたいしてアップキャストとダウンキャストを
 * 試みるプログラムの作成
 * 作成日：6月2日
 * 作成者：成田修之
 */

#include<iostream>
#include"e_04_03.h"

using namespace std;

int main()
{
	Base base(1,2);				//基底クラスオブジェクト
	Derived derived(3,4,5);		//派生クラスオブジェクト

	//基底クラスを指すポインタをbaseへのポインタとして定義
	Base* ptrBase1 =&base;
	//ポインタからBaseのメンバ関数funcを呼び出してデータを表示
	cout << "baseの値\n";
	ptrBase1->func();

	//派生クラスを指すポインタから基底クラスを指すポインタへのアップキャスト
	Base* ptrBase2 = &derived;
	//基底クラス部分メンバ関数で部分メンバデータの表示
	cout << "derivedの基底クラスBase部分オブジェクトの値\n";
	ptrBase2->func();

	//アップキャストした後派生クラスのメンバにはアクセスできなかった
//	cout << "derivedのデータの値";
//	ptrBase2->method();
//
	//ダウンキャストはできなかった
//	Derived* ptrDerived1 = &base;
//	cout << "derivedのデータの値";
//	ptrDerived1->method();

	//派生クラスへのポインタをderiveへのポインタとして定義
	Derived* ptrDerived2 = &derived;
	//派生クラスのオブジェクトのデータを表示
	cout << "derivedのデータの値\n";
	ptrDerived2->method();

	//main関数の返却値
	return 0;
}

/* コメントアウトした部分がキャストできなかった。基底クラスへのポインタで派生クラスを
 * 指すアップキャストしたとき派生クラスのメンバへアクセスはできなかった。
 * 派生クラスへのポインタで基底クラスのポインタを指すダウンキャストはできなかった。
 */
