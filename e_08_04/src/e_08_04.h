/* 演習08-04
 * 多層クラスによる例外クラスの階層化を実際にプログラムを作成して動作の検証を行い
 * 学習した内容を確認
 * 作成日：6月6日
 * 作成者：成田修之
 */

#ifndef ___Math_Exception
#define ___Math_Exception

#include<string>

//演算例外の基底クラス
class MathException {
public:
	//純粋仮想デストラクタ
	virtual ~MathException() = 0;
	//例外が発生したことを表示する関数
	virtual void display()const {
		std::cout << "数値演算例外\n";
	}
};

//純粋仮想デストラクタの定義
MathException::~MathException() {

}

//0による除算での演算例外
class DividedByZero :public MathException {
public:
	//0による除算の演算例外であることを表示
	void display() const {
		std::cout << "0による除算\n";
	}
};

//オーバーフローしたとき送出される例外クラス
class Overflow :public MathException {
	//オーバーフローした時の値データ
	int v;
public:
	//コンストラクタ
	Overflow(int val):v(val) {

	}
	//オーバーフローした時の値を返却する
	int value()const {
		return v;
	}
	//オーバーフローしたこととその時の値を表示する関数
	void display() const {
		std::cout << "オーバーフロー（値は" << v << ")\n";
	}
};

//アンダーフローした時送出される例外クラス
class Underflow : public MathException {
	//アンダーフローした時の値データ
	int v;
public:
	//コンストラクタ
	Underflow(int val):v(val) {

	}
	//アンダーフローした時の値を返却する
	int value()const {
		return v;
	}
	//アンダーフローしたこととその時の値を表示する関数
	void display() const {
		std::cout << "アンダーフロー（値は" << v << ")\n";
	}
};

//インクルードガードの終わり
#endif
