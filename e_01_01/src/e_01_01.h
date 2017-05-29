/* 演習01-01 ヘッダ部
 * クラスHumanのコンストラクタを問題ページのように書き換えて初期化が期待通りに行われることを確認
 * 作成日：5月26日
 * 作成者：成田修之
 */

//
#ifndef ___Class_Human
#define ___Class_Human

#include<string>

class Human {

	std::string full_name;		//氏名のデータ
	int height;					//身長のデータ
	int weight;					//体重のデータ

public:
	//コンストラクタの宣言
	Human(const std::string& full_name, int height, int weight);

	//名前を返却する関数
	std::string name() const;
	//身長を返却する関数
	int get_height() const;
	//体重を返却する関数
	int get_weight() const;
	//引数分体重に加算する関数
	void grow_fat(int dw);
	//引数分体重から引く関数
	void slim_off(int dw);
};

//インクルードガードの終わり
#endif
