/* 演習03-01
 * list3－2をほかの条件でも識別表示できるように作成
 * 作成日：5月30日
 * 作成者：成田修之
 */

#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

//良かどうか判定する関数
bool isB(int x) {
	return x >= 70 && x <= 79;
}

//優または可か判定する関数
bool isAorC(int x) {
	return (x >= 80 && x <= 100) || (x >= 60 && x <= 69);
}

//不可かどうか判定する関数
bool isD(int x) {
	return x >= 0 && x <= 59;
}

//優かどうか判定する関数
bool isA(int x) {
	return x >= 80 && x <= 100;
}

//可か不可か判定する関数
bool isCorD(int x){
	return (x >= 60 && x <= 69) || (x >= 0 && x <= 59);
}

//その人の点と判定を表示する関数
void put_list(const int a[], int n, bool fit(int)) {
	//全員分繰り返す
	for(int i = 0; i < n; i++) {
		//各判定が真の時は★を表示
		if(fit(a[i])) {
			cout << "★";
		//偽の時は空白を表示
		} else {
			cout << "  ";
		}
		//各点数を表示
		cout << "a[" << i << "] = " << a[i] << "\n";
	}
}


int main() {
	//10人分の点数を格納する配列
	int nArray[10];
	//要素数を求めて初期化した変数
	int n = sizeof(nArray) / sizeof(nArray);

	//ランダムな値を生成する種を設定
	srand(time(NULL));

	//人数分繰り返して0から100までのランダムな値を代入
	for(int i = 0; i < n; i++) {
		nArray[i] = rand() % 101;
	}

	//良の人に星を表示
	cout << "良----------\n";
	put_list(nArray,n,isB);

	//優または可の人に星を表示
	cout << "\n優または可--\n";
	put_list(nArray,n,isAorC);

	//不可の人に星を表示
	cout << "\n不可--------\n";
	put_list(nArray,n,isD);

	//優の人に星を表示
	cout << "\n優----------\n";
	put_list(nArray,n,isA);

	//可か不可の人に星を表示
	cout << "\n可か不可----\n";
	put_list(nArray,n,isCorD);

	//main関数の返却値
	return 0;
}
