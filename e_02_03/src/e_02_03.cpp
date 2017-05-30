/* 演習02－03
 * 符号なし整数xの第potビットを1，0、反転した値を返却する関数
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

unsigned set(unsigned x, int pos) {
	int x2 = 0;
	int b = int_bits();

	//先頭からpos番目手前まで繰り返す
	for(int i = b  ; i > pos; i--) {
		//0か1か表示
		cout << ((x >> (i - 1)) & 1U ? '1' : '0');
		//1の時その位の2のべき乗を加算
		if((x >> (i - 1)) & 1U){
			x2 += nPower2(i - 1);
		}
	}

	//pos番目の時1を表示してその位の時のべき乗を足す
	cout << '1';
	x2 += nPower2(pos - 1);

	//posの後から最後まで繰り返す
	for(int i = pos -1 ; i > 0; i--) {
		//0か1かを表示
		cout << ((x >> (i -1)) & 1U ? '1' : '0');
		//1の時その位の2のべき乗を加算
		if((x >> (i - 1)) & 1U){
			x2 += nPower2(i - 1);
		}
	}
	//加算し終えたx2を返却
	cout << "\n";
	return x2;
}

unsigned reset(unsigned x, int pos) {
	int x2 = 0;
	int b = int_bits();

	//先頭からpos番目手前まで繰り返す
	for(int i = b  ; i > pos; i--) {
		//0か1か表示
		cout << ((x >> (i - 1)) & 1U ? '1' : '0');
		//1の時その位の2のべき乗を加算
		if((x >> (i - 1)) & 1U){
			x2 += nPower2(i - 1);
		}
	}

	//pos番目の時0を表示して次の位へ
	cout << '0';

	//posの後から最後まで繰り返す
	for(int i = pos -1 ; i > 0; i--) {
		//0か1かを表示
		cout << ((x >> (i -1)) & 1U ? '1' : '0');
		//1の時その位の2のべき乗を加算
		if((x >> (i - 1)) & 1U){
			x2 += nPower2(i - 1);
		}
	}
	//加算し終えたx2を返却
	cout << "\n";
	return x2;
}

unsigned inverse(unsigned x, int pos) {
	int x2 = 0;
	int b = int_bits();

	//先頭からpos番目手前まで繰り返す
	for(int i = b  ; i > pos; i--) {
		//0か1か表示
		cout << ((x >> (i - 1)) & 1U ? '1' : '0');
		//1の時その位の2のべき乗を加算
		if((x >> (i - 1)) & 1U){
			x2 += nPower2(i - 1);
		}
	}

	//pos番目の時反転して表示して1の時その位の時のべき乗を足す
	cout << ((x >> (pos - 1)) & 1U ? '0' : '1');
	if(!(x >> (pos - 1) & 1U)) {
		x2 += nPower2(pos - 1);
	}

	//posの後から最後まで繰り返す
	for(int i = pos -1 ; i > 0; i--) {
		//0か1かを表示
		cout << ((x >> (i -1)) & 1U ? '1' : '0');
		//1の時その位の2のべき乗を加算
		if((x >> (i - 1)) & 1U){
			x2 += nPower2(i - 1);
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
