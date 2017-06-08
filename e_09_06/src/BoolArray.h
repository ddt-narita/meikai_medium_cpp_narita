/* 演習09-06
 * Array<bool>型の配列に対して対話的に処理を行うプログラムを作成する
 * 作成日：6月8日
 * 作成者：成田修之
 */

#include<iostream>
#include"Array.h"


#ifndef ___Class_Template_Array_Bool
#define ___Class_Template_Array_Bool

#include<limits>
#include"Array.h"

//
template<> class Array<bool> {

	//型を別の名前で定義
	typedef unsigned char BYTE;
	//CHARの長さを静的なメンバとして定義
	static const int  CHAR_BITS = std::numeric_limits<unsigned char>::digits;

	int nelem;		//要素数
	int velem;		//必要なBYTE型配列の要素数
	BYTE* vec;		//BITE型先頭要素へのポインタ

	//sz個の要素の格納に必要なBYTE型配列の個数
	static int size_of(int sz) {
		return (sz + CHAR_BITS - 1) / CHAR_BITS;
	}

public:
	//ビットベクトル中の1ビットへの参照を表すためのクラス
	class BitOfByteRef {
		BYTE& vec;		//参照先のポインタ
		int idx;		//その参照先のビット番号

	public:
		//コンストラクタ
		BitOfByteRef(BYTE& r, int i) :vec(r),idx(i) {

		}

		//新なのか偽なのか取得する変換関数
		operator bool()const {
			return (vec >> idx) & 1U;
		}

		//審議を設定する代入演算子関数
		BitOfByteRef& operator=(bool b) {
			//真のとき
			if(b) {
				//1を参照先までシフトした値との論理和で設定する
				vec |= 1U << idx;
			//偽の時
			}else {
				//1を参照先までシフトした値の補集合との論理積で取り除く
				vec &= ~(1U << idx);
			}
			//設定した値を返却する
			return *this;
		}
	};

	//エラーを出した時の例外クラス
	class IdxRngErr {
		const Array* ident;		//その配列へのポインタ
		int index;				//添え字のデータ

	public:
		//コンストラクタ
		IdxRngErr(const Array* p, int i) :ident(p),index(i) {

		}

		//エラーを出した時の添え字を返却する
		int Index()const {
			return index;
		}
	};

	//コンストラクタ
	explicit Array(int sz, bool v = bool()):nelem(sz),velem(size_of(sz)) {
		//必要要素数分確保する
		vec = new BYTE[velem];

		//ビットベクトルの総素数分繰り返して初期化
		for(int i = 0; i < velem; i++) {
			vec[i] = v;
		}
	}

	//コピーコンストラクタ
	Array(const Array& x) {
		//コピーするのが自分自身ででないとき
		if(&x == this) {
			nelem = 0;		//要素数を0に設定
			vec = 0;		//NULLを代入
		//自身ではないとき
		} else {
			nelem = x.nelem;		//要素数をコピー
			velem = x.velem;		//ビットベクトルの要素数をコピーする
			vec = new BYTE[velem];	//
			//ビットベクトルの要素数繰り返してコピーする
			for(int i = 0; i < velem; i++) {
				vec[i] = x.vec[i];
			}
		}
	}

	//デストラクタ
	~Array() {
		delete[]vec;
	}

	//ビットベクトルの要素数を返却する関数
	int get_vsize()const {
		return velem;
	}

	//要素数を返却する関数
	int size() const {
		return nelem;
	}

	//代入演算子
	Array& operator=(const Array& x) {

		//代入するのが自身でないとき
		if(&x != this) {

			//ビットベクトルの要素数が違うとき
			if(velem != x.velem) {
				delete[]vec;			//それまでもっていた領域を解放し
				velem = x.velem;		//要素数をコピーして
				vec = new BYTE[velem];	//その分の領域を確保
			}
			//要素数をコピー
			nelem = x.nelem;
			//ビットベクトル要素数分繰り返してコピー
			for(int i = 0; i < velem; i++) {
				vec[i] = x.vec[i];
			}
		}
		return *this;
	}
	//ビットベクトル中の要素への参照になるように返却する関数
	BitOfByteRef operator[](int i) {
		//
		if(i < 0 || i >= nelem) {
			//
			throw IdxRngErr(this, i);
		}
		//
		return BitOfByteRef(vec[i / CHAR_BITS], (i & (CHAR_BITS - 1)));
	}

	//bool型を返却する添え字演算子
	bool operator[](int i) const {

		//その添え字が不当な値の時
		if(i < 0 || i >= nelem) {
			//添え字エラーを送出する
			throw IdxRngErr(this,i);
		}
		//その値を評価した値が新なのか偽なのか返却する
		return (vec[i / CHAR_BITS] >> (i & (CHAR_BITS - 1)) & 1U) == 1;
	}
};

#endif
