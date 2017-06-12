/* 演習10-06
 * <functional>で提供される算術演算のファンクタとtransformアルゴリズムを
 * 組み合わせたプログラムの作成
 * 作成日：6月12日
 * 作成者：成田修之
 */

#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<functional>

using namespace std;

//要素を表示する関数
template<class Type>
struct put1 :public unary_function<const Type&,void> {
	//要素の後にスペースを一つ開けて表示
	void operator()(const Type&n) {
		cout << n << " ";
	}
};

//関数テンプレートput1のchar型に明示的に特殊化
template<>
struct put1<char> :public unary_function<const char&, void> {
	//要素を単一引用符で囲んでスペース
	void operator()(const char& n) {
		cout << "'" << n << "' ";
	}
};

//関数テンプレートput1をstring型に明示的に特殊化
template<>
struct put1<string>:public unary_function<const string&, void> {
	//要素を2重引用符で囲んでスペース
	void operator()(const string& n){
		cout << "\"" << n << "\"";
	}
};

//全要素を表示する関数
template<class InputIterator>
void print(InputIterator first, InputIterator last)
{
	cout << "{ ";
	//全要素にその方にあった関数put1を適用して表示
	for_each(first,last, put1<typename std::iterator_traits<InputIterator>::value_type>());
	cout << "}";
}


int main()
{

	const int nNumber = 10;
	//ベクトルオブジェクトの作成
	vector<int> a;
	//10回繰り返す
	for(vector<int>::size_type i = 1; i <= nNumber; i++) {
		//
		a.push_back(i);
	}

	//ベクトルオブジェクトaで初期化したbを作成
	vector<int> b(a);
	//関数rondom_shuffleでbをランダムにシャッフルする
	random_shuffle(b.begin(),b.end());

	//aとbの和を格納するベクトルオブジェクトを作成
	vector<int> c(nNumber);
	//transformアルゴリズムをつかってaとbの和をcに格納
	transform(a.begin(), a.end(), b.begin(), c.begin(), plus<int>());

	//aからbの差を格納するベクトルオブジェクトを作成
	vector<int> d(nNumber);
	//transformアルゴリズムをつかってaとbの差をdに格納
	transform(a.begin(), a.end(), b.begin(), d.begin(), minus<int>());

	//aとbの積を格納するベクトルオブジェクトを作成
	vector<int> e(nNumber);
	//transformアルゴリズムをつかってaとbの積をeに格納
	transform(a.begin(), a.end(), b.begin(), e.begin(), multiplies<int>());

	//aからbの商を格納するベクトルオブジェクトを作成
	vector<int> f(nNumber);
	//transformアルゴリズムをつかってaとbの商をfに格納
	transform(a.begin(), a.end(), b.begin(), f.begin(), divides<double>());

	//aからbの剰余を格納するベクトルオブジェクトを作成
	vector<int> g(nNumber);
	//transformアルゴリズムをつかってaとbの剰余をgに格納
	transform(a.begin(), a.end(), b.begin(), g.begin(), modulus<int>());

	//もととなるaの表示
	cout << "a = ";
	//関数printを用いてaを表示
	print(a.begin(),a.end());
	cout << "\n";

	//aをランダムにしたbの表示
	cout << "b = ";
	//関数printを用いてbを表示
	print(b.begin(),b.end());
	cout << "\n";

	//和を表示
	cout << "c = ";
	//関数printを用いてcを表示
	print(c.begin(),c.end());
	cout << "\n";

	//差を表示
	cout << "d = ";
	//関数printを用いてdを表示
	print(d.begin(),d.end());
	cout << "\n";

	//積を表示
	cout << "e = ";
	//関数printを用いてeを表示
	print(e.begin(),e.end());
	cout << "\n";

	//商を表示
	cout << "f = ";
	//関数printを用いてfを表示
	print(f.begin(),f.end());
	cout << "\n";

	//剰余を表示
	cout << "g = ";
	//関数printを用いてgを表示
	print(g.begin(),g.end());
	cout << "\n";

	//main関数の返却値
	return 0;
}


