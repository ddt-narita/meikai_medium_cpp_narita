/* 演習02－03
 * 符号なし整数xの第potビットを1，0、反転した値を返却する関数
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

unsigned set(unsigned x, int pos)
{
	//pos番目の数値が1ではない時その位分足す
	if(!(x >> (pos - 1) & 1U))	{
		x += (1 << (pos - 1));
	}
	//その数値をビット表記
	print_bits(x);
	//改行
	cout << "\n";
	//出来た数値を返却
	return x;
}

unsigned reset(unsigned x, int pos)
{
	//pos番目の位が1の時はその位分引く
	if(x >> (pos - 1) & 1U) {
		x -= (1 << (pos - 1));
	}
	//出来た数値をビット表記
	print_bits(x);
	//改行
	cout << "\n";
	//出来た数値を返却
	return x;
}

unsigned inverse(unsigned x, int pos)
{
	//pos番目の位が1の時はその位分引き
	if(x >> (pos - 1) & 1U){
		x -= (1 << (pos - 1));
	//0の時はその位分足す
	} else {
		x += (1 << (pos - 1));
	}
	//出来た数値をビット表記
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

	//初期値を表示
	cout << a << "\n";
	print_bits(a);

	//どの位を変化させるか入力
	cout << "\nどの位を変化させますか：";
	cin >> nSet;

	//入力された値分それぞれシフトした値を表示
	cout << set(a,nSet) << "\n";
	cout << reset(a,nSet) << "\n";

	//どの位を反転させるか入力
	cout << "どの位を反転させますか：";
	cin >> nSet;
	//入力された位の値を反転して計算
	cout << inverse(a,nSet) << "\n";

	//main関数の返却値
	return 0;

}
