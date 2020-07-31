#include <bits/stdc++.h>
using namespace std;

namespace NyaGadget
{
	/***** セグメント木ライブラリ *****/
	// 点加算と区間最大値の取得

	template <class T> struct DS_SegmentTree
	{
		long long n;
		vector<T> node;

		/**
		@brief コンストラクタ
		@param size データ構造最大値
		@note
		 半開区間[0, size)のデータ構造を作る。
		**/
		DS_SegmentTree(long long size)
		{
			n = 1;
			while (n < size) n *= 2;
			node.resize(2 * n - 1, 0);
		}

		/**
		@brief コンストラクタ
		@param v 初期値
		@note
		 初期値を配列で渡して同じサイズのデータ構造を作る。
		**/
		DS_SegmentTree(vector<T> v)
		{
			n = 1;
			while (n < (long long)v.size()) n *= 2;
			node.resize(2 * n - 1, 0);
			for (long long i = 0; i < (long long)v.size(); i++) node[i + n - 1] = v[i];
			for (long long i = n - 2; i >= 0; i--) node[i] = max(node[i * 2 + 1], node[i * 2 + 2]);
		}

		/**
		@brief 点加算関数
		@note
		 要素[i]にxを加算する。
		**/
		void Add(long long i, T x)
		{
			i += (n - 1);
			node[i] = x;
			while (i > 0)
			{
				i = (i - 1) / 2;
				node[i] = max(node[i * 2 + 1], node[i * 2 + 2]);
			}
		}

		/**
		@brief 区間最大値取得関数
		@note
		 半開区間[li, ri)の最大値を取得する。
		**/
		T GetMax(long long li, long long ri, long long k = 0, long long l = 0, long long r = -1)
		{
			if (r < 0) r = n;
			if (r <= li || ri <= l) return 0;
			if (li <= l && r <= ri) return node[k];
			T vl = GetMax(li, ri, k * 2 + 1, l, (l + r) / 2);
			T vr = GetMax(li, ri, k * 2 + 2, (l + r) / 2, r);
			return max(vl, vr);
		}

		/**
		@brief 区間最小値取得関数
		@note
		 半開区間[li, ri)の最大値を取得する。
		**/
		T GetMin(int li, int ri, int k = 0, int l = 0, int r = -1)
		{
			// 最初に呼び出されたときの対象区間は [0, n)
			if (r < 0) r = n;
			// 要求区間と対象区間が交わらない -> 適当に返す
			if (r <= li || ri <= l) return -1;
			// 要求区間が対象区間を完全に被覆 -> 対象区間を答えの計算に使う
			if (li <= l && r <= ri) return node[k];

			// 要求区間が対象区間の一部を被覆 -> 子について探索を行う
			// 左側の子を vl ・ 右側の子を vr としている
			// 新しい対象区間は、現在の対象区間を半分に割ったもの
			int vl = GetMin(li, ri, 2 * k + 1, l, (l + r) / 2);
			int vr = GetMin(li, ri, 2 * k + 2, (l + r) / 2, r);
			return min(vl, vr);
		}
	};
}
