#include <bits/stdc++.h>
using namespace std;

namespace NyaGadget
{
	/*** 遅延評価セグメント木ライブラリ ***/

	template <class T> struct Vertex
	{	// 各頂点は対象閉区間[l,r]の合計値を持つ
		T value;        // 頂点の値
		T lazy;         // 遅延評価値
		long long l;    // 対象閉区間最小値
		long long r;    // 対象閉区間最大値
	};

	template <class T> struct LazySegmentTree
	{
		vector<Vertex<T>> tree;

		/**
		@brief コンストラクタ
		@note
		 初期値0で[0,n)を処理する木を作る
		**/
		LazySegmentTree(long long n)
		{	// 木のサイズは2t-1(tは2の冪乗)
			long long test = 1;
			while (test < n) test *= 2;
			tree.resize(2 * test - 1);

			long long depth = 1;
			long long range = (long long)tree.size() / 2;
			tree[0] = { 0, 0, 0, range };
			for (long long i = 1; i < (long long)tree.size(); i++)
			{	// 各ノードの区間範囲を設定する
				tree[i] = { 0, 0, tree[i - 1].l + range + 1, tree[i - 1].r + range + 1 };

				if (i == pow(2, depth) - 1)
				{
					depth++;
					range /= 2;
					tree[i] = { 0, 0, 0, range };
				}
			}
		}

		/**
		@brief コンストラクタ
		@note
		 初期値を配列vで与えて木を作る。
		**/
		LazySegmentTree(vector<T>& v)
		{	// 木のサイズは2t-1(tは2の冪乗)
			long long test = 1;
			while (test < (long long)v.size()) test *= 2;
			tree.resize(2 * test - 1);

			long long depth = 1;
			long long range = (long long)tree.size() / 2;
			tree[0] = { 0, 0, 0, range };
			for (long long i = 1; i < (long long)tree.size(); i++)
			{	// 各ノードの区間範囲を設定する
				tree[i] = { 0, 0, tree[i - 1].l + range + 1, tree[i - 1].r + range + 1 };

				if (i == pow(2, depth) - 1)
				{
					depth++;
					range /= 2;
					tree[i] = { 0, 0, 0, range };
				}
			}

			for (long long i = 0; i < (long long)v.size(); i++)
				tree[i + (long long)tree.size() / 2].value = v[i];
			for (long long i = (long long)tree.size() / 2 - 1; -1 < i; i--)
				tree[i].value = tree[i * 2 + 1].value + tree[i * 2 + 2].value;
		}

		/**
		@brief 区間に対して加算処理をする関数
		@param l 加算する区間の左端
		@param r 加算する区間の右端
		@param x 加算する値
		@param v 頂点インデックス
		@note
		 [l, r]の区間にxを加算する
		**/
		void Add(long long l, long long r, T x, long long v = 0)
		{
			LazyUpdate(v);
			// 完全に加算区間範囲外のとき枝刈り
			if (r < tree[v].l || tree[v].r < l) return;

			if (l <= tree[v].l && tree[v].r <= r)
			{	// 加算区間と全範囲が一致
				tree[v].lazy += (tree[v].r - tree[v].l + 1) * x;
				LazyUpdate(v);
			}
			else
			{	// 加算区間に一部範囲が含まれる
				Add(l, r, x, 2 * v + 1);
				Add(l, r, x, 2 * v + 2);
				tree[v].value = tree[2 * v + 1].value + tree[2 * v + 2].value;
			}
		}

		/**
		@brief 区間合計値を取得する関数
		@param l 加算する区間の左端
		@param r 加算する区間の右端
		@param sum 合計
		@param v 頂点インデックス
		@note
		 [l,r]の合計を取得して返す
		**/
		void Sum(long long l, long long r, T& sum, long long v = 0)
		{
			if (v == 0) sum = 0;

			LazyUpdate(v);
			if (tree[v].l == l && tree[v].r == r)
			{
				sum += tree[v].value;
				return;
			}

			v *= 2;
			if (tree[v + 1].r < l)
				Sum(l, r, sum, v + 2);
			else if (r < tree[v + 2].l)
				Sum(l, r, sum, v + 1);
			else
			{
				Sum(l, tree[v + 1].r, sum, v + 1);
				Sum(tree[v + 2].l, r, sum, v + 2);
			}
		}

		/**
		@brief 遅延更新関数
		@note
		 頂点vの遅延評価を伝播させる。
		**/
		void LazyUpdate(long long v)
		{
			if (tree[v].lazy != 0)
			{
				tree[v].value += tree[v].lazy;
				if (1 <= tree[v].r - tree[v].l)
				{	// 子ノードが存在する
					tree[2 * v + 1].lazy += tree[v].lazy / 2;
					tree[2 * v + 2].lazy += tree[v].lazy / 2;
				}
				tree[v].lazy = 0;
			}
		}
	};
}
