/* 演習09-07
 * 9章1節のクラステンプレートTwin<>をインクルードモデルで実現したプログラムの作成
 * 作成日：6月8日
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
	Twin(const Twin<Type>& t);

	//1つ目のデータの値を返却する関数
	Type first() const;

	//一つ目のデータへの参照を返却する関数
	Type& first();

	//2つ目のデータの値を返却する関数
	Type second() const;

	//2つ目のデータへの参照を返却する関数
	Type& second();

	//引数に受け取った値で2つのデータをセットする関数
	void set(const Type& f, const Type& s);

	//小さいほうのデータを返却する関数
	Type min() const;

	//昇順になっているかどうかを判定する関数
	bool ascending()const;

	//昇順にソートする関数
	void sort();

};

//挿入子の多重定義
template <class Type> inline std::ostream& operator<<(std::ostream& os, const Twin<Type>& t);

#include "Twin_Inplementation.h"


//インクルードガードの終わり
#endif
