/* 演習07-03 RectEquilTriangle
 * 左上直角二等辺三角形と右下直角２等辺三角形を作成する
 * 作成日：６月６日
 * 作成者：成田修之
 */

#ifndef ___Class_RectEquilTriangle
#define ___Class_RectEquilTriangle

#include<string>
#include<sstream>
#include<iostream>
#include"Shape.h"
#include"TwoDimensional.h"

class RectEquilTriangle :public Shape, public TwoDimensional
{
protected:
	int length;

public:
	RectEquilTriangle(int len) :length(len) {

	}

	double get_area() const {
		return length * length / 2.0;
	}
};


//左下直角2等辺三角形
class RectEquilTriangleLB :public RectEquilTriangle {
public:
	//コンストラクタ
	RectEquilTriangleLB(int h):RectEquilTriangle(h) {

	}

	///クローンを生成してそのオブジェクトへのポインタを返却する関数のオーバーライド
	RectEquilTriangleLB* clone() const {
		return new RectEquilTriangleLB(length);
	}

	//描画する関数のオーバーライド
	void draw() const {
		//高さ分繰り返す
		for(int i = 1; i <= length; i++) {
			//その段分*を表示する
			for(int j = 1; j <= i; j++) {
				std::cout << '*';
			}
			std::cout << "\n";
		}
	}

	//クラス名と高さデータの文字列表現を表現を返却する関数
	std::string to_string() const {
		std::ostringstream os;
		os << "LowerLeft(height：" << length << ")";
		return os.str();
	}

	void debug() const {
		Shape::debug();
		std::cout << "クラス：RectEquilTriangleLB\n";
		std::cout << "アドレス：" << this << "\n";
		std::cout << "length：" << length << "\n";
	}
};


//左上直角2等辺三角形
class RectEquilTriangleLU :public RectEquilTriangle {
public:
	//コンストラクタ
	RectEquilTriangleLU(int h):RectEquilTriangle(h) {

	}

	///クローンを生成してそのオブジェクトへのポインタを返却する関数のオーバーライド
	virtual RectEquilTriangleLU* clone() const {
		return new RectEquilTriangleLU(length);
	}

	//描画する関数のオーバーライド
	void draw() const {
		//高さ分繰り返す
		for(int i = 1; i <= length; i++) {
			//高さからその段を引いた数足す一個*を表示
			for(int j = length - i; j >= 0; j--) {
				std::cout << "*";
			}
			std::cout << "\n";
		}
	}

	//クラス名と高さデータの文字列表現を表現を返却する関数
	std::string to_string() const {
		std::ostringstream os;
		os << "UpperLeft(height：" << length << ")";
		return os.str();
	}

	void debug() const {
		Shape::debug();
		std::cout << "クラス：RectEquilTriangleLU\n";
		std::cout << "アドレス：" << this << "\n";
		std::cout << "length：" << length << "\n";
	}
};

//右下直角2等辺三角形
class RectEquilTriangleRB :public RectEquilTriangle {
public:
	//コンストラクタ
	RectEquilTriangleRB(int h):RectEquilTriangle(h) {

	}

	///クローンを生成してそのオブジェクトへのポインタを返却する関数のオーバーライド
	virtual RectEquilTriangleRB* clone() const {
		return new RectEquilTriangleRB(length);
	}

	//描画する関数のオーバーライド
	void draw() const {
		//高さ分繰り返す
		for(int i = 1; i <= length; i++) {
			//高さからその段分引いた数空白を表示
			for(int j = 1; j <= length - i; j++) {
				std::cout << " ";
			}
			//残りを*で埋める
			for(int j = 1; j <= i; j++) {
				std::cout << "*";
			}
			std::cout << "\n";
		}
	}

	//クラス名と高さデータの文字列表現を表現を返却する関数
	std::string to_string() const {
		std::ostringstream os;
		os << "LowerRight(height：" << length << ")";
		return os.str();
	}

	void debug() const {
		Shape::debug();
		std::cout << "クラス：RectEquilTriangleRB\n";
		std::cout << "アドレス：" << this << "\n";
		std::cout << "length：" << length << "\n";
	}
};

//右上直角二等辺三角形
class RectEquilTriangleRU :public RectEquilTriangle {
public:
	//コンストラクタ
	RectEquilTriangleRU(int h) :RectEquilTriangle(h) {

	}

	///クローンを生成してそのオブジェクトへのポインタを返却する関数のオーバーライド
	virtual RectEquilTriangleRU* clone() const {
		return new RectEquilTriangleRU(length);
	}

	//
	void draw() const {
		//高さ分繰り返す
		for(int i = 1; i <= length; i++) {
			//その段マイナス一個空白を表示
			for(int j = 1; j <= i - 1; j++) {
				std::cout << " ";
			}
			//残りを*で埋める
			for(int j = length - i; j >= 0;j--) {
				std::cout << "*";
			}
			std::cout << "\n";
		}
	}

	//クラス名と高さデータの文字列表現を表現を返却する関数
	std::string to_string() const {
		std::ostringstream os;
		os << "UpperRight(" << length << ")";
		return os.str();
	}

	void debug() const {
		Shape::debug();
		std::cout << "クラス：RectEquilTriangleRU\n";
		std::cout << "アドレス：" << this << "\n";
		std::cout << "length：" << length << "\n";
	}
};

#endif
