#include <bits/stdc++.h>
using namespace std;

namespace NyaGadget
{
	/**
	@brief グリッド上の最短経路を得る
	@param grid 二次元グリッド
	@param start 開始地点の文字
	@param wall 壁となる文字
	@return 最短経路(到達できない場合は-1)
	@note
	 予めグリッドに開始地点文字を書き込んでおく必要があることに注意。
	 単一始点最短経路を戻り値から返す。計算量 O(HW)
	**/
	vector<vector<long long>> GT_GridBFS
	(vector<vector<char>>& grid, char start, const char& wall = '#')
	{
		const long long vx[] = { 0, 1, 0, -1 }, vy[] = { 1, 0, -1, 0 };
		vector<vector<long long>> min_cost(grid.size(), vector<long long>(grid[0].size(), -1));
		queue<pair<long long, long long>> q;
		for (long long i = 0; i < (long long)grid.size(); i++)
		{
			for (long long j = 0; j < (long long)grid[i].size(); j++)
			{
				if (grid[i][j] == start)
				{
					q.push({ i, j });
					min_cost[i][j] = 0;
				}
			}
		}
		while (!q.empty())
		{
			auto p = q.front(); q.pop();
			for (long long i = 0; i < 4; i++)
			{
				long long ny = p.first + vy[i], nx = p.second + vx[i];
				if ((nx >= 0 && ny >= 0 
					&& nx < (long long)grid[0].size() && ny < (long long)grid.size()) 
					&& min_cost[ny][nx] == -1 && grid[ny][nx] != wall)
				{
					min_cost[ny][nx] = min_cost[p.first][p.second] + 1;
					q.push({ ny, nx });
				}
			}
		}
		return min_cost;
	}
}
