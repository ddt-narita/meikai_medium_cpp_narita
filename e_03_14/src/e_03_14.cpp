/* 演習03-14
 * list3-13のクラスPerson型配列をqsort関数を使わずにクイックソート
 * アルゴリズムによってソートするプログラムの作成
 * 作成日：6月2日
 * 作成者：成田修之
 */


#include<iostream>
#include<iomanip>
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

class Person {
public:
	char name[10];	//名前のデータ
	int height;		//身長のデータ
	int weight;		//体重のデータ

	//体重を受け取った値でセットする関数
	void set_weight(int w) {
		weight = w;
	}

	//オブジェクトの名前データを表示する関数
	void nameReturn() {
		cout<< name;
	}
};

//関数strcmpを用いて二つの文字列を比較して返却された値を返却する関数
int npcmp(const Person* x, const Person* y) {
	return strcmp(x->name,y->name);
}

//関数quicksortで使う身長を比較する関数
int hpcmp(const Person* x, const Person* y) {
	return x->height < y->height ? -1 :
			x->height > y->height ? 1  : 0;
}

//関数quicksortで使う体重を比較する関数
int wpcmp(const Person* x, const Person* y) {
	return x->weight < y->weight ? 1  :
			x->weight > y->weight ? -1 : 0;
}

//クラスPersonの配列の各要素の名前、身長、体重を表示する関数
void print_person(const Person x[], int no)
{
	for(int i = 0; i < no; i++) {
		cout << setw(10) << left << x[i].name << " " << x[i].height << "cm "
				<< x[i].weight << "kg\n";
	}
}


int main()
{
	//クラスPersonの配列
	Person x[] = {{"Shibata",  170, 52},
				  {"Takaoka",  180, 70},
				  {"Nangoh",   172, 63},
				  {"Sugiyama", 165, 50}
	};

	//クラスの配列の要素数を求めて代入
	int nArrayNumber = sizeof(x) / sizeof(x[0]);

	//ソート前の並びを表示
	cout << "ソート前\n";
	print_person(x,nArrayNumber);

	//関数quicksortをnpcmpによって比較するように呼び出しソートする
	quicksort(x,nArrayNumber,sizeof(Person),
			reinterpret_cast<int(*)(const void*, const void*)>(npcmp));

	//名前順にソートした後の並びを表示
	cout << "\n名前昇順ソート後\n";
	print_person(x,nArrayNumber);

	//関数quicksortをhpcmpによって比較するように呼び出しソートする
	quicksort(x,nArrayNumber,sizeof(Person),
			reinterpret_cast<int(*)(const void*, const void*)>(hpcmp));

	//身長順にソートした後の並び順を表示
	cout << "\n身長昇順ソート後\n";
	print_person(x,nArrayNumber);

	//柴田さんの体重を南郷さんより多くしてソートがきちんと行われていることを確認
	cout << "2番目の";
	//2番目の人に対して名前を表示する関数を用いて名前を表示
	x[1].nameReturn();
	cout << "さんの体重を65キロに太ったとして体重降順にソートします。";
	//上でソートされた配列の2番目の人の体重を65キロにセットする
	x[1].set_weight(65);

	//関数quicksortをwpcmpによって比較するように呼び出しソートする
	quicksort(x,nArrayNumber,sizeof(Person),
			reinterpret_cast<int(*)(const void*, const void*)>(wpcmp));

	//体重を降順にソートした後の並び順を表示
	cout << "\n体重降順ソート後\n";
	print_person(x,nArrayNumber);

	//main関数
	return 0;
}
