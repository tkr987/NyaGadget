#include <bits/stdc++.h>
using namespace std;

namespace NyaGadget
{
	/*** 区間スケジューリング処理ライブラリ ***/

	/**
	@brief 区間スケジューリング処理関数
	@param data 区間[a,b]の集合
	@param border 境界の扱い
	@note
	 閉区間[a,b]をpair<a,b>とする。
	 重複部分を持つ区間が存在したとき1つ残して消去する処理を
	 繰り返したときに残った区間数を返す。
	 border = trueなら境界が接するだけでも重複部分として処理する。
	 border = falseなら境界が接しているだけなら重複部分として処理しない。
	**/
	template <class T> long long RangeScheduling
	(vector<pair<T, T>>& data, bool border)
	{
		auto NyaSort = [](const pair<T, T>& l, const pair<T, T>& r)
		{	// 降順は演算子>, 昇順は演算子<, if順の優先でソートされる
			if (l.second != r.second) return l.second < r.second;
			return l.first < r.first;
		};
		sort(all(data), NyaSort);

		long long l = 0;
		long long res = 1;
		for (long long r = 1; r < (long long)data.size(); r++)
		{
			if (border)
			{
				if (data[l].second < data[r].first)
				{
					res++;
					l = r;
				}
			}
			else
			{
				if (data[l].second <= data[r].first)
				{
					res++;
					l = r;
				}
			}
		}

		return res;
	}
}
