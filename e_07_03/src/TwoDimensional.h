/* 演習07-03 TwoDimensional
 * 左上直角二等辺三角形と右下直角２等辺三角形を作成する
 * 作成日：６月６日
 * 作成者：成田修之
 */

#ifndef ___Class_TwoDimensional
#define ___Class_TwoDimensional

class TwoDimensional {
public:
	//純粋仮想デストラクタ
	virtual ~TwoDimensional() = 0;
	//２次元図形の面積を求める純粋仮想関数
	virtual double get_area() const = 0;
};

//純粋仮想デストラクタの定義
inline TwoDimensional::~TwoDimensional() {

}

#endif
