#include <bits/stdc++.h>

namespace NyaGadget
{
	/***** ワーシャルフロイド法ライブラリ *****/
	struct GT_WarshallFloyd
	{
		/**
		@brief 全点対間最短路を求める
		@param mg 隣接行列
		@param res 最短距離を返す
		@param inf 存在しない辺の値
		@note
		計算量O(V^3)なので隣接行列にしか適用できない。
		負の閉路がある場合falseを返す。
		**/
		static bool Run(std::vector<std::vector<long long>>& mg, std::vector<std::vector<long long>>& res, long long inf = LLONG_MAX)
		{
			long long vmax = (long long)mg.size();
			for (auto i = 0LL; i < vmax; ++i) mg[i][i] = 0;

			res = mg;
			for (auto k = 0LL; k < vmax; k++)
			{
				for (auto i = 0LL; i < vmax; i++)
				{
					if (res[i][k] == inf) continue;
					for (auto j = 0LL; j < vmax; j++)
					{
						if (res[k][j] == inf) continue;
						res[i][j] = std::min(res[i][j], res[i][k] + res[k][j]);
					}
				}
			}
			for (auto i = 0LL; i < vmax; i++)
			{
				if (res[i][i] < 0) return false;
				res[i][i] = inf;
			}
			return true;
		}
	};
}