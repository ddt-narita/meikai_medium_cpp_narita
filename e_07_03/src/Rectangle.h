/* 演習07-03 Rectangle
 * 左上直角二等辺三角形と右下直角２等辺三角形を作成する
 * 作成日：６月６日
 * 作成者：成田修之
 */

#ifndef ___Class_Rectangle
#define ___Class_Rectangle

#include<string>
#include<sstream>
#include<iostream>
#include"Shape.h"
#include"TwoDimensional.h"

//長方形クラス
class Rectangle: public Shape, public TwoDimensional {
	int width;		//幅
	int height;		//高さ

public:
	//コンストラクタ
	Rectangle(int w, int h) :width(w),height(h){

	}

	//複製してそのオブジェクトへのポインタを返却する関数
	Rectangle* clone() const {
		return new Rectangle(width, height);
	}

	//そのオブジェクトを描画する関数
	void draw() const {
		//高さ分繰り返す
		for(int i = 1; i <= height; i++) {
			//幅分繰り返して＊を表示する
			for(int j = 1; j <= width; j++) {
				std::cout << "*";
			}
			//高さ１ごとに改行する
			std::cout << "\n";
		}
	}

	//文字列表現を返却する関数
	std::string to_string() const {
		std::ostringstream os;
		//文字列出力ストリームに図形名と幅と高さを挿入して返却
		os << "Rectangle(width:" << width << ",height:" << height << ")";
		return os.str();
	}

	//デバッグ時用の情報を表示する関数
	void debug()const {
		//基底クラスShapeの関数Debugを表示した後
		Shape::debug();
		//新たに長方形クラスで追加されたデータメンバの表示を行う
		std::cout << "width : " << width << "\n";
		std::cout << "height : " << height << "\n";
	}

	//面積を求める関数
	double get_area() const {
		//長方形の面積公式幅かける高さを求めて返却
		return width * height;
	}
};

#endif
