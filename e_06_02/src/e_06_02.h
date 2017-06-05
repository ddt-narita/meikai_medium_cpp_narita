/* 演習06-02 header
 * 前問で作成したクラスを含めてすべての図形クラス軍をテストするプログラムを作成
 * list6-4と同じくShape型の配列を利用してオブジェクトの生成と表示を行う
 * 作成日：6月5日
 * 作成者：成田修之
 */

#ifndef ___Class_Shape
#define ___Class_Shape

#include<iostream>
#include<sstream>
#include<string>
#include<typeinfo>

//抽象クラス
class Shape {
public:
	virtual ~Shape() = 0;							//純粋仮想デストラクタとするための宣言
	virtual Shape* clone() const = 0;				//クローンを生成してそのオブジェクトへのポインタを返却する仮想関数
	virtual void draw() const = 0;				//その図形を表示する関数
	virtual std::string to_string() const = 0;	//文字列表現にする関数

	//文字列表現の情報付きで図形を表示する関数
	void print() const {
		std::cout << to_string() << "\n";
		draw();
	}

	//デバッグ時用の情報を表示する関数
	virtual void debug()const = 0;
};

//純粋仮想デストラクタの定義
inline Shape::~Shape() {

}

//デバッグ情報を表示する関数の定義
inline void Shape::debug() const
{
	std::cout << "---デバッグ情報---\n";
	std::cout << "型：" << typeid(*this).name() << "\n";
	std::cout << "アドレス：" << this << "\n";
}

//Shape型のpublic派生のポイントクラス
class Point :public Shape {
public:

	//描画する関数のオーバーライド
	void draw() const {
		std::cout << "*\n";
	}

	//クローンを生成してそのオブジェクトへのポインタを返却する関数のオーバーライド
	Point* clone() const {
		return new Point;
	}

	//クラス名の文字列表現を表現を返却する関数
	std::string to_string() const {
		return "Point";
	}

	//デバッグ時用の情報を表示する関数
	void debug() const {
		Shape::debug();
	}
};

//直線クラスの抽象クラス
class Line :public Shape {
protected:
	int length;		//長さのデータ

public:

	//コンストラクタ
	Line(int len) :length(len) {

	}

	//長さを返却する関数
	int get_length() const {
		return length;
	}

	//デバッグ時用の情報を表示する関数
	void debug() const {
		Shape::debug();
		std::cout << "length：" << length << "\n";
	}
};

//水平方向への直線クラス
class HorzLine :public Line {
public:
	//コンストラクタ
	HorzLine(int len) :Line(len) {

	}

	///クローンを生成してそのオブジェクトへのポインタを返却する関数のオーバーライド
	virtual HorzLine* clone() const {
		return new HorzLine(length);
	}

	//描画する関数のオーバーライド
	void draw() const {
		//長さ分-を表示する
		for (int i = 0; i <=length; i++) {
			std::cout << "-";
		}
		std::cout << "\n";
	}

	//クラス名の文字列表現を表現を返却する関数
	std::string to_string() const {
		std::ostringstream os;
		os << "HorzLine(length:" << length << ")";
		return os.str();
	}
};


//垂直方向への直線クラス
class VertLine :public Line {
public:
	//コンストラクタ
	VertLine(int len) :Line(len) {

	}

	///クローンを生成してそのオブジェクトへのポインタを返却する関数のオーバーライド
	virtual VertLine* clone() const {
		return new VertLine(length);
	}

	//描画する関数のオーバーライド
	void draw() const {
		//長さ分繰り返して｜を表示して次の段へ
		for(int i = 1; i <= length; i++) {
			std::cout << "|\n";
		}
	}

	//クラス名の文字列表現を表現を返却する関数
	std::string to_string() const {
		std::ostringstream os;
		os << "VertLine(length：" << length << ")";
		return os.str();
	}
};

//
class Rectangle :public Shape {
	int width;			//幅に関するデータ
	int height2;		//高さに関するデータ

public:
	//コンストラクタ
	Rectangle(int w, int h):width(w),height2(h) {

	}

	///クローンを生成してそのオブジェクトへのポインタを返却する関数のオーバーライド
	Rectangle* clone() const {
		return new Rectangle(width, height2);
	}

	//描画する関数のオーバーライド
	void draw() const {
		//高さ分繰り返す
		for(int i = 1; i <= height2; i++) {
			//幅分*を表示する
			for(int j = 1; j <= width; j++) {
				std::cout << "*";
			}
			std::cout << "\n";
		}
	}

	//クラス名と幅と高さデータの文字列表現を表現を返却する関数
	std::string to_string() const {
		std::ostringstream os;
		os << "Rectangle(width：" << width << ", height：" << height2 << ")";
		return os.str();
	}

	//デバッグ時用の情報を表示する関数
	void debug() const {
		Shape::debug();
		std::cout << "width ：" << width << "\n";
		std::cout << "height：" << height2 << "\n";
	}
};

//直角2等辺三角形の抽象クラス
class Triangle :public Shape {
protected:
	//高さのデータ
	int height;
public:
	//コンストラクタ
	Triangle(int h) :height(h) {

	}

	//高さを返却する関数
	int get_height() const {
		return height;
	}

	//引数をその2等辺直角三角形の高さにセットする関数
	void set_height(int h) {
		height = h;
	}

	//デバッグ情報を表示する関数
	void debug() const {
		Shape::debug();
		std::cout << "height：" << height << "\n";
	}
};

//左下直角2等辺三角形
class LowerLeft :public Triangle {
public:
	//コンストラクタ
	LowerLeft(int h):Triangle(h) {

	}

	///クローンを生成してそのオブジェクトへのポインタを返却する関数のオーバーライド
	LowerLeft* clone() const {
		return new LowerLeft(height);
	}

	//描画する関数のオーバーライド
	void draw() const {
		//高さ分繰り返す
		for(int i = 1; i <= height; i++) {
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
		os << "LowerLeft(height：" << height << ")";
		return os.str();
	}
};


//左上直角2等辺三角形
class UpperLeft :public Triangle {
public:
	//コンストラクタ
	UpperLeft(int h):Triangle(h) {

	}

	///クローンを生成してそのオブジェクトへのポインタを返却する関数のオーバーライド
	virtual UpperLeft* clone() const {
		return new UpperLeft(height);
	}

	//描画する関数のオーバーライド
	void draw() const {
		//高さ分繰り返す
		for(int i = 1; i <= height; i++) {
			//高さからその段を引いた数足す一個*を表示
			for(int j = height - i; j >= 0; j--) {
				std::cout << "*";
			}
			std::cout << "\n";
		}
	}

	//クラス名と高さデータの文字列表現を表現を返却する関数
	std::string to_string() const {
		std::ostringstream os;
		os << "UpperLeft(height：" << height << ")";
		return os.str();
	}
};

//右下直角2等辺三角形
class LowerRight :public Triangle {
public:
	//コンストラクタ
	LowerRight(int h):Triangle(h) {

	}

	///クローンを生成してそのオブジェクトへのポインタを返却する関数のオーバーライド
	virtual LowerRight* clone() const {
		return new LowerRight(height);
	}

	//描画する関数のオーバーライド
	void draw() const {
		//高さ分繰り返す
		for(int i = 1; i <= height; i++) {
			//高さからその段分引いた数空白を表示
			for(int j = 1; j <= height - i; j++) {
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
		os << "LowerRight(height：" << height << ")";
		return os.str();
	}
};

//右上直角二等辺三角形
class UpperRight :public Triangle {
public:
	//コンストラクタ
	UpperRight(int h) :Triangle(h) {

	}

	///クローンを生成してそのオブジェクトへのポインタを返却する関数のオーバーライド
	virtual UpperRight* clone() const {
		return new UpperRight(height);
	}

	//
	void draw() const {
		//高さ分繰り返す
		for(int i = 1; i <= height; i++) {
			//その段マイナス一個空白を表示
			for(int j = 1; j <= i - 1; j++) {
				std::cout << " ";
			}
			//残りを*で埋める
			for(int j = height - i; j >= 0;j--) {
				std::cout << "*";
			}
			std::cout << "\n";
		}
	}

	//クラス名と高さデータの文字列表現を表現を返却する関数
	std::string to_string() const {
		std::ostringstream os;
		os << "UpperRight(" << height << ")";
		return os.str();
	}
};

//挿入子の多重定義
inline std::ostream& operator<<(std::ostream& os, const Shape& s) {
	//多相的な関数to_stringを使って動的にオブジェクトの文字列表現を返却する
	return os << s.to_string();
}

#endif
