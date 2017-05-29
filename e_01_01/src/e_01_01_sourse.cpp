/* 演習01-01 ソース部
 * クラスHumanのコンストラクタを問題ページのように書き換えて初期化が期待通りに行われることを確認
 * 作成日：5月26日
 * 作成者：成田修之
 */

#include<iostream>
#include<string>
#include"e_01_01.h"

using namespace std;

//コンストラクタ
Human::Human(const string& full_name, int height, int weight):full_name(full_name), height(height),weight(weight)
{
}

//氏名を返却する関数
string Human::name() const
{
	return full_name;
}

//身長を返却する関数
int Human::get_height() const
{
	return height;
}

//体重を返却する関数
int Human::get_weight() const
{
	return weight;
}

//引数分体重を増やす
void Human::grow_fat(int dw)
{
	weight += dw;
}

//引数分体重を減らす
void Human::slim_off(int dw)
{
	weight -= dw;
}
