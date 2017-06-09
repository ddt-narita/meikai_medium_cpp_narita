/* 演習09-09
 * スタッククラステンプレートにメンバ関数の追加
 * 作成日：6月8日
 * 作成者：成田修之
 */

#include<iostream>
#include<string>
#include"SimpleStack.h"

using namespace std;

int main()
{
	//入力するための文字列オブジェクト
	string x;

	//文字列の入力を促す
	cout << "文字列：";
	cin  >> x;

	//char型のスタックオブジェクトを入力された文字列の長さ分の容量で作成
	SimpleStack<char> s(x.length());

	//作成したスタックオブジェクトの容量を表示
	cout << "スタックを作成しました。容量は" << s.capacity() << "\n";

	//スタックが空っぽであることを確認
	cout << "スタック内は空っぽで" << (s.is_empty() ? "す。\n" : "はありません。\n");


	try{
		//要素分繰り返す
		for(unsigned int i = 0; i < x.length(); i++) {
			//順番にプッシュする
			s.push(x[i]);
		}

		//プッシュしたことを表示
		cout <<"入力された文字列をスタックにプッシュしました。\n";
		//頂上のデータを確認する
		cout << "頂上のデータは" << s.peek() << "です。\n";

		//スタック内のオブジェクトが満杯になっていることを確認
		cout << "スタック内は満杯で" << (s.is_full() ? "す。\n" : "はありません。\n");

		//要素数分繰り返す
		for(unsigned int i = 0; i < x.length(); i++) {
			//char型の変数にポップした文字を入力
			char c = s.pop();
			//入力された文字文字を表示
			cout << c;
		}
		cout  << "\n";
	}
	//送出されたオーバーフローオブジェクトを受け取った時
	catch(const SimpleStack<char>::Overflow&) {
		//満杯のスタックにプッシュしようとしたことを表示
		cout << "\a満杯の<char>スタックにプッシュしようとしました。\n";
	}
	//送出されたエンプティーオブジェクトを受け取った時
	catch(const SimpleStack<char>::Empty&) {
		//空のスタックからポップしようとしたことを表示
		cout << "\a空の<char>スタックからポップしようとしました。\n";
	}

	//main関数の返却値
	return 0;
}
