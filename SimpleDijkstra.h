#include <bits/stdc++.h>
using namespace std;

/**
@brief 単純なダイクストラ法
@param n 頂点数
@param G 重みつき隣接行列
@note
 計算量O(N^2)
 G[a][b]=cはa->bの辺コストがcを表す
**/
void SimpleDijkstra(long long n, vector<vector<long long>>& G)
{
	long long MAX = n;
	long long INF = LLONG_MAX;
	int WHITE = 0; // 最短距離が確定してない
	int GRAY = 1;  // 最短距離が更新されたことを表す(処理には無関係)
	int BLACK = 2; // 最短距離確定

	long long minv;
	vector<long long> d(MAX), color(MAX);
	for (long long i = 0; i < n; i++)
	{
		d[i] = INF;
		color[i] = WHITE;
	}

	d[0] = 0;
	color[0] = GRAY;
	while (1)
	{
		minv = INF;
		long long u = -1;
		for (long long i = 0; i < n; i++)
		{
			if (minv > d[i] && color[i] != BLACK)
			{
				u = i;
				minv = d[i];
			}
		}
		if (u == -1) break;
		color[u] = BLACK;
		for (long long v = 0; v < n; v++)
		{
			if (color[v] != BLACK && G[u][v] != INF)
			{
				if (d[v] > d[u] + G[u][v])
				{
					d[v] = d[u] + G[u][v];
					color[v] = GRAY;
				}
			}
		}
	}

	for (long long i = 0; i < n; i++)
	{
		cout << i << " " << (d[i] == INF ? -1 : d[i]) << endl;
	}
}
