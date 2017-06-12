/* 演習11-02
 * 関数テンプレートput_string_vectorでの文字列操作を添え字演算子ではなく、
 * 反復子を用いて行うように書き換えたプログラムを作成
 * 作成日：6月12日
 * 作成者：成田修之
 */

#include<string>
#include<vector>
#include<iostream>

using namespace std;

//
template<typename Allocator>
void put_string_vector(const vector<string, Allocator>& v)
{
	//要素を表示する最初のかっこ
	cout << "{ ";
	//要素の初めから終わりまで繰り返す
	for(typename vector<string,Allocator>::const_iterator i = v.begin(); i != v.end();i++) {
		//反復子を用いてベクトルの要素stringを表示
		cout << "\"" << *i << "\" ";
	}
	cout << "}";
}


int main()
{
	//string型を要素型とする要素数3つのvectorオブジェクト
	vector<string> s1(3);
	//string型を要素型とするvectorオブジェクト
	vector<string> s2;
	//s2の末端に追加
	s2.push_back("ABC");
	//s2の末端に追加
	s2.push_back("123");
	//s2の末端に追加
	s2.push_back("XYZ");

	//s1を表示
	cout << "s1 = ";
	//関数put_string_vectorを使って全要素を表示
	put_string_vector(s1);
	cout << "\n";

	//s2を表示
	cout << "s2 = ";
	//関数put_string_vectorを使って全要素を表示
	put_string_vector(s2);
	cout << "\n";

	//main関数の返却値
	return 0;
}
