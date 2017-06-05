/* 演習05-01 SeniorMember_header
 * 会員クラス軍に自己紹介をする仮想関数introduceを追加
 * 作成日：6月5日
 * 作成者：成田修之
 */

#ifndef ___SeniorMember
#define ___SeniorMember

#include<string>
#include"e_05_01_Member.h"


//基底クラスMemberのpublic派生クラスSeniorMember
class SeniorMember:public Member {
	//要介護度を表すデータ
	int care_level;

public:
	//コンストラクタ
	SeniorMember(const std::string& name, int no, double w,int level = 0);

	//要介護度を返却する関数
	int get_care_level() const {
		return care_level;
	}

	//要介護度を引数でセットする関数
	void set_care_level(int level) {
		//引数が有効な範囲(1から5)ならその値をそれ以外の時0をセットする
		care_level = (level >= 1 && level <= 5) ? level : 0;
	}

	//会員情報を表示する関数
	void print() const;

	//自己紹介をする仮想関数
	void introduce();
};

#endif
