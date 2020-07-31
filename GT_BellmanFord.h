#include <bits/stdc++.h>
using namespace std;

namespace NyaGadget
{
	/***** ベルマンフォード法ライブラリ *****/

	struct BellmanFordEdge
	{
		long long from = 0;
		long long to = 0;
		long long cost = 0;
	};

	struct GT_BellmanFord
	{
		/**
		@brief 実行関数
		@param s 処理開始頂点
		@param wlg 重み付き隣接リスト
		@param res 結果を格納する構造体
		@param inf 存在しない辺を表現する値
		@return 正常に処理できればtrue, 負の閉路が存在するときはfalse
		@note
		 計算量O(EV)
		**/
		bool Run
		(long long s, const vector<vector<pair<long long, long long>>>& wlg, vector<long long>& res, long long inf = LLONG_MAX)
		{
			vector<BellmanFordEdge> edge;
			for (long long from = 0; from < (long long)wlg.size(); from++)
			{
				for (auto& e : wlg[from]) edge.push_back({ from, e.f, e.s });
			}
			res.resize((long long)wlg.size(), LLONG_MAX);
			res[s] = 0;
			for (long long i = 0; i < (long long)wlg.size(); i++)
			{
				bool update = false;
				for (auto& e : edge)
				{	// 更新処理
					if (res[e.from] != inf && res[e.from] + e.cost < res[e.to])
					{
						res[e.to] = res[e.from] + e.cost;
						update = true;
					}
				}
				if (!update) break;
				if (i == (long long)wlg.size() - 1 && update) return false;
			}

			return true;
		}
	};
}