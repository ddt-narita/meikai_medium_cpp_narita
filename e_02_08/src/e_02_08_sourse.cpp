/* 演習02-08 ソース部
 * 要素数をビット数に制限されず、加減上限を任意に設定できるビットベクトルによる集合クラスの作成
 * 作成日：5月30日
 * 作成者：成田修之
 */

#include<string>
#include<sstream>
#include<iostream>
#include"e_02_08.h"

using namespace std;

//
string BitSet::to_string() const {
	ostringstream s;							//出力ストリーム
	int* set = new int[ max - min + 1];		//最大の要素数分の配列
	int count = 0;			//要素数をカウントする変数

	//各要素に対して繰り返す
	for(int i = 0; i < bitsNumber; i++) {
		//ビットごとに走査
		for(int j = 0; j < LONG_BIT; j++) {
			//要素があるときはカウントしてその時の要素の値を格納
			if(bits[i] & set_of(j)) {
				set[count++] = j + (LONG_BIT * i) + min;
			}
		}
	}


	s << "{";
	//要素があるとき
	if(count){
		//要素分繰り返してその要素と「,」を出力ストリームに乗せる
		for(int i = 0; i < count - 1; i++) {
			s << set[i] << ",";
		}
		s << set[count - 1];
	}
	s << "}";
	return s.str();
}

//ビットベクトルの文字列表現に直す関数
string BitSet::bit_string() const {
	//文字列オブジェクト
	string s;
	//要素分の領域確保
	char** bp = new char*[bitsNumber];
	//要素分繰り返す
	for(int i = 0; i < bitsNumber; i++) {
		//各要素にビット数分確保
		bp[i] = new char[LONG_BIT + 1];
		//各要素があるかどうか01で格納
		for(int j = LONG_BIT - 1; j >= 0; j--) {
			bp[i][LONG_BIT - j - 1] = (set_of(j) & bits[i]) ? '1' : '0';
		}
	}
	//要素分繰り返す
	for(int i = 0; i < bitsNumber; i++) {
		//ビット数分繰り返して各文字を文字列オブジェクトに加算
		for(int j = 0; j < LONG_BIT; j++) {
			s += bp[i][j];
		}
		//要素ごとの終わりに改行
		s += "\n     ";
	}
	//最後にナル文字
	s += '\0';

	return s;
}

//挿入子の多重定義
ostream& operator<< (ostream& os, const BitSet& x){
	return os << x.to_string();
}
