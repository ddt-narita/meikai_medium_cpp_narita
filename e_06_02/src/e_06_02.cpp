/* 演習06-02 main
 * 前問で作成したクラスを含めてすべての図形クラス軍をテストするプログラムを作成
 * list6-4と同じくShape型の配列を利用してオブジェクトの生成と表示を行う
 * 作成日：6月5日
 * 作成者：成田修之
 */

#include<iostream>
#include"e_06_02.h"

using namespace std;

int main()
{
	//Shape型へのポインタの配列
	Shape* a[] = {
			new Point(),			//点
			new HorzLine(9),		//水平線
			new VertLine(6),		//垂直線
			new Rectangle(7,3),		//長方形
			new LowerLeft(6),		//左下直角2等辺三角形
			new UpperLeft(8),		//左上直角2等辺三角形
			new LowerRight(7),		//右下直角2等辺三角形
			new UpperRight(9)		//右上直角2等辺三角形
	};

	//どの図形についての情報を表示するか入力するための変数
	int selected;

	//終了条件で抜け出すまで続ける
	do{
		//不正な値が入力さて続ける限り繰り返す
		do {
			cout << "どの図形についての情報解説付き表示とデバッグ時用の情報を表示しますか？\n";
			cout << "0…点,1…水平線,2…垂直線,3…長方形,4…右下直角2等辺三角形,5…右上直角2等辺三角形,\n"
					"6…左下直角2等辺三角形,7…左上直角2等辺三角形,8…終了：";
			cin  >> selected;
		//不正な値の時は繰り返す
		}while(selected < 0 || selected > 8);

		//8が入力されたときはループを抜けて終了
		if(selected == 8) {
			break;
		}

		a[selected]->print();	//入力された図形について情報解説付き表示する
		a[selected]->debug();	//入力された図形についてデバッグ情報を表示する
		cout << "\n";
	}while(1);

	//プログラム終了前に動的に作った各図形領域を解放
	for(unsigned int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
		delete a[i];
	}

	//main関数の返却値
	return 0;
}
