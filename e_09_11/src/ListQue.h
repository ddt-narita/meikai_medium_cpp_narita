/* 演習09-11
 * テキストを参考にキュークラス群の作成
 * 作成日：6月9日
 * 作成者：成田修之
 */

#ifndef ___Class_ListQue
#define ___Class_ListQue

#include"Que.h"
#include<exception>
#include<new>


//線形リストでのキュークラス
template <class Type> class ListQue :public Que<Type>
{
	//リストキューのデータのノードクラステンプレート
	template<class Type1> class Node {
		//リストキュークラスのフレンドクラスであることを宣言
		friend class ListQue<Type>;
		//ノードのデータを指すポインタ型データ
		Type* data;
		//次のノードへのポインタ型データ
		Node* next;
	public:
		//コンストラクタ
		Node(Type* d, Node* n):data(d), next(n) {

		}
	};

	//先頭ノードへのポインタ
	Node<Type>* top;
	//ダミーノードへのポインタ
	Node<Type>* dummy;

public:
	//コンストラクタ
	ListQue(){
		//先頭とダミーのポインタにノードオブジェクトを動的に確保する。
		top = dummy = new Node<Type>(NULL,NULL);
	}

	//デストラクタ
	~ListQue() {
		//先頭へのポインタで初期化
		Node<Type>* ptr = top;
		//ダミーと一致するまで（全要素分）繰り返す
		while(ptr!= dummy) {
			//次のノードへのポインタをコピー
			Node<Type>* next = ptr->next;
			//そのポインタが指すデータに確保していた領域を解放
			delete ptr->data;
			//ポインタのさす領域（先頭）を解放
			delete ptr;
			//次のノードへのポインタを代入
			ptr = next;
		}
		//ダミーノードに確保していた領域を解放
		delete dummy;
	}

	//プッシュする関数
	void push(const Type& x) {
		//先頭ノードへのポインタでコピー
		Node<Type>* ptr = top;
		try{
			//引数で受け取った型のノード型オブジェクトを先頭に追加
			top = new Node<Type>(new Type(x), ptr);

		//動的な確保に失敗したとき
		} catch (const std::bad_alloc&) {
			//オーバーフロークラスを送出
			throw Que<char>::Overflow();
		}
	}

	//ポップする関数
	Type pop() {
		//空の時にポップしようとしたとき
		if(top == dummy) {
			//例外クラスオブジェクトを送出
			throw Que<char>::Empty();
		//空ではないとき
		} else {
			//要素数を数えるためのポインタ
			Node<Type>** ptr1 = &top;
			//先頭を指すポインタのポインタ
			Node<Type>** ptr2 = &top;

			//要素数を数えるための変数
			int i;
			//ポインタがナルを指すまで繰り返す
			for(i = 0; *ptr1 != NULL; i++) {
				//次のノードを指すポインタのアドレスを代入
				ptr1 = &((*ptr1)->next);
			}

			//ダミーの２つ手前、先頭の１つ手前まで繰り返す
			for(int j = 0; j < i - 2; j++) {
				//次のノードを指すポインタのアドレスを代入
				ptr2 = &((*ptr2)->next);
			}

			//ptr2のさすポインタ（先頭を指すポインタ）のデータのさす要素を避難
			Type temp = *((*ptr2)->data);
			//先頭のノードを解放
			delete[](*ptr2);
			//先頭の一つ手前のポインタがダミーを指すようにする
			*ptr2 = dummy;
			//避難していたデータのさす要素を返却
			return temp;
		}
	}
};

#endif
