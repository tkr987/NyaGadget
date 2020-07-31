#include <bits/stdc++.h>

namespace NyaGadget
{
	/***** Bit操作ライブラリ *****/

	struct NT_NyaaBit
	{
		/**
		@brief 1になっているビットの数を取得する
		@note flipをtrueにすると0になっているビットの数を返す。
		**/
		static long long Count(long long x, bool flip = false)
		{
			long long sum = 0;
			for (auto i = 0LL; i < Size(x); ++i) sum += Test(x, i, flip);
			return sum;
		}

		/**
		@brief bit列を整数に変換する
		**/
		static long long ToLL(std::string bit)
		{
			long long res = 0;
			long long maxSize = (long long)bit.size();
			for (auto i = 0LL; i < maxSize; ++i) if (bit[i] == '1') res += (1LL << (maxSize - i - 1));
			return res;
		}

		/**
		@brief 文字列に変換する
		**/
		static std::string ToString(long long x, bool flip = false)
		{
			std::string res;
			if (!flip) for (auto i = Size(x) - 1; -1 < i; --i) res += (char)('0' + Test(x, i));
			else       for (auto i = 0LL; i < Size(x); ++i)    res += (char)('0' + Test(x, i));
			return res;
		}

		/**
		@brief 文字列に変換する
		@note maxSize桁の文字列に変換する。
		**/
		static std::string ToString(long long maxSize, long long x, bool flip = false)
		{
			std::string res;
			for (auto i = 0LL; i < (maxSize - Size(x)); i++)   res += '0';
			if (!flip) for (auto i = Size(x) - 1; -1 < i; --i) res += (char)('0' + Test(x, i));
			else       for (auto i = 0LL; i < Size(x); ++i)    res += (char)('0' + Test(x, i));
			return res;
		}

		/**
		@brief 半開区間で1になっているビットの数を取得する
		@note
		値xの半開区間[b, e)でビットが1になっている数を返す。
		flipをtrueにすると0になっているビットの数を返す。
		**/
		static long long RangeCount(long long x, long long b, long long e, bool flip = false)
		{
			long long sum = 0;
			for (auto i = b; i < e; i++) sum += Test(x, i, flip);
			return sum;
		}

		/**
		@brief nビット左シフト
		**/
		static long long Shift(long long x, long long n)
		{
			return (x << n);
		}

		/**
		@brief 値xのビットサイズを取得する
		**/
		static long long Size(long long x)
		{
			long long size = 0;
			while ((long long)(1LL << size) <= x) size++;
			return size;
		}

		/**
		@brief 任意桁のビットを取得する
		@note flipがtrueなら反転したビット値を返す。
		**/
		static long long Test(long long x, long long i, bool flip = false)
		{
			if (flip) return ((x & Shift(1, i)) != 0) ? 0 : 1;
			else return ((x & Shift(1, i)) != 0) ? 1 : 0;
		}

		/**
		@brief 任意桁のビットを10進数に変換して返す
		@note 値xのi桁目ビットを10進数に変換して返す。
		**/
		static long long To10(long long x, long long i)
		{
			return Test(x, i) * (long long)pow(2, i);
		}

		/**
		@brief ビット組み合わせテーブル
		@note
		ビットサイズN桁でm個が1となるビット列の集合を昇順で返す。
		例えばN=4,m=2なら{0011, 0101, 0110, ... 1100}を返す。
		**/
		static void CombinationTable(long long N, long long m, std::vector<std::string>& res)
		{
			if (N <= 0 || m < 0) return;

			long long c = (1LL << m) - 1;
			while (c < 1LL << N)
			{
				res.push_back(ToString(N, c));
				long long x = c & -c, y = c + x;
				c = ((c) & ~y) / x >> 1LL | y;
			}
		}

		/**
		@brief ビット組み合わせテーブル
		@note
		ビットサイズN桁でm個が1となるビット列の集合を昇順で返す。
		例えばN=4,m=2なら{3(0011), 5(0101), 6(0110), ... 12(1100)}を返す。
		計算量は不明だが、素直な実装より高速に動作する。
		**/
		static void CombinationTable(long long N, long long m, std::vector<long long>& res)
		{
			if (N <= 0 || m < 0) return;

			long long c = (1LL << m) - 1;
			while (c < 1LL << N)
			{
				res.push_back(c);
				long long x = c & -c, y = c + x;
				c = ((c) & ~y) / x >> 1LL | y;
			}
		}
	};
}