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
/***** for each macro *****/
#define fori(i, ...) if(ll i = -1) for(__VA_ARGS__) if(i++, true)
#define each(i, e, v) fori(i, auto& e: v)
#define forir(i, ...) if(ll i = Size(v)) for(__VA_ARGS__) if(i--, true)
#define eachr(i, e, v) forir(i, auto& e: boost::adaptors::reverse(v))

/***** lambda *****/
auto Bit = [] // long long bit shift
(auto n) { return (1LL << n); };
auto Count = [] // long long count value
(auto b, auto e, auto x) { return (ll)count(b, e, x); };
auto CtoN = [] // char to number
(auto c) { return (ll)(c - '0'); };
auto DivC = [] // long double div ceiling
(auto a, auto b) { return ceil((ld)a / (ld)b); };
auto Fix = [] // fix value
(auto b, auto e, auto fix)
{ for (auto it = b; it != e; ++it)* it += fix; };
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
	/*** N進数ライブラリ ***/

	template <ll N> struct BaseN
	{	// テンプレート引数Nは基数
		ll n;
		ll x;
		vt<ll> bit;
		vt<ll> rbit;

		BaseN(ll size = 0)
		{
			x = 0; n = N;
			bit.resize(size);
			rbit.resize(size);
		}

		BaseN& operator=(ll r)
		{
			x = r;
			ll size = 0;
			while ((ll)pow(n, size) <= r) size++;
			ll maxsize = Size(rbit);
			rbit.clear();
			rep(i, 0, maxsize - size) rbit.push_back(0);
			repr(i, size - 1, -1)
			{
				rbit.push_back(r / Pow(n, i));
				r -= Pow(n, i) * rbit.back();
			}
			{
				bit.clear();
				bit = rbit;
				reverse(all(bit));
			}
			return *this;
		}

		BaseN& operator ++()
		{
			*this = this->x + 1;
			return *this;
		}

		BaseN operator++(int)
		{
			BaseN res = *this;
			++(*this);
			return res;
		}

		ll X(ll i)
		{	// i桁目のbit値を10進数で返す
			if (Size(bit) <= i) return 0;
			return bit[i] * pow(n, i);
		}

		ll X(ll b, ll e)
		{	// [b, e)桁目のbit値合計を10進数で返す
			ll sum = 0;
			rep(i, b, e) sum += X(i);
			return sum;
		}
	};

	ll ConvertDEC(ll n, vt<ll>& bit, ll i)
	{	// i桁目のbit値を10進数で返す
		if (Size(bit) <= i) return 0;
		return bit[i] * Pow(n, i);
	}
}
