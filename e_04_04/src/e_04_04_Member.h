/* 演習04-04 Member部
 * クラスresigningMemberへのポインタからクラスMemberへのポインタへのアップキャスト
 * が行えるかどうかプログラムを作成して確認
 * 作成日：6月2日
 * 作成者：成田修之
 */

#ifndef ___Member
#define ___Member

#include<string>

class Member {
	std::string full_name;	//名前のデータメンバ
	int	number;				//会員番号のデータメンバ
	double weight;			//体重のデータメンバ

public:
	//コンストラクタ
	Member(const std::string& name, int no, double w):full_name(name),number(no){
		//体重に関しては不正な初期化を防ぐように関数set_weightを利用して初期化
		set_weight(w);
	}

	//名前を返却する関数
	std::string name() const {
		return full_name;
	}

	//会員番号を返却する関数
	int no() const {
		return number;
	}

	//体重を返却する関数
	double get_weight()const {
		return weight;
	}

	//体重を受け取った値が0以下であれば0にそうでなければその値に設定する関数
	void set_weight(double w) {
		weight = w > 0 ? w : 0;
	}
};

//インクルードガードの終わり
#endif
