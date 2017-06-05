/* 演習04-04 メイン部
 * クラスresigningMemberへのポインタからクラスMemberへのポインタへのアップキャスト
 * が行えるかどうかプログラムを作成して確認
 * 作成日：6月2日
 * 作成者：成田修之
 */

#include<iostream>
#include"e_04_04_ResigningMember.h"

using namespace std;

int main()
{
	ResigningMember oda("織田信子",31,48.7);

	Member* ptr = &oda;

	cout << "番号：" << ptr->no() << "\n";
	cout << "氏名：" << ptr->name() << "\n";
	cout << "体重：" << ptr->get_weight() << "\n";
	ptr->set_weight(45.3);
}

/* クラスResigningMemberは基底クラスのMemberからのprivate派生なのでアップキャスト
 * が出来なかった
 */

