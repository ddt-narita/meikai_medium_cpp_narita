/* 演習09-11
 * テキストを参考にキュークラス群の作成
 * 作成日：6月9日
 * 作成者：成田修之
 */

#ifndef ___Class_ArrayQue
#define ___Class_ArrayQue

#include"Que.h"

template<class Type> class ArrayQue:public Que<Type> {
	static const int size = 10;	//固定されたキューの容量
	int ptr;			//キューのポインタ
	Type que[size];		//キュー本体
public:
	//コンストラクタ
	ArrayQue():ptr(0) {

	}
	//デストラクタ
	~ArrayQue(){

	}

	//プッシュする関数
	void push(const Type& x) {
		//容量より大きい場所にプッシュしようとしたとき
		if(ptr >= size) {
			//オーバーフローのオブジェクトを送出
			throw typename Que<Type>::Overflow();
		}
		//末尾に引数のオブジェクトを格納して、ポインタをインクリメント
		que[ptr++] = x;
	}

	//ポップする関数
	Type pop() {
		//キューが空の時
		if(ptr <= 0) {
			//Enptyオブジェクトを送出
			throw typename Que<Type>::Empty();
		}
		//ポインタを一つ下げて
		ptr--;

		//返却する要素を非難しておく
		Type returnQue = que[0];

		//要素数分繰り返す
		for(int i = 0; i < ptr; i++) {
			//一つ下のキューに代入（一つずつ下す）
			que[i] = que[i + 1];
		}
		//非難していた返却する要素を返却
		return returnQue;

	}
};

#endif
