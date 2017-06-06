/* 演習07-03 Shape
 * 左上直角二等辺三角形と右下直角２等辺三角形を作成する
 * 作成日：６月６日
 * 作成者：成田修之
 */

#ifndef ___Class_Shape
#define ___Class_Shape

#include<string>
#include<iostream>
#include<typeinfo>


//抽象クラス
class Shape {
public:
	//純粋仮想デストラクタ
	virtual ~Shape() = 0;
	//複製する純粋仮想関数
	virtual Shape* clone() const = 0;
	//図形を描画する純粋仮想関数
	virtual void draw() const = 0;
	//文字列表現を返却する仮想関数
	virtual std::string to_string() const = 0;
	//その図形の文字列表現と描画をする仮想関数
	void print() const {
		std::cout << to_string() << "\n";
		draw();
	}
	//デバッグ時用の情報を表示する純粋仮想関数
	virtual void debug() const = 0;
};

//純粋仮想デストラクタの定義
inline Shape::~Shape(){

}

//Shape型におけるデバッグ時用の情報を表示する関数の定義
inline void Shape::debug()const
{
	std::cout << "--デバッグ情報--\n";
	std::cout << "型：" << typeid(*this).name() << "\n";
	std::cout << "アドレス：" << this << "\n";
}

//挿入子の多重定義
inline std::ostream& operator<<(std::ostream& os,const Shape& s)
{
	//文字列表現を乗せた出力ストリームを返却する
	return os << s.to_string();
}

#endif
