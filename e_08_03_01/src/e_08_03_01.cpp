/* 演習08-03-01
 * 例外ハンドラを基底クラスの参照で派生した例外クラスすべてを捕捉するようにする
 * 作成日：6月6日
 * 作成者：成田修之
 */

#include<iostream>
#include"e_08_03_01.h"

using namespace std;

//計算後の値が範囲内にないときに例外を送出する関数
int check(int value)
{
	//計算後の値が0より小さいとき
	if(value < 0) {
		//例外クラスUnderflowを送出する
		throw Underflow(value);
	}
	//計算後の値が99より大きいとき
	if(value > 99) {
		//例外クラスUpperflowを送出する
		throw Overflow(value);
	}

	//0から99の間の値ならそのままその値を返却する
	return value;
}

//関数checkに計算後の値を渡して例外がなければ計算結果を返す加算演算の関数
int add2(int x, int y)
{
	return check(x + y);
}

//関数checkに計算後の値を渡して例外がなければ計算結果を返す減算演算の関数
int sub2(int x, int y)
{
	return check(x - y);
}

//関数checkに計算後の値を渡して例外がなければ計算結果を返す乗算演算の関数
int mul2(int x, int y)
{
	return check(x * y);
}

//関数checkに計算後の値を渡して例外がなければ計算結果を返す除算演算の関数
int div2(int x, int y)
{
	//割る側の右オペランドの値が0の時
	if(y == 0){
		//例外クラスDividedByZeroを送出
		throw DividedByZero();
	}
	return check(x / y);
}


int main()
{
	int x;	//各種演算をされる左オペランド
	int y;	//各種演算をされる右オペランド

	//入力された値が0より小さいか99より大きい限り繰り返す
	do{
		//演算されるxに値を代入する
		cout << "xの値：";
		cin  >> x;
	} while(x < 0 || x > 99);

	//入力された値が0より小さいか99より大きい限り繰り返す
	do {
		//演算するyに値を代入する
		cout << "yの値：";
		cin  >> y;
	} while(y < 0 || y > 99);


	try{
		//加算演算時
		cout << "x + y = " << add2(x,y) << "\n";
		//減算演算時
		cout << "x - y = " << sub2(x,y) << "\n";
		//乗算演算時
		cout << "x * y = " << mul2(x,y) << "\n";
		//除算演算時
		cout << "x / y = " << div2(x,y) << "\n";
	//各演算で送出された例外を捕捉
	} catch(const MathException& e) {
		//何らかの例外が発生したことを表示
		cout << "MathExceptionを捕捉：何らかの算術例外が発生！！\n";
	}

	//main関数の返却値
	return 0;
}
