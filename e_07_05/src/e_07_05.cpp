/* 演習07-05
 * list7-14の各クラスにデストラクタを追加してオブジェクト解体の順序の確認を行う
 * 作成日：6月6日
 * 作成者：成田修之
 */

#include<iostream>

using namespace std;

//基底クラスV1
class V1 {
public:
	//コンストラクタ
	V1() {
		cout << "V1を初期化\n";
	}
	//デストラクタ
	~V1(){
		cout << "V1を解放\n";
	}
};

//基底クラス
class V2 {
public:
	//コンストラクタ
	V2() {
		cout << "V2を初期化\n";
	}
	//デストラクタ
	~V2(){
		cout << "V2を解放\n";
	}
};

//基底クラスV1、V2の派生クラス
class X :virtual public V1,virtual public V2 {
public:
	//コンストラクタ
	X() {
		cout << "Xを初期化\n";
	}
	//デストラクタ
	~X(){
		cout << "Xを解放\n";
	}
};

//基底クラスV1、V2の派生クラス
class Y :virtual public V2,virtual public V1 {
public:
	//コンストラクタ
	Y() {
		cout << "Yを初期化\n";
	}
	//デストラクタ
	~Y(){
		cout << "Yを解放\n";
	}
};


class Z :public X, public Y{
public:
	//コンストラクタ
	Z() {
		cout << "Zを初期化\n";
	}
	//デストラクタ
	~Z(){
		cout << "Zを解放\n";
	}
};


int main()
{
	//クラスZのオブジェクトを生成し、どの順序でデストラクタが呼び出され解体するか確認
	Z dummy;

	//main関数の返却値
	return 0;
}
