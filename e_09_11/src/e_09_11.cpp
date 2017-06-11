
#include<iostream>
#include"Que.h"
#include"ArrayQue.h"
#include"ListQue.h"

using namespace std;

//キューのタイプの列挙帯
enum QueType{ ArrayQUE, ListQUE };


//選択された種類のキューを作成する関数
template<class Type>
Que<Type>* generate_Que(QueType sw){
	//引数に受け取った値で分岐
	switch(sw) {
	//配列が選ばれたとき配列のキューを作成して返却
	case ArrayQUE: return new ArrayQue<Type>();
	//それ以外の時リストでのキューを作成して返却
	default :	return new ListQue<Type>();
	}
}



int main()
{
	//作成するキューのタイプを入力するための変数
	int type;

	do{
		//作成するキューの種類の入力を促す表示
		cout << "キューの種類（0…配列／1…リスト）：";
		//入力
		cin  >> type;
	//正当な値が入力されるまで繰り返す
	} while(type < 0 || type > 1);

	//入力されたキューのタイプのキューを作成する
	Que<int>*s = generate_Que<int>(static_cast<QueType>(type));

	//終了が入力されるまで繰り返す
	while(1) {
		//行うことを入力するための変数
		int menu;
		//何をするのか入力を促す表示
		cout << "(1)…プッシュ (2)…ポップ (0)…終了：";
		//キーボードから入力
		cin  >> menu;

		//終了が入力されたときはループから抜け出して終了
		if(menu == 0) {
			//
			break;
		}

		//入力された値によって分岐
		switch(menu) {
			//データを入力、表示するための変数
			int x;

		//追加したいデータの入力を促す
		case 1: cout << "データ：";
				//データを入力
				cin  >> x;
				try {
					//入力されたデータをプッシュする
					s->push(x);
				//プッシュに失敗したとき
				}catch(const Que<int>::Overflow&){
					cout << "オーバーフローしました。\n";

				}
				break;

		case 2: try{
					//ポップしたデータを代入
					x = s->pop();
					//ポップしたデータを表示
					cout << "ポップしたデータは" << x << "です。\n";
				//キューが空の時にポップしたとき
				}catch(const Que<int>::Empty&) {
					//スタックが空であることを表示
					cout << "スタックは空です。\n";
				}
				break;
		}
	}

	//main関数の返却値
	return 0;
}
