#include <bits/stdc++.h>
using namespace std;

namespace NyaGadget
{
	/***** �񐔗񋓃��C�u���� *****/

	/**
	@brief �񐔂�񋓂���
	@param
	 n�̖񐔂�ans�ɑS�Ċi�[����B
	 �v�Z��O(sqrt(N))�A�񐔂̌���log(N)���x�ɂȂ�B
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
