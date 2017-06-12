/* 演習12_02
 * list12-02の関数file_existでオープンするストリームをifstream型からofstream型に
 * 書き換えてオープンしたファイルの内容が全部消去あs列ことを確認する
 * 作成日：6月12日
 * 作成者：成田修之
 */


#include<string>
#include<fstream>
#include<iostream>

using namespace std;

//ファイルが存在するかどうか判定する関数
bool file_exist1(const char*filename)
{
	//引数で受け取ったファイル名のファイル入力ストリームとしてオープン
	ofstream fis2(filename);

	//ちゃんとオープンしているか判定して返却
	return static_cast<bool>(fis2);
}

int main()
{
	//ファイル名の入力に用いる変数
	string file_name;
	//確認したいファイル名を入力
	cout << "中身を空にしたいファイルの名前：";
	cin  >> file_name;

	//ファイルが存在するかどうか関数file_exist1を呼び出して判定
	cout << "そのファイルは存在"
			<< (file_exist1(file_name.c_str()) ? "します。\n" : "しません。\n");


	//main関数の返却値
	return 0;
}

//プログラムを実行した後ファイルに書き込んだ内容がすべて消去されていたのを確認した
