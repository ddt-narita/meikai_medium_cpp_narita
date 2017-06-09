/* 演習09-09
 * スタッククラステンプレートにメンバ関数の追加
 * 作成日：6月8日
 * 作成者：成田修之
 */

#ifndef ___Class_SimpleStack_Inplementation
#define ___Class_SimpleStack_Inplementation

//コンストラクタ
template<class Type>SimpleStack<Type>::SimpleStack(int sz): size(sz),ptr(0){
	//容量分の領域を確保
	stk = new Type[size];

}

//デストラクタ
template<class Type>SimpleStack<Type>::~SimpleStack(){
	//スタックのために確保していた領域を解放する
	delete[]stk;
}

//プッシュする関数
template<class Type>Type& SimpleStack<Type>::push(const Type& x) {
	//スタックのポインタが容量以上の位置を指し、満杯の時
	if(ptr >= size) {
		//オーバーフローの例外クラスを送出
		throw Overflow();
	}
	//頂上にデータを足しスタックのポインタを一つ上にする
	return stk[ptr++] = x;
}

//ポップする関数
template<class Type>Type SimpleStack<Type>::pop() {
	//スタックのポインタが０を指し空っぽの時
	if(ptr <= 0) {
		//空の例外クラスを送出
		throw Empty();
	}
	//スタックポインタを一つ下し頂上のデータを返却する
	return stk[--ptr];
}

//頂上のデータを削除することなく返却する
template<class Type>Type& SimpleStack<Type>::peek(){
	//スタックが空のとき
	if(ptr == 0) {
		//空の時の例外クラスを送出
		throw Empty();
	}
	//スタックのポインタを移動せずに頂上のクラスを返却する
	return stk[ptr - 1];
}

//スタックの容量を返却する関数
template<class Type>int SimpleStack<Type>::capacity() {
	return size;
}

//スタックが満杯であるかどうかを返却する関数
template<class Type>bool SimpleStack<Type>::is_full() {
	return ptr == size;
}

//スタックが空であるかどうかを返却する関数
template<class Type>bool SimpleStack<Type>::is_empty() {
	return ptr == 0;
}

#endif
