/* 演習05-02 SeniorMember_sourse
 * list5-18の関数senior_printの引数をポインタではなく参照に書き換えたプログラムの作成
 * 作成日：6月5日
 * 作成者：成田修之
 */


#include<string>
#include<iostream>
#include"e_05_02_SeniorMember.h"

using namespace std;

//コンストラクタ
SeniorMember::SeniorMember(const string& name, int no, double w, int level)
							:Member(name, no, w)
{
	//不正な値での初期化を防ぐために関数set_care_levelでの初期化
	set_care_level(level);
}

//会員情報を表示する関数のオーバーライド
void SeniorMember::print() const
{
	//要介護度を追加して表示
	cout << "No." << no() << " : " <<  name() << " (" << get_weight() << "kg)"
			<< "要介護度：" << care_level << "\n";
}

//自己紹介文を表示
void SeniorMember::introduce() {
	cout << "私は番号" << no() << "の高齢者会員" << name() << "です。\n";
	cout << "体重は" << get_weight() << "です。\n";
	cout << "要介護度は" << get_care_level() << "です。\n\n";
}
