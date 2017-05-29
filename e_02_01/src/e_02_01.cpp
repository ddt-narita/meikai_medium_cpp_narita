/* 演習02-01
 * 符号なし整数を左右にシフトした値が2のべき乗での乗算や除算の演算結果と一致することを確認
 * 作成日：5月29日
 * 作成者：成田修之
 */

#include<iostream>
using namespace std;

//2のべき乗を返却する関数
int power2(int n){
	int n2 = 1;	//1で初期化

	//引数分繰り返して2掛ける
	for(int i = 1; i <= n; i++) {
		n2 *= 2;
	}
	return n2;
}


int main()
{
	int nShift = 64;	//シフトする変数
	int nPower = 64;	//2のべき乗で求める変数
	int shiftNumber;	//シフトする数を入力する変数

	//右にいくつシフトするか入力する
	cout << "何桁右にシフトしますか：";
	cin  >> shiftNumber;

	//右に入力された分シフト、2のシフトする数乗で割る
	nShift >>= shiftNumber;
	nPower /= power2(shiftNumber);


	//それぞれ表示して一致してることを表示
	if(nShift == nPower) {
		cout << "シフトした変数：" << nShift << "　べき乗で計算した変数：" << nPower << "で一致しています。\n";
	} else {
		cout << "シフトした変数：" << nShift << "　べき乗で計算した変数：" << nPower << "一致していません\n";
	}

	//左にシフトする数を入力
	cout << "何桁左にシフトしますか：";
	cin  >> shiftNumber;

	//それぞれ入力された数シフト、2のべき乗で掛ける
	nShift <<= shiftNumber;
	nPower *= power2(shiftNumber);

	//それぞれ表示して一致していることを表示
	if(nShift == nPower) {
		cout << "シフトした変数：" << nShift << "　べき乗で計算した変数：" << nPower << "で一致しています。\n";
	} else {
		cout << "シフトした変数：" << nShift << "　べき乗で計算した変数：" << nPower << "で一致していません\n";
	}

	//main関数の返却値
	return 0;

}
