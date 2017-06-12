/* 演習11-03
 * コマンドラインから与えられた文字列のソートや、シャッフルを行うプログラムの作成
 * 作成日：6月12日
 * 作成者：成田修之
 */

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<functional>

using namespace std;

//ポインタの配列からベクトルに変換する関数
vector<string> strptary_to_vec(char** p, int n)
{
	//返却に使う一時ベクトルオブジェクト
	vector<string> temp;
	//引数で受け取った要素数分繰り返す
	for(int i = 0; i < n; i++) {
		//一時ベクトルオブジェクトの末端に要素を追加
		temp.push_back(p[i]);
	}
	//出来た一時ベクトルオブジェクトを返却
	return temp;
}


//コマンドラインからの文字列の要素数と文字列へのポインタの配列の先頭ポインタを
//引数として受けったmain関数
int main(int argc,char** argv)
{
	//関数strptaryを使ってコマンドラインから受け取った文字列配列のベクトルを作成
	vector<string> sa = strptary_to_vec(argv,argc);
	//作ったベクトルで文字列をシャッフル
	random_shuffle(sa.begin(), sa.end());
	//シャッフルしたことを明示
	cout << "シャッフルしました。\n";
	//要素数分繰り返す
	for(vector<string>::size_type i = 0; i < sa.size(); i++) {
		//各要素を表示
		cout << "sa[" << i << "] = " << sa[i] << "\n";
	}

	//関数sortを使って文字列のベクトルをソート
	sort(sa.begin(),sa.end());
	//ソートしたことを明示
	cout << "ソートしました。\n";
	//要素数分繰り返す
	for(vector<string>::size_type i = 0; i < sa.size(); i++) {
		//各要素を表示
		cout << "sa[" << i << "] = " << sa[i] << "\n";
	}

	//main関数の返却値
	return 0;
}
