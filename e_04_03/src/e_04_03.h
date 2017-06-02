/* 演習04-03
 * list4-12のクラスBase型とDerived型にたいしてアップキャストとダウンキャストを
 * 試みるプログラムの作成
 * 作成日：6月2日
 * 作成者：成田修之
 */

#ifndef ___Member
#define ___Member

#include<iostream>

//基底クラスBase
class Base {
	int a;	//データ
	int b;	//データ
public:
	//コンストラクタ
	Base(int aa, int bb):a(aa), b(bb) {

	}
	//クラスBaseのデータ2つを表示
	void func() const {
		std::cout << "a = " << a << "\n";
		std::cout << "b = " << b << "\n";
	}
};

//クラスBaseの派生クラスDerived
class Derived :public Base {
	int x;	//データ
public:
	//コンストラクタ
	Derived(int aa, int bb, int xx) :Base(aa,bb),x(xx) {

	}
	//クラスDerivedの特化データの表示
	void method()const {
		func();
		std::cout << "x = " << x << "\n";
	}
};

//インクルードガードの終わり
#endif
