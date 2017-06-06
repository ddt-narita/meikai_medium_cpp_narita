/* 演習07-04
 * ３次元クラスThreeDimensionalを抽象基底クラスとして定義してそれを継承するクラスを自由に作成
 * 作成日：６月６日
 * 作成者：成田修之
 */


#ifndef ___Class_ThreeDimensionalObject
#define ___Class_ThreeDimensionalObject

#include<sstream>
#include<string>
#include<iostream>

#include"ThreeDimensional.h"


//円柱クラス
class Cylinder :public ThreeDimensional {
	int radius;		//半径
	int height;		//高さ
	//円周率π
	const double PI = 3.14;
public:

	//コンストラクタ
	Cylinder(int r,int h):radius(r),height(h){

	}

	//複製したオブジェクトへのポインタを返却する関数
	Cylinder* clone() const {
		return new Cylinder(radius,height);
	}

	//体積を求める関数
	double get_volume()const {
		return PI * radius * height;
	}

	//文字列表現にして返却する関数
	std::string to_string() const {
		std::ostringstream os;
		//半径と高さを一緒に表示
		os << "Cylinder(radius：" << radius << ",height：" << height << ")";
		return os.str();
	}

	//デバッグ時用の情報を表示する関数
	void debug() const {
		ThreeDimensional::debug();
		std::cout << "radius：" << radius << "\n";
		std::cout << "height：" << height << "\n";
	}
};


//立方体クラス
class Cube :public ThreeDimensional {
	int length;		//立方体の一辺の長さ
public:
	//コンストラクタ
	Cube(int len):length(len) {

	}

	//複製したオブジェクトへのポインタを返却する関数
	Cube* clone() const {
		return new Cube(length);
	}

	//体積を求めて返却する関数
	double get_volume() const {
		return length * length * length;
	}

	//文字列表現を返却する関数
	std::string to_string() const {
		std::ostringstream os;
		os << "Cube(length：" << length << ")";
		return os.str();
	}

	//デバッグ時用の情報を表示する関数
	void debug()const {
		//ThreeDimensionalの関数debugを呼び出し新たに追加されたデータlengthを表示
		ThreeDimensional::debug();
		std::cout << "length：" << length << "\n";
	}
};

#endif
