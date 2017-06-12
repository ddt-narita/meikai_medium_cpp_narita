/* 演習12-04
 * list12－7のプログラムに現在の気分おw表す文字列を追加したプログラムの作成
 * 作成日：6月12日
 * 作成者：成田修之
 */

#include<fstream>
#include<iostream>
#include<ctime>


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
		//気分の情報を取得する変数
		string fine;

		//ファイルから情報を取得して入力
		fis >> year >> month >> day >> h >> m >> s >> fine;
		//前回の情報を表示
		cout << "前回は" << year<< "年" << month << "月" << day << "日" << " "
				<< h << "時" << m << "分" << s << "秒で、気分は"<< fine << "でした。\n";
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
		//気分を入力するための変数
		string fine;

		//日付と現在時刻を出力ストリームに出力して書き込み
		fos << local->tm_year + 1900 << " " << local->tm_mon + 1 << " " << local->tm_mday << " "
				<< local->tm_hour << " " << local->tm_min << " " << local->tm_sec << "\n";
		//気分の入力を促す
		cout << "現在の気分は：";
		cin  >> fine;
		//入力された気分を出力ストリームに出力して書き込む
		fos << fine;
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
