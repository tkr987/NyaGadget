#include <bits/stdc++.h>
using namespace std;

namespace NyaGadget
{
	struct DP_NyaaKnapsack
	{	/*** ナップサックDPライブラリ ***/
		struct Item
		{
			long long w; // 重さ
			long long v; // 価値
		};
		vector<Item> item;

		/**
		@brief ナップサックDP実行関数
		@param ysize 通常はアイテム最大値
		@param wsize 通常は大きさ最大値
		@note
			wsizeは制約10^5以下なら様々な要素に変更可能
		**/
		void Run(long long ysize, long long wsize)
		{	// 0番目にダミーのアイテムを追加
			item.insert(item.begin(), { 0,0 });

			// DPは通常は価値だが変更可能
			vector<vector<long long>> dp(ysize + 1);
			for (long long y = 0; y < ysize + 1; y++) dp[y].resize(wsize + 1);
			for (long long y = 1; y < ysize + 1; y++) for (long long w = 1; w < wsize + 1; w++)
			{	// DPの実行
				if (0 <= w - item[y].w) dp[y][w] = max(dp[y - 1][w], dp[y - 1][w - item[y].w] + item[y].v);
				else dp[y][w] = dp[y - 1][w];
			}

			// 答えの出力
			cout << *max_element(dp.back().begin(), dp.back().end());
		}
	};
}
