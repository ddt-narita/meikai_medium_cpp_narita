/* 演習02-02
 * 符号なし整数xの全ビットを右にnビット回転した値を返す関数rrotateと
 * 左にnビット回転した値を返す関数lrotateの作成
 * 作成日：5月29日
 * 作成者：成田修之
 */

#include<iostream>
using namespace std;

//2のべき乗を返却する関数
int nPower2(int n){
	int p2 = 1;		//1で初期化
	//1から引数まで2をかけることを繰り返す
	for(int i = 1; i < n; i++) {
		p2 *= 2;
	}
	//求めたべき乗を返却
	return p2;
}

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
unsigned rrotate(unsigned x, int n) {
	int count = 0;			//シフトした後先頭から何個目かを数える変数
	int b = int_bits();		//intの長さ
	int x2 = 0;				//返却する値
	//シフト後の先頭から最後まで繰り返す
	for(int i = n - 1; i >= 0; i--) {
		//0か1か表示
		cout << ((x >> i) & 1U ? '1' : '0');
		//1の時先頭からcount個目だと思って2のべき乗で加算
		if((x >> i) & 1U){
			x2 += nPower2(b - count);
		}
		//毎回カウントを進める
		count++;
	}

	//先頭からシフトの個数分繰り返す
	for(int i = int_bits() - 1; i >= n; i--) {
		//0か1か表示
		cout << ((x >> i) & 1U ? '1' : '0');
		//1の時先頭からcount個目だと思って2のべき乗で加算
		if((x >> i) & 1U){
			x2 += nPower2(b - count);
		}
		//毎回カウントを進める
		count++;
	}
	//加算した値を返却
	cout << "\n";
	return x2;
}

unsigned lrotate(unsigned x, int n) {
	int count = 0;			//何桁目かカウントする
	int b = int_bits();		//intの長さ
	int x2 = 0;				//返却する値

	//シフトする先頭から始める最後まで繰り返す
	for(int i = b - n - 1; i >= 0; i--) {
		//0か1か表示
		cout << ((x >> i) & 1U ? '1' : '0');
		//1の時先頭からcount個目の2のべき乗と考えて加算
		if((x >> i) & 1U){
			x2 += nPower2(b - count);
		}
		//毎回カウントを進める
		count++;
	}

	//シフトされる前の先頭から初めてシフトの先頭まで繰り返す
	for(int i = b - 1; i >= b - n; i--) {
		//0か1かを表示
		cout << ((x >> i) & 1U ? '1' : '0');
		//1の時先頭からcount個目の2のべき乗と考えて加算
		if((x >> i) & 1U){
			x2 += nPower2(b - count);
		}
		count++;
	}
	//加算し終えたx2を返却
	cout << "\n";
	return x2;
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
