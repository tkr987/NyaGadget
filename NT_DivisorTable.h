#include <bits/stdc++.h>
using namespace std;

namespace NyaGadget
{
	/***** ρρCu *****/

	/**
	@brief ρπρ·ι
	@param
	 nΜρπansΙSΔi[·ιB
	 vZΚO(sqrt(N))AρΜΒΝlog(N)φxΙΘιB
	**/
	void NT_DivisorTable(long long n, std::vector<long long>& ans)
	{
		for (auto i = 1LL; i * i <= n; i++)
		{
			if (n % i == 0)
			{
				ans.push_back(i);
				if (i * i == n) continue;
				ans.push_back(n / i);
			}
		}
		sort(ans.begin(), ans.end());
	}
}
