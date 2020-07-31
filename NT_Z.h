#include <bits/stdc++.h>
using namespace std;

namespace NyaGadget
{
	/***** Zアルゴリズム *****/

	/**
	@brief 最長共通接頭辞を返す
	@param s 入力文字列
	@param res 結果を格納する配列
	@note
	 文字列の最長共通接頭辞を返す 計算量O(S)
	**/
	void NT_Z(const string& s, vector<long long>& res)
	{
		res.resize(s.size());
		for (long long i = 1, j = 0; i < (long long)s.size(); i++) {
			if (i + res[i - j] < j + res[j])
			{
				res[i] = res[i - j];
			}
			else
			{
				long long k = max((long long)0, j + res[j] - i);
				while (i + k < (long long)s.size() && s[k] == s[i + k]) ++k;
				res[i] = k;
				j = i;
			}
		}
		res[0] = (long long)s.size();
	}

	/**
	@brief 最長共通接頭辞を返す
	@param s 入力数列
	@param res 結果を格納する配列
	@note
	 数列の最長共通接頭辞を返す 計算量O(N)
	**/
	void NT_Z(const vector<long long>& v, vector<long long>& res)
	{
		res.resize(v.size());
		for (long long i = 1, j = 0; i < (long long)v.size(); i++) {
			if (i + res[i - j] < j + res[j])
			{
				res[i] = res[i - j];
			}
			else
			{
				long long k = max((long long)0, j + res[j] - i);
				while (i + k < (long long)v.size() && v[k] == v[i + k]) ++k;
				res[i] = k;
				j = i;
			}
		}
		res[0] = (long long)v.size();
	}
}
