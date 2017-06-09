/* 演習09-08
 * 9章2節のクラステンプレートArray<>、Array<bool>、FixedArray<>を
 * インクルードモデルで実現
 * 作成日：6月8日
 * 作成者：成田修之
 */


#ifndef ___Class_Template_Array_Bool_Inplementation
#define ___Class_Template_Array_Bool_Inplementation

#include<limits>
#include"Array.h"


 int Array<bool>::size_of(int sz) {
	return (sz + CHAR_BITS - 1) / CHAR_BITS;
}


 //コンストラクタ
Array<bool>::BitOfByteRef::BitOfByteRef(BYTE& r, int i) :vec(r),idx(i) {

 }

 //新なのか偽なのか取得する変換関数
Array<bool>::BitOfByteRef::operator bool()const {
	 return (vec >> idx) & 1U;
 }

 //審議を設定する代入演算子関数
Array<bool>::BitOfByteRef& Array<bool>::BitOfByteRef::operator=(bool b) {
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


//コンストラクタ
Array<bool>::IdxRngErr::IdxRngErr(const Array* p, int i) :ident(p),index(i) {

}

//エラーを出した時の添え字を返却する
int Array<bool>::IdxRngErr::Index()const {
	return index;
}

//コンストラクタ
Array<bool>::Array(int sz, bool v){
	nelem= sz;
	velem = size_of(sz);

	vec = new BYTE[velem];
	for(int i = 0; i < velem; i++) {
		vec[i] = v;
	}
}



//コピーコンストラクタ
Array<bool>::Array(const Array& x) {
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
Array<bool>::~Array() {
	delete[]vec;
}

//ビットベクトルの要素数を返却する関数
int Array<bool>::get_vsize()const {
	return velem;
}

//要素数を返却する関数
int Array<bool>::size() const {
	return nelem;
}

//代入演算子
Array<bool>& Array<bool>::operator=(const Array& x) {

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
Array<bool>::BitOfByteRef Array<bool>::operator[](int i){
	//要素数の範囲外の時
	if(i < 0 || i >= nelem) {
		//添え字の例外クラスを送出
		throw IdxRngErr(this, i);
	}
	//ビットベクトル中のその要素についての参照を返却する
	return BitOfByteRef(vec[i / CHAR_BITS], (i & (CHAR_BITS - 1)));
}

//bool型を返却する添え字演算子
bool Array<bool>::operator[](int i) const {

	//その添え字が不当な値の時
	if(i < 0 || i >= nelem) {
		//添え字エラーを送出する
		throw IdxRngErr(this,i);
	}
	//その値を評価した値が新なのか偽なのか返却する
	return (vec[i / CHAR_BITS] >> (i & (CHAR_BITS - 1)) & 1U) == 1;
}

#endif
