/* 演習04-04 ResigningMember部
 * クラスresigningMemberへのポインタからクラスMemberへのポインタへのアップキャスト
 * が行えるかどうかプログラムを作成して確認
 * 作成日：6月2日
 * 作成者：成田修之
 */

#ifndef ___Class_ResigningMenber
#define ___Class_ResigningMenber

#include<string>
#include<iostream>
#include"e_04_04_Member.h"

class ResigningMember : private Member {
public:
	//コンストラクタ
	ResigningMember(const std::string&name, int number,double w):Member(name,number,w){

	}

	//関数get_weightの再定義
	double get_weight() {
		std::cout << "退会した会員の体重の取得はできません。\n";
		return 0;
	}

	//using指令によって館員番号は取得できるようにメンバ関数noへのアクセス権を公開にする
	using Member::no;
};

//インクルードガードの終わり
#endif
