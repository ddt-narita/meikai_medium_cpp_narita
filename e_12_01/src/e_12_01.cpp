/* 演習12-01
 * list12-02のファイルのオープンに成功したかどうかをほかの書き方で実現
 * 作成日：6月12日
 * 作成者：成田修之
 */

#include<string>
#include<fstream>
#include<iostream>


using namespace std;

//ファイルが存在するかどうか判定する関数
bool file_exist1(const char* filename)
{
	//引数で受け取ったファイル名のファイル入力ストリームとしてオープン
	ifstream fis(filename);
	//ちゃんとオープンされたかどうかを判定して返却
	return !fis.fail();
}

//ファイルが存在するかどうか判定する関数
bool file_exist2(const char*filename)
{
	//引数で受け取ったファイル名のファイル入力ストリームとしてオープン
	ifstream fis2(filename);
	//ちゃんとオープンしているか判定して返却
	return static_cast<bool>(fis2);
}

int main()
{
	//ファイル名の入力に用いる変数
	string file_name;
	//確認したいファイル名を入力
	cout << "存在を確認したいファイルの名前：";
	cin  >> file_name;

	//ファイルが存在するかどうか関数file_exist1を呼び出して判定
	cout << "そのファイルは存在"
			<< (file_exist1(file_name.c_str()) ? "します。\n" : "しません。\n");

	//確認したいファイル名を入力
	cout << "存在を確認したいファイルの名前：";
	cin  >> file_name;

	//関数file_exist2を呼び出してファイルが存在するかどうか判定
	cout << "そのファイルは存在"
			<< (file_exist2(file_name.c_str()) ? "します。\n" : "しません。\n");

	//main関数の返却値
	return 0;
}
