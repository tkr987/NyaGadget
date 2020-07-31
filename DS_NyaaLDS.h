#include <bits/stdc++.h>
using namespace std;

namespace NyaGadget
{
	/***** 最長減少部分列ライブラリ *****/

	template <class T> struct ResultLDS
	{
		vector<T> dsub;         // 最長減少部分列
		vector<vector<T>> isub; // 分解個数最小の増加部分列集合
	};

	/**
	@brief 最長減少部分列を返す関数
	@param v 入力数列
	@param res 出力
	@param eq false=狭義減少部分列, true=広義減少部分列
	@note
	 計算量O(NlogN)で最長減少部分列(LDS)が得られる。
	 内部的には配列vを分解個数が最小になるよう増加部分列集合に分解している。
	 よって、副産物として分解個数最小の増加部分列集合が得られる。
	 分解個数最小であり、最長増加部分列でないことに注意。
	 第三引数についてfalseにすると「狭義減少部分列」「分解個数最小の広義増加部分列集合」
	 trueにすると「広義減少部分列」「分解個数最小の狭義増加部分列集合」が得られる。
	**/
	template <class T> void DS_NyaaLDS
	(const vector<T>& v, ResultLDS<T>& res, bool eq = false)
	{	// Longest Decreasing Subsequence
		vt<ll> test(v.size() + 1, LLONG_MIN);
		if (eq)
		{	// 同値を含める、つまり広義減少部分列を得る
			for (auto& e : v)
			{
				auto it = --lower_bound(test.begin(), test.end(), e);
				if ((long long)res.isub.size() <= (long long)v.size() - std::distance(test.begin(), it))
					res.isub.resize(res.isub.size() + 1);
				res.isub[(long long)v.size() - std::distance(test.begin(), it)].push_back(e);
				*it = e;
			}
		}
		else
		{	// 同値を含めない、つまり狭義減少部分列を得る
			for (auto& e : v)
			{
				auto it = --upper_bound(test.begin(), test.end(), e);
				if ((long long)res.isub.size() <= (long long)v.size() - std::distance(test.begin(), it))
					res.isub.resize(res.isub.size() + 1);
				res.isub[(long long)v.size() - std::distance(test.begin(), it)].push_back(e);
				*it = e;
			}
		}
		for (auto& e : res.isub) res.dsub.push_back(e.front());
	}
}
