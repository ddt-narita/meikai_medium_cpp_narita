/* 演習09-01
 * クラスTwinのchar型に特殊化した挿入子を作成
 * 作成日：6月7日
 * 作成者：成田修之
 */

#include<iostream>
#include<string>
#include"e_09_01.h"

using namespace std;

//
template<> inline std::ostream& operator<<(std::ostream& os, const Twin<std::string>& st)
{
	return os << "[\"" << st.first() << "\",\"" << st.second() << "\"]";
}

//
template<> inline std::ostream& operator<<(std::ostream& os, const Twin<char>& chr)
{
	return os << "['" << chr.first() << "','" << chr.second() << "']";
}

//
template <class Type> bool operator<(const Twin<Type>& a, const Twin<Type>& b)
{
	//
	int nReturn;
	//
	if(a.first() < b.first()) {
		nReturn = 1;
	//
	} else if (!(b.first() < a.first()) && a.second() < b.second()) {
		nReturn = 1;
	//
	} else {
		nReturn = 0;
	}

	return nReturn;
}


int main()
{
	//charでのTwin型のオブジェクトを作成
	Twin<Twin<char> > t1(Twin<char>('a','g'), Twin<char>('T','k'));
	//t1の値を表示
	cout << "t1 = " << t1 << "\n";

	//int型でのTwin型オブジェクトを作成
	Twin<Twin<int> >t2(Twin<int>(36,57),Twin<int>(43,78));
	//t2の値を表示
	cout << "t2 = " << t2 << "\n";

	//それぞれに入力して変更することを明示
	cout << "t1の値を変更します。\n";

	//第一値の第一値に入力
	cout << "新しい第一値の第一値：";
	cin  >> t1.first().first();

	//第一値の第二値に入力
	cout << "新しい第一値の第二値：";
	cin  >> t1.first().second();

	//第二値の第一値に入力
	cout << "新しい第二値の第一値：";
	cin  >> t1.second().first();

	//第二値の第二値に入力
	cout << "新しい第二値の第二値：";
	cin  >> t1.second().second();

	//昇順になっていないとき
	if(!t1.ascending()) {
		//関数sortを呼び出して昇順になるようにソートする
		cout << "第一値＜第二値が成立しませんのでソートします。\n";
		t1.sort();
	}

	//変更後の値を表示する
	cout << "t1は" << t1 << "に変更されました。\n";

	//main関数の返却値
	return 0;
}
