/* 演習01-02
 * Dateクラスに不正な日付での初期化や入力を補正するように書き換え
 * 作成日：5月28日
 * 作成者：成田修之
 */

#include<iostream>
#include"e_01_02.h"

using namespace std;

//その日付の情報を表示する関数
void dispray(const Date& day) {
	//曜日の文字の配列
	string dw[] = {"日","月","火","水","木","金","土"};

	//各情報を表示
	cout << "・日付" << day << "に関する情報\n";
	cout << "曜日は" << dw[day.day_of_week()] << "曜日\n";
	cout << "年内経過日数は" << day.day_of_year() << "日\n";
	cout << "1970年1月1日の" << long(day) << "日後\n";
	cout << "その年は閏年で" << (day.leap_year() ? "ある": "ない") << "\n";
}

void change(Date& day) {
	//終了条件で抜け出すまで続ける
	while(true) {
		//何をするか入力をうながす
		cout << "[1]年変更[2]月変更[3]日変更[4]年月日変更[5]n日進める[6]n日戻す[0]戻る：";
		int selected;
		cin >> selected;

		//終了条件を満たしたとき終わる
		if(selected == 0) {
			return;
		}
		//年月日にち、更新する日数の入力に使う変数
		int y,m,d,n;
		//1か4が入力されたとき年を入力
		if(selected == 1 || selected == 4) {
			cout << "年：";
			cin  >> y;
		}
		//2か4が入力されたとき月を入力
		if(selected == 2 || selected == 4) {
			cout << "月：";
			cin  >> m;
		}
		//3か4が入力されたとき日を入力
		if(selected == 3 || selected == 4) {
			cout << "日：";
			cin  >> d;
		}
		//5か6が入力されたとき日にちを入力
		if(selected == 5 || selected == 6) {
			cout << "日数：";
			cin  >> n;
		}
		//入力された値によってそれぞれ更新
		switch(selected) {
		case 1: day.set_year(y);	break;
		case 2: day.set_month(m);	break;
		case 3: day.set_day(d);		break;
		case 4: day.set(y,m,d);		break;
		case 5: day += n;			break;
		case 6: day -= n;			break;
		}
		cout << day << "に変更されました。\n";
	}
}

//インクリメントデクリメントに関するもの
void inc_dec(Date& day)
{
	//終了条件で抜け出すまで続ける
	while(true) {
		cout << "[1]++day [2]day++ [3]--day [4]day-- [0]戻る：";
		int selected;
		cin >> selected;

		//終了条件を満たしたとき終わる
		if(selected == 0) {
			return;
		}
		//入力された各動作を行って表示
		switch(selected) {
		case 1: cout << "++day = " << ++day << "\n"; break;
		case 2: cout << "day++ = " << day++ << "\n"; break;
		case 3: cout << "--day = " << --day << "\n"; break;
		case 4: cout << "day-- = " << day-- << "\n"; break;
		}
		cout << "day = " << day << "\n";
	}
}

//前後の日にちに関数る関数の動作
void before_after(Date& day)
{
	//終了条件で抜け出すまで繰り返す
	while(true) {
		cout << "[1]翌日[2]前日[3]n日後(day+n)[4]n日後(n+day)[5]n日前[0]戻る";
		int selected;
		cin >> selected;

		//終了条件の時while分を抜ける
		if(selected == 0) {
			return;
		}
		int n;
		//n日前後を求めるときは日数の入力をする
		if(selected >= 3&& selected <= 5) {
			cout << "日数：";
			cin >> n;
		}
		cout << "それは";
		//各日付を関数をよびだして表示
		switch(selected) {
		case 1: cout << day.following_day(); break;
		case 2: cout << day.preceding_day(); break;
		case 3: cout << day + n; break;
		case 4: cout << n + day; break;
		case 5: cout << day - n; break;
		}
		cout << "です。\n";
	}
}

//比較に関する関数の表示
void compare(const Date& day) {
	Date day2;
	cout << "対象の日付day2を入力せよ。\n";
	cin >> day2;
	//bool型にしてtrue,falseにしてそれぞれの結果を表示
	cout << boolalpha;
	cout << "day = " << day << "\n";
	cout << "day2 = " << day2 << "\n";
	cout << "day - day2 = " << (day - day2) << "\n";
	cout << "day2 - day = " << (day2 - day) << "\n";
	cout << "day == day2 = " << (day == day2) << "\n";
	cout << "day != day2 = " << (day != day2) << "\n";
	cout << "day >  day2 = " << (day >  day2) << "\n";
	cout << "day >= day2 = " << (day >= day2) << "\n";
	cout << "day <  day2 = " << (day < day2) << "\n";
	cout << "day <= day2 = " << (day <= day2) << "\n";
}


int main()
{
	//入力するためのオブジェクト
	Date day;
	//入力する
	cout << "日付を入力してください：";
	cin  >> day;

	//終了条件で抜け出すまで続ける
	while(true) {
		//何が何を行うか表示
		cout << "[1]情報表示[2]日付の変更[3]増減分演算子[4]前後の日付[5]比較[0]終了：";
		//入力させる
		int selected;
		cin >> selected;

		//while分を抜けて0なら終了
		if(selected == 0) {
			break;
		}
		//入力された値によって関数を呼び出す
		switch(selected) {
		case 1: dispray(day);		break;
		case 2: change(day);		break;
		case 3: inc_dec(day);		break;
		case 4: before_after(day);	break;
		case 5: compare(day);		break;
		}
	}
}
