/* 演習09-11
 * テキストを参考にキュークラス群の作成
 * 作成日：6月9日
 * 作成者：成田修之
 */

#ifndef ___Class_Que
#define ___Class_Que

template<class Type> class Que {
public:
	//満杯の時にプッシュしようとした際に送出されるオブジェクト
	class Overflow {

	};

	//空の時にポップしようとした際に送出されるオブジェクト
	class Empty {

	};

	//純粋仮想デストラクタ
	virtual ~Que() = 0;
	//プッシュする純粋仮想関数
	virtual void push(const Type &) = 0;
	//ポップする純粋仮想関数
	virtual Type pop() = 0;
};

//純粋仮想デストラクタの定義
template <class Type> Que<Type>::~Que() {

}

#endif
