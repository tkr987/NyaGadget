#include <bits/stdc++.h>
using namespace std;

namespace NyaGadget
{
	/*** クラスカル法ライブラリ ***/

	struct GT_Kruskal
	{
		struct Edge
		{
			long long f = 0; // from vertex
			long long t = 0; // to vertex
			long long cost = 0;
			bool operator < (const Edge& r) { return cost < r.cost; }
		};

		/**
		@brief 最小全域木の最小コストを求める
		@param lg 隣接リスト
		@note
		 計算量 O(ElogV)
		**/
		static long long Run(vector<vector<pair<long long, long long>>>& lg)
		{
			vector<Edge> edge;
			for (long long f = 0; f < (long long)lg.size(); f++)
			{	// 辺をコストでソート
				for (auto& e: lg[f])
					edge.push_back({ f, e.first, e.second });
			}
			sort(edge.begin(), edge.end());

			long long res = 0;
			UnionFind uf((long long)lg.size() + 1);
			for (auto& e: edge)
			{
				if (uf.Find(e.f) != uf.Find(e.t))
				{	// 閉路にならなければ追加
					uf.Union(e.f, e.t);
					res += e.cost;
				}
			}
			return res;
		}

		/*** UnionFindライブラリ ***/

		struct UnionFindVertex
		{	// 頂点を表現する構造体
			long long self = 0; // 自分自身のインデックス
			long long root = 0; // 根のインデックス
			long long size = 0; // 自分が属している木のサイズ
		};

		struct UnionFind
		{
			vector<UnionFindVertex> v;

			/**
			@brief コンストラクタ
			@param max 頂点数
			@note
			 [0-max)の素集合データ構造を作成する
			**/
			UnionFind(long long max)
			{	// [0-max]のデータ構造にするため、max+1でリサイズ
				v.resize(max);
				for (long long i = 0; i < max; i++)
				{	// 各頂点の根を自分自身で初期化、木サイズは1
					v[i].self = i;
					v[i].root = i;
					v[i].size = 1;
				}
			}

			/**
			@brief 根を検索する関数
			@param i 根を検索する頂点インデックス
			@note
			 引数で指定された頂点の根を返す。
			**/
			long long Find(long long i)
			{
				if (i == v[i].root) return i;

				// 根の探索をすると同時に次からO(1)で根を参照できるようにする(経路圧縮)
				v[i].root = Find(v[i].root);
				return v[i].root;
			}

			/**
			@brief 頂点を併合する関数
			@param i1 併合する頂点1
			@param i2 併合する頂点2
			@note
			 頂点i1を含む木と頂点i2を含む木を「サイズ優先で」併合する。
			 ただし、i1とi2が既に同じ木に属しているときは何もしない。
			 併合したときtrue、何もしなかったときfalseを返す。
			 サイズによる工夫により、計算量はアッカーマンの逆関数になる。
			**/
			bool Union(long long i1, long long i2)
			{
				long long root1 = Find(i1);
				long long root2 = Find(i2);

				// 既に同じ木に属しているときは何もしない
				if (root1 == root2) return false;

				// サイズの小さい木の根をサイズの大きい木の根に繋いで併合する
				if (v[root1].size < v[root2].size)
				{
					v[root1].root = root2;
					v[root2].size += v[root1].size;
				}
				else
				{
					v[root2].root = root1;
					v[root1].size += v[root2].size;
				}
				return true;
			}

			/**
			@brief 頂点を併合する関数
			@param i1 併合する頂点1
			@param i2 併合する頂点2
			@param p  親指定
			@note
			 頂点i1を含む木と頂点i2を含む木を「pを含む木を親として」併合する。
			 ただし、i1とi2が既に同じ木に属しているときは何もしない。
			 併合したときtrue、何もしなかったときfalseを返す。
			 計算量はO(logN)になり、アッカーマンの逆関数に比べて若干遅くなる。
			**/
			bool Union(long long i1, long long i2, long long p)
			{
				long long root1 = Find(i1);
				long long root2 = Find(i2);
				long long rootp = Find(p);

				// 既に同じ木に属しているときは何もしない
				if (root1 == rootp && root2 == rootp) return false;

				// 子の木を親の木へ併合する
				if (rootp == root1)
				{
					v[root2].root = rootp;
					v[rootp].size += v[root2].size;
				}
				else if (rootp == root2)
				{
					v[root1].root = rootp;
					v[rootp].size += v[root1].size;
				}
				else
				{
					v[root1].root = rootp;
					v[rootp].size += v[root1].size;
					v[root2].root = rootp;
					v[rootp].size += v[root2].size;
				}
				return true;
			}
		};
	};
}