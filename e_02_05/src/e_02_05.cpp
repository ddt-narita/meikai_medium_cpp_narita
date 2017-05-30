/* 演習02-05
 * 符号なし整数xの全ビットを1と0であらわした文字列を作成しその文字列の先頭文字を返却する関数
 * 作成日：5月30日
 * 作成者：成田修之
 */

#include<iostream>
#include<limits>
using namespace std;

const char* bits_of(unsigned x) {
	int len = numeric_limits<unsigned int>::digits;	//int型の長さ
	static char* chrPtr = new char[len + 1];			//長さ＋NULL文の領域を確保
	int j = 0;											//文字配列の添字に使う変数

	//長さ分繰り返してシフトしたときの位の値を配列に格納
	for(int i = len - 1; i >= 0; i--, j++) {
		//シフトした後1の時は1を格納
		if((x >> i) & 1U) {
			chrPtr[j] = '1';
		//シフト後0の時は0を格納
		} else {
			chrPtr[j] = '0';
		}
	}
	//最後をナル文字入力
	chrPtr[len] = 0;
	//先頭文字へのポインタを返却
	return chrPtr;
}


int main()
{
	unsigned a = 5;	//符号なし整数A
	unsigned b = 4;	//符号なし整数B

	//2つの符号なし整数に入力を促す
	cout << "非負の整数を2つ入力せよ。\n";
	//整数Aに入力
	cout << "整数A：";
	cin  >> a;
	//整数Bに入力
	cout << "整数B：";
	cin  >> b;

	cout << "a 		= " << bits_of(a)		<< "\n";	//符号なし整数Aの2進表記
	cout << "b 		= " << bits_of(b)	 	<< "\n";	//符号なし整数Bの2進表記
	cout << "a & b 	= " << bits_of(a & b)	<< "\n";	//AとBの論理積を表示
	cout << "a | b 	= " << bits_of(a | b)	<< "\n";	//AとBの論理和を表示
	cout << "a ^ b 	= " << bits_of(a ^ b)	<< "\n";	//AとBの排他的論理和を表示
	cout << "~a		= " << bits_of(~a)		<< "\n";	//Aの補数を表示
	cout << "~b		= " << bits_of(~b)		<< "\n";	//Bの補数を表示

	//main関数の返却値
	return 0;

}
