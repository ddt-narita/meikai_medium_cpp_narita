/* 演習02-08 メイン部
 * 要素数をビット数に制限されず、加減上限を任意に設定できるビットベクトルによる集合クラスの作成
 * 作成日：5月30日
 * 作成者：成田修之
 */

#include<iostream>
#include"e_02_08.h"

using namespace std;

int main()
{
	int min = 4;	//最小値
	int max = 7;	//最大値
	int diff;		//差
	int nRemove;	//除去する要素

	//最大値最小値の入力
	cout << "最小値：";
	cin >> min;
	cout << "最大値：";
	cin >> max;

	//差を求める
	diff = max - min + 1;

	//差分の要素の配列を作成
	int* nArray = new int[diff];

	//各要素を最小値から順に代入
	for(int i = 0; i < diff; i++) {
		nArray[i] = i + min;
	}
	//オブジェクトb1を生成
	BitSet b1(min,max,nArray,diff);

	//最小値、最大値を入力
	cout << "最小値：";
	cin >> min;
	cout << "最大値：";
	cin >> max;

	//差を求める
	diff = max - min + 1;
	//差分の要素の配列を生成
	int* nArray2 = new int[diff];

	//全要素を最小値から順に代入
	for(int i = 0; i < diff; i++) {
		nArray2[i] = i + min;
	}
	//オブジェクトb2を生成
	BitSet b2(min,max,nArray2,diff);

	//b2について表示
	cout << "b1 = " << b1 << "\n";
	cout << "     " << b1.bit_string() << "\n";

	//b2について表示
	cout << "b2 = " << b2 << "\n";
	cout << "     " << b2.bit_string() << "\n";

	//消したい要素を入力し削除して表示
	cout << "b1の消去したい集合の要素を入力してください：";
	cin >> nRemove;
	b1.remove(nRemove);
	cout << "b1 = " << b1 << "\n";
	cout << "     " << b1.bit_string() << "\n";

	//空集合かどうかの判定
	cout << "b2は空集合で" << (b2.empty() ? "す\n" : "はありません\n");

	//要素数を求める
	cout << "b2の要素数は" << b2.size() << "個です。\n";

	//main関数の返却値
	return 0;

}
