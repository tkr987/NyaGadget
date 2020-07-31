#include <bits/stdc++.h>

namespace NyaGadget
{
	/***** �Œ����������񃉃C�u���� *****/

	struct NT_NyaaLIS
	{
		/**
		@note
		eq = false �̂Ƃ����`�Œ�����������
		�܂� res[i] < res[i+1] �ƂȂ�悤�ȍŒ�����������̒����𓾂�B
		eq = true �̂Ƃ��L�`�Œ�����������
		�܂� res[i] <= res[i+1] �ƂȂ�悤�ȍŒ�����������̒����𓾂�B
		**/
		static long long Run(const std::vector<long long>& v, bool eq = false)
		{
			std::vector<long long> test;
			if (!eq)
			{
				for (auto i = 0LL; i < (long long)v.size(); ++i)
				{
					auto it = std::lower_bound(test.begin(), test.end(), v[i]);
					if (it == test.end()) test.push_back(v[i]);
					else *it = v[i];
				}
			}
			else
			{
				for (auto i = 0LL; i < (long long)v.size(); ++i)
				{
					auto it = std::upper_bound(test.begin(), test.end(), v[i]);
					if (it == test.end()) test.push_back(v[i]);
					else *it = v[i];
				}
			}
			return (long long)test.size();
		}
	};
}