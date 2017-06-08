/* 演習09-06
 * Array<bool>型の配列に対して対話的に処理を行うプログラムを作成する
 * 作成日：6月8日
 * 作成者：成田修之
 */


#include<iostream>
#include"Array.h"
#include"BoolArray.h"

using namespace std;

int main()
{
	int nNumber;	//要素数を入力するための変数
	//入力を促す
	cout << "要素数を入力してください：";
	cin >> nNumber;

	//入力された要素数分の配列オブジェクトを生成
	Array<bool> boolArray(nNumber);

	//何するか入力するための変数
	int selected;

	//0が選択されて抜け出すまで繰り返す
	while(true) {

		//何をするか選択させる表示
		cout << "[1]要素数,[2]その要素のビットベクトルの要素数,[0]終了";
		//何をするのか入力
		cin >> selected;

		//0が選択されたとき
		if(selected == 0) {
			break;
		}

		//選択されたものについて分岐
		switch(selected) {
		//
		case 1: cout << "要素数は" << boolArray.size() << "です。\n"; break;
		//2が選択されたとき関数get_sizeを呼び出して要素数を表示
		case 2: cout << "ビットベクトルの要素数は" << boolArray.get_vsize() << "です。\n"; break;
		}
	}

	//main関数の返却値
	return 0;
}
