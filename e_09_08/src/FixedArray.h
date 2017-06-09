/* 演習09-08
 * 9章2節のクラステンプレートArray<>、Array<bool>、FixedArray<>を
 * インクルードモデルで実現
 * 作成日：6月8日
 * 作成者：成田修之
 */

#ifndef ___Class_FixedArray
#define ___Class_FixedArray

template <class Type, int N> class FixedArray {
	Type vec[N];

public:
	//
	class IdxRngErr {

	};

	//
	explicit FixedArray(const Type& v = Type());

	//
	FixedArray(const FixedArray& x);

	//
	int size()const;

	//
	FixedArray& operator=(const FixedArray& x);

	//
	Type& operator[](int i);

	//
	const Type& operator[](int i)const;
};


#include"FixedArray_Inplementation.h"

#endif
