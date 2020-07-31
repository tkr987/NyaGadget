#include <bits/stdc++.h>
#include <boost/range/adaptors.hpp>

using namespace std;
using ll = long long;
using ld = long double;

namespace NyaGadget
{
	/*** 二分探索ライブラリ ***/

	struct BinarySearchResult
	{	// 二分探索の結果を格納する
		ll ok_min = 0;		// okとなる最小値
		ll ok_max = 0;		// okとなる最大値
		ll ok_count = 0;	// okの個数
	};

	struct BinarySearchSample
	{	// 二分探索に最低限必要な変数
		// 他に変数が必要なときは新しく構造体を定義すること。
		ll key;		// 二分探索の比較値
		ll mid;	    // 二分探索の中間値
	};

	bool BinarySearchTest(BinarySearchSample& bsv)
	{	// これはテスト用関数なので、新しく定義すること。
		// なお、戻り値がbool型、引数がBinarySearch用の構造体である必要がある。
		return bsv.mid < bsv.key;
	}

	/*
	@brief 二分探索関数
	@param rmin 探索範囲最小値
	@param rmax 探索範囲最大値
	@param value 二分探索に必要な変数
	@param IsOK 二分探索の比較関数
	@param res 結果を格納する構造体
	@note
	 rmin < rmax になるように探索範囲を指定すること。
	 value はBinarySearchSampleを拡張した構造体を定義してテンプレート引数から指定する。
	 IsOK()はvalueと同じ型の変数を引数から受け取り、それを比較や計算に利用する関数とする。
	 IsOK()は通常、okとなる比較結果をbool値で返す。
	 探索結果は、okとなる範囲がresに格納される。
	 ただし、okとなる値が存在しないときはok_countが0になる。
	*/
	template <class T> void
	BinarySeach(ll rmin, ll rmax, T& value, function<bool(T&)> IsOK, BinarySearchResult& res)
	{	// ngやokがrmax+2のままだったときは特殊なテストケースになる
		ll ng = rmax + 2;
		ll ok = rmax + 2;

		// まず、okとngがrminとrmaxどちらか調べる
		// なお、rminやrmax自体が条件を満たすこともあるので、初期値を-1、+1する
		value.mid = rmin;
		if (IsOK(value))
			ok = rmin - 1;
		else
			ng = rmin - 1;
		value.mid = rmax;
		if (IsOK(value))
			ok = rmax + 1;
		else
			ng = rmax + 1;

		// 条件を満たす値が1つも存在しない
		if (ok == rmax + 2)
			return;
		if (ng == rmax + 2)
		{	// 探索範囲全ての値が条件を満たす
			res = { rmin, rmax, rmax - rmin + 1 };
			return;
		}

		while (1 < abs(ok - ng))
		{	// okとngのどちらが大きいかわからないことを考慮して絶対値を取る
			value.mid = (ok + ng) / 2;

			if (IsOK(value))
				ok = value.mid;
			else
				ng = value.mid;
		}

		res.ok_min = min(res.ok_min, ok);
		res.ok_max = max(res.ok_max, ok);
		res.ok_count = res.ok_max - res.ok_min + 1;
	}
}