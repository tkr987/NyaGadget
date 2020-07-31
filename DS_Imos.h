#include <bits/stdc++.h>

namespace NyaGadget
{
	/***** いもす法ライブラリ *****/

	template <class T> struct DS_Imos
	{
		std::vector<T> test;
		/**
		@brief コンストラクタ
		@note
		 閉区間[0, N]に対して処理したいときはN+1のサイズを確保すること。
		**/
		DS_Imos(long long size) { test.resize(size); }
		/**
		@brief 加算関数
		@note
		 半開区間[l, r)に対して値addだけ加算する
		**/
		void Add(long long l, long long r, T add)
		{
			if (l < 0) return;
			test[l] += add;
			if ((long long)test.size() <= r) return;
			test[r] -= add;
		}
		/**
		@brief 実行関数
		@note
		 シミュレーションの実行をして結果をresに格納する
		**/
		void Run(vector<long long>& res)
		{
			long long maxSize = min(test.size(), res.size());
			for (long long i = 1; i < (long long)test.size(); ++i) test[i] += test[i - 1];
			for (long long i = 0; i < maxSize; ++i) res[i] += test[i];
		}
	};
}
