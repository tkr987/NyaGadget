#include <bits/stdc++.h>
#include <boost/range/adaptors.hpp>
#include <boost/multiprecision/cpp_int.hpp>

/***** type *****/
using namespace std;
using ll = long long;
using ld = long double;
template <class T> using vt = vector<T>;
template <class T> using vvt = vector<vector<T>>;
template <class T> using vvvt = vector<vector<vector<T>>>;
using ml = boost::multiprecision::cpp_int;

/***** define *****/
#define all(c) (c).begin(), (c).end()            // begin to end
#define rep(i, b, e) for (ll i = b; i < e; i++)  // repeat
#define repr(i, b, e) for (ll i = b; e < i; i--) // repeat reverse
/***** const value *****/
#define llong_max 9223372036854775807            // 9 * 10^18
#define ldbl_max 1.79769e+308                    // 1.7 * 10^308
#define mod 1000000007                           // 1e9 + 7
#define pi 3.14159265                            // 3.14 ...
#define nyan 10                                  // nyan size
/***** for each macro *****/
#define fori(i, ...) if(ll i = -1) for(__VA_ARGS__) if(i++, true)
#define each(i, e, v) fori(i, auto& e: v)
#define forir(i, ...) if(ll i = Size(v)) for(__VA_ARGS__) if(i--, true)
#define eachr(i, e, v) forir(i, auto& e: boost::adaptors::reverse(v))

/***** lambda *****/
auto Fix = [] // fix value
(auto b, auto e, auto fix)
{ for (auto it = b; it != e; ++it)* it += fix; };
auto Bit = [] // long long bit shift
(auto n) { return (1LL << n); };
auto Count = [] // long long count value
(auto b, auto e, auto x) { return (ll)count(b, e, x); };
auto CtoN = [] // char to number
(auto c) { return (ll)(c - '0'); };
auto DivC = [] // long double div ceiling
(auto a, auto b) { return ceil((ld)a / (ld)b); };
auto NyaN = [] // long long nyan size
(auto n) { return (ll)pow(10, n); };
auto Size = []  // long long collection size
(auto& c) { return (ll)(c).size(); };
auto Sum = [] // long long accumulate
(auto b, auto e) { return accumulate(b, e, 0LL); };

/***** template *****/
template <class T> vvt<T> VVT
(ll ys, ll xs, T fill = T())
{	// vector<vector<T>> resize + fill
	vvt<T> v(ys);
	each(i, y, v) { y.resize(xs, fill); } return v;
}
template <class T> vvvt<T> VVVT
(ll zs, ll ys, ll xs, T fill = T())
{	// vector<vector<vector<T>>> resize + fill
	vvvt<T> v(zs);
	each(i, z, v) { z = VVT(ys, xs, fill); } return v;
}
template <class T> vt<T> InputVT
(ll size, T fix = T())
{   // input vector<T> (T != struct) + fix
	vt<T> v(size);
	each(i, e, v) { cin >> e; e += fix; } return v;
}
template <class T> vvt<T> InputVVT
(ll ys, ll xs, T fix = T())
{   // input vector<vector<T>> (T != struct) + fix
	vvt<T> v(ys); each(i, y, v) y.resize(xs);
	each(i, y, v) each(j, x, y) { cin >> x; x += fix; } return v;
}
template <class T> vvvt<T> InputVVVT
(ll zs, ll ys, ll xs, T fix = T())
{	// input vector<vector<vector<T>>> (T != struct) + fix
	vvvt<T> v(zs);
	each(i, z, v) { z = InputVVT<T>(ys, xs, fix); } return v;
}

namespace NyaGadget
{
	/*** 除算の同値商集合を列挙するライブラリ ***/

	struct TableOfEqualDivResult
	{	// q = fn / [fdmin, fdmax)の同値商集合を格納
		// fdminとfdmaxが半開区間なことに注意
		ll c = 0;     // 分母集合の要素数
		ll q = 0;     // 商
		ll fn = 0;    // 分子
		ll fdmin = 0; // 分母最小値
		ll fdmax = 0; // 分母最大値
	};

	/**
	@brief 除算の同値商集合を求める関数
	@param rmax 分子最大値
	@param res 結果を格納する構造体
	@note
	 除算の同値商集合を返す。
	 つまり、分数の計算 rmax / [fdmin, fdmax) をll型に変換したとき
	 同値となる集合[fdmin, fdmax)を返す。
	 計算量はO(sqrt(rmax))
	**/
	void TableOfEqualDiv
	(ll rmax, vt<TableOfEqualDivResult>& res)
	{
		TableOfEqualDivResult test;
		test.fn = rmax;
		for (ll i = 1; i * i <= rmax; i++)
		{
			test.c = 1;
			test.q = rmax / i;
			test.fdmin = i;
			test.fdmax = i + 1;
			res.push_back(test);
		}
		while (test.q != 1)
		{
			test.q = rmax / (res.back().fdmax);
			test.fdmin = res.back().fdmax;
			test.fdmax = rmax / test.q + 1;
			test.c = test.fdmax - test.fdmin;
			res.push_back(test);
		}
	}
}