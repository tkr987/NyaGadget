#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

namespace NyaGadget
{

#define rep(i, begin, end) for (ll i = begin; i < end; i++)
#define fori(i, ...) if(ll i = -1) for(__VA_ARGS__) if(i++, true)
#define each(i, e, v) fori(i, auto& e: v)

	struct Imos2D
	{	// “ñŽŸŒ³IMOS–@ƒ‰ƒCƒuƒ‰ƒŠ
		vector<vector<ll>> grid;

		Imos2D(ll w, ll h)
		{
			grid.resize(h + 1);
			each(i, e, grid)
				e.resize(w + 1);
		}

		void Add(ll hmin, ll hmax, ll wmin, ll wmax, ll v)
		{
			grid[hmin][wmin] += v;
			grid[hmin][wmax + 1] -= v;
			grid[hmax + 1][wmin] -= v;
			grid[hmax + 1][wmax + 1] += v;
		}

		void Update(void)
		{
			rep(i, 0, size(grid))
			{
				rep(j, 1, size(grid[i]))
					grid[i][j] += grid[i][j - 1];
			}
			rep(i, 1, size(grid))
			{
				rep(j, 0, size(grid[i]))
					grid[i][j] += grid[i - 1][j];
			}
		}
	};

#undef fori
#undef each
#undef rep

}
