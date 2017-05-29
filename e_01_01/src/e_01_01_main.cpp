/* 演習01-01 ソース部
 * クラスHumanのコンストラクタを問題ページのように書き換えて初期化が期待通りに行われることを確認
 * 作成日：5月26日
 * 作成者：成田修之
 */

#include<iostream>
#include<string>
#include"e_01_01.h"

using namespace std;


int main()
{
	//コンストラクタで初期化が行えていることを確認
	Human nakano("中野太郎",173,65);			//クラスHumanのオブジェクトnakano
	const Human morita("森田孝司",168,71);		//クラスHumanのオブジェクトmorita

	//nakanoの体重を3キログラム減らす
	nakano.slim_off(3);

	//中野さんの氏名、身長、体重の情報を表示
	cout << "nakano = " << nakano.name() << "  " << nakano.get_height() << "cm  "
		 << nakano.get_weight() << "kg\n";

	//森田さんの氏名、身長、体重の情報を表示
	cout << "morita = " << morita.name() << "  " << morita.get_height() << "cm  "
		 <<morita.get_weight() << "kg\n";

	//main関数の返却値
	return 0;
}
