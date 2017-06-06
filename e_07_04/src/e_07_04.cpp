/* 演習07-04
 * ３次元クラスThreeDimensionalを抽象基底クラスとして定義してそれを継承するクラスを自由に作成
 * 作成日：６月６日
 * 作成者：成田修之
 */

#include"ThreeDimensional.h"
#include"ThreeDimensionalObject.h"
#include<iostream>
using namespace std;

int main()
{
	//三次元クラスのポインタの配列をそれぞれ生成した３次元派生クラスのオブジェクトを指すように生成
	ThreeDimensional* a[] = {
			new Cylinder(4,3),
			new Cube(5)
	};

	//配列の数だけ繰り返す
	for(unsigned int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
		//そのポインタが指すクラスの文字列表現を表示
		cout << a[i]->to_string() << "\n";
		//そのポインタが指すクラスの体積を求める関数を使って体積を表示
		cout << "体積は："<< a[i]->get_volume() << "\n";
		//そのポインタが指すクラスの関数debugをつかってそのオブジェクトの情報を表示
		a[i]->debug();
		cout << "\n";
	}

	//各ポインタが指すオブジェクトの領域を解放
	for(unsigned int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
		delete a[i];
	}

	//main関数の返却値
	return 0;
}
