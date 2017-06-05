/* 演習05-01 VipMember_souse
 * 会員クラス軍に自己紹介をする仮想関数introduceを追加
 * 作成日：6月5日
 * 作成者：成田修之
 */

#include<string>
#include<iostream>
#include"e_05_01_VipMember.h"

using namespace std;

//コンストラクタ
VipMember::VipMember(const std::string& name, int no, double w, const string& prv)
:Member(name, no, w)
{
	//不正な値での初期化を防ぐため関数set_care_levelで初期化
	set_privilege(prv);
}

//会員情報を表示する関数のオーバーライド
void VipMember::print() const
{
	//要介護度の表示を追加して表示
	cout << "No." << no() << "：" << name() << " (" << get_weight() << "kg)"
			<< "特典内容：" << get_privilege() << "\n";
}

//自己紹介文を表示
void VipMember::introduce()const {
	cout << "私は番号" << no() << "の特別会員" << name() << "です。\n";
	cout << "体重は" << get_weight() << "です。\n";
	cout << "特典内容は" << get_privilege() << "です。\n\n";
}
