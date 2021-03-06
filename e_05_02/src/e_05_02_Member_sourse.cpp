/* 演習05-02 Member_sourse
 * list5-18の関数senior_printの引数をポインタではなく参照に書き換えたプログラムの作成
 * 作成日：6月5日
 * 作成者：成田修之
 */

#include<string>
#include<iostream>
#include"e_05_02_Member.h"

using namespace std;

//コンストラクタの定義
Member::Member(const string& name, int no, double w)
						:full_name(name),number(no)
{
	//体重については不正な値とならないように関数set_weightで初期化
	set_weight(w);
}

//会員情報をまとめて表示する関数
void Member::print() const
{
	cout << "No." << number << " : " << full_name << " ( " << weight << "kg) \n";
}

//自己紹介文を表示
void Member::introduce() const {
	cout << "私は番号" << no() << "の一般会員" << name() << "です。\n";
	cout << "体重は" << get_weight() << "です。\n\n";
}



