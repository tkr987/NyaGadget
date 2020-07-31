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
auto Adjust = [] // add vector or sub vector
(auto b, auto e, auto x)
{ for (auto it = b; it != e; ++it)* it += x; };
auto Bit = [] // long long bit shift
(auto n) { return (1LL << n); };
auto Count = [] // long long count value
(auto b, auto e, auto x) { return (ll)count(b, e, x); };
auto CtoLL = []  // char to long long
(auto c) { return (ll)(c - '0'); };
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
	/*** 中央値分割ライブラリ ***/

	template <class T> struct MedianSplittingResult
	{	// MedianSplitting()の結果を格納する構造体
		priority_queue<T> lpq;  // left queue (昇順 priority queue)
		priority_queue<T, vt<T>, greater<T>> rpq;  // right queue (降順 priority queue)

		vt<T> median; // 中央値
		vt<T> add_lv; // 左のキューに加算された値
		vt<T> add_rv; // 右のキューに加算された値
		vt<T> sub_lv; // 左のキューに減算された値
		vt<T> sub_rv; // 右のキューに減算された値
	};

	template <class T> void MedianSplitting
	(T add, MedianSplittingResult<T>& res)
	{
		res.median.clear();
		res.add_lv.clear(); res.add_rv.clear();
		res.sub_lv.clear(); res.sub_rv.clear();
		if (res.lpq.empty())
		{	// 1つめの要素はlpqへ挿入
			res.lpq.push(add);
			res.add_lv.push_back(add);
			res.median.push_back(add);
			return;
		}

		if (Size(res.rpq) < Size(res.lpq))
		{	// Size(rpq)が小さいときだけrpqへの要素挿入を許可
			res.rpq.push(add);
			res.add_rv.push_back(add);
			if (res.rpq.top() < res.lpq.top())
			{	// rpqが小さいのはngなので交換
				T ltemp = res.lpq.top();
				T rtemp = res.rpq.top();
				res.lpq.pop(); res.rpq.pop();
				res.sub_lv.push_back(ltemp); res.sub_rv.push_back(rtemp);
				res.lpq.push(rtemp); res.rpq.push(ltemp);
				res.add_lv.push_back(rtemp); res.add_rv.push_back(ltemp);
			}
		}
		else
		{
			res.lpq.push(add);
			res.add_lv.push_back(add);
			if (res.rpq.top() < res.lpq.top())
			{	// rpqが小さいのはngなので交換
				T ltemp = res.lpq.top();
				T rtemp = res.rpq.top();
				res.lpq.pop(); res.rpq.pop();
				res.sub_lv.push_back(ltemp); res.sub_rv.push_back(rtemp);
				res.lpq.push(rtemp); res.rpq.push(ltemp);
				res.add_lv.push_back(rtemp); res.add_rv.push_back(ltemp);
			}
		}

		if (Size(res.lpq) != Size(res.rpq))
		{	// 要素数が奇数のとき中央値は1個
			res.median.push_back(res.lpq.top());
		}
		else
		{	// 要素数が偶数のとき中央値は2個
			res.median.push_back(res.lpq.top());
			res.median.push_back(res.rpq.top());
		}
	}
}
