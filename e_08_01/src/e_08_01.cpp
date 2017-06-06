/* 演習08-01
 * set_terminate関数によってexception_errorを登録するプログラムの作成
 * 作成日：6月6日
 * 作成者：成田修之
 */

#include<iostream>

#include<exception>

using namespace std;

//送出する例外がなかった時の処理を行う関数
void exception_error()
{
	//エラーが発生したことを表示する
	cout << "例外関連のエラーが発生しました。\n";
	//異常終了する
	abort();
}

int main()
{
	//送出するべき例外のないとき実行する関数をexceptionに設定
	set_terminate(exception_error);

	//
	try{
		//送出するべき例外がない送出
		throw;
	//未捕捉の全例外を捕捉
	}catch(...){

	}
	//main関数の返却値
	return 0;
}
