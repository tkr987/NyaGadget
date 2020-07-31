#include <bits/stdc++.h>
#include <boost/range/adaptors.hpp>
#include <boost/multiprecision/cpp_int.hpp>

/***** type *****/
using namespace std;
using ll = long long;
using ld = long double;
using ml = boost::multiprecision::cpp_int;

/***** lambda *****/
auto Count = [] // long long count value
(auto b, auto e, auto x) { return (ll)count(b, e, x); };
auto Divc = []  // long double div ceiling
(auto a, auto b) { return ceil((ld)a / (ld)b); };
auto Size = []  // long long collection size
(auto& c) { return (ll)(c).size(); };
auto Sum = []   // long long accumulate
(auto b, auto e) { return accumulate(b, e, 0LL); };

/***** define *****/
#define all(c) (c).begin(), (c).end()            // begin to end
#define rep(i, b, e) for (ll i = b; i < e; i++)  // repeat
#define repr(i, b, e) for (ll i = b; e < i; i--) // repeat reverse
/***** const value *****/
#define llong_max 9223372036854775807            // 9 * 10^18
#define ldbl_max 1.79769e+308                    // 1.7 * 10^308
#define mod 1000000007                           // 1e9 + 7
#define pi 3.14159265                            // 3.14 ...
/***** for each macro *****/
#define fori(i, ...) if(ll i = -1) for(__VA_ARGS__) if(i++, true)
#define each(i, e, v) fori(i, auto& e: v)
#define forir(i, ...) if(ll i = Size(v)) for(__VA_ARGS__) if(i--, true)
#define eachr(i, e, v) forir(i, auto& e: boost::adaptors::reverse(v))

namespace NyaGadget
{

	/*** ランレングス圧縮ライブラリ ***/

	template <class T> struct RunLengthEncodingResult
	{	// ランレングス圧縮の結果を格納する構造体
		ll begin = 0;  // 区間開始位置
		ll end = 0;    // 区間終了位置
		vector<T> sub; // 区間データ
	};

	template <> struct RunLengthEncodingResult<string>
	{	// ランレングス圧縮の結果を格納する構造体
		ll begin = 0;  // 区間開始位置
		ll end = 0;    // 区間終了位置
		string sub;    // 区間データ
	};

	template <class T> bool RunLengthEncodingTest(T& l, T& r)
	{	// 複雑な同値関係を定義したい場合は、新しく定義すること。
		return l == r;
	}

	/**
	@brief 文字列のランレングス圧縮
	@param s 圧縮する文字列
	@param res 圧縮結果
	**/
	void RunLengthEncoding
	(string& s, vector<RunLengthEncodingResult<string>>& res)
	{
		res.push_back({ 0, 0, "" });
		each(i, e, s)
		{
			if (i == Size(s) - 1)
			{
				res.back().end = i + 1;
				res.back().sub = s.substr(res.back().begin, i + 1 - res.back().begin);
				break;
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
	template <class T> void RunLengthEncoding
	(vector<T>& v, vector<RunLengthEncodingResult<T>>& res)
	{
		res.push_back({ 0, 0, vector<T>() });
		each(i, e, v)
		{
			if (i == Size(v) - 1)
			{
				res.back().end = i + 1;
				rep(j, res.back().begin, i + 1)
					res.back().sub.push_back(v[j]);
				break;
			}
			if (!RunLengthEncodingTest(v[i], v[i + 1]))
			{
				res.back().end = i + 1;
				rep(j, res.back().begin, i + 1)
					res.back().sub.push_back(v[j]);
				res.push_back({ i + 1, 0, vector<T>() });
			}
		}
	}

	/**
	@brief 配列のランレングス圧縮
	@param v 圧縮する配列
	@param IsSame 同値関係を定義した関数
	@param res 圧縮結果
	@note
	 このテンプレート関数は複雑な同値関係でランレングス圧縮するために用意された。
	**/
	template <class T> void RunLengthEncoding
	(vector<T>& v, function<bool(T&, T&)> IsSame, vector<RunLengthEncodingResult<T>>& res)
	{
		res.push_back({ 0, 0, vector<T>() });
		each(i, e, v)
		{
			if (i == Size(v) - 1)
			{
				res.back().end = i + 1;
				rep(j, res.back().begin, i + 1)
					res.back().sub.push_back(v[j]);
				break;
			}
			if (!IsSame(v[i], v[i + 1]))
			{
				res.back().end = i + 1;
				rep(j, res.back().begin, i + 1)
					res.back().sub.push_back(v[j]);
				res.push_back({ i + 1, 0, vector<T>() });
			}
		}
	}
}