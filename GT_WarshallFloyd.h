#include <bits/stdc++.h>

namespace NyaGadget
{
	/***** ���[�V�����t���C�h�@���C�u���� *****/
	struct GT_WarshallFloyd
	{
		/**
		@brief �S�_�ΊԍŒZ�H�����߂�
		@param mg �אڍs��
		@param res �ŒZ������Ԃ�
		@param inf ���݂��Ȃ��ӂ̒l
		@note
		�v�Z��O(V^3)�Ȃ̂ŗאڍs��ɂ����K�p�ł��Ȃ��B
		���̕H������ꍇfalse��Ԃ��B
		**/
		static bool Run(std::vector<std::vector<long long>>& mg, std::vector<std::vector<long long>>& res, long long inf = LLONG_MAX)
		{
			long long vmax = (long long)mg.size();
			for (auto i = 0LL; i < vmax; ++i) mg[i][i] = 0;

			res = mg;
			for (auto k = 0LL; k < vmax; k++)
			{
				for (auto i = 0LL; i < vmax; i++)
				{
					if (res[i][k] == inf) continue;
					for (auto j = 0LL; j < vmax; j++)
					{
						if (res[k][j] == inf) continue;
						res[i][j] = std::min(res[i][j], res[i][k] + res[k][j]);
					}
				}
			}
			for (auto i = 0LL; i < vmax; i++)
			{
				if (res[i][i] < 0) return false;
				res[i][i] = inf;
			}
			return true;
		}
	};
}