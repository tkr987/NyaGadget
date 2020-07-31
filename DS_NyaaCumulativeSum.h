#include <bits/stdc++.h>

namespace NyaGadget
{
	/***** 累積和ライブラリ *****/

	template <class T> struct DS_NyaaCumulativeSum
	{
		std::vector<T> sum;
		DS_NyaaCumulativeSum(std::vector<T>& v)
		{
			if (v.empty()) sum.push_back(0);
			else sum.push_back(v.front());
			for (long long i = 1; i < (long long)v.size(); ++i) sum.push_back(sum.back() + v[i]);
		}
		/**
		@brief 範囲の合計値を取得する
		@note
		 閉区間[s, t)の合計値を返す。
		 範囲外のsやtに対しては0を返す。
		**/
		T Range(long long s, long long t)
		{
			if (s < 0) s = 0;
			if ((long long)sum.size() < t) t = (long long)sum.size();
			// 戻り値の計算
			if (t <= 0 || (long long)sum.size() <= s) return 0;
			return (s == 0) ? sum[t - 1] : sum[t - 1] - sum[s - 1];
		}
	};
}
