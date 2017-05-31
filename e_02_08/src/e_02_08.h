/* 演習02-08 ヘッダ部
 * 要素数をビット数に制限されず、加減上限を任意に設定できるビットベクトルによる集合クラスの作成
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
	int min;	//下限
	int max;	//上限

	//上限から下限まで配列がいくつ必要かの要素数
	int bitsNumber;

	//集合を表すポインタ
	unsigned long* bits;

	//{e}だけで構成されるビットベクトルを生成
	static unsigned long set_of(int e) {
		return 1UL << e;
	}

public:

	//
	int max_element() {
		return min;
	}

	//
	int min_element() {
		return max;
	}

	//
	BitSet():min (0),max(LONG_BIT), bitsNumber(1) {
		bits = new unsigned long[bitsNumber];
	}

	//
	BitSet(int min, int max,const int* e, int n):min(min),max(max) {
		int f = n ;			//要素数で初期化した変数
		int number = 0;			//要素数がいくつ必要になるか数えるための変数
		//要素数から最小値引いた値がビット数より大きい限りビット数で引き続けカウントする
		for(; f >= LONG_BIT; number++) {
			f -= LONG_BIT;
		}
		//カウントした数＋1個の要素数
		bitsNumber = number + 1;
		//データとなるビットベクトルの配列
		bits = new unsigned long[bitsNumber];
		//全要素を0で初期化
		for(int i = 0; i < bitsNumber; i++) {
			bits[i] = 0;
		}

		//そのあと引数の配列の要素に当たる各ビットに1を代入
		for(int i = 0; i < n; i++) {
			add(e[i]);
		}
	}

	~BitSet(){
		delete[]bits;
	}

	//有効な値か確かめる関数
	bool is_valid(int v) const {
		return v >= min && v <= max;
	}

	//その要素が含まれるか確認する関数
	bool contains(int e) const {
		//何もなければ0を返却
		int nReturn = 0;
		//各要素で調べる
		for(int i = 0; i < bitsNumber; i++) {
			//その数値が有効かつ要素が含まれていれば1を代入してループ抜ける
			if(is_valid(e) &&  (bits[i] & set_of(e))) {
				nReturn = 1;
				break;
			}
		}
		return nReturn;
	}

	//集合に要素を追加する関数
	void add(int e) {
		//有効な数値の時
		if(is_valid(e)) {
			e -=min;		//最小値で引きビットに直しやすくする
			int j;			//どの要素に対して行うかカウントする変数
			//ビット数より大きいとき引き続けカウントする
			for(j = 0; e >= LONG_BIT; j++) {
				e -= 32;
			}
			//カウントした要素に対して32未満に直したものを論理和でセットする
			bits[j] |= set_of(e);
		}
	}

	//集合の要素を除去する関数
	void remove(int e) {
		//有効な数値の時
		if(is_valid(e)) {
			e -= min;	//ビットに直しやすいように最小値で引く
			int i;		//カウントする変数
			//ビット数より大きいとき限り繰り返し引きカウントする
			for(i = 0; e >= LONG_BIT; i++) {
				e -= 32;
			}
			//カウントした要素に対してビット数未満に直したものの補数との論理積で消去する
			bits[i] &= ~set_of(e);
		}
	}

	//空集合かどうか判定する関数
	bool empty() const {
		//1で初期化
		int nReturn = 1;
		//要素分繰り返す
		for(int i = 0; i < bitsNumber; i++) {
			//その要素が0でない時空集合ではないので0を代入してループを抜ける
			if(bits[i]) {
				nReturn = 0;
				break;
			}
		}
		return nReturn;
	}

	//要素数を求める関数
	int size() {
		int count = 0;
		//ビットベクトルの要素数分繰り返す
		for(int i = 0; i < bitsNumber; i++) {
			//各要素で初期化
			unsigned long x = bits[i];
			//その数より1小さい数との論理積で0になるまで繰り返し、要素数をカウントする
			while(x) {
				x &= x - 1;
				count++;
			}
		}
		return count;
	}

	//論理積に更新する関数
	BitSet& operator&=(const BitSet& r) {
		//各要素に対して論理積を当てはめる
		for(int i = 0; i < bitsNumber && i < r.bitsNumber; i++) {
			bits[i] &= r.bits[i];
			bits[i] <<= (r.min - min - 1);
		}
		//もしこのオブジェクトの要素数のほうが多いときそれ以降の要素を0で代入
		if(bitsNumber > r.bitsNumber) {
			for(int i = r.bitsNumber; i < bitsNumber; i++) {
				bits[i] = 0;
			}
		}
		return *this;
	}

	//論理和に更新する関数
	BitSet& operator|=(const BitSet& r) {
		//各要素に対して論理和当てはめる
		for(int i = 0; i < bitsNumber && i < r.bitsNumber; i++) {
			bits[i] |= r.bits[i];
		}

		return *this;
	}

	//一致するかを判定する関数
	bool operator==(const BitSet& r) const {
		int nReturn = 1;
		//要素数分繰り返す
		for(int i = 0; i < bitsNumber; i++) {
			//要素が違うとき0を代入してループをぬける
			if(bits[i] != r.bits[i]) {
				nReturn = 0;
				break;
			}
		}
		return nReturn;
	}

	//一致しないことを判定する関数
	bool operator!=(const BitSet& r) const {
		return !(*this == r);
	}

	//文字列表現に直す関数
	std::string to_string() const;

	//ビットベクトルの文字列表現に直す関数
	std::string bit_string() const;

};

//挿入子関数の宣言
std::ostream& operator<<(std::ostream& os, const BitSet& x);

#endif
