/* 演習12-03
 * list12-07のプログラムに御置ける現在の日付時刻の取得を第一章で作成したクラス
 * Dateを利用して行うように変更したプログラムの作成
 * 作成日：6月12日
 * 作成者：成田修之
 */

#include<fstream>
#include<iostream>
#include<ctime>
#include"Date.h"

using namespace std;

//ファイル名
char fname[] = "lasttime.txt";

//前回の情報の取得、表示する関数
void get_data()
{
	//入力ファイルストリームでオープン
	ifstream fis(fname);

	//オープンに失敗したとき
	if(fis.fail()) {
		//プログラムを初めて実行することを表示
		cout << "本プログラムを実行するのは初めてですね。\n";
	//成功したとき
	}else {
		//情報の取得に使う変数
		int year,month,day,h,m,s;

		//ファイルから情報を取得して入力
		fis >> year >> month >> day >> h >> m >> s;
		//前回の情報を表示
		cout << "前回は" << year<< "年" << month << "月" << day << "日" << " "
				<< h << "時" << m << "分" << s << "秒でした。\n";
	}
}

//関数を呼び出した時の日付時刻を書き込む関数
void put_data()
{
	//出力ストリームでファイルをオープン
	ofstream fos(fname);

	//オープンに失敗したとき
	if(fos.fail()){
		//オープンできないことを表示
		cout << "ファイルをオープンできません。\n";
	//成功したとき
	} else {
		//現在の時刻で初期化
		time_t t = time(NULL);
		//ローカルタイムの入った構造体を作成
		struct tm* local = localtime(&t);
		//日付オブジェクトの作成
		Date date1;
		//日付と現在時刻を出力ストリームに出力して書き込み
		fos << date1 << " " << local->tm_hour << " " << local->tm_min << " " << local->tm_sec << "\n";
	}

}



int main()
{
	//関数get_dataでファイルから情報を取得表示する
	get_data();

	//関数put_dataで現在の日付と時刻をファイルに書き込み
	put_data();

	//main関数の返却値
	return 0;
}
