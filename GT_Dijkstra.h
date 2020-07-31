#include <bits/stdc++.h>
using namespace std;

namespace NyaGadget
{
	/*** ダイクストラ法ライブラリ ***/

	struct GT_Dijkstra
	{
		/**
		@brief 隣接行列の最短コストを求める
		@param s スタート地点
		@param mg 重みつき隣接行列
		@param res 結果を格納する構造体
		@note
		 計算量O((V+E)log(V))
		 重み付き隣接行列で存在しない辺コストはLLONG_MAXとする。
		 mg[f][t]=cは頂点fから頂点tの辺コストがcを表す
		**/
		void Run
		(long long s, vector<vector<long long>>& mg, vector<long long>& res)
		{
			long long INF = LLONG_MAX;
			long long N = (long long)mg.size(); // 頂点数
			int WHITE = 0; // 最短距離が確定してない
			int GRAY = 1;  // 最短距離が更新されたことを表す(処理には無関係)
			int BLACK = 2; // 最短距離確定

			vector<long long> d(N), color(N);
			// pair.first = cost, pair.second = v(to)
			priority_queue<pair<long long, long long>> PQ;
			for (long long i = 0; i < N; i++)
			{
				d[i] = INF;
				color[i] = WHITE;
			}

			d[s] = 0;
			color[s] = GRAY;
			PQ.push({ 0, s });
			while (!PQ.empty())
			{
				pair<long long, long long> e = PQ.top(); PQ.pop();
				long long f = e.second;
				color[f] = BLACK;
				if (d[f] < e.first * (-1)) continue;

				for (long long t = 0; t < N; t++)
				{
					if (color[t] == BLACK) continue;
					if (mg[f][t] == INF) continue;
					if (d[t] > d[f] + mg[f][t])
					{
						d[t] = d[f] + mg[f][t];
						// 逆順で並べるため-1倍する
						PQ.push({ d[t] * (-1), t });
						color[t] = GRAY;
					}
				}
			}
			res.resize((long long)d.size());
			for (long long i = 0; i < (long long)d.size(); i++)
				res[i] = (d[i] != INF) ? d[i] : -1;
		}

		/**
		@brief 隣接リストの最短コストを求める
		@param s スタート地点
		@param lg 重みつき隣接リスト
		@param res 結果を格納する構造体
		@note
		 計算量O((V+E)log(V))
		 G[a][i]=(b,c)は頂点aの辺i(a->b)のコストがcを表す
		**/
		void Run
		(long long s, vector<vector<pair<long long, long long>>>& lg, vector<long long>& res)
		{
			long long INF = LLONG_MAX;
			long long N = (long long)lg.size(); // 頂点数
			int WHITE = 0; // 最短距離が確定してない
			int GRAY = 1;  // 最短距離が更新されたことを表す(処理には無関係)
			int BLACK = 2; // 最短距離確定

			vector<long long> d(N), color(N);
			// pair.first = cost, pair.second = v(to)
			priority_queue<pair<long long, long long>> PQ;
			for (long long i = 0; i < N; i++)
			{
				d[i] = INF;
				color[i] = WHITE;
			}

			d[s] = 0;
			color[s] = GRAY;
			PQ.push({ 0, s });
			while (!PQ.empty())
			{
				pair<long long, long long> e = PQ.top(); PQ.pop();
				long long f = e.second;
				color[f] = BLACK;
				if (d[f] < e.first * (-1)) continue;

				for (long long i = 0; i < (long long)lg[f].size(); i++)
				{
					long long t = lg[f][i].first;
					if (color[t] == BLACK) continue;
					if (d[t] > d[f] + lg[f][i].second)
					{
						d[t] = d[f] + lg[f][i].second;
						// 逆順で並べるため-1倍する
						PQ.push({ d[t] * (-1), t });
						color[t] = GRAY;
					}
				}
			}
			res.resize((long long)d.size());
			for (long long i = 0; i < (long long)d.size(); i++)
				res[i] = (d[i] != INF) ? d[i] : -1;
		}
	};
}
