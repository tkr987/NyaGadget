#include <bits/stdc++.h>

namespace NyaGadget
{
	/***** 数列列挙ライブラリ *****/

	struct NT_NyaaNumberEnumeration
	{
		std::vector<long long> test;

		/**
		@brief 数列列挙の実行
		@param range 各桁の数値範囲
		@param maxSize 最大の桁数
		@param res 条件を満たす数列集合を格納する
		@note
		 DFSで各桁が[range.first, range.second]を満たすsize桁の数列を全て列挙する。
		**/
		void Run(std::pair<long long, long long> range, long long size, std::vector<std::vector<long long>>& res)
		{
			if ((long long)test.size() == size)
			{
				res.push_back(test);
				return;
			}

			for (long long i = range.first; i <= range.second; ++i)
			{	// pop_backは必須
				test.push_back(i);
				Run(range, size, res);
				test.pop_back();
			}
		}
	};
}
