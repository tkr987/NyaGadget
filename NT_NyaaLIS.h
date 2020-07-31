#include <bits/stdc++.h>

namespace NyaGadget
{
	/***** 最長増加部分列ライブラリ *****/

	struct NT_NyaaLIS
	{
		/**
		@note
		eq = false のとき狭義最長増加部分列
		つまり res[i] < res[i+1] となるような最長増加部分列の長さを得る。
		eq = true のとき広義最長増加部分列
		つまり res[i] <= res[i+1] となるような最長増加部分列の長さを得る。
		**/
		static long long Run(const std::vector<long long>& v, bool eq = false)
		{
			std::vector<long long> test;
			if (!eq)
			{
				for (auto i = 0LL; i < (long long)v.size(); ++i)
				{
					auto it = std::lower_bound(test.begin(), test.end(), v[i]);
					if (it == test.end()) test.push_back(v[i]);
					else *it = v[i];
				}
			}
			else
			{
				for (auto i = 0LL; i < (long long)v.size(); ++i)
				{
					auto it = std::upper_bound(test.begin(), test.end(), v[i]);
					if (it == test.end()) test.push_back(v[i]);
					else *it = v[i];
				}
			}
			return (long long)test.size();
		}
	};
}