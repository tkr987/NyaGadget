#include <bitset>
#include <utility>
#include <vector>

using namespace std;

/**
---------------------------------------------------------------------------------------------------
[sample code]
int main()
{
	vector<string> s_collection = { "a","b","c" };
	vector <vector<pair<bool, string>>> permutation_table;
	vector<pair<bool, string>> bit_permutation;

	// ビット置換テーブルの作成
	NyaGadgetBitAllSearch<string> bit_all_search;
	bit_all_search.BitPermutationTable(3, s_collection, permutation_table);
	// ビット全探索の実行
	bit_all_search.BeginBitPermutation(permutation_table, bit_permutation);
	do {
		cout << "(";
		for (const auto & elm : bit_permutation)
		{
			if (elm.first)
				cout << elm.second;
		}
		cout << ")";
	}while(bit_all_search.NextBitPermutation(permutation_table, bit_permutation) != permutation_table.size());

	return 0;
}
--------------------------------------------------------------------------------------------------
[output]
()(a)(b)(ab)(c)(ac)(bc)(abc)
**/
template <typename T> class NyaGadgetBitAllSearch
{
public:
	/**
	 @brief ビット置換テーブルを作成する関数
	 @note
	  ビット全探索をするためにnビットの置換テーブルを作成する。
	**/
	void BitPermutationTable(const int n, const vector<T>& input_collection, vector<vector<pair<bool, T>>>& permutation_table)
	{
		int max = (int)pow(2, n);
		permutation_table.resize(max);
		for (auto& e : permutation_table)
			e.resize(n);

		for (int i = 0; i < max; i++)
		{
			int bit = i;
			for (int shift = 0; shift < n; shift++)
			{
				permutation_table[i][shift].first = 1 & bit;
				permutation_table[i][shift].second = input_collection[shift];
				bit = bit >> 1;
			}
		}
	}
	/**
	@brief ビット置換テーブルの最初の部分集合を取得する関数
	@param permutation_table 置換テーブル
	@param bit_permutation 置換テーブルの部分集合(要素)
	@return 置換テーブルにおける最初の要素インデックスを返す
	**/
	int BeginBitPermutation(const vector<vector<pair<bool, T>>>& permutation_table, vector<pair<bool, T>>& bit_permutation)
	{
		index_ = 0;

		bit_permutation.clear();
		for (const auto& elm : permutation_table[index_])
			bit_permutation.push_back(elm);

		return index_;
	}
	/**
	@brief ビット置換テーブルにおける次の部分集合を取得する関数
	@param permutation_table 置換テーブル
	@param bit_permutation 置換テーブルの部分集合(要素)
	@return 置換テーブルにおける次の要素インデックスを返す
	**/
	int NextBitPermutation(const vector<vector<pair<bool, T>>>& permutation_table, vector<pair<bool, T>>& bit_permutation)
	{
		index_++;

		if (index_ < permutation_table.size())
		{
			bit_permutation.clear();
			for (const auto& elm : permutation_table[index_])
				bit_permutation.push_back(elm);
		}

		return index_;
	}
private:
	int index_;
};