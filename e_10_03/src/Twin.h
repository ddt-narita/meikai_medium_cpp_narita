/* 演習10-03
 * 日付クラスDateや、Twin<>の2次配列を作成するプログラムの作成
 * 作成日：6月11日
 * 作成者：成田修之
 */


#ifndef ___Class_Twin
#define ___Class_Twin

#include<utility>
#include<algorithm>

template <class Type> class Twin {
	Type v1;	//1つ目のデータ
	Type v2;	//2つ目のデータ

public:
	//コンストラクタ
	Twin(const Type& f = Type(), const Type& s = Type()):v1(f),v2(s) {

	}

	//コピーコンストラクタ
	Twin(const Twin<Type>& t) :v1(t.first()), v2(t.second()) {

	}
	//1つ目のデータの値を返却する関数
	Type first() const {
		return v1;
	}
	//一つ目のデータへの参照を返却する関数
	Type& first() {
		return v1;
	}
	//2つ目のデータの値を返却する関数
	Type second() const {
		return v2;
	}
	//2つ目のデータへの参照を返却する関数
	Type& second() {
		return v2;
	}
	//引数に受け取った値で2つのデータをセットする関数
	void set(const Type& f, const Type& s) {
		v1 = f;
		v2 = s;
	}
	//小さいほうのデータを返却する関数
	Type min() const {
		return v1 < v2 ? v1: v2;
	}
	//昇順になっているかどうかを判定する関数
	bool ascending()const {
		return v1 < v2;
	}
	//昇順にソートする関数
	void sort() {
		//データが昇順になっていないとき
		if(!(v1 < v2)) {
			//関数swapをよびだして入れ替える
			std::swap(v1, v2);
		}
	}
};

//挿入子の多重定義
template <class Type> inline std::ostream& operator<<(std::ostream& os, const Twin<Type>& t)
{
	//一つ目のデータと2つ目のデータを文字列表現にして返却する
	return os << "[" << t.first() << "," << t.second() << "]";
}

//インクルードガードの終わり
#endif
