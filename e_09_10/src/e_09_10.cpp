/* 演習09-10
 * 先入れ先出しのキューを実現するクラステンプレートの作成
 * 作成日：6月9日
 * 作成者：成田修之
 */

#include<iostream>
#include<string>
#include"Que.h"

using namespace std;

int main()
{
	//入力するための文字列オブジェクト
	string x;

	//文字列の入力を促す
	cout << "文字列：";
	cin  >> x;

	//char型のスタックオブジェクトを入力された文字列の長さ分の容量で作成
	Que<char> s(x.length());

	try{
		//要素分繰り返す
		for(unsigned int i = 0; i < x.length(); i++) {
			//順番にプッシュする
			s.push(x[i]);
		}
		//要素数分繰り返す
		for(unsigned int i = 0; i < x.length() - 1; i++) {
			//char型の変数にポップした文字を入力
			char c = s.pop();
			//入力された文字文字を表示
			cout << c;
		}
		cout  << "\n";
	}
	//送出されたオーバーフローオブジェクトを受け取った時
	catch(const Que<char>::Overflow&) {
		//満杯のスタックにプッシュしようとしたことを表示
		cout << "\a満杯の<char>スタックにプッシュしようとしました。\n";
	}
	//送出されたエンプティーオブジェクトを受け取った時
	catch(const Que<char>::Empty&) {
		//空のスタックからポップしようとしたことを表示
		cout << "\a空の<char>スタックからポップしようとしました。\n";
	}

	//main関数の返却値
	return 0;
}
