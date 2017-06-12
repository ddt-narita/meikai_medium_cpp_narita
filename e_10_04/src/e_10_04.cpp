/* 演習10-04
 * list10-17を様々な型を表示するように変更
 * 作成日：6月12日
 * 作成者：成田修之
 */

#include<vector>
#include<iostream>

using namespace std;

//ベクトルの全要素を表示する関数テンプレート
template<class InputIterator>
void print(InputIterator first,InputIterator last) {
	//ベクトルの要素をカッコ内で表示
	cout << "{";
	//反復子を先頭から初めて最後まで繰り返す
	for(InputIterator i = first; i != last; i++) {
		//各要素を表示
		cout << *i << " ";
	}
	cout << "}";
}


int main()
{
	//int型の配列
	int a[] = {1,2,3,4,5};
	//上の配列でベクトルオブジェクトの作成
	vector<int> x(a, a+5);
	//double型の配列
	double b[] = {2.4, 54.4, 5.4, 8.1, 3.5};
	//上の配列でベクトルオブジェクトを作成
	vector<double> y(b, b + 5);
	//string型の配列
	string c[] = {"abc", "ABC", "1234"};
	//上の配列でベクトルオブジェクトを作成
	vector<string> z(c, c + 3);

	//int型の配列で作ったベクトルの全要素を表示
	cout << "a = ";
	//関数printの呼び出し
	print(x.begin(), x.end());
	cout << "\n";
	//double型の配列で作ったベクトルの全要素を表示
	cout << "b = ";
	//関数printの呼び出し
	print(y.begin(), y.end());
	cout << "\n";
	//string型の配列で作ったベクトルの全要素を表示
	cout << "c = ";
	//関数printの呼び出し
	print(z.begin(), z.end());
	cout << "\n";

	//main関数の返却値
	return 0;
}
