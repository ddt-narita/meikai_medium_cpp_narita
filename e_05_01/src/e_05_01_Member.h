/* 演習05-01 Member_header
 * 会員クラス軍に自己紹介をする仮想関数introduceを追加
 * 作成日：6月5日
 * 作成者：成田修之
 */

#ifndef ___Member
#define ___Member

#include<string>

class Member {
	std::string full_name;	//名前のデータ
	int number;				//会員番号のデータ
	double weight;			//体重のデータ

public:
	//コンストラクタ
	Member(const std::string& name, int no, double w);

	//名前のデータを返却する関数
	std::string name()const {
		return full_name;
	}

	//基底クラスが多相性となるので仮想デストラクタを設定
	virtual ~Member() {

	}

	//会員番号のデータを返却する関数
	int no()const {
		return number;
	}

	//体重のデータを返却する関数
	double get_weight() const {
		return weight;
	}

	//引数で体重をセットする関数
	void set_weight(double w) {
		//引数が有効な範囲(0より大きい値)でなければ0をセットする
		weight = (w > 0) ? w : 0;
	}

	//会員情報を表示する仮想関数
	virtual void print() const;

	//自己紹介をする仮想関数
	virtual void introduce() const;

};

#endif
