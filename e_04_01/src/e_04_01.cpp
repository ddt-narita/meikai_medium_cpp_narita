/* 演習04-01
 * list4-15のクラスBaseのコンストラクタを引数があっても派生クラスの
 * デフォルトコンストラクタで呼び出せるように書き換えて確認する
 * 作成日：6月2日
 * 作成者：成田修之
 */

#include<iostream>
using namespace std;

//基底クラスBase
class Base {
	int x;		//非公開のクラスBaseのデータ

public:

	//引数を受け取らなくても呼び出せるように書き直したデフォルトコンストラクタ
	Base(int xx = 99):x(xx) {
		//ちゃんと呼び出せたとき基底クラスのデータを初期化したこととその値を表示
		cout << "Base::xを" << x << "で初期化。\n";
	}

	//データのⅹを返却する公開メンバ関数
	int get_x() const {
		return x;
	}
};

//コンストラクタ等何も定義しない、クラスBaseの派生クラス
class Derived :public Base {

};

int main() {
	//クラスBaseの派生クラスのオブジェクトを生成
	//デフォルトコンストラクタがきちんとコンパイラによって自動で呼び出されていることを確認
	Derived d;

	//基底クラスBaseの公開メンバ関数で基底クラス部分オブジェクトのⅹを表示
	cout << "d.get_x() = " << d.get_x() << "\n";

	//main関数の返却値
	return 0;
}
