/* 演習03-13
 * list3-19を年月日の順で当てさせるように変更したプログラムの作成
 * 作成日：6月2日
 * 作成者：成田修之
 */

//インクルードガード
#ifndef ___Class_SimpleDate
#define ___Class_SimpleDate

//日付クラス
class SimpleDate {
	int y;		//年を表すデータ
	int m;		//月を表すデータ
	int d;		//日を表すデータ

public:
	//受け取った3つの値をデータに格納するコンストラクタ
	SimpleDate(int yy = 1, int mm = 1 ,int dd = 1):y(yy),m(mm),d(dd) {

	}

	//年のデータを返却するメンバ関数
	int year() const {
		return y;
	}
	//月のデータを返却するメンバ関数
	int month() const {
		return m;
	}
	//日にちのデータを返却するメンバ関数
	int days()const {
		return d;
	}

	//受け取った値から年のデータの値を引いた値を返却するメンバ関数
	int comp_y(int yy) const {
		return yy - y;
	}

	//受け取った値から月のデータの値を引いた値を返却するメンバ関数

	int comp_m(int mm) const {
		return mm - m;
	}

	//受け取った値から日のデータの値を引いた値を返却するメンバ関数
	int comp_d(int dd) const {
		return dd - d;
	}
};

//インクルードガードの終わり
#endif
