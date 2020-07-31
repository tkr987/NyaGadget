#include <bits/stdc++.h>

namespace NyaGadget
{
	/*** 二次元累積和ライブラリ***/

	struct DS_CumulativeSum2D
	{
		std::vector<std::vector<long long>> csum;

		/**
		@brief 二次元累積和の構築
		@note
		 引数で渡された二次元配列から累積和を構築する。
		**/
		DS_CumulativeSum2D(const std::vector<std::vector<long long>>& v)
		{	// 0で初期化されたgsum[0][x]とgsum[y][0]も追加して配列を構築
			long long ysize = (long long)v.size() + 1;
			long long xsize = (long long)v[0].size() + 1;
			csum.resize(ysize);
			for (auto& e : csum) e.resize(xsize);

			for (long long y = 1; y < ysize; y++) for (long long x = 1; x < xsize; x++)
			{
				csum[y][x] = csum[y - 1][x] + csum[y][x - 1] - csum[y - 1][x - 1] + v[y - 1][x - 1];
			}
		}

		/**
		@brief 結果取得関数
		@param ymin 左上y座標
		@param xmin 左上x座標
		@param ymax 左下y座標
		@param xmax 左下x座標
		@note
		 二次元範囲の累積結果をO(1)で出力する。
		**/
		long long Result(long long ymin, long long xmin, long long ymax, long long xmax)
		{	// 累積和のcsumは元の座標と1ずつずれているので調整
			ymin++; xmin++; ymax++; xmax++;
			return csum[ymin - 1][xmin - 1] + csum[ymax][xmax] - csum[ymax][xmin - 1] - csum[ymin - 1][xmax];
		}
	};
}