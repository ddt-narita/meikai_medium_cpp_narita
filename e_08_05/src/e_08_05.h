/* 演習08-05
 * 数値演算例外クラス群の関数displayを文字列を返却するように仕様変更した関数を作成
 * 作成日：6月6日
 * 作成者：成田修之
 */


#ifndef ___Math_Exception
#define ___Math_Exception

#include<string>
#include<sstream>
#include<iostream>

//演算例外の基底クラス
class MathException {
public:
	//純粋仮想デストラクタ
	virtual ~MathException() = 0;
	//例外が発生したことを表示する関数
	virtual std::string what()const {
		//返却する文字列ストリーム
		std::ostringstream s;
		//文字列ストリームに挿入
		s << "数値演算例外\n";
		//挿入された出力ストリームを返却
		return s.str();
	}
};

//純粋仮想デストラクタの定義
MathException::~MathException() {

}

//0による除算での演算例外
class DividedByZero :public MathException {
public:
	//0による除算の演算例外であることを表す文字列を返却する関数
	virtual std::string what()const {
		//返却する文字列ストリーム
		std::ostringstream s;
		//文字列をストリームに挿入
		s << "0による除算\n";
		//挿入された出力ストリームを返却
		return s.str();
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
	virtual std::string what()const {
		//返却する文字列ストリーム
		std::ostringstream s;
		//文字列をストリームに挿入
		s << "オーバーフロー(値は" << v <<")\n";
		//挿入された出力ストリームを返却
		return s.str();
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

	//アンダーフローしたこととその値の文字列表現を返却する関数
	virtual std::string what()const {
		//返却する文字列ストリーム
		std::ostringstream s;
		//文字列をストリームに挿入
		s << "アンダーフロー（値は" << v << "）\n";
		//挿入された出力ストリームを返却
		return s.str();
	}
};

//インクルードガードの終わり
#endif
