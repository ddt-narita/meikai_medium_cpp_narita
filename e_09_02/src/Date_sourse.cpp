/* 演習09-02
 * Date型のTwin<>とDate型Twin<>のTwin<>を作るプログラムの作成
 * 作成日：6月7日
 * 作成者：成田修之
 */

#include<ctime>
#include<sstream>
#include<iostream>
#include"Date.h"

using namespace std;

//閏年を考慮しない月ごとの最大の日を表す配列
int Date::dmax[] = {31,28,31,30,31,30,31,31,30,31,30,31};

//その年の日数を返却する関数
int Date::days_of_year(int year){
	return 365 + leap_year(year);
}

//その年のその月の最大日数を返却する関数
int Date::days_of_month(int year, int month) {
	return dmax[month - 1] + (month == 2&& leap_year(year));
}

//今日の日付で初期化されるデフォルトコンストラクタ
Date::Date()
{
	time_t current = time(NULL);
	struct tm* local = localtime(&current);

	y = local->tm_year + 1900;
	m = local->tm_mon +1;
	d = local->tm_mday;
}

//コンストラクタ
Date::Date(int yy , int mm, int dd) {
	set(yy,mm,dd);
}

//引数でそのオブジェクトを設定するセッター
void Date::set(int yy, int mm, int dd) {
	y = yy;
	m = mm;
	d = dd;
}

//前の日を返却する関数
Date Date::preceding_day() const {
	Date temp(*this);
	return --temp;
}

//次の日を返却する関数
Date Date::following_day() const {
	Date temp(*this);
	return ++temp;
}

//その日の経過日数を返却する関数
int Date::day_of_year() const {
	//その月の日で初期化
	int days = d;

	//1月から初めてその月の手前までその月の最大日を足す
	for(int i = 1; i < m; i++) {
		days += days_of_month(y,i);
	}
	return days;
}

//その日の曜日を求める関数
int Date::day_of_week() const {
	int yy = y;
	int mm = m;
	if(mm == 1 || mm == 2) {
		yy--;
		mm += 12;
	}
	return (yy + yy / 4 - yy / 100 + yy / 400 + (13 * mm + 8) / 5 + d) % 7;
}

//1970年からの経過一数を返却するlong型への変換関数
Date::operator long() const{
	return *this - Date(1970,1,1);
}

//前置加算演算子関数
Date& Date::operator++(){
	//その年と月の最大の日より小さいときそのまま一日増やす
	if(d < days_of_month(y,m)) {
		d++;
	//最大の日の時
	} else {
		//12月の時は一年増やして月を1月にリセット
		if(++m > 12) {
			y++;
			m = 1;
		}
		//日にちを一日にセット
		d = 1;
	}
	return *this;
}

//後置加算演算子関数
Date Date::operator++(int ) {
	Date temp(*this);
	++(*this);
	return temp;
}

//前置減算演算子関数
Date& Date::operator--() {
	//日にちが1より大きいときそのまま一日減らす
	if(d > 1)  {
		d--;
	//日にちが1日の時
	}else {
		//引く前が1月の時一年減らして月を12月にセット
		if(--m <= 1) {
			y--;
			m = 12;
		}
		//日にちをその月の最大の日にセット
		d = days_of_month(y,m);
	}
	return *this;
}

//後置減算演算子関数
Date Date::operator--(int) {
	Date temp(*this);
	--(*this);
	return temp;
}

//演算子+=の多重定義
Date& Date::operator+=(int dn) {
	//足す日数が0より小さいとき下の-=演算子に任せる
	if(dn < 0) {
		return *this -= -dn;
	}
	//引数で足す
	d += dn;

	//その月の最大の日より大きい限りその月の最大日で引くのを繰り返す
	while(d > days_of_month(y,m)) {
		d -= days_of_month(y,m);
		//増えた後の月が12より大きいとき1年増やして月を1月にセット
		if(++m > 12) {
			y++;
			m = 1;
		}
	}
	return *this;
}

//演算子-=の多重定義
Date& Date::operator-=(int dn) {
	//0より小さいときは符号を変えて上の＋＝演算子に任せる
	if(dn < 0) {
		return *this += -dn;
	}
	//引数で引く
	d -= dn;

	//引いた後の日数が1より小さい限り続ける
	while(d < 1) {
		//引いた後の月が1より小さいとき一年引いて月を12月にセット
		if(--m < 1) {
			y--;
			m = 12;
		}
		//その月の最大の日を足す
		d += days_of_month(y,m);
	}
	return *this;
}

//多重定義された演算子を使ってn日後を表示
Date Date::operator+(int dn) const {
	Date temp(*this);
	return temp += dn;
}

//多重定義された演算子を使ってその日からn日後を表示
Date operator+(int dn, const Date& day) {
	return day + dn;
}

//その日からｎ日前を多重定義された演算子を使って返却
Date Date::operator-(int dn) const {
	Date temp(*this);
	return temp -= dn;
}

//何日離れているか日数を返却する関数
long Date::operator-(const Date& day) const {
	long count;									//離れている日数
	long count1 = this->day_of_year();			//左オペランドの経過日数
	long count2 = day.day_of_year();			//右オペランドの経過日数

	//同じ年のときは経過日数を引いたもの
	if(y == day.y) {
		count = count1 - count2;
	//左オペランドのほうが新しいときその年の日数から二つの年の経過日数を引く
	} else if (y > day.y) {
		count = days_of_year(day.y) - count2 - count1;
		//古いほうの次の年から初めて新しいほうの年までその年の日数分足していく
		for(int yy = day.y + 1; yy < y; yy++) {
			count += days_of_year(yy);
		}
	//右オペランドのほうが新しいとき、経過日数の差をその年の日数を引く
	}else {
			count = -(days_of_year(y) - count1 + count2);
			//古いほうの次の年から初めて新しい年まで続けてその年の日数分引いていく
			for(int yy = y + 1; yy < day.y; yy++) {
				count -= days_of_year(yy);
			}
	}
	return count;
}

//論理演算子の多重定義
bool Date::operator==(const Date& day) const {
	//各データが等しいか評価
	return  y == day.y && m == day.m && d == day.d;
}

//論理演算子の多重定義
bool Date::operator!=(const Date& day) const {
	return !(*this == day);
}

//大なりの演算子関数
bool Date::operator>(const Date& day) const {
	//年で評価して返却
	if(y > day.y) {
		return true;
	}
	if(y < day.y) {
		return false;
	}
	//月で評価して返却
	if(m > day.m) {
		return true;
	}
	if(m < day.m) {
		return false;
	}
	//年でも月でもダメな時は日にちで評価して返却
	return d > day.d;
}

//小なりで真となるものは偽でまたはその逆で返却
bool Date::operator>=(const Date& day) const {
	return !(*this < day);
}

//小なりの演算子関数
bool Date::operator<(const Date& day) const {
	//年で決まるときはそれで返却
	if(y < day.y) {
		return true;
	}
	if(y > day.y) {
		return false;
	}
	//月で決まるときはそれで返却
	if(m < day.m) {
		return true;
	}
	if(m > day.m) {
		return false;
	}
	//年でも月でも決まらなければ日にちで評価して返却
	return d < day.d;
}

//小なりイコールの演算子関数
bool Date::operator<=(const Date& day) const {
	return !(*this > day);
}

//クラスDateのオブジェクトを文字列表現にする関数
string Date::to_string() const {
	ostringstream s;
	s << y << "年" << m << "月" << d << "日";
	return s.str();
}

//挿入子の多重定義
ostream& operator<<(ostream& s, const Date& x) {
	return s << x.to_string();
}

//抽出子の多重定義
istream& operator>> (istream& s, Date& x) {
	int yy, mm, dd;
	//年月日に入力する
	do {
		cout << "年：";
		s 	 >> yy;
	}while(yy < 1900 || 4000 < yy);

	do {
		cout << "月：";
		s 	 >> mm;
	}while(mm < 1 || 12 < mm);

	do{
		cout << "日：";
		s 	 >> dd;
	}while(dd > x.days_of_month(yy,mm));
	//入力されたもので作ったもので右オペランドのオブジェクトに代入して入力ストリームを返却
	x = Date(yy, mm, dd);
	return s;
}



