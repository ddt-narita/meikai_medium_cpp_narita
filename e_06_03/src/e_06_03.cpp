/* 演習06-03 main
 * じゃんけんのプレーヤーを表す抽象クラス、そこから派生する人間、コンピュータークラスの作成
 * 作成日：6月6日
 * 作成者：成田修之
 */

#include<iostream>
#include<ctime>
#include"e_06_03.h"


using namespace std;

int main()
{
	//ランダムな値を生成する種を設定
	srand(time(NULL));

	//手を入力するための変数
	int h;
	//手に相当する値の入力を促す
	std::cout << "入力してください\n";

	//不正な値が入力されつ限り繰り返す
	do{
		//手に相当する値の入力を促す
		std::cout << "０…グー、1…チョキ、２…パー：";
		std::cin >> h;
	}while(h < 0 || h > 2);

	//人間クラスのオブジェクトを作ってそれを指すポインタを宣言
	Player* b = new HumanPlayer(h);

	//人間クラスのオブジェクトの文字列表現を表示
	cout << b->to_string();

	//コンピュータークラスオブジェクトを指すポインタを宣言
	Player* a = new ComputerPlayer;

	//コンピュータークラスのオブジェクトの文字列表現を表示
	cout << a->to_string();

	//main関数の返却地
	return 0;
}
