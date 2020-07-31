#include <bits/stdc++.h>
using namespace std;

namespace NyaGadget
{
	/*** 二分探索ライブラリ ***/

	template <class T> struct BinarySearchResult
	{
		T b;              // 先頭アドレス
		long long i = 0;  // インデックス 
		long long v = 0;  // 値
		long long cl = 0; // 条件を満たさない要素数(iと同じ)
		long long cr = 0; // 条件を満たす要素数
		BinarySearchResult<T> operator++()
		{
			if (cr != 1)
			{
				i++;
				v = *(b + i);
				cl++;
				cr--;
			}
			return *this;
		}
		BinarySearchResult<T> operator++(int)
		{
			BinarySearchResult res = *this;
			++(*this);
			return res;
		}
		BinarySearchResult<T> operator--()
		{
			if (i != 0)
			{
				i--;
				v = *(b + i);
				cl--;
				cr++;
			}
			return *this;
		}
		BinarySearchResult<T> operator--(int)
		{
			BinarySearchResult res = *this;
			--(*this);
			return res;
		}
	};

	/**
	@brief 値x以上となる最初の要素を取得する関数
	@param b 検索する範囲開始位置
	@param e 検索する範囲終端位置
	@param x 検索する値
	**/
	template <class T1, class T2>
	BinarySearchResult<T1> LowerBound(T1 b, T1 e, T2 x)
	{
		auto it = lower_bound(b, e, x);
		if (it == e) it--;
		return { b, it - b, *it, it - b , e - it };
	}

	/**
	@brief 値xより大きい最初の要素を取得する関数
	@param b 検索する範囲開始位置
	@param e 検索する範囲終端位置
	@param x 検索する値
	**/
	template <class T1, class T2>
	BinarySearchResult<T1> UpperBound(T1 b, T1 e, T2 x)
	{
		auto it = upper_bound(b, e, x);
		if (it == e) it--;
		return { b, it - b, *it, it - b, e - it };
	}

	/*** BinarySearchResult 演算子 ***/
	template <class T>
	const BinarySearchResult<T> operator+(const BinarySearchResult<T>& l, long long r)
	{
		if (l.i + r < 0) r = l.i;
		if (l.cr - 1 < r) r = l.cr - 1;
		return { l.b, l.i + r, *(l.b + l.i + r), l.cl + r, l.cr - r };
	}
	template <class T>
	const BinarySearchResult<T> operator-(const BinarySearchResult<T>& l, long long r)
	{
		if (l.i - r < 0) r = l.i;
		if (l.cr - 1 < -r) r = -(l.cr - 1);
		return { l.b, l.i - r, *(l.b + l.i - r), l.cl - r, l.cr + r };
	}
	template <class T>
	void operator+=(BinarySearchResult<T>& l, long long r)
	{
		if (l.i + r < 0) r = l.i;
		if (l.cr - 1 < r) r = l.cr - 1;
		l = { l.b, l.i + r, *(l.b + l.i + r), l.cl + r, l.cr -= r };
	}
	template <class T>
	void operator-=(BinarySearchResult<T>& l, long long r)
	{
		if (l.i - r < 0) r = l.i;
		if (l.cr - 1 < -r) r = -(l.cr - 1);
		l = { l.b, l.i - r, *(l.b + l.i - r), l.cl - r, l.cr + r };
	}
}
