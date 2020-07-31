#include <bits/stdc++.h>
using namespace std;

namespace NyaGadget
{
	/***** �O���t���B�\�����C�u���� *****/

	struct GT_NyaaReachable
	{
		/**
		@brief ���_s����t�ւ̓��B�\���𒲂ׂ�֐�
		@param s �J�n�̒��_
		@param t �ڕW�̒��_
		@param lg �אڃ��X�g
		@return ���B�ł���Ƃ���true, �ł��Ȃ��Ƃ�false��Ԃ��B
		@note
		 �����I�ɂ�NyaaReachable::Run(s,g,res)�Ɠ����B
		 �v�Z�ʂ�O(max(V, E))���x���Ǝv����(���ؖ�)�B
		**/
		bool Run(long long s, long long t, const vector<vector<long long>>& lg)
		{
			vector<bool>res(lg.size(), false);
			NyaaDFS dfs;
			dfs.Run(-1, s, lg, res);
			return res[t];
		}

		/**
		@brief �S���_�ɑ΂���s����̓��B�\���𒲂ׂ�֐�
		@param s �J�n�̒��_
		@param lg �אڃ��X�g
		@param res ���ʂ��i�[����\����
		@note
		 �v�Z�ʂ�O(max(V, E))���x���Ǝv����(���ؖ�)�B
		 s=0,res[N]=true�Ȃ璸�_0����N�֓��B�\�Ƃ������Ƃ�\���B
		**/
		void Run(long long s, const vector<vector<long long>>& lg, vector<bool>& res)
		{
			res.resize(lg.size(), false);
			NyaaDFS dfs;
			dfs.Run(-1, s, lg, res);
		}

		struct NyaaDFS
		{
			/**
			@brief DFS�����֐�
			@param r ���_v�̍�
			@param v ���݂̒��_
			@param g ��������O���t
			@param res ���ʂ��i�[����\����
			**/
			void Run(long long r, long long v, const vector<vector<long long>>& lg, vector<bool>& res)
			{	// ���_�̍X�V����
				res[v] = true;
				for (auto e : lg[v])
				{
					if (e == r) continue; // ��߂��h��
					if (res[e]) continue; // �K��ςݒ��_
					Run(v, e, lg, res);
				}
			}
		};
	};
}