#include <bits/stdc++.h>

namespace NyaGadget
{
	/***** 文字列処理ライブラリ *****/
 
	struct NyaaString
	{
		/*
		@brief 整数を文字列に変換する
		@param n 変換する整数
		@param size 変換後の桁数
		@return 変換した文字列
		@note
		 sizeがnの桁を超えるときは'0'で埋めて調整する
		*/
		static std::string LtoS(long long n, long long size)
		{
			std::string ret = std::to_string(n);
			std::string zero;
			if ((long long)ret.size() < size)
			{
				for (auto i = 0LL; i < size - (long long)ret.size(); ++i) zero += "0";
			}
			return zero + ret;
		}

		static std::string UpperCase(std::string s)
		{
			for (auto&& e : s) if ('a' <= e && e <= 'z') e = 'A' + ('z' - e);
		}
	};
}
