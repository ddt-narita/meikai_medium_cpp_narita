/* 演習08-07
 * list8-13の2つの例外ハンドラをconst exception&型で受け取るように書き換えて作成
 * 作成日：6月6日
 * 作成者：成田修之
 */


#include<iostream>
#include<exception>

using namespace std;

//2つの値を加算する関数（引数が不正の時はエラーを送出する）
int add(int v1, int v2)
{
	//第一引数が不正な範囲の時
	if(v1 < 0 || v1 > 99) {
		//論理エラーout_of_rangeを送出する
		throw out_of_range("v1の値が不正。");
	}
	//第2引数が不正な範囲の時
	if(v2 < 0 || v2 > 99) {
		//論理エラーout_of_rangeを送出
		throw out_of_range("v2の値が不正。");
	}

	//引数2つを加算した値で初期化された変数を設計
	int sum = v1 + v2;

	//加算された値が不正な値であったとき
	if(sum < 0 || sum > 99) {
		//オーバーフローの論理エラーoverflow_errorを送出
		throw overflow_error("オーバーフロー。");
	}

	//引数がどちらも正常な範囲内の時加算した値を返却
	return v1 + v2;
}


int main()
{
	int x;		//加算する値を入力する変数
	int y;		//加算する値を入力する変数

	//xに値の入力を促す
	cout << "xの値(0～99)：";
	cin  >> x;

	//yに値の入力を促す
	cout << "yの値(0～99)：";
	cin  >> y;


	try {
		//入力された2つの値で関数addを呼び出して返却された加算後の値を表示
		cout << "加算した値は" << add(x,y) << "です。\n";

	//呼び出した関数内で算術例外オブジェクトが送出されたときその参照を受け取る
	} catch(const exception& e) {
		//論理エラーが発生したこととどんなエラーの種類かを表示
		cout << "論理エラー発生：" << e.what() << "\n";
	}

	//main関数の返却値
	return 0;
}
