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
#define nya 10                                   // nya size
/***** for each macro *****/
#define fori(i, ...) if(ll i = -1) for(__VA_ARGS__) if(i++, true)
#define each(i, e, v) fori(i, auto& e: v)
#define forir(i, ...) if(ll i = Size(v)) for(__VA_ARGS__) if(i--, true)
#define eachr(i, e, v) forir(i, auto& e: boost::adaptors::reverse(v))

/***** lambda *****/
auto Adjust = [] // add vector or sub vector
(auto b, auto e, auto x)
{ for (auto it = b; it != e; ++it)* it += x; };
auto Bit = [] // long long bit shift
(auto n) { return (1LL << n); };
auto Count = [] // long long count value
(auto b, auto e, auto x) { return (ll)count(b, e, x); };
auto CtoLL = [] // char to long long
(auto c) { return (ll)(c - '0'); };
auto Divc = [] // long double div ceiling
(auto a, auto b) { return ceil((ld)a / (ld)b); };
auto Nya = [] // long long nya size
(auto n) { return (ll)pow(10, n); };
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

	namespace Cpp17
	{
		/**
		@brief Å‘åŒö–ñ”‚ğŒvZ‚·‚éŠÖ”
		@note
		 a‚Æb‚ÌÅ‘åŒö–ñ”‚ğ•Ô‚·
		**/
		ll Gcd(ll a, ll b)
		{
			return b ? Gcd(b, a % b) : a;
		}
		/**
		@brief Å¬Œö”{”‚ğŒvZ‚·‚éŠÖ”
		@note
		 a‚Æb‚ÌÅ¬Œö”{”‚ğ•Ô‚·
		**/
		ll Lcm(ll a, ll b)
		{
			return a / Gcd(a, b) * b;
		}
	}
};
