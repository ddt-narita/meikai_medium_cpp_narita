/* 演習03-13
 * list3-19を年月日の順で当てさせるように変更したプログラムの作成
 * 作成日：6月2日
 * 作成者：成田修之
 */

#include<iostream>
#include"e_03_13.h"

using namespace std;

int main()
{
	//int型を受け取りint型を返却するSimpleDateのメンバ関数へのポインタ型を定義
	typedef int (SimpleDate::* Comp)(int) const;
	//定義されたメンバ型関数へのポインタ型の配列
	Comp pcomp[] = {
			//各比較するメンバ関数
			&SimpleDate::comp_y,&SimpleDate::comp_m,&SimpleDate::comp_d
	};
	//入力を促したいものに関する文字列を指すポインタの配列
	const char* pmenu[] = {"年：","月：","日："};

	//当てさせたいものを上の配列のから選ぶ上の配列の添字となる変数
	int menu = 0;
	//当てさせたい日付のSimpleDate型のオブジェクトを作成
	const SimpleDate birthday(1963,11,18);
	//入力された値との差を代入するための変数
	int deff;

	//これからすることの明示
	cout << "私の誕生日を当ててください。\n";

	//
	do{
		int value;				//年月日をそれぞれ入力するための変数
		cout << pmenu[menu];	//入力させたいものを表示
		cin >> value;			//入力
		//入力されたものとの差を代入
		deff = (birthday.*pcomp[menu])(value);

		//差が0の時
		if(!deff) {
			//正解したことを表示
			cout << "正解です。\n";
			//次に当てたいものの配列の添字をインクリメント
			menu++;
		//差が0より大きいときいくつ大きいか表示
		} else if(deff > 0) {
			cout << deff << "だけ大きいです。\n";
		//差が0より小さいときいくつ小さいか表示
		} else {
			cout << -deff << "だけ小さいです。\n";
		}
	//日にちまで当たるまで繰り返す
	}while(menu != 3);

	//main関数の返却値
	return 0;
}
