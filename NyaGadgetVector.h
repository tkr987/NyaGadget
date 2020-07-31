#include <vector>

using namespace std;

class NyaGadgetVector
{
public:
	/**
	@brief ���Z�֐�
	@note
	 collection�̑S�v�f��add_value�����l�����Z����
	**/
	template<typename T> static void Add(vector<T>& collection, T add_value)
	{
		for (auto& e : collection)
			e += add_value;
	}
	/**
	@brief ��r�֐�
	@note
	 collection1��collection2�̒��g���������ǂ������ׂ�B
	 collection�̗v�f���S�ē����Ȃ�0��Ԃ��B
	 collection�̗v�f�������łȂ���΁A�قȂ�v�f�̌���Ԃ��B
	**/
	template<typename T> static long long Compare(const vector<T>& collection1, const vector<T>& collection2)
	{
		long long diff = 0;
		long long n = min((long long)collection1.size(), (long long)collection2.size());
		for (long long i = 0; i < n; i++)
		{
			if (collection1[i] != collection2[i])
				diff++;
		}
		diff += abs(collection1.size() - collection2.size());

		return diff;
	}
	/**
	@brief ����v�f���擾�֐�
	@note
	 �����l�̗v�f����������̂����ׂ�B
	 �R���e�iinput_collection�̓����v�f�̌��𐔂���output_collection�Ɍ��ʂ��i�[����B
	 output_collection�̑������ɂ͗v�f�̒l�A�������ɂ͗v�f�̌����i�[�����B
	------------------------------------------------------------------------------------------
	[sample code]
	long long main() {
		vector<long> input_collection = {10000000000, 10000000000, 2, 1, 2, 2, 2};
		vector<pair<long, long long>> count_collection;			// p.first=value, p.second=size
		NyaGadgetVector::CountValue<long>(input_collection, count_collection);

		for (const auto& e : count_collection)
			cout << "(" << e.first << "," << e.second << ")";
		return 0;
	}
	------------------------------------------------------------------------------------------
	[output]
	(1,1)(2,4)(10000000000,2)
	**/
	template<typename T> static void CountValue(const vector<T>& input_collection, vector<pair<T, long long>>& output_collection)
	{
		map<T, long long> count_collection;
		for (const auto& e : input_collection)
			count_collection[e] += 1;

		for (const auto e : count_collection)
			output_collection.push_back(make_pair(e.first, e.second));
	}
	/**
	@brief �v�f�폜�֐�
	@note
	�萔����O(4)��input_collection[index]���폜����(STL��erase��O(N))�B
	�������A�����ō폜����v�f�Ɩ����̗v�f��swap����H�v�����Ă��邽�߁A�R���e�i�̗v�f�̏��Ԃ͕ۏ؂���Ȃ��B
	**/
	template<typename T> static void EraceO4(const vector<T>& input_collection, long long index)
	{
		T temp = input_collection[input_collection.size() - 1];
		input_collection[input_collection.size() - 1] = input_collection[index];
		input_collection[index] = temp;
		input_collection.erase(input_collection.size() - 1, 1);

	}
	/**
	@brief �W�����͊֐�
	@note
	 �W�����͂�����͂��ꂽsize�̒l��collection�Ɋi�[����
	**/
	template<typename T> static void InputStream(vector<T>& collection, long long size)
	{
		if ((long long)collection.size() <= size)
			collection.resize(size);

		for (long long i = 0; i < size; i++)
			cin >> collection[i];
	}
	/**
	@brief pair�̈����𔽓]������֐�
	@note
	 input_collection��pair.first��pair.second�����ւ��ĐV���ȃR���e�i���쐬����B
	**/
	template<typename T, typename U> static void TurnPair(const vector<pair<T, U>>& input_collection, vector<pair<U, T>>& output_collection)
	{
		for (const auto& e : input_collection)
			output_collection.push_back(make_pair(e.second, e.first));
	}
	/**
	@brief �ő�l�擾�֐�
	@note
	 collection�̗v�f�̒��ōő�l���擾����
	**/
	template<typename T> static T Max(const vector<T>& collection)
	{
		T max = collection[0];
		for (const auto& e : collection)
		{
			if (max < e)
				max = e;
		}
		return max;
	}
	/**
	@brief �ŏ��l�擾�֐�
	@note
	 collection�̗v�f�̒��ōŏ��l���擾����
	**/
	template<typename T> static T Min(const vector<T>& collection)
	{
		T min = collection[0];
		for (const auto& e : collection)
		{
			if (e < min)
				min = e;
		}
		return min;
	}
	/**
	@brief ���ʎ擾�֐�
	@note
	 �͈�[min_range, max_range]�̒l�����R���e�i�ɑ΂��đS�v�f�̏���(�l�̑傫���̏���)�����߂�B
	 �v�Z�ʂ͒l�͈̔͂�N�Ƃ����O(N)
	-----------------------------------------------------------------------------------------------
	[sample code]
	long long main() {
		vector<long long> input_collection = {56,0,67,100,67,76};
		vector<long long> rank_collection;
		NyaGadgetVector::Rank(0, 100, input_collection, rank_collection);

		cout << "(�l, ����) = ";
		for (const auto &e : input_collection)
			cout << "(" << e  << "," << rank_collection[e] << ")";
		return 0;
	}
	-----------------------------------------------------------------------------------------------
	[output]
	(�l, ����) = (56,5)(0,6)(67,3)(100,1)(67,3)(76,2)
	**/
	static void Rank(long long min_range, long long max_range, vector<long long>& input_collection, vector<long long>& rank_collection)
	{
		rank_collection.clear();
		rank_collection.resize(max_range - min_range + 2);
		for (const auto& e : input_collection)
			rank_collection[e]++;

		rank_collection[max_range + 1] = 1;
		for (long long i = max_range; min_range <= i; i--)
			rank_collection[i] += rank_collection[i + 1];

		for (long long i = 0; i < (long long)rank_collection.size() - 1; i++)
			rank_collection[i] = rank_collection[i + 1];
		rank_collection.erase(rank_collection.begin() + ((long long)rank_collection.size() - 1));

	}
	/**
	@brief �u���֐�
	@note
	 collection�̑S�v�f��replace_value�ɒu��������
	**/
	template<typename T> static void Replace(vector<T>& collection, T replace_value)
	{
		for (auto& e : collection)
			e = replace_value;
	}
	/**
	@brief ���v�֐�
	@note
	 collection�̗v�f�����v���ĕԂ�(�͈͂�start_index�ȏ�end_index����)
	**/
	template<typename T> static T Sum(const vector<T>& collection, long long start_index, long long end_index)
	{
		long long sum = 0;
		for (long long i = start_index; i < end_index; i++)
			sum += collection[i];
		return sum;
	}
};
