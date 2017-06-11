/* 演習09-11
 * テキストを参考にキュークラス群の作成
 * 作成日：6月9日
 * 作成者：成田修之
 */

#ifndef ___Class_ListQue
#define ___Class_ListQue

#include"Que.h"
#include<vector>


template <class Type> class VectorQue:public Que<Type> {
	std::vector<Type> que;

public:
	VectorQue(){

	}

	~VectorQue(){

	}

	void push(const Type& x) {
		try{
			que.push_back(x);
		} catch(...) {
			throw Overflow();
		}
	}

	Type pop() {
		if(que.empty()){
			throw Empty();
		}
		Type x = que.back();
		que.pop_back();
		return x;
	}
};
