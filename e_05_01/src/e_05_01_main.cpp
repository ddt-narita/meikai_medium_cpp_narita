/* 演習05-01 main
 * 会員クラス軍に自己紹介をする仮想関数introduceを追加
 * 作成日：6月5日
 * 作成者：成田修之
 */

#include<iostream>
#include"e_05_01_Member.h"
#include"e_05_01_VipMember.h"
#include"e_05_01_SeniorMember.h"

using namespace std;

int main()
{
	//一般会員のオブジェクトを作成
	Member kaneko("金子健太",15,75.2);
	//特別会員のオブジェクトを作成
	VipMember mineya("峰屋龍次", 17, 89.2, "会費全額免除");
	//高齢者会員のオブジェクトを作成
	SeniorMember susaki("洲崎健一",43,63.7,3);


	kaneko.introduce();		//一般会員の自己紹介
	mineya.introduce();		//特別会員の自己紹介
	susaki.introduce();		//高齢者会員の自己紹介

}
