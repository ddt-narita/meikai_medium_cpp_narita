/* 演習05-01 VipMember_header
 * 会員クラス軍に自己紹介をする仮想関数introduceを追加
 * 作成日：6月5日
 * 作成者：成田修之
 */

#ifndef ___VipMember
#define ___VipMember

#include<string>
#include"e_05_01_Member.h"

//基底クラスMemberのpublic派生の派生クラスVipMember
class VipMember:public Member {
	//特典情報を表す文字列データ
	std::string privilege;

public:
	//コンストラクタ
	VipMember(const std::string& name, int no, double w, const std::string& prv);

	//特典情報を返却する関数
	std::string get_privilege() const {
		return privilege;
	}

	//特典情報をセットする関数
	void set_privilege(const std::string prv) {
		//特典情報に引数がNULL文字なら未登録をNULL文字以外ならその文字を代入する
		privilege = (prv != "") ? prv : "未登録";
	}

	//会員情報を表示する関数
	void print() const;

	//自己紹介をする仮想関数
	void introduce() const;

};

#endif
