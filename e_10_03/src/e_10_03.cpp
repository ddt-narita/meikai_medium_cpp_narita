/* 演習10-03
 * 日付クラスDateや、Twin<>の2次配列を作成するプログラムの作成
 * 作成日：6月11日
 * 作成者：成田修之
 */

#include<iostream>
#include<vector>
#include"Date.h"
#include"Twin.h"

using namespace std;

int main()
{
	//通常の2次元配列
	cout << "ベクトルによる日付の2次元配列\n";
	//行数と列数を入力するための変数
	int row,column;
	//行数の入力を促す
	cout << "行数：";
	cin >> row;
	//列数の入力を促す
	cout << "列数：";
	cin >> column;

	//入力された行数列数で日付クラスの2次元配列を作成
	vector<vector<Date> > arrayVector(row, vector<Date>(column));

	//行数分繰り返す
	for(int i = 0; i < row; i++) {
		//列数分繰り返す
		for(int j = 0; j < column; j++) {
			//各要素の日付を表示
			cout << "arrayVector[" << i << "][" << j << "] = " << arrayVector[i][j] << "\n";
		}
	}

	//凹凸2次元配列についてであることを表示
	cout << "\nベクトルによる日付の凹凸2次元配列\n";

	//行数に入力を促す
	cout << "行数：";
	cin >> row;

	//日付クラスの2次元配列を生成
	vector<vector<Date> > vectorOutotu;

	//行数分繰り返す
	for(int i = 0; i < row; i++) {
		//各行の列数を入力するための変数
		int width;
		//その行の列数を入力を促す
		cout << i << "行目の列数：";
		//その行の列数を入力
		cin  >> width;
		//入力された列数分の日付クラスの配列をその行に追加
		vectorOutotu.push_back(vector<Date>(width));
	}

	//行数分繰り返す
	for(int i = 0; i < row; i++) {
		//各行の列数分繰り返す
		for(unsigned int j = 0; j < vectorOutotu[i].size(); j++) {
			//各要素の日付を表示
			cout << "vectorOutotu[" << i << "][" << j << "] = " << vectorOutotu[i][j] << "\n";
		}
	}


	//通常の2次元配列
	cout << "\nベクトルによるTwin<>の2次元配列\n";
	//行数と列数を入力するための変数

	//行数の入力を促す
	cout << "行数：";
	cin >> row;
	//列数の入力を促す
	cout << "列数：";
	cin >> column;

	//入力された行数列数でTwin<>の2次元配列を作成
	vector<vector<Twin<int> > > twinVector(row, vector<Twin<int> >(column));

	//行数分繰り返す
	for(int i = 0; i < row; i++) {
		//列数分繰り返す
		for(int j = 0; j < column; j++) {
			//各要素のTwin<>を表示
			cout << "arrayVector[" << i << "][" << j << "] = " << twinVector[i][j] << "\n";
		}
	}

	//凹凸2次元配列についてであることを表示
	cout << "\nベクトルによるTwin<>の凹凸2次元配列\n";

	//行数に入力を促す
	cout << "行数：";
	cin >> row;

	//Twin<>の2次元配列を生成
	vector<vector<Twin<int> > > twinOutotu;

	//行数分繰り返す
	for(int i = 0; i < row; i++) {
		//各行の列数を入力するための変数
		int width;
		//その行の列数を入力を促す
		cout << i << "行目の列数：";
		//その行の列数を入力
		cin  >> width;
		//入力された列数分Twin<>の配列をその行に追加
		twinOutotu.push_back(vector<Twin<int> >(width));
	}

	//行数分繰り返す
	for(int i = 0; i < row; i++) {
		//各行の列数分繰り返す
		for(unsigned int j = 0; j < twinOutotu[i].size(); j++) {
			//各要素のTwin<>を表示
			cout << "twinOutotu[" << i << "][" << j << "] = " << twinOutotu[i][j] << "\n";
		}
	}

	//main関数の返却値
	return 0;

}
