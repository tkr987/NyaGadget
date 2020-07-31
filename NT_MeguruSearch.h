#include <bits/stdc++.h>
using namespace std;

namespace NyaGadget
{
	/*** めぐる式二分探索ライブラリ ***/

	struct MeguruSearchResult
	{	// 二分探索の結果を格納する
		long long ok_min = 0;    // okとなる最小値
		long long ok_max = 0;    // okとなる最大値
		long long ok_count = 0;	 // okとなる要素個数
	};

	struct NT_MeguruSeach
	{

		bool IsOK(long long mid, long long key)
		{	// 問題毎に新しく定義する
			return mid <= key;
		}

		/*
		@brief 二分探索関数
		@param rmin 探索範囲最小値
		@param rmax 探索範囲最大値
		@param key okとなる境界値
		@param res 結果を格納する構造体
		@note
		 rmin < rmax になるように探索範囲を指定すること。
		*/
		void Run(long long rmin, long long rmax, long long key, MeguruSearchResult& res)
		{	// 半開区間 (ng, ok] or [ok, ng) で処理する
			long long ng, ok;
			if (IsOK(rmin, key) && IsOK(rmax, key)) { res = { rmin, rmax, rmax - rmin + 1 }; return; }
			else if (IsOK(rmin, key) && !IsOK(rmax, key)) { ng = rmax + 1; ok = rmin; }
			else if (!IsOK(rmin, key) && IsOK(rmax, key)) { ng = rmin - 1; ok = rmax; }
			else { res = { 0, 0, 0 }; return; }

			while (1 < abs(ok - ng))
			{	// okとngのどちらが大きいかわからないことを考慮して絶対値を取る
				long long mid = (ok + ng) / 2;
				if (IsOK(mid, key)) ok = mid;
				else ng = mid;
			}

			if (ng < ok) res = { ng + 1, ok, abs(ok - ng) };
			else         res = { ok, ng - 1, abs(ok - ng) };
		}
	};
}
