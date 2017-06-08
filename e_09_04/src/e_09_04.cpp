

#include<iomanip>
#include<iostream>
#include"Matrix.h"


using namespace std;

int main()
{
	int row = 4;		//行数
	int column = 5;		//列数

	//二つの変数で2次配列クラスを生成
	Matrix<int> a(row,column);

	//要素に代入
	a[3][2] = 3;

	//行数分繰り返す
	for(int i = 0; i < row; i++) {
		//列数分繰り返す
		for(int j = 0; j < column; j++) {
			//各要素を表示
			cout << setw(3) << a[i][j];
		}
		cout << "\n";
	}

	//main関数の返却値
	return 0;
}
