/* 演習09-10
 * 先入れ先出しのキューを実現するクラステンプレートの作成
 * 作成日：6月9日
 * 作成者：成田修之
 */

#ifndef ___Class_Que
#define ___Class_Que

template<class Type> class Que {
	int size;		//容量データ
	int ptr;		//キューのポインタ
	Type* que;		//キュー本体

	//コピーコンストラクタの無効化
	Que(const Que<Type>&);
	//代入演算子の無効化
	Que& operator=(const Que<Type>&);

public:
	//オーバーフローした時送出されるオブジェクト
	class Overflow {

	};
	//空の時にポップしようとしたときに送出されるオブジェクト
	class Empty {

	};
	//明示的なコンストラクタ
	explicit Que(int sz);
	//デストラクタ
	~Que();
	//プッシュする関数
	Type& push(const Type& x);
	//ポップする関数
	Type pop();

};

//インクルードモデル化
#include"Que_Implementation.h"

#endif
