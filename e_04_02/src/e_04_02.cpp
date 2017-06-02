/* 演習04-02
 * デストラクタの起動順序を確認できるようにlist4-16を書き換えたプログラムの作成
 * 作成日：6月2日
 * 作成者：成田修之
 */

#include<iostream>
using namespace std;

//基底クラスBase
class Base {
	int x;	//データ
public:
	//デフォルトコンストラクタ
	Base(int a = 0):x(a) {
		cout << "Base::xを" << a << "で初期化しました。\n";
	}
	//デストラクタ
	~Base() {
		cout << "Base::xを削除しました\n";
	}
};

class Memb {
	int x;	//データ
public:
	//デフォルトコンストラクタ
	Memb(int a = 0):x(a) {
		cout << "Memb::xを" << a << "で初期化しました。\n";
	}
	//デストラクタ
	~Memb() {
		cout << "Memb::xを削除しました。\n";
	}
};

//クラスBaseの基底クラス
class Derived :public Base {
	int y;		//クラスDerivedのデータ
	Memb m1;	//クラスMembがたのオブジェクトデータ
	Memb m2;	//クラスMembがたのオブジェクトデータ

	//コンストラクタで呼び出す初期化されたことを表示する関数
	void say() {
		y = 0;
		cout << "Derived::yを" << y << "で初期化しました。\n";
	}
public:
	//デフォルトコンストラクタ
	Derived() {
		say();
	}
	//コンストラクタ
	Derived(int a, int b, int c) :Base(c),m1(a),m2(b) {
		say();
	}
	//デストラクタ
	~Derived() {
		cout << "Derived::yを削除しました\n";
	}
};

int main()
{
	//デフォルトコンストラクタで初期化されたBaseの派生クラスDerivedオブジェクト
	Derived d1;

	//コンストラクタで初期化されたBaseの派生クラスDerivedのオブジェクト
	Derived d2(1,2,3);

	//main関数の返却値
	return 0;
}
