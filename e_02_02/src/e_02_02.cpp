/* 演習02-02
 * 符号なし整数xの全ビットを右にnビット回転した値を返す関数rrotateと
 * 左にnビット回転した値を返す関数lrotateの作成
 * 作成日：5月29日
 * 作成者：成田修之
 */

#include<iostream>
using namespace std;

//1の数を数える関数
int count_bits(unsigned x) {
	int bits = 0;
	//xが0でない限り繰り返す
	while(x) {
		//xの最下位が1の時カウント
		if(x & 1U) {
			bits++;
		}
		//1シフトする
		x >>= 1;
	}
	//数えた1の数を返却
	return bits;
}

//intの長さを求める関数
int int_bits()
{
	return count_bits(~0U);
}

//2進法表記する関数
void print_bits(unsigned x) {
	//長さ分繰り返してシフトしたときの位を表示
	for(int i = int_bits() - 1; i >= 0; i--) {
		cout << ((x >> i) & 1U ? '1' : '0');
	}
}


//
unsigned rrotate(unsigned x, int n)
{
	//一周以上は一緒だから長さの剰余を求める
	n %= int_bits();
	//シフトする部分ではない部分を左にシフトシフトしたい部分を余った分だけシフト
	int y = (x >> n) + (x << (int_bits() - n));
	//求めた数をビット表示
	print_bits(y);
	//ビット表示とその数の間を空けるため改行
	cout << "\n";
	//求めた数を返却
	return y;
}

unsigned lrotate(unsigned x, int n)
{
	//長さを超えるものについては剰余と一緒
	n %= int_bits();
	//xをn個左へシフトしたものとあまり分右へシフトしたものを足す
	int y = (x << n) + (x >> (int_bits() - n));
	//出来た数値をビット表記
	print_bits(y);
	//表記と数値の間の改行
	cout << "\n";
	//出来た数値を返却
	return y;
}


int main()
{
	unsigned int a = 54;	//初期の値
	int shift;				//いくつシフトするか入力するのに使う変数

	//初期値を表示
	cout << a << "\n";
	print_bits(a);

	//いくつシフトするか入力
	cout << "\nいくつシフトしますか：";
	cin >> shift;

	//入力された値分それぞれシフトした値を表示
	cout << rrotate(a,shift) << "\n";
	cout << lrotate(a,shift) << "\n";

	//main関数の返却値
	return 0;
}
