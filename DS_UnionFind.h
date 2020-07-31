#include <bits/stdc++.h>

namespace NyaGadget
{
	/***** UnionFindライブラリ *****/

	struct UnionFindVertex
	{	// 頂点を表現する構造体
		long long self = 0; // 自分自身のインデックス
		long long root = 0; // 根のインデックス
		long long size = 0; // 自分が属している木のサイズ
	};

	struct DS_UnionFind
	{	// 木構造で粗集合データを実現させる
		std::vector<UnionFindVertex> v;

		/**
		@brief コンストラクタ
		@param max 最大値
		@note
		 [0-max]の素集合データ構造を作成する
		**/
		DS_UnionFind(long long max)
		{	// [0-max]のデータ構造にするため、max+1でリサイズ
			v.resize(max + 1);
			for (long long i = 0; i < max + 1; i++)
			{	// 各頂点の根を自分自身で初期化、木サイズは1
				v[i].self = i;
				v[i].root = i;
				v[i].size = 1;
			}
		}

		/**
		@brief 要素xの根を検索する関数
		**/
		long long Find(long long x)
		{
			if (x == v[x].root) return x;
			// 根の探索をすると同時に次からO(1)で根を参照できるようにする(経路圧縮)
			v[x].root = Find(v[x].root);
			return v[x].root;
		}

		long long Size(long long x)
		{	// 要素xが属する集合のサイズを取得する
			return v[Find(x)].size;
		}

		bool Same(long long x, long long y)
		{	// 要素xと要素yが同じ集合かどうか調べる
			return Find(x) == Find(y);
		}

		/**
		@brief 要素を併合する関数
		@param x 併合する要素x
		@param y 併合する要素y
		@note
		 要素xを含む木と要素yを含む木を「サイズ優先で」併合する。
		 ただし、xとyが既に同じ木に属しているときは何もしない。
		 併合したときtrue、何もしなかったときfalseを返す。
		 サイズによる工夫により、計算量はアッカーマンの逆関数になる。
		**/
		bool Union(long long x, long long y)
		{
			long long root1 = Find(x);
			long long root2 = Find(y);

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
		@brief 要素を併合する関数
		@param x 併合する要素1
		@param y 併合する要素2
		@param p  親指定
		@note
		 要素xを含む木と要素yを含む木を「pを含む木を親として」併合する。
		 ただし、xとyが既に同じ木に属しているときは何もしない。
		 併合したときtrue、何もしなかったときfalseを返す。
		 計算量はO(logN)になり、アッカーマンの逆関数に比べて若干遅くなる。
		**/
		bool Union(long long x, long long y, long long p)
		{
			long long root1 = Find(x);
			long long root2 = Find(y);
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
}
