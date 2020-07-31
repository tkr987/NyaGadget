#include <bits/stdc++.h>
using namespace std;

namespace NyaGadget
{
	/*** BITライブラリ ***/

	template<class T> struct DS_BinaryIndexedTree
	{
		vector<T> data;

		/**
		@param コンストラクタ
		@size 配列サイズ
		**/
		DS_BinaryIndexedTree(long long size)
		{
			data.assign(size + 1, 0);
		}

		/**
		@param 区間合計取得関数
		@param l 区間左端インデックス
		@param r 区間右端インデックス
		@return 合計値
		@note
		 閉区間[l,r]の合計値を返す。
		 計算量O(logN)
		**/
		T Sum(long long l, long long r)
		{
			T lsum = 0; l--;
			for (++l; l > 0; l -= l & -l) lsum += data[l];
			T rsum = 0;
			for (++r; r > 0; r -= r & -r) rsum += data[r];
			return rsum - lsum;
		}

		/**
		@param 点加算関数
		@param i 加算するインデックス
		@param x 加算値
		@note
		 計算量O(logN)
		**/
		void Add(long long i, T x)
		{
			for (++i; i < data.size(); i += i & -i) data[i] += x;
		}
	};
}
