#include <bits/stdc++.h>
using namespace std;

namespace NyaGadget
{
	/***** グラフ到達可能性ライブラリ *****/

	struct GT_NyaaReachable
	{
		/**
		@brief 頂点sからtへの到達可能性を調べる関数
		@param s 開始の頂点
		@param t 目標の頂点
		@param lg 隣接リスト
		@return 到達できるときはtrue, できないときfalseを返す。
		@note
		 内部的にはNyaaReachable::Run(s,g,res)と同じ。
		 計算量はO(max(V, E))程度だと思われる(未証明)。
		**/
		bool Run(long long s, long long t, const vector<vector<long long>>& lg)
		{
			vector<bool>res(lg.size(), false);
			NyaaDFS dfs;
			dfs.Run(-1, s, lg, res);
			return res[t];
		}

		/**
		@brief 全頂点に対してsからの到達可能性を調べる関数
		@param s 開始の頂点
		@param lg 隣接リスト
		@param res 結果を格納する構造体
		@note
		 計算量はO(max(V, E))程度だと思われる(未証明)。
		 s=0,res[N]=trueなら頂点0からNへ到達可能ということを表す。
		**/
		void Run(long long s, const vector<vector<long long>>& lg, vector<bool>& res)
		{
			res.resize(lg.size(), false);
			NyaaDFS dfs;
			dfs.Run(-1, s, lg, res);
		}

		struct NyaaDFS
		{
			/**
			@brief DFS処理関数
			@param r 頂点vの根
			@param v 現在の頂点
			@param g 処理するグラフ
			@param res 結果を格納する構造体
			**/
			void Run(long long r, long long v, const vector<vector<long long>>& lg, vector<bool>& res)
			{	// 頂点の更新処理
				res[v] = true;
				for (auto e : lg[v])
				{
					if (e == r) continue; // 後戻りを防ぐ
					if (res[e]) continue; // 訪問済み頂点
					Run(v, e, lg, res);
				}
			}
		};
	};
}