#include <bits/stdc++.h>
#include <boost/range/adaptors.hpp>

using namespace std;
using ll = long long;
using ld = long double;

namespace NyaGadget
{
	/*** �񕪒T�����C�u���� ***/

	struct BinarySearchResult
	{	// �񕪒T���̌��ʂ��i�[����
		ll ok_min = 0;		// ok�ƂȂ�ŏ��l
		ll ok_max = 0;		// ok�ƂȂ�ő�l
		ll ok_count = 0;	// ok�̌�
	};

	struct BinarySearchSample
	{	// �񕪒T���ɍŒ���K�v�ȕϐ�
		// ���ɕϐ����K�v�ȂƂ��͐V�����\���̂��`���邱�ƁB
		ll key;		// �񕪒T���̔�r�l
		ll mid;	    // �񕪒T���̒��Ԓl
	};

	bool BinarySearchTest(BinarySearchSample& bsv)
	{	// ����̓e�X�g�p�֐��Ȃ̂ŁA�V������`���邱�ƁB
		// �Ȃ��A�߂�l��bool�^�A������BinarySearch�p�̍\���̂ł���K�v������B
		return bsv.mid < bsv.key;
	}

	/*
	@brief �񕪒T���֐�
	@param rmin �T���͈͍ŏ��l
	@param rmax �T���͈͍ő�l
	@param value �񕪒T���ɕK�v�ȕϐ�
	@param IsOK �񕪒T���̔�r�֐�
	@param res ���ʂ��i�[����\����
	@note
	 rmin < rmax �ɂȂ�悤�ɒT���͈͂��w�肷�邱�ƁB
	 value ��BinarySearchSample���g�������\���̂��`���ăe���v���[�g��������w�肷��B
	 IsOK()��value�Ɠ����^�̕ϐ�����������󂯎��A������r��v�Z�ɗ��p����֐��Ƃ���B
	 IsOK()�͒ʏ�Aok�ƂȂ��r���ʂ�bool�l�ŕԂ��B
	 �T�����ʂ́Aok�ƂȂ�͈͂�res�Ɋi�[�����B
	 �������Aok�ƂȂ�l�����݂��Ȃ��Ƃ���ok_count��0�ɂȂ�B
	*/
	template <class T> void
	BinarySeach(ll rmin, ll rmax, T& value, function<bool(T&)> IsOK, BinarySearchResult& res)
	{	// ng��ok��rmax+2�̂܂܂������Ƃ��͓���ȃe�X�g�P�[�X�ɂȂ�
		ll ng = rmax + 2;
		ll ok = rmax + 2;

		// �܂��Aok��ng��rmin��rmax�ǂ��炩���ׂ�
		// �Ȃ��Armin��rmax���̂������𖞂������Ƃ�����̂ŁA�����l��-1�A+1����
		value.mid = rmin;
		if (IsOK(value))
			ok = rmin - 1;
		else
			ng = rmin - 1;
		value.mid = rmax;
		if (IsOK(value))
			ok = rmax + 1;
		else
			ng = rmax + 1;

		// �����𖞂����l��1�����݂��Ȃ�
		if (ok == rmax + 2)
			return;
		if (ng == rmax + 2)
		{	// �T���͈͑S�Ă̒l�������𖞂���
			res = { rmin, rmax, rmax - rmin + 1 };
			return;
		}

		while (1 < abs(ok - ng))
		{	// ok��ng�̂ǂ��炪�傫�����킩��Ȃ����Ƃ��l�����Đ�Βl�����
			value.mid = (ok + ng) / 2;

			if (IsOK(value))
				ok = value.mid;
			else
				ng = value.mid;
		}

		res.ok_min = min(res.ok_min, ok);
		res.ok_max = max(res.ok_max, ok);
		res.ok_count = res.ok_max - res.ok_min + 1;
	}
}