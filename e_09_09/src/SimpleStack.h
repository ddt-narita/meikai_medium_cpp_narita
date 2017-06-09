/* 演習09-09
 * スタッククラステンプレートにメンバ関数の追加
 * 作成日：6月8日
 * 作成者：成田修之
 */

#ifndef ___Class_SimpleStack
#define ___Class_SimpleStack

template<class Type>class SimpleStack {
	int size;		//容量を返却する関数
	int ptr;		//スタックポインタ
	Type* stk;		//スタックの本体の先頭を指すポインタ

public:
	//満杯の時の例外クラス
	class Overflow {

	};

	//空の時の例外クラス
	class Empty {

	};

	//明示的なコンストラクタ
	explicit SimpleStack(int sz);

	//デストラクタ
	~SimpleStack();

	//プッシュする関数
	Type& push(const Type& x);

	//ポップする関数
	Type pop();

	//頂上のデータを削除することなく返却する関数
	Type& peek();

	//スタックの容量を返却する関数
	int capacity();

	//スタックが満杯かどうかを返却する関数
	bool is_full();

	//スタックが空かどうかを返却する関数
	bool is_empty();
};

//インクルードモデル化
#include"SimpleStack_Inplementation.h"

//インクルードガードの終わり
#endif
