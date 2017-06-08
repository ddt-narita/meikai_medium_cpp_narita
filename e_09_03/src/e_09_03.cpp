/* 演習09-03
 * Twin<Twin<Date>,Twin<Date> >を要素として持つArray<>クラステンプレートオブジェクト
 * を生成して利用するプログラムの作成
 * 作成日：6月7日
 * 作成者：成田修之
 */

#include<new>
#include<iostream>
#include"Date.h"
#include"Array.h"
#include"Twin.h"

using namespace std;

int main()
{
	//配列の要素数
	const int nNumber = 3;
	//Array<Twin<Twin<Date> > >型の配列を要素数nNumber個で作成
	Array<Twin<Twin<Date> > > x(nNumber);

	//要素数分繰り返す
	for(int i = 0; i < nNumber; i++) {
		//各要素に代入するTwin<Twin<Date>>オブジェクトを作成する
		Twin<Twin<Date> >date(Twin<Date>(Date(1990 + i,1 + i,1 + i),Date(2000 + i, 2 + i, 5 + i)),
				Twin<Date>(Date(1800+ i,3 + i,20 + i),Date(1700 + i,8 + i,15 + i)));
		//作ったオブジェクトをArray<Twin<Twin<Date>>>オブジェクトの各要素に代入
		x[i] = date;
	}

	//要素数分繰り返す
	for(int i = 0; i < nNumber; i++) {
		//各要素を表示する
		cout << "x[" << i << "] = " << x[i] << "\n";
	}

	//main関数の返却値
	return 0;
}
