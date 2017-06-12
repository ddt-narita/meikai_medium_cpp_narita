/* 演習10-05
 * list10-17に関数呼び出しprint(x.rbegin(), x.rend())を追加するとどうなるか検証
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


	//int型の配列で作ったベクトルの全要素を表示
	cout << "a = ";
	//関数printの呼び出し
	print(x.begin(), x.end());
	cout << "\n";
	//逆進反復子で関数printを呼び出すことを明示
	cout << "逆進反復子で表示\n";
	//逆進反復子で関数printを呼び出し
	print(x.rbegin(),x.rend());
	cout << "\n";

	//main関数の返却値
	return 0;
}

/* 逆進反復子で関数printを呼び出すと末尾の要素から表示され、全身反復子で表示した
 * ときの真逆の順番で表示される
 */
