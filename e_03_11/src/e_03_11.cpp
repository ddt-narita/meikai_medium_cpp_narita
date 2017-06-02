/* 演習03-11
 * list03-17の関数quicksortを利用するプログラム
 * 作成日：6月1日
 * 作成者：成田修之
 */

#include<iostream>
#include<cstdlib>
#include<cstring>
#include<ctime>
using namespace std;

//quicksort関数で使う比較関数
int compar(const int* a,const int* b) {
	return *a < *b ? -1 : *a > *b ? 1 : 0;
}

//内部結合をもつ名前なし名前空間
namespace {
	//二つの要素を入れ替える関数
	void memswap(void* x,void* y,size_t n)
	{
		//1バイト単位で処理するためunsigned char*型へキャスト
		unsigned char* a = reinterpret_cast<unsigned char*>(x);
		unsigned char* b = reinterpret_cast<unsigned char*>(y);
		//その型の大きさ（バイト数）分繰り返して要素を交換
		for( ; n--; a++, b++) {
			unsigned char c = *a;
			*a = *b;
			*b = c;
		}
	}
}


void quicksort(void* base, size_t nmemb, size_t size, int(*compar)(const void*, const void*))
{
	if(nmemb > 0) {
		//1バイトで処理するためにconst char*型へキャスト
		const char* v = reinterpret_cast<const char*>(base);
		size_t pl = 0;				//先頭の添え字
		size_t pr = nmemb - 1;		//末尾の添え字
		size_t pv = nmemb;			//枢軸の添字
		size_t pt = (pl + pr) / 2;	//枢軸を更新するための変数

		do {
			//枢軸を指すポインタ
			const char* x;
			//枢軸が更新値と一致しない時更新
			if(pv != pt) {
				x = &v[(pv = pt) * size];
			}
			//枢軸より小さい値の限り右へスライド
			while(compar(reinterpret_cast<const void*>(&v[pl * size]),x) < 0) {
				pl++;
			}
			//枢軸より大きい値の限り左へスライド
			while(compar(reinterpret_cast<const void*>(&v[pr * size]),x) > 0) {
				pr--;
			}
			//先頭が末尾を超えない時
			if(pl <= pr) {
				//枢軸と先頭末端のどちらかが一致したとき交換が起こるので交換先に更新
				pt = (pl == pv) ? pr : (pr == pv) ? pl : pv;
				//関数memswapを使って先頭の指す値と末尾の指す値を交換
				memswap(const_cast<void*>(reinterpret_cast<const void*>(&v[pl * size])),
						const_cast<void*>(reinterpret_cast<const void*>(&v[pr * size])),
								size);
				//先頭を右へスライド
				pl++;
				//末尾が0以下になることを避ける
				if(pr == 0) {
					//スライドする前に0ならループを抜ける
					break;
				}
				//0より大きければ末尾を左へスライド
				pr--;
			}
		//先頭と末尾が交わらない限り繰り返す
		}while(pl <= pr);

		//枢軸を基準にソートした後末尾が0より大きい値を指す時
		if(0 < pr) {
			//枢軸より小さいものに関してquicksortで再起呼び出ししてソート
			quicksort(const_cast<void*>(reinterpret_cast<const void*>(&v[0])),
					pl + 1, size, compar);
		}

		//枢軸を基準にソートした後先頭が右端より小さい値を指すとき
		if(pl < nmemb - 1) {
			//枢軸より大きいものに関してquicksortで再起呼び出してソート
			quicksort(const_cast<void*>(reinterpret_cast<const void*>(&v[pl * size])),
					nmemb - pl, size, compar);
		}
	}
}


int main()
{
	srand(time(NULL));			//ランダムな値を生成する種を設定
	int nArrayNumber;			//要素数を入力する変数
	//要素数の入力
	cout << "配列の要素数：";
	cin  >> nArrayNumber;
	int i = 0;					//カウントに使う変数

	//入力された要素数分領域を確保
	int* nArray = new int[nArrayNumber];
	//入力された要素数分繰り返す
	for(i = 0; i < nArrayNumber; i++) {
		//各要素にランダムな値を代入
		nArray[i] = rand() % 100;
	}

	//入力された要素数分繰り返す
	for(int i = 0; i < nArrayNumber; i++) {
		//各要素を表示
		cout << nArray[i] <<"\n";
	}

	//関数quicksortを使って入力された要素を昇順にソートする
	quicksort(reinterpret_cast<void*>(nArray), nArrayNumber,sizeof(int),
			reinterpret_cast<int (*)(const void*, const void*)>(compar));

	//ソートが完了したことを表示
	cout << "ソートしました。\n";
	//要素数分繰り返す
	for(int i = 0; i < nArrayNumber; i++) {
		//ソートされていることを各要素を表示して確認
		cout << nArray[i] << "\n";
	}

	//main関数の返却値
	return 0;
}
