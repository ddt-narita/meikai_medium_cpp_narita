/* 演習10-02
 * 関数テンプレートprint_vectorを変更
 * 作成日：6月11日
 * 作成者：成田修之
 */

#include<iostream>
#include<vector>
#include<string>

using namespace std;

//ベクトルの全要素を表示する関数
template <class T, class Allocator>
void print_vector(const vector<T, Allocator>& v)
{
	//始まりのかっこを表示
	cout << "{";
	//ベクトルの大きさより一つ小さい（最後の要素の手前）まで繰り返す
	for(typename vector<T,Allocator>::size_type i = 0; i < v.size() - 1; i++) {
		//各要素を表示してカンマと空白を表示
		cout << v[i] << ", ";
	}
	//最後の要素については要素と締めのかっこのみ表示
	cout << v[v.size() - 1] << "}";
}


int main()
{
	//ベクトルを作るためのint型の配列を作成
	int nArray[] = {1,2,3,4,5};
	//上の配列でベクトルを作成
	vector<int> intVector(nArray,nArray + sizeof(nArray) / sizeof(nArray[0]));

	//ベクトルの表示
	cout << "intVector = ";
	//関数print_vectorを呼び出してベクトルの全要素を表示
	print_vector(intVector);

	//main関数の返却値
	return 0;

}
