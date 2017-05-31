/* 演習 03-05-01 list3-8ver.
 * 九九の加算表と乗算表のどちらを表示させるのか選択させ選択された表を表示する
 * プログラムの作成,関数へのポインタの配列と関数へのポインタを返却する関数の2つ作成
 * 作成日：5月31日
 * 作成者：成田修之
 */

#include<iomanip>
#include<iostream>
using namespace std;

//何算するかの列挙帯
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

//何算するか選択する関数
Kuku select()
{
	//何算するか選択を入力するための変数
	int tmp;
	//有効な数値が入力されるまで続ける
	do{
		cout << "(0)…足し算、(1)…掛け算、(2)…終了";
		cin >> tmp;
	} while(tmp < Sum || tmp > Invalid);
	//Kuku型にキャストして返却
	return static_cast<Kuku>(tmp);
}

int main()
{
	//int 型とint型を引数にとりint型を返却する関数へのポインタ型を定義
	typedef int (*KukuFP)(int,int);
	//何算するか選択するKuku型の変数設定
	Kuku selected;
	//要素型がKukuFP型で要素数が2の配列
	KukuFP afp[] = {sum, mul};

	//終了でない限り続ける
	do{
		selected = select();
		//選択された値が有効なら選ばれた関数のポインタで関数kukuを呼び出して表示
		if(selected >= Sum && selected < Invalid) {
			kuku(afp[selected]);
		}
	} while(selected != Invalid);

	//main関数の返却値
	return 0;

}
