/* 演習07-04
 * ３次元クラスThreeDimensionalを抽象基底クラスとして定義してそれを継承するクラスを自由に作成
 * 作成日：６月６日
 * 作成者：成田修之
 */

#ifndef ___Class_ThreeDimensional
#define ___Class_ThreeDimensional


#include<string>
#include<iostream>
#include<typeinfo>

class ThreeDimensional {

public:
	//純粋仮想デストラクタ
	virtual ~ThreeDimensional() = 0;

	//体積を求めて返却する関数
	virtual double get_volume() const = 0;

	//複製する純粋仮想関数
	virtual ThreeDimensional* clone() const = 0;

	//文字列表現を返却する仮想関数
	virtual std::string to_string() const = 0;

	//デバッグ時用の情報を表示する純粋仮想関数
	virtual void debug() const = 0;
};

//純粋仮想デストラクタの定義
inline ThreeDimensional::~ThreeDimensional() {

}

//Shape型におけるデバッグ時用の情報を表示する関数の定義
inline void ThreeDimensional::debug()const
{
	std::cout << "--デバッグ情報--\n";
	std::cout << "型：" << typeid(*this).name() << "\n";
	std::cout << "アドレス：" << this << "\n";
}


//挿入子の多重定義
inline std::ostream& operator<<(std::ostream& os,const ThreeDimensional& s)
{
	//文字列表現を乗せた出力ストリームを返却する
	return os << s.to_string();
}

#endif

