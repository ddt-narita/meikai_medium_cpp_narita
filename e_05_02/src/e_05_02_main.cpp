/* 演習05-02 VipMember_header
 * list5-18の関数senior_printの引数をポインタではなく参照に書き換えたプログラムの作成
 * 作成日：6月5日
 * 作成者：成田修之
 */

#include<iostream>
#include<typeinfo>
#include"e_05_02_Member.h"
#include"e_05_02_VipMember.h"
#include"e_05_02_SeniorMember.h"

using namespace std;

//SeniorMember型の時のみ情報を表示する関数
void senior_print(Member& p)
{
	//例外処理
	try{
		//Member型への参照pをSeniorMember型への参照へ動的にダウンキャストした参照を
		//Member型へアップキャストしてMember型への参照dに代入
		Member& d = dynamic_cast<SeniorMember&>(p);
		//動的キャストが成功したときはそのオブジェクトの関数printを呼び出して情報を表示
		d.print();
	//動的キャストが失敗したとき
	} catch (bad_cast&) {

	}
}

int main()
{
	//一般会員のオブジェクトを作成
	Member kaneko("金子健太",15,75.2);
	//特別会員のオブジェクトを作成
	VipMember mineya("峰屋龍次", 17, 89.2, "会費全額免除");
	//高齢者会員のオブジェクトを作成
	SeniorMember susaki("洲崎健一",43,63.7,3);

	senior_print(kaneko);	//関数senior_printを呼び出してSeniorMember型の時のみ情報を表示
	senior_print(mineya);	//関数senior_printを呼び出してSeniorMember型の時のみ情報を表示
	senior_print(susaki);	//関数senior_printを呼び出してSeniorMember型の時のみ情報を表示

}
