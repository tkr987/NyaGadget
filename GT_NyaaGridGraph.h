#include <bits/stdc++.h>
using namespace std;

namespace NyaGadget
{
	/***** グリッドグラフ変換ライブラリ *****/

	struct GT_NyaaGridGraph
	{
		// 頂点indexと座標を対応させた配列
		vector<pair<long long, long long>> gtable;
		// 座標と頂点indexを対応させた配列(頂点にならなかった座標は-1)
		vector<vector<long long>> vtable;

		/**
		@brief 隣接9マスのグリッドグラフに変換する
		@param grid 入力グリッド
		@param graph 出力グラフ
		@param wall 移動不可のグリッド値
		@note
		 中央を含む隣接9マスの座標で値がwall以外の座標を頂点としてグラフを作る。
		**/
		template <class T> void Convert9
		(const vector<vector<T>>& grid, vector<vector<long long>>& graph, T wall = '#')
		{
			ll vmax = 0;
			vtable.clear();
			vtable.resize(grid.size());
			for (long long y = 0; y < (long long)grid.size(); y++)
			{
				for (long long x = 0; x < (long long)grid[y].size(); x++)
				{
					if (grid[y][x] != wall)
					{
						vtable[y].push_back(vmax++);
						gtable.push_back({ y,x });
					}
					else
					{
						vtable[y].push_back(-1);
					}
				}
			}

			graph.clear();
			graph.resize(vmax);
			for (long long y = 0; y < (long long)grid.size(); y++)
			{
				for (long long x = 0; x < (long long)grid[y].size(); x++)
				{
					if (vtable[y][x] == -1) continue;
					for (long long y3 = y - 1; y3 < y + 2; y3++)
					{
						if (y3 < 0 || (long long)grid.size() <= y3) continue;
						for (long long x3 = x - 1; x3 < x + 2; x3++)
						{
							if (x3 < 0 || (long long)grid[y3].size() <= x3) continue;
							if (vtable[y3][x3] == -1) continue;
							graph[vtable[y][x]].push_back(vtable[y3][x3]);
						}
					}
				}
			}
		}

		/**
		@brief 隣接9マスのグリッドグラフに変換する
		@param grid 入力グリッド
		@param wlg 重み付き隣接リスト
		@param wall 移動不可のグリッド値
		@note
		 中央を含む隣接9マスの座標で値がwall以外の座標を頂点としてグラフを作る。
		**/
		template <class T> void Convert9
		(const vector<vector<T>>& grid, vector<vector<pair<long long, long long>>>& wlg, T wall = '#')
		{
			ll vmax = 0;
			vtable.clear();
			vtable.resize(grid.size());
			for (long long y = 0; y < (long long)grid.size(); y++)
			{
				for (long long x = 0; x < (long long)grid[y].size(); x++)
				{
					if (grid[y][x] != wall)
					{
						vtable[y].push_back(vmax++);
						gtable.push_back({ y,x });
					}
					else
					{
						vtable[y].push_back(-1);
					}
				}
			}

			vector<vector<long long>> graph(vmax);
			for (long long y = 0; y < (long long)grid.size(); y++)
			{
				for (long long x = 0; x < (long long)grid[y].size(); x++)
				{
					if (vtable[y][x] == -1) continue;
					for (long long y3 = y - 1; y3 < y + 2; y3++)
					{
						if (y3 < 0 || (long long)grid.size() <= y3) continue;
						for (long long x3 = x - 1; x3 < x + 2; x3++)
						{
							if (x3 < 0 || (long long)grid[y3].size() <= x3) continue;
							if (vtable[y3][x3] == -1) continue;
							graph[vtable[y][x]].push_back(vtable[y3][x3]);
						}
					}
				}
			}

			wlg.clear();
			wlg.resize(graph.size());
			for (long long i = 0; i < (long long)graph.size(); i++)
			{
				for (long long j = 0; j < (long long)graph[i].size(); j++)
				{
					wlg[i].push_back({ graph[i][j],1 });
				}
			}
		}

		/**
		@brief 上下左右5マスのグリッドグラフに変換する
		@param grid 入力グリッド
		@param graph 出力グラフ
		@param wall 移動不可のグリッド値
		@note
		 中央を含む上下左右5マスのグリッドで値がwall以外の座標を頂点としてグラフを作る。
		**/
		template <class T> void Convert5
		(const vector<vector<T>>& grid, vector<vector<long long>>& graph, T wall = '#')
		{
			ll vmax = 0;
			vtable.clear();
			vtable.resize(grid.size());
			for (long long y = 0; y < (long long)grid.size(); y++)
			{
				for (long long x = 0; x < (long long)grid[y].size(); x++)
				{
					if (grid[y][x] != wall)
					{
						vtable[y].push_back(vmax++);
						gtable.push_back({ y,x });
					}
					else
					{
						vtable[y].push_back(-1);
					}
				}
			}

			graph.clear();
			graph.resize(vmax);
			for (long long y = 0; y < (long long)grid.size(); y++)
			{
				for (long long x = 0; x < (long long)grid[y].size(); x++)
				{
					if (vtable[y][x] == -1) continue;
					if (0 <= y - 1 && vtable[y - 1][x] != -1)
						graph[vtable[y][x]].push_back(vtable[y - 1][x]);
					if (x + 1 < (long long)grid[y].size() && vtable[y][x + 1] != -1)
						graph[vtable[y][x]].push_back(vtable[y][x + 1]);
					if (y + 1 < (long long)grid.size() && vtable[y + 1][x] != -1)
						graph[vtable[y][x]].push_back(vtable[y + 1][x]);
					if (0 <= x - 1 && vtable[y][x - 1] != -1)
						graph[vtable[y][x]].push_back(vtable[y][x - 1]);
				}
			}
		}

		/**
		@brief 上下左右5マスのグリッドグラフに変換する
		@param grid 入力グリッド
		@param lg 重み付き出力グラフ
		@param wall 移動不可のグリッド値
		@note
		 中央を含む上下左右5マスのグリッドで値がwall以外の座標を頂点としてグラフを作る。
		**/
		template <class T> void Convert5
		(const vector<vector<T>>& grid, vector<vector<pair<long long, long long>>>& lg, T wall = '#')
		{
			ll vmax = 0;
			vtable.clear();
			vtable.resize(grid.size());
			for (long long y = 0; y < (long long)grid.size(); y++)
			{
				for (long long x = 0; x < (long long)grid[y].size(); x++)
				{
					if (grid[y][x] != wall)
					{
						vtable[y].push_back(vmax++);
						gtable.push_back({ y,x });
					}
					else
					{
						vtable[y].push_back(-1);
					}
				}
			}

			vector<vector<long long>> graph(vmax);
			for (long long y = 0; y < (long long)grid.size(); y++)
			{
				for (long long x = 0; x < (long long)grid[y].size(); x++)
				{
					if (vtable[y][x] == -1) continue;
					if (0 <= y - 1 && vtable[y - 1][x] != -1)
						graph[vtable[y][x]].push_back(vtable[y - 1][x]);
					if (x + 1 < (long long)grid[y].size() && vtable[y][x + 1] != -1)
						graph[vtable[y][x]].push_back(vtable[y][x + 1]);
					if (y + 1 < (long long)grid.size() && vtable[y + 1][x] != -1)
						graph[vtable[y][x]].push_back(vtable[y + 1][x]);
					if (0 <= x - 1 && vtable[y][x - 1] != -1)
						graph[vtable[y][x]].push_back(vtable[y][x - 1]);
				}
			}

			lg.clear();
			lg.resize(graph.size());
			for (long long i = 0; i < (long long)graph.size(); i++)
			{
				for (long long j = 0; j < (long long)graph[i].size(); j++)
				{
					lg[i].push_back({ graph[i][j],1 });
				}
			}
		}

		// 頂点vと対応する座標を取得する関数
		pair<long long, long long> GetGrid(long long v) { return gtable[v]; }
		// 座標(y,x)と対応する頂点indexを取得する関数
		long long GetVertex(long long y, long long x)
		{	// 頂点が存在しない(移動不可座標)またはグリッド範囲外のとき-1を返す
			if (y < 0 || vtable.size() <= y || x < 0 || vtable[y].size() <= x) return -1;
			return vtable[y][x];
		}
	};
}
