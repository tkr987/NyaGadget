#include <bits/stdc++.h>

namespace NyaGadget
{
	/***** 尺取り法ライブラリ *****/
 
	template <class T> struct TwoPointers
	{
		T sum = 0;
 
		bool OK(void)
		{	// 一致条件を書く
			return (sum <= 10);
		}
 
		long long Run(std::vector<T> v)
		{
			long long l = 0;
			long long r = 0;
			long long res = 0;
			while (l != (long long)v.size() || r != (long long)v.size())
			{	// 満たさない条件の間、右を飛ばす
				while (r < (long long)v.size() && !OK()) sum += v[r++];
				// 条件に一致、答えの処理
				if (OK()) ++res;
				// 左を動かす（条件に一致または末尾に到達するまで）
				sum -= v[l++];
			}
 
			return res;
		}
	};
}
