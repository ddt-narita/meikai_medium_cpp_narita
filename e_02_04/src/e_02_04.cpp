/* 演習02-04
 * 符号なし整数xの第posビットから第pos+n-1ビットまでのn個のビットを
 * 1，0、反転させて返す関数をそれぞれ作成
 * 作成日：5月29日
 * 作成者：成田修之
 */

#include<iostream>
using namespace std;


//2のべき乗を返却する関数
int nPower2(int n){
	int p2 = 1;		//1で初期化
	//1から引数まで2をかけることを繰り返す
	for(int i = 0; i < n; i++) {
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


unsigned set_n(unsigned x, int pos, int n) {
	int x2 = 0;
	int nHed = int_bits();

	//先頭からはじめ、posからn番目の手前まで繰り返す
	for(int i = nHed - 1; i >= pos + n - 1; i--) {
		//0か1か表示
		cout << ((x >> i) & 1U ? '1' : '0');
		//1の時その位の2のべき乗を加算
		if((x >> i) & 1U){
			x2 += nPower2(i);
		}
	}

	//posからn番目からはじめ、pos番目まで繰り返し1を表示
	for(int i = pos + n - 2; i >= pos - 1; i--) {
		cout << "1";
		//その桁の2のべき乗を加算
		x2 += nPower2(i);
	}

	//pos番目の後から最後まで繰り返す
	for(int i = pos - 2; i >= 0; i--) {
		//0か1かを表示
		cout << ((x >> i) & 1U ? '1' : '0');
		//1の時その位の2のべき乗を加算
		if((x >> i) & 1U){
			x2 += nPower2(i);
		}
	}
	//加算し終えたx2を返却
	cout << "\n";
	return x2;
}

unsigned reset(unsigned x, int pos, int n) {
	int x2 = 0;
	int nHed = int_bits();

	//先頭からはじめ、posからn番目手前まで繰り返す
	for(int i = nHed - 1; i >= pos + n - 1; i--) {
		//0か1か表示
		cout << ((x >> i ) & 1U ? '1' : '0');
		//1の時その位の2のべき乗を加算
		if((x >> i) & 1U){
			x2 += nPower2(i);
		}
	}

	//posからn番目から始め、pos番目まで繰り返し0を表示
	for(int i = pos + n - 2; i >= pos - 1; i--) {
		cout << "0";
	}

	//pos番目の後から最後まで繰り返す
	for(int i = pos - 2; i >= 0; i--) {
		//0か1かを表示
		cout << ((x >> i) & 1U ? '1' : '0');
		//1の時その位の2のべき乗を加算
		if((x >> i) & 1U){
			x2 += nPower2(i);
		}
	}
	//加算し終えたx2を返却
	cout << "\n";
	return x2;
}

unsigned inverse(unsigned x, int pos, int n) {
	int x2 = 0;
	int nHed = int_bits();

	//先頭からはじめ、posからn番目手前まで繰り返す
	for(int i = nHed - 1  ; i >= pos + n - 1; i--) {
		//0か1か表示
		cout << ((x >> i) & 1U ? '1' : '0');
		//1の時その位の2のべき乗を加算
		if((x >> i) & 1U){
			x2 += nPower2(i);
		}
	}

	//posからn番目から始めpos番目まで繰り返す
	for(int i = pos + n - 2; i >= pos - 1; i--) {
		//繰り返す間反転して表示して1の時その位の時のべき乗を足す
		cout << ((x >> i) & 1U ? '0' : '1');
		if(!(x >> i & 1U)) {
			x2 += nPower2(i);
		}
	}

	//pos番目の後から最後まで繰り返す
	for(int i = pos - 2; i >= 0; i--) {
		//0か1かを表示
		cout << ((x >> i) & 1U ? '1' : '0');
		//1の時その位の2のべき乗を加算
		if((x >> i) & 1U){
			x2 += nPower2(i);
		}
	}
	//加算し終えたx2を返却
	cout << "\n";
	return x2;
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
	cout << reset(a,nSet,nNumber) << "\n";
	cout << inverse(a,nSet,nNumber) << "\n";

}
