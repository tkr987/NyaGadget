#include <bits/stdc++.h>

namespace NyaGadget
{
	/***区間内要素数の数え上げライブラリ***/

	/**
	@bfief 区間要素数を取得する関数
	@param begin 検索範囲(最小値)
	@param end 検索範囲(最大値)
	@param l 検索区間(最小値)
	@param r 検索区間(最大値)
	@note
		vectorにおける検索区間内の要素数を返す。
	**/
	template <class T> static long long ElementCountingOfRange
	(typename vector<T>::iterator begin, typename vector<T>::iterator end, const T& l, const T& r)
	{
		auto itl = lower_bound(begin, end, l);
		auto itr = upper_bound(begin, end, r);

		return (itr == end) ? --itr - itl + 1 : itr - itl;
	}

	/**
	@bfief 区間要素数を取得する関数
	@param begin 検索範囲(最小値)
	@param end 検索範囲(最大値)
	@param l 検索区間(最小値)
	@param r 検索区間(最大値)
	@param Compare 比較関数
	@note
	 vectorにおける検索区間内の要素数を返す。
	 この関数は構造体のvectorなど複雑なデータ構造を処理するために用意された。
	**/
	template <class T> static long long ElemetCountingOfRange
	(typename vector<T>::iterator begin, typename vector<T>::iterator end, const T& l, const T& r, function<bool(const T&, const T&)> Compare)
	{
		auto itl = lower_bound(begin, end, l, Compare);
		auto itr = upper_bound(begin, end, r, Compare);

		return (itr == end) ? --itr - itl + 1 : itr - itl;
	}
}
