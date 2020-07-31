#include <bits/stdc++.h>
using namespace std;

namespace NyaGadget
{
	/***** グリッド上でのBFS処理ライブラリ *****/

	struct GT_NyaaGridBFS
	{
		/**
		@brief 4方向BFS実行関数
		@param start 探索開始座標
		@param grid 入力グリッド
		@param wall 移動不可な値
		@param res 出力結果
		@note
		 探索開始頂点startから4方向BFSで処理する。
		**/
		template <class T> void Run4(pair<long long, long long> start, const vector<vector<T>>& grid, T wall, vector<vector<long long>>& res)
		{	// 初期化
			const pair<long long, long long> move[4] = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };
			const long long inf = (long long)pow(10, 6);
			queue<pair<long long, long long>> q;
			q.push(start);
			// 初期化処理の追加
			res.resize(grid.size()); for (auto&& e : res) e.resize(grid[0].size(), inf);
			res[start.first][start.second] = 0;
			while (!q.empty())
			{
				auto from = q.front(); q.pop();
				for (auto& m : move)
				{
					long long y = from.first + m.first;
					long long x = from.second + m.second;
					if (y < 0 || (long long)grid.size() <= y || x < 0 || (long long)grid[y].size() <= x) continue;
					// 移動不可座標の処理
					if (grid[y][x] == wall) continue;
					// 移動可能座標の処理
					if (res[y][x] != inf) continue;
					res[y][x] = res[from.first][from.second] + 1;
					q.push({ y, x });
				}
			}
		}

		/**
		@brief 6方向BFS実行関数
		@param start 探索開始座標
		@param grid 入力グリッド
		@param wall 移動不可な値
		@param res 出力結果
		@note
		 探索開始頂点startから6方向BFSで処理する。
		**/
		template <class T> void Run6(pair<long long, long long> start, const vector<vector<T>>& grid, T wall, vector<vector<long long>>& res)
		{	// 初期化
			pair<long long, long long> move1[6] = { {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, 0}, {1, 1} };
			pair<long long, long long> move2[6] = { {-1, -1}, {-1, 0}, {0, -1}, {0, 1}, {1, -1}, {1, 0} };
			vector<vector<bool>> check(grid.size(), vector<bool>(grid[0].size(), false));
			check[start.first][start.second] = true;
			queue<pair<long long, long long>> q;
			q.push(start);
			// 初期化処理の追加
			res.resize(grid.size()); for (auto& e : res) e.resize(grid[0].size());
			while (!q.empty())
			{
				auto from = q.front(); q.pop();
				if (from.first % 2 != 0)
				{
					for (auto& m : move1)
					{
						long long y = from.first + m.first;
						long long x = from.second + m.second;
						if (y < 0 || (long long)grid.size() <= y || x < 0 || (long long)grid[y].size() <= x) continue;
						// 移動不可座標の処理
						if (grid[y][x] == wall) continue;
						// 移動可能座標の処理
						if (check[y][x]) continue;
						else check[y][x] = true;
						q.push({ y, x });
					}
				}
				else
				{
					for (auto& m : move2)
					{
						long long y = from.first + m.first;
						long long x = from.second + m.second;
						if (y < 0 || (long long)grid.size() <= y || x < 0 || (long long)grid[y].size() <= x) continue;
						// 移動不可座標の処理
						if (grid[y][x] == wall) continue;
						// 移動可能座標の処理
						if (check[y][x]) continue;
						else check[y][x] = true;
						q.push({ y, x });
					}
				}
			}
		}

		/**
		@brief 8方向BFS実行関数
		@param start 探索開始座標
		@param grid 入力グリッド
		@param wall 移動不可な値
		@param res 出力結果
		@note
		 探索開始頂点startから8方向BFSで処理する。
		**/
		template <class T> void Run8(pair<long long, long long> start, const vector<vector<T>>& grid, T wall, vector<vector<long long>>& res)
		{	// 初期化
			pair<long long, long long> move[8] = { {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1} };
			vector<vector<bool>> check(grid.size(), vector<bool>(grid[0].size(), false));
			check[start.first][start.second] = true;
			queue<pair<long long, long long>> q;
			q.push(start);
			// 初期化処理の追加
			res.resize(grid.size()); for (auto& e : res) e.resize(grid[0].size());
			while (!q.empty())
			{
				auto from = q.front(); q.pop();
				for (auto& m : move)
				{
					long long y = from.first + m.first;
					long long x = from.second + m.second;
					if (y < 0 || (long long)grid.size() <= y || x < 0 || (long long)grid[y].size() <= x) continue;
					// 移動不可座標の処理
					if (grid[y][x] == wall) continue;
					// 移動可能座標の処理
					if (check[y][x]) continue;
					else check[y][x] = true;
					q.push({ y, x });
				}
			}
		}
	};
}