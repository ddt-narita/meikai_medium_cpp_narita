/* 演習02-07
 * ビットベクトルによる集合クラスに各メンバ関数を追加
 * 作成日：5月30日
 * 作成者：成田修之
 */

#include<string>
#include<sstream>
#include<iostream>
#include"e_02_07.h"

using namespace std;

//文字列表現を返却する関数
string BitSet::to_string() const
{
	ostringstream s;		//出力ストリームs
	int set[LONG_BIT];		//最大の要素数分確保した配列
	int count = 0;			//要素数を数える変数

	//0から最後まで繰り返す
	for(int i = 0; i < LONG_BIT; i++) {
		//要素があるとき
		if(bits & set_of(i)) {
			//確保した配列の0番目から順にその要素を格納
			set[count++] = i;
		}
	}
	s << "{";

	//要素があるなら
	if(count) {
		//最後の要素の手前まで繰り返してその要素と間には「,」を表示
		for(int i = 0; i < count - 1; i++) {
			s << set[i] << ",";
		}
		//最後の要素はそのままで表示
		s << set[count - 1];
	}
	s << "}";
	//文字列表現にした出力ストリームを返却
	return s.str();
}

//ビットベクトルの文字列表現
string BitSet::bit_string() const
{
	//ナル文字を含めた個数分の配列を用意
	char bp[LONG_BIT + 1];

	//最大から0まで繰り返す
	for(int i = LONG_BIT - 1; i >= 0; i--) {
		//配列の0から順にその位の文字0か1を格納
		bp[LONG_BIT - i - 1] = (set_of(i) & bits) ? '1' : '0';
	}
	//最後の要素をナル文字とする
	bp[LONG_BIT] = '\0';

	//文字列を返却
	return string(bp);
}


//挿入子の多重定義
ostream& operator<<(ostream& os, const BitSet& x) {
	return os << x.to_string();
}

//最小の要素
int BitSet::min() const {
	//返却する最小の値を入れる関数
	int min;
	//空集合の時は-1を代入
	if(empty()) {
		min = -1;
	//空集合ではない時
	} else {
		//0から最後まで繰り返す
		for(int i = 0; i < LONG_BIT; i++) {
			//要素があるときその要素を代入してループを抜ける
			if(bits & set_of(i)){
				min = i;
				break;
			}
		}
	}
	//最小の値を返却
	return min;
}

//最大の要素
int BitSet::max() const {
	//返却する最大の要素を格納する変数
	int max;
	//空集合の時-1を代入
	if(empty()) {
		max = -1;
	//空集合ではない時
	} else {
		//最大から0まで繰り返す
		for(int i = LONG_BIT - 1; i >= 0; i--) {
			//要素があるときその要素を代入してループを抜ける
			if(bits & set_of(i)){
				max = i;
				break;
			}
		}
	}
	//代入された最大の要素を返却
	return max;
}

//全要素削除
void BitSet::clear() {
	//全要素に関数removeを適用
	for(int i = 0; i < LONG_BIT; i++) {
		remove(i);
	}
}

//全要素交換
void BitSet::swap(BitSet& r) {
	//避難させ
	BitSet trade = r;
	//代入して
	r = *this;
	//避難していたものを代入
	*this = trade;
}

//全要素交換（非メンバ）
void swap(BitSet& s1, BitSet& s2) {
	//避難させ
	BitSet trade = s1;
	//代入し
	s1 = s2;
	//避難させていたものを代入
	s2 = trade;
}

//対象差を求める
BitSet symmetric_defference(const BitSet& s1, const BitSet& s2) {
	//返却する対象差集合
	BitSet deff;
	//排他的論理和の演算子を適用して対象差を求める
	deff.bits= s1.bits ^ s2.bits;
	//対象差集合を返却
	return deff;
}

//集合s1とs2の積集合を求めて返却する関数
BitSet operator&(const BitSet& s1, const BitSet& s2) {
	//返却する積集合
	BitSet Power;
	//論理積演算子で求めて代入
	Power.bits= s1.bits & s2.bits;
	//求めた積集合を返却
	return Power;
}

//集合s1とs2の和集合を求めて返却する関数
BitSet operator|(const BitSet& s1, const BitSet& s2) {
	BitSet Plus;
	Plus.bits = s1.bits | s2.bits;
	return Plus;
}

//集合s1とs2の差集合を求めて返却する関数
BitSet operator^(const BitSet& s1, const BitSet& s2) {
	BitSet Deff;
	Deff.bits = s1.bits ^ s2.bits;
	return Deff;
}

//集合sの部分集合であるかを判定
bool BitSet::is_subset_of(const BitSet& s) {
	//判定を返却する変数何もなければ真となるように1で初期化
	int nReturn = 1;
	//0から全要素について調べる
	for(int i = 0; i < LONG_BIT; i++) {
		//ある要素が集合sの要素じゃない時0を代入してループ抜ける
		if(bits & set_of(i)) {
			if(!(s.bits & set_of(i))) {
				nReturn = 0;
				break;
			}
		}
	}
	return nReturn;
}


//集合sが真部分集合であるか判定
bool BitSet::is_proper_subset_of(const BitSet& s) {
	//返却するための変数何もなければ真となるように1で初期化
	int nReturn = 1;
	//一致するときは真部分集合ではないので0代入
	if(bits == s.bits) {
		nReturn = 0;
	//一致はしない時
	} else {
		//全要素分繰り返す
		for(int i = 0; i < LONG_BIT; i++) {
			//要素があるとき集合sにその要素がなければ0代入してループ抜ける
			if(bits & set_of(i)) {
				if(!(s.bits & set_of(i))) {
					nReturn = 0;
				}
			}
		}
	}
	return nReturn;
}

