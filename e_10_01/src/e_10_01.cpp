/* 演習10-01
 * 日付クラスのベクトルを作成
 * 作成日：6月11日
 * 作成者：成田修之
 */

#include<vector>
#include<iostream>
#include"Date.h"

using namespace std;

int main()
{
	//Date型を要素とするベクトルオブジェクトの作成
	vector<Date> vectorDate;
	//入力に使うDate型オブジェクト
	Date x;

	//日付の個数を入力するための変数
	int nNumber;
	//いくつ入力するか入力するための変数
	cout << "日付をいくつ入力しますか：";
	//入力
	cin  >> nNumber;

	//入力された個数分繰り返す
	for(int i = 0; i < nNumber; i++) {
		//何個目の日付か表示
		cout << "日付 " << i  << "\n";
		//日付を入力
		cin >> x;
		//Date型を要素とするベクトルオブジェクトにプッシュする
		vectorDate.push_back(x);
	}

	//入力された日付を表示していくことを表示
	cout << "入力された日付を表示します。\n";
	//日付の個数分繰り返す
	for(int i = 0; i < nNumber; i++) {
		//各日付を表示
		cout << "x[" << i << "] = " << vectorDate[i] << "\n";
	}

	//main関数の返却値
	return 0;
}
