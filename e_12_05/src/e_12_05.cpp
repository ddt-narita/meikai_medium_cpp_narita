/* 演習12-05
 * 要素型がdouble型で要素数が10である配列の全要素の値を読み書きするプログラムの作成
 * 作成日：6月13日
 * 作成者：成田修之
 */

#include<iostream>
#include<fstream>
#include<iomanip>

using namespace std;

int main()
{
	//配列の要素数
	const int nArrayNumber = 10;
	//ファイルへの読み書きに使う変数
	double dblArray[nArrayNumber];

	//配列への入力を促す
	cout << "double型配列の各要素に数値を入力してください\n";

	//要素数分繰り返す
	for(int i = 0; i < nArrayNumber; i++) {
		//どの要素に入力するかを表示
		cout << "dblArray[" << i << "] = ";
		//各要素に入力
		cin >> dblArray[i];
	}

	//出力ストリームでファイル"dblArray.binをバイナリモードでオープンする"
	ofstream fos("dblArray.bin",ios_base::binary);
	//オープンに失敗したとき
	if(!fos) {
		//オープンできなかったことを表示
		cout << "ファイルをオープンできません\n";
	//成功したとき
	}else {
		//要素分繰り返す
		for(int i = 0; i < nArrayNumber; i++){
			//関数writeを使ってファイルに配列の各要素を書き込む
			fos.write(reinterpret_cast<char*>(&dblArray[i]),sizeof(double));
		}
		//明示的にファイルを閉じてストリームとの接続を切る
		fos.close();
	}

	//入力ストリームでファイルdblArray.binをバイナリモードでオープンする
	ifstream fis("dblArray.bin",ios_base::binary);
	//オープンに失敗したとき
	if(!fis) {
		//オープンできなかったことを表示
		cout << "ファイルをオープンできません\n";
	//成功したとき
	} else {
		//要素数分繰り返す
		for(int i = 0; i < nArrayNumber; i++) {
			//関数readを使って各要素をファイルに書き込む
			fis.read(reinterpret_cast<char*>(&dblArray[i]),sizeof(double));
			//各要素を固定小数点、精度20で表示する
			cout << "dblArray[" << i <<"]の値は" << fixed << setprecision(20) << dblArray[i] << "です。\n";
		}
		//ファイルを明示的にクローズする
		fis.close();
	}

	//main関数の返却値
	return 0;

}
