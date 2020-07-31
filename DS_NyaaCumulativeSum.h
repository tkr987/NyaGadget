#include <bits/stdc++.h>

namespace NyaGadget
{
	/***** �ݐϘa���C�u���� *****/

	template <class T> struct DS_NyaaCumulativeSum
	{
		std::vector<T> sum;
		DS_NyaaCumulativeSum(std::vector<T>& v)
		{
			if (v.empty()) sum.push_back(0);
			else sum.push_back(v.front());
			for (long long i = 1; i < (long long)v.size(); ++i) sum.push_back(sum.back() + v[i]);
		}
		/**
		@brief �͈͂̍��v�l���擾����
		@note
		 ���[s, t)�̍��v�l��Ԃ��B
		 �͈͊O��s��t�ɑ΂��Ă�0��Ԃ��B
		**/
		T Range(long long s, long long t)
		{
			if (s < 0) s = 0;
			if ((long long)sum.size() < t) t = (long long)sum.size();
			// �߂�l�̌v�Z
			if (t <= 0 || (long long)sum.size() <= s) return 0;
			return (s == 0) ? sum[t - 1] : sum[t - 1] - sum[s - 1];
		}
	};
}
