#include <bits/stdc++.h>

namespace NyaGadget
{
	/***** 重複区間を結合して最大化するライブラリ *****/

	/**
	@brief 重複区間を結合する関数
	@note
	 [v.first, v.second]の区間集合vを入力する。
	 重複区間を最大限結合し、入力と同じ形式で出力する。
	 borderをfalseにすると境界が接してるだけの区間は重複無しとして扱う。
	**/
	void DS_NyaaRangeUnion
	(std::vector<std::pair<long long, long long>>& v, std::vector<std::pair<long long, long long>>& res, bool border = true)
	{
		sort(v.begin(), v.end());
		long long begin = v[0].first;
		long long end = v[0].second;
		if (border)
		{
			for (long long i = 1; i < (long long)v.size(); i++)
			{
				if (end < v[i].first)
				{
					res.push_back({ begin, end });
					begin = v[i].first;
					end = v[i].second;
				}
				else
				{
					if (end < v[i].second) end = v[i].second;
				}
			}
		}
		else
		{
			for (long long i = 1; i < (long long)v.size(); i++)
			{
				if (end <= v[i].first)
				{
					res.push_back({ begin, end });
					begin = v[i].first;
					end = v[i].second;
				}
				else
				{
					if (end < v[i].second) end = v[i].second;
				}
			}
		}
		res.push_back({ begin, end });
	}
}
