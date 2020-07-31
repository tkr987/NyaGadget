#include <bits/stdc++.h>
using namespace std;

namespace NyaGadget
{
	/***** 強連結成分分解ライブラリ *****/

	struct GT_NyaaSCC
	{	// StronglyConnectedComponents
		vector<long long> ideg;       // 入次数
		vector<long long> odeg;       // 出次数
		vector<bool> visited;         // DFSするときに訪れた頂点かどうか
		vector<long long> vs;         // トポロジカルに並べ直した頂点集合

		/**
		@brief 強連結成分分解の実行
		@param lg 隣接リスト
		@param res 強連結成分分解した頂点集合
		@note
		 有向グラフを連結成分に分解する。
		 閉路は存在しても処理できるが、孤立点は無視されるので注意。
		**/
		void Run
		(const vector<vector<long long>>& lg, vector<vector<long long>>& res)
		{
			ideg.clear();
			ideg.resize(lg.size());
			odeg.clear();
			odeg.resize(lg.size());
			visited.clear();
			visited.resize(lg.size(), false);
			vs.clear();
			vs.resize(lg.size());
			vector<vector<long long>> rg(lg.size()); // 辺を逆向きにしたグラフ
			for (long long from = 0; from < (long long)lg.size(); from++)
			{
				if ((long long)lg[from].size() != 0) odeg[from]++;
				for (long long to = 0; to < (long long)lg[from].size(); to++)
				{
					rg[lg[from][to]].push_back(from);
					ideg[lg[from][to]]++;
				}
			}

			for (long long v = 0; v < (long long)lg.size(); v++)
			{
				if (!visited[v]) DFS(-1, v, lg);
			}

			visited.clear();
			visited.resize((long long)lg.size(), false);
			for (long long i = (long long)vs.size() - 1; 0 <= i; i--)
			{
				if (ideg[vs[i]] == 0 && odeg[vs[i]] == 0) continue;
				if (!visited[vs[i]])
				{
					res.resize((long long)res.size() + 1);
					RDFS(-1, vs[i], rg, res);
				}
			}
		}

		/**
		@brief DFS処理関数
		@param r 頂点vの根
		@param v 現在の頂点
		@param lg 隣接リスト
		**/
		void DFS
		(long long r, long long v, const vector<vector<long long>>& lg)
		{
			{	// 頂点の更新処理
				visited[v] = true;
			}
			for (auto e : lg[v])
			{	// 後戻りしないようにする
				if (e == r) continue;
				if (!visited[e]) DFS(v, e, lg);
			}
			vs.push_back(v);
		}

		/**
		@brief 逆順DFS処理関数
		@param r 頂点vの根
		@param v 現在の頂点
		@param rg 辺を逆向きにしたグラフ
		@param res 強連結成分分解した頂点集合
		**/
		void RDFS
		(long long r, long long v, const vector<vector<long long>>& rg, vector<vector<long long>>& res)
		{
			{	// 頂点の更新処理
				visited[v] = true;
				res.back().push_back(v);
			}
			for (auto e : rg[v])
			{	// 後戻りしないようにする
				if (e == r) continue;
				if (!visited[e]) RDFS(v, e, rg, res);
			}
		}
	};
}
