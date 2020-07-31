#include <bits/stdc++.h>

namespace NyaGadget
{
	/***** UnionFind���C�u���� *****/

	struct UnionFindVertex
	{	// ���_��\������\����
		long long self = 0; // �������g�̃C���f�b�N�X
		long long root = 0; // ���̃C���f�b�N�X
		long long size = 0; // �����������Ă���؂̃T�C�Y
	};

	struct DS_UnionFind
	{	// �؍\���őe�W���f�[�^������������
		std::vector<UnionFindVertex> v;

		/**
		@brief �R���X�g���N�^
		@param max �ő�l
		@note
		 [0-max]�̑f�W���f�[�^�\�����쐬����
		**/
		DS_UnionFind(long long max)
		{	// [0-max]�̃f�[�^�\���ɂ��邽�߁Amax+1�Ń��T�C�Y
			v.resize(max + 1);
			for (long long i = 0; i < max + 1; i++)
			{	// �e���_�̍����������g�ŏ������A�؃T�C�Y��1
				v[i].self = i;
				v[i].root = i;
				v[i].size = 1;
			}
		}

		/**
		@brief �v�fx�̍�����������֐�
		**/
		long long Find(long long x)
		{
			if (x == v[x].root) return x;
			// ���̒T��������Ɠ����Ɏ�����O(1)�ō����Q�Ƃł���悤�ɂ���(�o�H���k)
			v[x].root = Find(v[x].root);
			return v[x].root;
		}

		long long Size(long long x)
		{	// �v�fx��������W���̃T�C�Y���擾����
			return v[Find(x)].size;
		}

		bool Same(long long x, long long y)
		{	// �v�fx�Ɨv�fy�������W�����ǂ������ׂ�
			return Find(x) == Find(y);
		}

		/**
		@brief �v�f�𕹍�����֐�
		@param x ��������v�fx
		@param y ��������v�fy
		@note
		 �v�fx���܂ޖ؂Ɨv�fy���܂ޖ؂��u�T�C�Y�D��Łv��������B
		 �������Ax��y�����ɓ����؂ɑ����Ă���Ƃ��͉������Ȃ��B
		 ���������Ƃ�true�A�������Ȃ������Ƃ�false��Ԃ��B
		 �T�C�Y�ɂ��H�v�ɂ��A�v�Z�ʂ̓A�b�J�[�}���̋t�֐��ɂȂ�B
		**/
		bool Union(long long x, long long y)
		{
			long long root1 = Find(x);
			long long root2 = Find(y);

			// ���ɓ����؂ɑ����Ă���Ƃ��͉������Ȃ�
			if (root1 == root2) return false;

			// �T�C�Y�̏������؂̍����T�C�Y�̑傫���؂̍��Ɍq���ŕ�������
			if (v[root1].size < v[root2].size)
			{
				v[root1].root = root2;
				v[root2].size += v[root1].size;
			}
			else
			{
				v[root2].root = root1;
				v[root1].size += v[root2].size;
			}
			return true;
		}

		/**
		@brief �v�f�𕹍�����֐�
		@param x ��������v�f1
		@param y ��������v�f2
		@param p  �e�w��
		@note
		 �v�fx���܂ޖ؂Ɨv�fy���܂ޖ؂��up���܂ޖ؂�e�Ƃ��āv��������B
		 �������Ax��y�����ɓ����؂ɑ����Ă���Ƃ��͉������Ȃ��B
		 ���������Ƃ�true�A�������Ȃ������Ƃ�false��Ԃ��B
		 �v�Z�ʂ�O(logN)�ɂȂ�A�A�b�J�[�}���̋t�֐��ɔ�ׂĎ኱�x���Ȃ�B
		**/
		bool Union(long long x, long long y, long long p)
		{
			long long root1 = Find(x);
			long long root2 = Find(y);
			long long rootp = Find(p);

			// ���ɓ����؂ɑ����Ă���Ƃ��͉������Ȃ�
			if (root1 == rootp && root2 == rootp) return false;

			// �q�̖؂�e�̖؂֕�������
			if (rootp == root1)
			{
				v[root2].root = rootp;
				v[rootp].size += v[root2].size;
			}
			else if (rootp == root2)
			{
				v[root1].root = rootp;
				v[rootp].size += v[root1].size;
			}
			else
			{
				v[root1].root = rootp;
				v[rootp].size += v[root1].size;
				v[root2].root = rootp;
				v[rootp].size += v[root2].size;
			}
			return true;
		}
	};
}
