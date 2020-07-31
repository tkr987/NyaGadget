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
#define bit(n) (1LL << (n))                      // bit shift
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

/***** lambda *****/
auto Count = [] // long long count value
(auto b, auto e, auto x) { return (ll)count(b, e, x); };
auto Divc = []  // long double div ceiling
(auto a, auto b) { return ceil((ld)a / (ld)b); };
auto Size = []  // long long collection size
(auto& c) { return (ll)(c).size(); };
auto Sum = []   // long long accumulate
(auto b, auto e) { return accumulate(b, e, 0LL); };
auto VVT = []   // vector<vector<T>> resize 
(auto& vvt, auto ysize, auto xsize)
{ vvt.resize(ysize); each(i, vy, vvt) vy.resize(xsize); };
auto VVVT = []   // vector<vector<vector<T>>> resize 
(auto& vvvt, auto zsize, auto ysize, auto xsize)
{ vvvt.resize(zsize); each(z, vz, vvvt) VVT(vz, ysize, xsize); };
auto InVVT = []  // input vector<vector<T>> (T != struct)
(auto& vvt) { each(y, vy, vvt) each(x, e, vy) cin >> e; };
auto InVVVT = [] // input vector<vector<vector<T>>> (T != struct)
(auto& vvvt) { each(z, vz, vvvt) InVVT(vz); };

namespace NyaGadget
{
	/***区間内要素数の数え上げライブラリ***/

	/**
	@bfief 区間要素数を取得する関数
	@param begin 検索範囲(最小値)
	@param end 検索範囲(最大値)
	@param l 検索区間(最小値)
	@param r 検索区間(最大値)
	@note
		vectorにおける検索区間内の要素数を返す。
	**/
	template <class T> static ll ElementCountingOfRange
	(typename vt<T>::iterator begin, typename vt<T>::iterator end, const T& l, const T& r)
	{
		auto itl = lower_bound(begin, end, l);
		auto itr = upper_bound(begin, end, r);

		return (itr == end) ? --itr - itl + 1 : itr - itl;
	}

	/**
	@bfief 区間要素数を取得する関数
	@param begin 検索範囲(最小値)
	@param end 検索範囲(最大値)
	@param l 検索区間(最小値)
	@param r 検索区間(最大値)
	@param Compare 比較関数
	@note
	 vectorにおける検索区間内の要素数を返す。
	 この関数は構造体のvectorなど複雑なデータ構造を処理するために用意された。
	**/
	template <class T> static ll ElemetCountingOfRange
	(typename vt<T>::iterator begin, typename vt<T>::iterator end, const T& l, const T& r, function<bool(const T&, const T&)> Compare)
	{
		auto itl = lower_bound(begin, end, l, Compare);
		auto itr = upper_bound(begin, end, r, Compare);

		return (itr == end) ? --itr - itl + 1 : itr - itl;
	}
}