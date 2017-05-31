/* 演習03-03
 * 条件を満たす全要素を配列から探索する関数search_if_allを作成
 * 作成日：5月31日
 * 作成者：成田修之
 */

#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

//2の倍数かどうかを判定する関数
bool divisible2(int n) {
	return n % 2 == 0 ? 1 : 0;
}

//条件を満たすすべての要素を配列から探索して個数を変えす関数
int search_if_all(const int a[], int n, bool cond(int n),int** idx) {
	//条件を満たす要素を格納する配列
	int* clear = new int[n];
	//要素の個数をカウントする変数
	int count = 0;
	//引数の配列の要素数分繰り返す
	for(int i = 0; i < n; i++) {
		//その要素が条件を満たすときその添字を格納してカウント
		if(cond(a[i])) {
			clear[count++] = i;
		}
	}
	//格納した先頭のポインタを引数idxの指すポインタに格納
	*idx = clear;
	//個数を返却
	return count;
}


int main()
{
	srand(time(NULL));			//ランダムな値を生成する種を設定
	int nArrayNumber = 16;		//要素数


	//要素数を入力
	cout << "要素数：";


	int** a = new int*[1];	//配列数分の領域を確保

	//入力された要素数分の配列を確保
	int* nArray = new int[nArrayNumber];

	//要素数分繰り返してランダムな値を代入し表示
	for(int i = 0; i < nArrayNumber; i++) {
		nArray[i] = rand() % 50;
		cout << nArray[i] << " ";
	}
	//最後に改行
	cout << "\n";

	//関数search_if_allを呼び出して条件を満たす個数を表示
	int number = search_if_all(nArray,nArrayNumber,divisible2,a);
	cout << "偶数は" << number << "個です。\n";

	cout << "それぞれの添字は：";
	//個数分繰り返してその添字を表示
	for(int i = 0; i < number; i++) {
		cout << a[0][i] << " ";
	}
	cout << "です。\n";
	//main関数の返却値
	return 0;

}
