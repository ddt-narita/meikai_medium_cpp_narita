/* 演習09-10
 * 先入れ先出しのキューを実現するクラステンプレートの作成
 * 作成日：6月9日
 * 作成者：成田修之
 */

#ifndef ___Class_Que_Implementation
#define ___Class_Que_Implementation

//コンストラクタ
template<class Type>
Que<Type>::Que(int sz):size(sz),ptr(0)
{
	//引数で初期化された容量分の領域をキューに確保
	que = new Type[size];
}

//デストラクタ
template<class Type>
Que<Type>::~Que()
{
	//キューが確保していた領域を解放
	delete[]que;
}

//プッシュする関数
template<class Type>
Type& Que<Type>::push(const Type& x) {
	//容量より大きい場所にプッシュしようとしたとき
	if(ptr >= size) {
		//オーバーフローのオブジェクトを送出
		throw Overflow();
	}
	//引数を代入して返却しポインタを一つ上へ
	return que[ptr++] = x;
}

//ポップする関数
template<class Type>
Type Que<Type>::pop(){
	//キューが空の時
	if(ptr <= 0) {
		//Enptyオブジェクトを送出
		throw Empty();
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

#endif
