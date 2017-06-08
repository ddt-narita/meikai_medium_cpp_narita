/* 演習09-07
 * 9章1節のクラステンプレートTwin<>をインクルードモデルで実現したプログラムの作成
 * 作成日：6月8日
 * 作成者：成田修之
 */

#ifndef ___Class_Twin_Inplementation
#define ___Class_Twin_Inplementation

#include<utility>
#include<algorithm>



//コピーコンストラクタ
template <class Type>	Twin<Type>::Twin(const Twin<Type>& t) :v1(t.first()), v2(t.second()) {

}

//1つ目のデータの値を返却する関数
template <class Type>	Type Twin<Type>::first() const {
	return v1;
}

//一つ目のデータへの参照を返却する関数
template <class Type>Type& Twin<Type>::first() {
	return v1;
}

//2つ目のデータの値を返却する関数
template <class Type>Type Twin<Type>::second() const {
	return v2;
}

//2つ目のデータへの参照を返却する関数
template <class Type>Type& Twin<Type>::second() {
	return v2;
}

//引数に受け取った値で2つのデータをセットする関数
template <class Type>void Twin<Type>::set(const Type& f, const Type& s) {
	v1 = f;
	v2 = s;
}

//小さいほうのデータを返却する関数
template <class Type>Type Twin<Type>::min() const {
	return v1 < v2 ? v1: v2;
}

//昇順になっているかどうかを判定する関数
template <class Type>bool Twin<Type>::ascending()const {
	return v1 < v2;
}

//昇順にソートする関数
template <class Type> void Twin<Type>::sort() {
//データが昇順になっていないとき
	if(!(v1 < v2)) {
		//関数swapをよびだして入れ替える
		std::swap(v1, v2);
	}
}

//挿入子の多重定義
template <class Type> inline std::ostream& operator<<(std::ostream& os, const Twin<Type>& t)
{
//一つ目のデータと2つ目のデータを文字列表現にして返却する
	return os << "[" << t.first() << "," << t.second() << "]";
}
//インクルードガードの終わり
#endif
