/* 演習09-08
 * 9章2節のクラステンプレートArray<>、Array<bool>、FixedArray<>を
 * インクルードモデルで実現
 * 作成日：6月8日
 * 作成者：成田修之
 */


#ifndef ___ClassTemplate_Array
#define ___ClassTemplate_Array

//配列クラステンプレート
template <class Type> class Array {
	int nelem;		//要素数データ
	Type* vec;		//先頭を指すポインタデータ

	//その値が正当な値かどうか判定する関数
	bool is_valid_index(int idx) const{
		return idx >= 0 && idx < nelem;
	}

public:
	//添え字の例外クラス
	class IdxRngErr {
		const Array* ident;		//例外を発生した要素へのポインタデータ
			int idx;				//例外を発生した要素の添え字

		public:
			//コンストラクタ
			IdxRngErr(const Array* p, int i);
			//添え字を返却する関数
			int Index()const;
	};

	//明示的なコンストラクタ
	explicit Array(int size, const Type& v );

	//コピーコンストラクタ
	Array(const Array<Type>& x);

	//デストラクタ
	~Array();

	//要素数を返却する関数
	int size()const;

	//代入演算子の多重定義
	Array& operator=(const Array& x);

	//添え字演算子の多重定義
	Type& operator[](int i);

	//const型の場合の添え字演算子の多重定義
	const Type& operator[](int i) const;
};

#include"Array_Inplementation.h"

//インクルードガードの終わり
#endif
