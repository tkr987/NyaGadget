#include <bits/stdc++.h>

namespace NyaGadget
{
	/***** BFSライブラリ *****/

	struct GT_NyaaBFS
	{
		/**
		@brief BFS実行関数
		@param start 探索開始頂点
		@param g グラフ
		@param res 結果を格納する構造体
		@note
		 探索開始頂点startからBFSで処理する。
		**/
		void Run(long long start, const std::vector<std::vector<long long>>& g, std::vector<long long>& res)
		{	// 初期化
			std::queue<long long> q;
			q.push(start);
			res.resize(g.size());

			while (!q.empty())
			{
				long long from = q.front(); q.pop();
				for (auto&& to : g[from])
				{	// 頂点fromから頂点toへの処理
					q.push(to);
				}
			}
		}

		/**
		@brief BFS実行関数
		@param start 探索開始頂点の集合
		@param g グラフ
		@param res 結果を格納する構造体
		@note
		 探索開始頂点が複数あるとき最初に全てキューに入れる必要がある。
		 したがって、開始頂点はvectorに格納して渡す。
		**/
		void Run(std::vector<long long> start, const std::vector<std::vector<long long>>& g, std::vector<long long> & res)
		{	// 初期化
			std::queue<long long> q;
			for (auto& e : start) q.push(e);
			res.resize(g.size());

			while (!q.empty())
			{
				long long from = q.front(); q.pop();
				for (auto&& to : g[from])
				{	// 頂点fromから頂点toへの処理
					q.push(to);
				}
			}
		}
	};
}
