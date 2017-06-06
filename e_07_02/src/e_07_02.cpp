/* 演習07-02
 * list7-1のクラスderivedにメンバ関数printを追加
 * 作成日：６月６日
 * 作成者：成田修之
 */

#include<iostream>

using namespace std;

//基底クラスBase1
class Base1 {
public:
	//公開データメンバ
	int x;
	//コンストラクタ
	Base1(int a = 0) : x(a) {
		//オブジェクト生成時に初期化したこととその値を表示
		cout << "Base1::を" << x << "に初期化しました。\n";
	}

	//オブジェクトの型とその値を表示する関数
	void print() {
		cout << "Base1クラスです：x = " << x << "\n";
	}
};

//基底クラスBase2
class Base2 {
public:
	//公開データメンバ
	int x;
	//コンストラクタ
	Base2(int a = 0) :x(a) {
		//オブジェクトの生成の際に初期化したこととその値を表示する
		cout << "Base2::を" << x << "に初期化しました。\n";
	}

	//そのオブジェクトの型とそのデータの値を表示する関数
	void print() {
		cout << "Base2クラスです：x = " << x << "\n";
	}
};

//派生クラスDerived
class Derived : public Base1, public Base2 {
	//データ
	int y;
public:
	//コンストラクタ
	Derived(int a, int b, int c):Base1(b),Base2(a),y(c) {
		//オブジェクト生成時に初期化したこととその値を表示する
		cout << "Derived::yを" << y << "に初期化しました。\n";
	}

	//引数でクラスBase1のデータ、Base2のデータに設定する関数
	void func(int a, int b) {
		Base1::x = a;
		Base2::x = b;
	}

	//それぞれの型情報と値を表示する関数
	void print() {
		Base1::print();
		Base2::print();
		cout << "Derivedクラスです：y = " << y << "\n";
	}
};


int main()
{
	//クラスDerived型のオブジェクトの作成
	Derived z(1,2,3);
	//関数func
	z.func(1,2);

	//クラスDerivedの関数printの呼び出し
	z.print();

	//クラスBase1の関数printの呼び出し
	z.Base1::print();
	//クラスBase2の関数print呼び出し
	z.Base2::print();

	//main関数の返却値
	return 0;
}
