/* 演習03-02
 * 指定された条件を満たす要素を配列から線形探索する関数search_ifの作成
 * 作成日：5月31日
 * 作成者：成田修之
 */

#include<iostream>
#include<ctime>
#include<cstdlib>

using namespace std;

//15から30の間かどうかを返却
bool erea15to30 (int n) {
	return n >= 15 && n <= 30;
}

//5で割り切れるかを返却
bool divisible5(int n) {
	return n % 5 == 0 ? 1 : 0;
}

//条件を満たす先頭の要素の添字を返却する関数
int search_if(const int a[], int n, bool cond(int n)) {
	//先頭の添字
	int nHed;
	//要素数分繰り返す
	for(int i = 0; i < n; i++) {
		//引数の関数を呼び出して真の時
		if(cond(a[i])){
			//その時の添字で代入して
			nHed = i;
			//ループを抜ける
			break;
		}
	}
	return nHed;
}


int main()
{
	srand(time(NULL));			//ランダムな値を生成する種を設定
	int nArrayNumber = 16;		//要素数

	//要素数を入力
	cout << "要素数：";
	cin  >> nArrayNumber;

	//入力された要素数分の配列を確保
	int* nArray = new int[nArrayNumber];

	//要素数分繰り返してランダムな値を代入し表示
	for(int i = 0; i < nArrayNumber; i++) {
		nArray[i] = rand() % 50;
		cout << nArray[i] << " ";
	}
	//最後に改行
	cout << "\n";


	//条件15以上30未満となる関数を呼ぶようにsearch_ifを呼び出して先頭の要素が何番目か表示
	cout << "15以上30以下となる最初の要素は" << search_if(nArray,nArrayNumber,erea15to30) + 1 << "個目です。\n";
	//条件5で割り切れる関数を呼ぶようにsearch_ifを呼び出して先頭の要素が何番目か表示
	cout << "5で割り切れる最初の要素は" << search_if(nArray,nArrayNumber,divisible5) + 1 << "個目です。\n";

	//

}
