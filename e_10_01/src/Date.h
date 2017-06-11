/* 演習10-01
 * 日付クラスのベクトルを作成
 * 作成日：6月11日
 * 作成者：成田修之
 */


//インクルードガード
#ifndef ___Class_Date
#define ___Class_Date

#include<iostream>
#include<string>


class Date {
	int y;		//年についてのデータ
	int m;		//月のデータ
	int d;		//日にちのデータ

	//その月最大の日の配列
	static int dmax[];
	//その日の年内経過日数を返却する関数
	static int days_of_year(int year);
	//その年のその月の最大の日を返却する関数
	static int days_of_month(int year, int month);

public:
	//入力された年がうるう年かを判定する関数
	static bool leap_year(int year) {
		return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
	}

	//デフォルトコンストラクタの宣言
	Date();
	//コンストラクタの宣言
	Date(int yy, int mm = 1, int dd =1);

	//そのオブジェクトの年がうるう年かを返却する関数
	bool leap_year() const {
		return leap_year(y);
	}

	//その日の年を返却する関数
	int year() const {
		return y;
	}
	//その日の月を返却する関数
	int month() const {
		return m;
	}
	//その日の日にちを返却する関数
	int day() const {
		return d;
	}

	//入力された年にセットするセッター
	void set_year(int yy) {
		y = yy;
	}
	//入力された月にセットするセッター
	void set_month(int mm) {
		m = mm;
	}
	//入力された日にセットするセッター
	void set_day(int dd) {
		d = dd;
	}
	//入力された日付にセットするセッター
	void set(int yy, int mm, int dd);

	Date preceding_day() const;	//前の日を返却する関数
	Date following_day() const;	//次の日を返却する関数

	int day_of_year() const;		//その年の経過日数を返却する関数
	int day_of_week() const;		//その日の曜日を返却する関数

	operator long() const;		//long型への変換関数
	Date& operator++();			//前置加算演算子関数
	Date operator++(int);			//後置加算演算子関数

	Date& operator--();			//前置減算演算子関数
	Date operator--(int);			//後置減産演算子関数

	Date& operator+=(int dn);		//加算代入演算子関数
	Date& operator-=(int dn);		//減産代入演算子関数

	Date operator+(int dn) const;							//ｎ日後を返却する関数
	friend Date operator+(int dn, const Date& day);		//ｎ日後を返却する関数

	Date operator-(int dn) const;					//ｎ日前を返却する関数
	long operator-(const Date& day) const;		//二つの日付の差を返却する関数

	bool operator== (const Date& day) const;	//論理演算子関数
	bool operator!= (const Date& day) const;	//否定論理演算子関数

	bool operator>	(const Date& day) const;	//大なりの論理演算子関数
	bool operator>=	(const Date& day) const;	//大なりイコールの論理演算子関数
	bool operator<=	(const Date& day) const;	//小なりの論理演算子関数
	bool operator<	(const Date& day) const;	//小なりイコールの論理演算子関数

	std::string to_string() const;		//文字列表現にして返却する関数
	//抽出子の演算子関数の宣言
	friend std::istream& operator>>(std::istream& s, Date& x);

};

//挿入子演算子関数の宣言
std::ostream& operator<<(std::ostream& s, const Date& x);


//インクルードガードの終わり
#endif
