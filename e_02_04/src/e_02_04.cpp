/* 演習02-04
 * 符号なし整数xの第posビットから第pos+n-1ビットまでのn個のビットを
 * 1，0、反転させて返す関数をそれぞれ作成
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


unsigned set_n(unsigned x, int pos, int n)
{
	//pos番目からn個分繰り返す
	for(int i = pos - 1; i < pos + n; i++) {
		//その位が1ではない時その位の分足す
		if(!((x >> i) & 1U))	{
			x += (1 << i);
		}
	}
	//出来た値をビット表記
	print_bits(x);
	//改行
	cout << "\n";
	//出来た数値を返却
	return x;
}

unsigned reset_n(unsigned x, int pos, int n)
{
	//pos番目からn個分繰り返す
	for(int i = pos - 1; i < pos + n; i++) {
		//その位が１ならその位の分引く
		if(((x >> i) & 1U))	{
			x -= (1 << i);
		}
	}
	//出来た数値をビット表記
	print_bits(x);
	//改行
	cout << "\n";
	//出来た数値を返却
	return x;
}

unsigned inverse_n(unsigned x, int pos, int n)
{
	//pos番目からn個分繰り返す
	for(int i = pos - 1; i < pos + n; i++) {
		//その位が1でないならその時の位を加え
		if(!((x >> i) & 1U))	{
			x += (1 << i);
		//その位が1ならその時の位の分引く
		} else {
			x -= (1 << i);
		}
	}
	//出来た数値についてビット表記
	print_bits(x);
	//改行
	cout << "\n";
	//出来た数値を返却
	return x;
}



int main()
{
	unsigned int a = 54;	//初期の値
	int nSet;				//いくつシフトするか入力するのに使う変数
	int nNumber;			//変化させる個数

	//初期値を表示
	cout << a << "\n";
	print_bits(a);

	//どの位を変化させるか入力
	cout << "\nどの位から変化させますか：";
	cin >> nSet;
	cout << "何個変化させますか：";
	cin >> nNumber;

	//入力された値分それぞれシフトした値を表示
	cout << set_n(a,nSet,nNumber) << "\n";
	cout << reset_n(a,nSet,nNumber) << "\n";
	cout << inverse_n(a,nSet,nNumber) << "\n";

}
