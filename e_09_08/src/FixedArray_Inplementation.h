/* 演習09-08
 * 9章2節のクラステンプレートArray<>、Array<bool>、FixedArray<>を
 * インクルードモデルで実現
 * 作成日：6月8日
 * 作成者：成田修之
 */


	template<class Type,int N>
	FixedArray<Type,N>::FixedArray(const FixedArray& x) {
		if(&x != this) {
			for(int i = 0; i < N; i++) {
				vec[i] = x.vec[i];
			}
		}
	}

	template<class Type,int N>
	int FixedArray<Type,N>::size() const{
		return N;
	}

	template<class Type,int N>
	FixedArray<Type,N>& FixedArray<Type,N>::operator=(const FixedArray& x) {
		for(int i = 0; i < N; i++) {
			vec[i] = x.vec[i];
		}
		return *this;
	}

	template<class Type,int N>
	Type& FixedArray<Type,N>::operator[](int i) {
		if(i < 0 || i >= N) {
			throw IdxRngErr(this,i);
		}
		return vec[i];
	}


	template<class Type,int N>
	const Type& FixedArray<Type,N>::operator[](int i)const {
		if(i < 0 || i >= N) {
			throw IdxRngErr(this,i);
		}
		return vec[i];
	}
