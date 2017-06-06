/* 演習08-03-02
 * 例外ハンドラを基底クラスの参照で派生した例外クラスすべてを捕捉するようにする
 * 0による除算は先に捕捉して特別扱いできるように変更
 * 作成日：6月6日
 * 作成者：成田修之
 */


#ifndef ___Math_Exception
#define ___Math_Exception

//計算にかかわる例外の基底クラス
class MathException {

};

//0で除算を行った時の例外クラス
class DividedByZero :public MathException {

};

//オーバーフローした時の例外クラス
class Overflow :public MathException {
	//オーバーフローした時の値データ
	int v;
public:
	//コンストラクタ
	Overflow(int val) :v(val){

	}
	//オーバーフローした時の値を返却する関数
	int value() const {
		return v;
	}
};

//アンダーフローした時の例外クラス
class Underflow :public MathException {
	//アンダーフローした時の値データ
	int v;
public:
	//コンストラクタ
	Underflow(int val) :v(val) {

	}

	//アンダーフローした時のデータを返却する関数
	int value()const {
		return v;
	}
};

#endif
