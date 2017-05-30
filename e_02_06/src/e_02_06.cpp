/* 演習02-06
 * 3つの型変換を確認できるプログラムの作成
 * 作成日：5月30日
 * 作成者：成田修之
 */

#include<iostream>
#include<limits>
using namespace std;


//各型の数値のビット表示をする関数テンプレート
template <class Type> void print_bits(Type x) {
	//int型の長さ
	int len = numeric_limits<Type>::digits;

	//長さ分繰り返してシフトしたときの位を表示
	for(int i = len - 1; i >= 0; i--) {
		cout << ((x >> i) & 1U ? '1' : '0');
	}
}


int main()
{
	int sInt = -25;					//signed型
	unsigned uInt =25;				//unsigned型
	char sChr = -86;				//signed char型
	unsigned char uChr = 43;		//unsigned char型

	//signed型について初期値を表示
	cout << "signed型：" << sInt << "\n";
	print_bits(sInt);
	cout << "\n";
	//unsigned型について初期値を表示
	cout << "unsigned型：" << uInt << "\n";
	print_bits(uInt);
	cout << "\n";

	//unsigned型にsigned型を代入した際の型変換を確認
	uInt = sInt;
	cout << "unsigned型にsigned型を代入した値：" << uInt << "\n";
	print_bits(uInt);
	cout << "\n";

	//signed char型の初期値を表示
	cout << "signed char型：" << sChr << "\n";
	print_bits(sChr);
	cout << "\n";

	//unsigned型にsigned char型を代入した際の型変換を確認
	uInt = sChr;
	cout << "unsigned型にsigned char型を代入した値：" << uInt << "\n";
	print_bits(uInt);
	cout << "\n";

	//unsigned型にchar signed型を代入した際の型変換を確認
	uChr = sInt;
	cout << "unsigned char型にsigned型を代入した値：" << uChr << "\n";
	print_bits(uChr);
	cout << "\n";

	//main関数の返却値
	return 0;

}
