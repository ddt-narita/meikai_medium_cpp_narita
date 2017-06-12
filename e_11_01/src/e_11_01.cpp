/* 演習11-01
 * string型のテキストで学習してないメンバ関数を利用するプログラムの作成
 * 作成日：6月12日
 * 作成者：成田修之
 */

#include<string>
#include<iostream>

using namespace std;

int main()
{
	string str;		//文字列１
	string str2;	//文字列2
	string::size_type nNumber;		//文字列に対して個数にかかわるものの変数
	string::size_type position = 0;		//文字列に対して位置に関する変数

	//文字列1に入力を促す
	cout << "文字列1に入力してください：";
	cin >> str;

	//文字列の長さをメンバ関数lengthを用いて表示
	cout << "入力された文字列の長さは" << str.length() << "です。\n";
	//最大のサイズをメンバ関数max_sizeを用いて表示
	cout << "文字列の最大のサイズは" << str.max_size() << "です。\n";

	//文字列2に入力を促す
	cout << "文字列2に入力してください：";
	cin >> str2;

	//入力された文字列1に文字列2を代入する個数の入力を促す
	cout << "文字列1に文字列2を代入します。いくつ代入しますか：";
	cin >> nNumber;

	//メンバ関数assignを使って先頭から入力された個数分代入
	str.assign(str2, position, nNumber);

	//代入された文字列1を表示
	cout << "代入した文字列1を表示します。：";
	cout << str << "\n";

	//文字列2に再度入力を促す
	cout << "文字列2に入力してください：";
	cin >> str2;

	//文字列1に挿入する位置の入力をうながす
	cout << "文字列1に文字列2を挿入します。文字列1のどこから挿入しますか：";
	cin >> position;
	//入力する個数を表示
	cout << "何文字挿入しますか：";
	cin >> nNumber;

	//メンバ関数insertを用いて文字列1に文字列2を挿入
	str.insert(position,str2,0,nNumber);

	//挿入後の文字列1を表示
	cout << "挿入された文字列1を表示します。：";
	cout << str << "\n";

	//文字列1から削除する位置の入力を促す
	cout << "文字列1から文字を削除します。どこから削除しますか。：";
	cin >> position;

	//何個削除するのか入力を促す
	cout << "何個削除しますか：";
	cin >> nNumber;

	//メンバ関数を用いて文字列1の入力された位置から入力された個数削除
	str.erase(position,nNumber);

	//削除した後の文字列1の表示
	cout << "削除した後の文字列1を表示します。:";
	cout << str << "\n";

	//文字列1から探したい文字列の入力を促す
	cout << "文字列1から探したい文字列を入力してください：";
	cin >> str2;

	//メンバ関数を用いて文字列1中の文字列2が現れる一番先頭の要素の番号を表示
	cout << "文字列" << str2 << "が現れる先頭は" << str.find_first_of(str2) << "番目、\n";
	//メンバ関数を用いて末尾の要素番号を表示
	cout << "末尾は" << str.find_last_of(str2) << "番目です\n";

	//main関数の返却値
	return 0;

}
