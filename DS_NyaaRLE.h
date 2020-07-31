#include <bits/stdc++.h>

namespace NyaGadget
{
	/*** ランレングス圧縮ライブラリ ***/

	template <class T> struct RunLengthEncodingResult
	{	// ランレングス圧縮の結果を格納する構造体
		long long begin = 0; // 区間開始位置
		long long end = 0;   // 区間終了位置
		std::vector<T> sub;  // 区間データ
	};

	template <> struct RunLengthEncodingResult<std::string>
	{	// ランレングス圧縮の結果を格納する構造体
		long long begin = 0; // 区間開始位置
		long long end = 0;   // 区間終了位置
		std::string sub;     // 区間データ
	};

	struct DS_NyaaRLE
	{
		/**
		@brief 文字列のランレングス圧縮
		@param s 圧縮する文字列
		@param res 圧縮結果
		**/
		DS_NyaaRLE(std::string& s, std::vector<RunLengthEncodingResult<std::string>>& res)
		{
			res.push_back({ 0, 0, "" });
			for (long long i = 0; i < (long long)s.size(); i++)
			{
				if (i == (long long)s.size() - 1)
				{
					res.back().end = i + 1;
					res.back().sub = s.substr(res.back().begin, i + 1 - res.back().begin);
					return;
				}
				if (s[i] != s[i + 1])
				{
					res.back().end = i + 1;
					res.back().sub = s.substr(res.back().begin, i + 1 - res.back().begin);
					res.push_back({ i + 1, 0, "" });
				}
			}
		}

		/**
		@brief 配列のランレングス圧縮
		@param v 圧縮する配列
		@param res 圧縮結果
		**/
		template <class T> DS_NyaaRLE(std::vector<T>& v, std::vector<RunLengthEncodingResult<T>>& res)
		{
			res.push_back({ 0, 0, std::vector<T>() });
			for (long long i = 0; i < (long long)v.size(); i++)
			{
				if (i == (long long)v.size() - 1)
				{
					res.back().end = i + 1;
					for (long long j = res.back().begin; j < i + 1; j++) res.back().sub.push_back(v[j]);
					return;
				}
				if (!IsSame(v[i], v[i + 1]))
				{
					res.back().end = i + 1;
					for (long long j = res.back().begin; j < i + 1; j++) res.back().sub.push_back(v[j]);
					res.push_back({ i + 1, 0, std::vector<T>() });
				}
			}
		}

		template <class T> bool IsSame(T& l, T& r)
		{	// lとrが同値かどうか調べる
			return l == r;
		}
	};
}