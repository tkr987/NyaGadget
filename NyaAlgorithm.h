#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <utility>
#include <vector>

using namespace std;

class NyaGadgetAlgorithm
{
public:
	/**
	@brief —v‘f‚ÌŠe’l‚ÌŒÂ”‚ğ”‚¦‚éŠÖ”
	@note
	 
	**/
	template<typename T1, typename T2> static void CountValue(T1 input_collection, map<T2, int>& output_collection)
	{
		for (const auto& e : input_collection)
			output_collection[e] += 1;
	}
};

int main() {
	// your code goes here
	vector<int> v(10, 0);
	for (int i = 0; i < 10; i++)
	{
		if (i % 2 == 0)
			v[i] = 2;
		else
			v[i] = 10;
	}

	map<int, int> r;
	NyaGadgetAlgorithm::CountValue<vector<int>, int>(v, r);

	for (const auto& e : r)
		cout << "(" << e.first << "," << e.second << ")";
	return 0;
}
