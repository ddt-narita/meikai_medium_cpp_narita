/* 演習03-04
 * 関数f(x)を台形公式によって積分した値を返却する関数の作成
 * 作成日：5月31日
 * 作成者：成田修之
 */

#include<iostream>

using namespace std;

//2次関数
double f2(double x) {
	return x *= x;
}
//3次関数
double f3(double x) {
	return x *= x * x;
}

//関数f(x)を台形公式によって積分した値を返却する関数
double daikei(double x1, double x2,int n, double fp(double)) {
	//積分した値を返却するための関数
	double dblIntegral;
	//始点から始め終点空間隔分手前まで繰り返す
	for(int i = x1; i <= x2 - n; i += n) {
		//関数fpから帰ってきた値を台形公式で面積を求めて加算
		dblIntegral += (fp(i) + fp(i + n)) * n / 2;
	}
	return dblIntegral;
}

int main()
{
	double dblStart;	//始点を入力するための変数
	double dblEnd;		//終点を入力するための変数
	int nInterval;		//間隔を入力するための変数

	//2次関数について入力
	cout << "2次関数の積分\n";
	cout << "始点：";		//始点の入力を促す
	cin  >> dblStart;		//キーボードから入力
	cout << "終点";			//終点の入力を促す
	cin  >> dblEnd;			//キーボードから入力
	cout << "間隔";			//間隔の入力を促す
	cin  >> nInterval;		//キーボードから入力

	//2次関数の積分結果を表示
	cout << "結果は" << daikei(dblStart,dblEnd,nInterval,f2) <<"です。\n";

	//3次関数について入力
	cout << "3次関数の積分\n";
	cout << "始点：";		//始点の入力を促す
	cin  >> dblStart;		//キーボードから入力
	cout << "終点";			//終点の入力を促す
	cin  >> dblEnd;			//キーボードから入力
	cout << "間隔";			//間隔の入力を促す
	cin  >> nInterval;		//キーボードから入力

	//3次関数の積分結果を表示
	cout << "結果は" << daikei(dblStart,dblEnd,nInterval,f3) <<"です。\n";

	//main関数の返却値
	return 0;
}
