/* 演習09-08
 * 9章2節のクラステンプレートArray<>、Array<bool>、FixedArray<>を
 * インクルードモデルで実現
 * 作成日：6月8日
 * 作成者：成田修之
 */

#ifndef ___ClassTemplate_Array_Inplementation
#define ___ClassTemplate_Array_Inplementation


	//コンストラクタ
	template<class Type>
	Array<Type>::IdxRngErr::IdxRngErr(const Array* p, int i) :ident(p),idx(i) {

	}
	//添え字を返却する関数
	template<class Type>
	int Array<Type>::IdxRngErr::Index()const {
		return idx;
	}

template<class Type>
Array<Type>::Array(int size, const Type& v):nelem(size) {
	//引数で受け取って初期化された要素数データ分領域を確保してその先頭をポインタデータが指すようにする
	vec = new Type[nelem];
	//要素数分繰り返す
	for(int i = 0; i < nelem; i++) {
		//引数の型のオブジェクトを格納する
		vec[i] = v;
	}
}


//コピーコンストラクタ
template<class Type>
Array<Type>::Array(const Array<Type>& x) {
	//コピー先が自身の時
	if(&x == this) {
		nelem = 0;		//要素数を0にして
		vec = 0;		//ポインタデータにNULLを代入する
		//コピー先が自身ではないとき
	}else {
		nelem = x.nelem;			//要素数をコピーする
		vec = new Type[nelem];		//コピーした要素数分の領域を確保する
		//各要素をコピーする
		for(int i = 0; i < nelem; i++) {
			vec[i] = x.vec[i];
		}
	}
}

//デストラクタ
template<class Type>Array<Type>::~Array() {
	delete[]vec;
}

//要素数を返却する関数
template<class Type>
int Array<Type>::size()const {
	return nelem;
}

//代入演算子の多重定義
template<class Type>
Array<Type>& Array<Type>::operator=(const Array& x) {
	//代入するオブジェクトが自身でないとき
	if(&x != this) {
		//要素数が同じではないとき
		if(nelem != x.nelem) {
			//オブジェクトが確保していた領域を解放して
			delete[]vec;
			//要素数をコピーして
			nelem = x.nelem;
			//その要素数分の領域を確保
			vec = new Type[nelem];
		}
		//各要素をコピーする
		for(int i = 0; i < nelem; i++) {
			vec[i] = x.vec[i];
		}
	}
	//コピーした自身への参照を返却する
	return *this;
}

//添え字演算子の多重定義
template<class Type>Type& Array<Type>::operator[](int i) {
	//正当な範囲の添え字ではないとき
	if(!is_valid_index(i)) {
		//例外クラスIdxRngErrを送出する
		throw IdxRngErr(this,i);
	}
	return vec[i];
}

//const型の場合の添え字演算子の多重定義
template<class Type>const Type& Array<Type>::operator[](int i) const {
	//正当な範囲の添え字ではないとき
	if(!is_valid_index(i)) {
		//例外クラスIdxRngErrを送出する
		throw IdxRngErr(this,i);
	}
	return vec[i];
}

//インクルードガードの終わり
#endif
