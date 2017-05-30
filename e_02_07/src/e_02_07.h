/* 演習02-07
 * ビットベクトルによる集合クラスに各メンバ関数を追加
 * 作成日：5月30日
 * 作成者：成田修之
 */

//
#ifndef ___Class_BitSet
#define ___Class_BitSet

#include<limits>
#include<string>
#include<iostream>

class BitSet {
	//long型のビット数
	static const int LONG_BIT = std::numeric_limits<unsigned long>::digits;
	//ビットベクトルを格納するデータ
	unsigned long bits;
	//vが妥当な値かどうかを判定
	static bool is_valid(int v) {
		return v >= 0 && v < LONG_BIT;
	}
	//{e}だけで構成されるビットベクトルを生成
	static unsigned long set_of(int e) {
		return 1UL << e;
	}

public:
	//要素の最大値
	static int max_element() {
		return LONG_BIT - 1;
	}
	//要素の最小値
	static int min_element() {
		return 0;
	}
	//デフォルトコンストラクタ
	BitSet():bits(0UL) {
	}
	//コンストラクタ
	BitSet(const int* e, int n):bits(0UL) {
		//要素数分繰り返してその値を追加
		for(int i = 0; i < n; i++) {
			add(e[i]);
		}
	}
	//集合にeが含まれるか判定
	bool contains(int e) const {
		return is_valid(e) && (bits & set_of(e));
	}
	//集合に要素eを追加
	void add(int e) {
		//eが有効な場合は追加する
		if(is_valid(e)) {
			bits |= set_of(e);
		}
	}
	//集合から要素eを削除
	void remove (int e) {
		//有効な値の時削除
		if(is_valid(e)) {
			bits &= ~set_of(e);
		}
	}
	//集合が空集合か判定
	bool empty() const {
		return !bits;
	}

	//集合の要素数を求める
	int size() const {
		//要素数を数える変数
		int count = 0;
		//集合のビットベクトルで初期化
		unsigned long x = bits;
		//xが0になるまで繰り返す
		while(x) {
			//xから1引いた集合との積集合にして最小の要素を除いていく
			x &= x - 1;
			//除いた数をカウント
			count++;
		}
		//カウントした要素数を返却する
		return count;
	}
	//積集合に更新
	BitSet& operator&=(const BitSet& r) {
		bits &= r.bits;
		return *this;
	}
	//和集合に更新
	BitSet& operator|=(const BitSet& r) {
		bits |= r.bits;
		return *this;
	}
	//差集合に更新
	BitSet& operator^=(const BitSet& r) {
		bits ^= r.bits;
		return *this;
	}
	//一致するかを判定
	bool operator==(const BitSet& r) {
		return bits == r.bits;
	}
	//等しくないかを判定
	bool operator!=(const BitSet& r) {
		return bits != r.bits;
	}

	int min() const;			//集合の最小の値を返却する関数
	int max() const;			//集合の最大の値を返却する関数
	void clear();				//全要素を削除して空集合にする関数
	void swap(BitSet& r);		//集合を集合rと交換する関数
	//集合s1とs2を交換する非メンバ関数
	friend void swap(BitSet& s1, BitSet& s2);
	//集合s1とs2の対象差を求めて返却する関数
	friend BitSet symmetric_defference(const BitSet& s1, const BitSet& s2);
	//集合s1とs2の積集合を求めて返却する関数
	friend BitSet operator&(const BitSet& s1, const BitSet& s2);
	//集合s1とs2の和集合を求めて返却する関数
	friend BitSet operator|(const BitSet& s1, const BitSet& s2);
	//集合s1とs2の差集合を求めて返却する関数
	friend BitSet operator^(const BitSet& s1, const BitSet& s2);
	bool is_subset_of(const BitSet& s);				//集合sが部分集合であるかを判定
	bool is_proper_subset_of(const BitSet& s);		//集合sが真部分集合であるか判定

	std::string to_string() const;		//文字列表現を返却
	std::string bit_string() const;		//ビットベクトルの文字列表現

};



//挿入子の演算子関数の宣言
std::ostream& operator<<(std::ostream& os, const BitSet& x);

#endif
