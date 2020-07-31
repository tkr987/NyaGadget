#include <bits/stdc++.h>
using namespace std;

namespace NyaGadget
{
    /*** 重み付きUnionFindライブラリ ***/

    template <class T> struct DS_WeightUnionFind
    {
        vector<long long> root;  // 根の頂点
        vector<long long> tsize; // 木のサイズ
        vector<T> weight;        // 重み

        DS_WeightUnionFind(long long n)
        {
            root.resize(n);
            tsize.resize(n);
            weight.resize(n);
            for (long long i = 0; i < n; i++)
            {
                root[i] = i;
                tsize[i] = 1;
                weight[i] = 0;
            }
        }

        /**
        @brief 差分取得関数
        @note
         重みw=y-xを返す。これはxとyの差分になる。
        **/
        T Diff(long long x, long long y){ return Weight(y) - Weight(x); }

        /**
        @brief 根を返す関数
        @note
         内部的には根の検索と同時に重みの修正もしている。
        **/
        long long Find(long long x)
        {
            if (root[x] == x) return x;

            long long r = Find(root[x]);
            weight[x] += weight[root[x]];
            return root[x] = r;
        }

        /**
        @brief 根が同じかどうか調べる関数
        @note
         xとyの根が同じならtrue、違うときはfalseを返す。
         根が同じということは同じ素集合データということ。
        **/
        bool Same(long long x, long long y) { return Find(x) == Find(y); }

        /**
        @brief 重みを返す関数
        @note
         内部的には重みを返すと同時に経路圧縮もしている。
        **/
        T Weight(long long x){ Find(x); return weight[x]; }

        /**
        @brief 併合関数
        @note
         w=y-xとなるようにxとyを併合する。
        **/
        bool Union(long long x, long long y, T w)
        {
            long long rx = Find(x);
            long long ry = Find(y);

            // 既に同じ木に属しているときは何もしない
            if (rx == ry) return false;

            // サイズの小さい木の根をサイズの大きい木の根に繋いで併合する
            w = (Weight(x) + w - Weight(y));
            if (tsize[rx] < tsize[ry])
            {
                root[rx] = ry;
                tsize[ry] += tsize[rx];
                weight[rx] = -w;
            }
            else
            {
                root[ry] = rx;
                tsize[rx] += tsize[ry];
                weight[ry] = w;
            }

            return true;
        }
    };
}
