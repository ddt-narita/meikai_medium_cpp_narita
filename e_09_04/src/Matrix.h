
#ifndef ___ClassTemplate_Matrix
#define ___ClassTemplate_Matrix

template <class Type> class Matrix {
	int row;			//行の要素数
	int column;			//列の要素数
	Type** ptr;		//先頭要素へのポインタ



public:
	//添え字が正当な範囲か調べる関数
	bool is_valid_row_index(int idx) {
		return idx >= 0 && idx < row;
	}

	//添え字が正当な範囲か調べる関数
	bool is_valid_column_index(int idx) {
		return idx >= 0 && idx < column;
	}

	//添え字の例外クラス
	class IdxRngErr {
		const Matrix* ident;	//例外を出した要素へのポインタ
		int idx;				//その要素の添え字
	public:
		//コンストラクタ
		IdxRngErr(const Matrix* p, int i):ident(p), idx(i) {

		}
		//添え字を返却する関数
		int Index()const {
			return idx;
		}
	};

	//コンストラクタ
	explicit Matrix(int r,int c, const Type& v = Type()) :row(r),column(c) {

		//行数分の配列を確保
		ptr = new Type*[row];
		//行数分繰り返す
		for(int i = 0; i < row; i++) {
			//行ごとに列数分の領域を確保
			ptr[i] = new Type[column];
		}

		//行数分繰り返す
		for(int i = 0; i < row; i++) {
			//列数分繰り返す
			for(int j = 0; j < column; j++) {
				//各要素を受け取った方で初期化
				ptr[i][j] = v;
			}
		}
	}

	//コピーコンストラクタ
	Matrix(const Matrix<Type>& x) {
		//自身ではないとき
		if(&x == this) {
			row = 0;		//行数に0代入
			column = 0;		//列数に0代入
			ptr = 0;		//ポインタにNULLを代入
		//
		} else {
			row = x.row;			//行数をコピー
			column = x.column;		//列数をコピー
			ptr = new Type*[row];	//行数分の領域を確保

			//行数分繰り返す
			for(int i = 0; i < row; i++) {
				//各行に列数分の領域を確保
				ptr[i] = new Type[column];
			}

			//行数分繰り返す
			for(int i = 0; i < row; i++) {
				//列数分繰り返す
				for(int j = 0; j < column; j++) {
					//各要素をコピー
					ptr[i][j] = x.ptr[i][j];
				}
			}
		}
	}

	//デストラクタ
	~Matrix() {
		//行数分繰り返す
		for(int i = 0; i < row; i++) {
			//行ごとに確保してる列の領域を解放
			delete[]ptr[i];
		}
		//列数分のポインタの領域を確保
		delete[]ptr;
	}

	//行数を返却する関数
	int size_row() const {
		return row;
	}

	//列数を返却する関数
	int size_column() const {
		return column;
	}

	//添え字演算子
	Type*& operator[](int i) {
		//正当な値ではないの時
		if(!is_valid_row_index(i)) {
			//添え字例外クラスを送出
			throw IdxRngErr(this,i);
		}
		//正当ならそのままの要素を返却
		return ptr[i];
	}



};

#endif
