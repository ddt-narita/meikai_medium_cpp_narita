/* 演習09-08
 * 9章2節のクラステンプレートArray<>、Array<bool>、FixedArray<>を
 * インクルードモデルで実現
 * 作成日：6月8日
 * 作成者：成田修之
 */

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
	static int size_of(int sz);

public:
	//ビットベクトル中の1ビットへの参照を表すためのクラス
	class BitOfByteRef{
		BYTE& vec;		//参照先のポインタ
		int idx;		//その参照先のビット番号

	public:
		//コンストラクタ
		BitOfByteRef(BYTE& r, int i);

		//新なのか偽なのか取得する変換関数
		operator bool()const;

		//審議を設定する代入演算子関数
		BitOfByteRef& operator=(bool b);
	};

	//エラーを出した時の例外クラス
	class IdxRngErr {
		const Array* ident;		//その配列へのポインタ
		int index;				//添え字のデータ

	public:
		//コンストラクタ
		IdxRngErr(const Array* p, int i);

		//エラーを出した時の添え字を返却する
		int Index()const;
	};


	//コンストラクタ
	explicit Array(int sz, bool v = bool());

	//コピーコンストラクタ
	Array(const Array& x);

	//デストラクタ
	~Array();

	//ビットベクトルの要素数を返却する関数
	int get_vsize()const;

	//要素数を返却する関数
	int size() const;

	//代入演算子
	Array& operator=(const Array& x);

	//ビットベクトル中の要素への参照になるように返却する関数
	BitOfByteRef operator[](int i);

	//bool型を返却する添え字演算子
	bool operator[](int i) const ;
};

#include"BoolArray_Inplementation.h"

#endif
