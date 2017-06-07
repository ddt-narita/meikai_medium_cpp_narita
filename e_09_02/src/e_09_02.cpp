/* 演習09-02
 * Date型のTwin<>とDate型Twin<>のTwin<>を作るプログラムの作成
 * 作成日：6月7日
 * 作成者：成田修之
 */

#include<iostream>
#include"Date.h"
#include"Twin.h"

using namespace std;

//クラスDateについての挿入子の多重定義
template<> inline std::ostream& operator<<(std::ostream& os, const Twin<Date>& date)
{
	return os << "(" << date.first() << "," << date.second() << ")";
}


int main()
{
	//Date型Twin<>のオブジェクトを作成
	Twin<Date> date1(Date(1993,3,2),Date(2003,11,29));

	//作ったDate型Twin<>のオブジェクトを表示
	cout << "date1 = " << date1 << "\n";

	//Date型Twin<>のTwin<>のオブジェクトを作成
	Twin<Twin<Date> > date2(Twin<Date>(Date(1993,1,5),Date(2017,6,7)),Twin<Date>(Date(1993,5,4),Date(2000,8,2)));

	//作ったDate型Twin<>のTwin<>のオブジェクトを表示
	cout << "date2 = " << date2 << "\n";

	//main関数の返却値
	return 0;
}
