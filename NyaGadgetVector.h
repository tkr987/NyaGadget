#include <vector>

using namespace std;

class NyaGadgetVector
{
public:
	/**
	@brief 加算関数
	@note
	 collectionの全要素にadd_valueだけ値を加算する
	**/
	template<typename T> static void Add(vector<T>& collection, T add_value)
	{
		for (auto& e : collection)
			e += add_value;
	}
	/**
	@brief 比較関数
	@note
	 collection1とcollection2の中身が同じかどうか調べる。
	 collectionの要素が全て同じなら0を返す。
	 collectionの要素が同じでなければ、異なる要素の個数を返す。
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
	@brief 同一要素数取得関数
	@note
	 同じ値の要素が何個ずつあるのか調べる。
	 コンテナinput_collectionの同じ要素の個数を数えてoutput_collectionに結果を格納する。
	 output_collectionの第一引数には要素の値、第二引数には要素の個数が格納される。
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
	@brief 要素削除関数
	@note
	定数時間O(4)でinput_collection[index]を削除する(STLのeraseはO(N))。
	ただし、内部で削除する要素と末尾の要素をswapする工夫をしているため、コンテナの要素の順番は保証されない。
	**/
	template<typename T> static void EraceO4(const vector<T>& input_collection, long long index)
	{
		T temp = input_collection[input_collection.size() - 1];
		input_collection[input_collection.size() - 1] = input_collection[index];
		input_collection[index] = temp;
		input_collection.erase(input_collection.size() - 1, 1);

	}
	/**
	@brief 標準入力関数
	@note
	 標準入力から入力されたsize個の値をcollectionに格納する
	**/
	template<typename T> static void InputStream(vector<T>& collection, long long size)
	{
		if ((long long)collection.size() <= size)
			collection.resize(size);

		for (long long i = 0; i < size; i++)
			cin >> collection[i];
	}
	/**
	@brief pairの引数を反転させる関数
	@note
	 input_collectionのpair.firstとpair.secondを入れ替えて新たなコンテナを作成する。
	**/
	template<typename T, typename U> static void TurnPair(const vector<pair<T, U>>& input_collection, vector<pair<U, T>>& output_collection)
	{
		for (const auto& e : input_collection)
			output_collection.push_back(make_pair(e.second, e.first));
	}
	/**
	@brief 最大値取得関数
	@note
	 collectionの要素の中で最大値を取得する
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
	@brief 最小値取得関数
	@note
	 collectionの要素の中で最小値を取得する
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
	@brief 順位取得関数
	@note
	 範囲[min_range, max_range]の値を持つコンテナに対して全要素の順位(値の大きさの順番)を求める。
	 計算量は値の範囲をNとするとO(N)
	-----------------------------------------------------------------------------------------------
	[sample code]
	long long main() {
		vector<long long> input_collection = {56,0,67,100,67,76};
		vector<long long> rank_collection;
		NyaGadgetVector::Rank(0, 100, input_collection, rank_collection);

		cout << "(値, 順位) = ";
		for (const auto &e : input_collection)
			cout << "(" << e  << "," << rank_collection[e] << ")";
		return 0;
	}
	-----------------------------------------------------------------------------------------------
	[output]
	(値, 順位) = (56,5)(0,6)(67,3)(100,1)(67,3)(76,2)
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
	@brief 置換関数
	@note
	 collectionの全要素をreplace_valueに置き換える
	**/
	template<typename T> static void Replace(vector<T>& collection, T replace_value)
	{
		for (auto& e : collection)
			e = replace_value;
	}
	/**
	@brief 合計関数
	@note
	 collectionの要素を合計して返す(範囲はstart_index以上end_index未満)
	**/
	template<typename T> static T Sum(const vector<T>& collection, long long start_index, long long end_index)
	{
		long long sum = 0;
		for (long long i = start_index; i < end_index; i++)
			sum += collection[i];
		return sum;
	}
};
