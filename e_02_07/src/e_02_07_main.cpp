/* 演習02-07
 * ビットベクトルによる集合クラスに各メンバ関数を追加
 * 作成日：5月30日
 * 作成者：成田修之
 */

#include<iostream>
#include"e_02_07.h"

using namespace std;

int main()
{
	//要素数を入力するための変数
	int nNumber;

	int LONG_BIT = numeric_limits<unsigned long>::digits;

	//要素数を入力
	cout << "配列の要素数：";
	cin >> nNumber;
	//入力された要素数で領域を確保
	int* a1 = new int[nNumber];
	//すべての要素に入力
	for(int i = 0; i < nNumber; i++) {
		do {
			cout << "a1[" << i << "] = ";
			cin >> a1[i];
		}while(a1[i] > LONG_BIT);

	}
	//入力された配列と要素数でオブジェクト生成
	BitSet b1(a1, nNumber);

	//要素数の入力
	cout << "配列の要素数：";
	cin >> nNumber;
	//入力された要素数で領域確保
	int* a2 = new int [nNumber];
	//各要素に入力
	for(int i = 0; i < nNumber; i++) {
		do{
			cout << "a2[" << i << "] = ";
			cin >> a2[i];
		}while(a2[i] > LONG_BIT);

	}
	//入力された配列と要素数でオブジェクトを生成
	BitSet b2(a2, nNumber);

	//それぞれの要素の最小最大を求める
	cout << "1個目の最小の要素：";
	cout << b1.min() << "\n";
	cout << "2個目の最大の要素：";
	cout << b2.max() << "\n";

	//2つの配列を入れ替えて表示
	b1.swap(b2);
	cout << "要素を入れ替えました\n";
	cout << b1 << "\n";
	cout << b2 << "\n";

	//もう一度入れ替えて元通りにする
	swap(b1,b2);
	cout << "戻しました\n";
	cout << b1 << "\n";
	cout << b2 << "\n";

	//各演算子を適用して結果を表示
	cout << "対象差集合\n";
	cout << symmetric_defference(b1,b2) << "\n";
	cout << "積集合\n";
	cout << (b1 & b2) << "\n";
	cout << "和集合\n";
	cout << (b1 | b2) << "\n";
	cout << "差集合\n";
	cout << (b1 ^ b2) << "\n";

	//集合が部分集合化どうかを表示
	cout << "b2はb1の部分集合" 		<< (b2.is_subset_of(b1) 			? "です\n" : "ではありません\n");
	cout << "b2はb1の真部分集合"	<< (b2.is_proper_subset_of(b1) 		? "です\n" : "ではありません\n");

	//全要素を消去して表示
	b1.clear();
	cout << "1個目の全要素を消去しました。b1：";
	cout << b1;

	//main関数の返却値
	return 0;
}

