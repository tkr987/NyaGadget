#include <bits/stdc++.h>

namespace NyaGadget
{
	/***** DFSライブラリ *****/

	struct GT_NyaaDFS
	{
		/**
		@brief DFS処理関数
		@param r 頂点vの根
		@param v 現在の頂点
		@param g 隣接リストか隣接行列
		@param res 処理結果
		**/
		void Run(long long r, long long v, const std::vector<std::vector<long long>>& g, std::vector<long long>& res)
		{
			for (auto e : g[v])
			{	// 後戻りしないようにする
				if (e == r) continue;
				if (res[v] != 0) res[v]++;
				Run(v, e, g, res);
			}
		}
	};
}
