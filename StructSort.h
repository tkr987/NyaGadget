#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

namespace NyaGadget
{
	struct NyaStruct {
		ll x = 0;
		ll y = 0;
		ll z = 0;
	};

	auto NyaSort = [](const NyaStruct& l, const NyaStruct& r)
	{	// �~���͉��Z�q>, �����͉��Z�q<, if���̗D��Ń\�[�g�����
		if (l.x != r.x) return x > r.x;
		if (l.y != r.y) return y < r.y;
		return l.z < r.z;
	};
}
