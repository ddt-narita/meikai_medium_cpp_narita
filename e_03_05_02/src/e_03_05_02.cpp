/* 演習 03-05-01 list3-8ver.
 * 九九の加算表と乗算表のどちらを表示させるのか選択させ選択された表を表示する
 * プログラムの作成,関数へのポインタの配列と関数へのポインタを返却する関数の2つ作成
 * 作成日：5月31日
 * 作成者：成田修之
 */

#include<iomanip>
#include<iostream>
using namespace std;

//何残するかの列挙帯
enum Kuku {Sum,Mul,Invalid};

//足し算の関数
int sum(int x1, int x2)
{
	return x1 + x2;
}

//掛け算の関数
int mul(int x1, int x2)
{
	return x1 * x2;
}

//九九の表を表示する関数
void kuku(int calc(int,int)) {
	cout << " |";
	//列を表示
	for(int i = 1; i <= 9; i++) {
		cout << setw(3) << i;
	}
	cout << "\n--+";
	//区切りを表示
	for(int i = 1; i <= 27; i++) {
		cout << "-";
	}
	cout << "\n";

	//行ごとに繰り返す
	for(int i = 1; i <= 9; i++) {
		cout << i << " |";
		//列ごとに繰り返して引数に受け取った関数の演算方法で表示
		for(int j = 1; j <= 9; j++) {
			cout << setw(3) << calc(i,j);
		}
		cout << "\n";
	}
}

//int型とint型を受け取りint型を返す関数へのポインタを返す関数
int (*selected_calc())(int,int)
{
	//何算するか選択を入力するための変数
	int tmp;

	//有効な値が入力されreturnによって呼び出し元に帰るまで繰り返す
	while(1) {
		//何残するか入力を促す
		cout << "(0)…足し算、(1)…掛け算、(2)…終了";
		cin >> tmp;

		//入力された値に応じた関数へのポインタを返却する
		switch(tmp) {
		case Sum:		 return sum;
		case Mul:		 return mul;
		case Invalid:	 return NULL;
		}
	}

}


int main()
{
	//if文によってbreakされるまで繰り返す
	while(1) {
		//int型2つを受け取りint型を返す関数へのポインタ型変数を関数selected_calc
		//によって返却された関数へのポインタで初期化
		int (*calc)(int,int) = selected_calc();
		//返却されたポインタがNULLの時はループを抜け終了
		if(calc == NULL) {
			break;
		}
		//返却された関数へのポインタで九九を表示する関数kukuを呼び出す
		kuku(calc);
	}
	//main関数の返却値
	return 0;
}
