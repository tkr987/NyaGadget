#include <bits/stdc++.h>
using namespace std;

namespace NyaGadget
{
	/*** Nim ライブラリ ***/

	struct NT_NyaaNim
	{
		/**
		@brief 要素xのグランディ数を返す
		@note
		 要素xから遷移できる集合全てのグランディ数を格納したvectorを渡すことで
		 そのmex(集合に含まれない最小の非負整数)を返す。
		 したがって、返り値は要素xのグランディ数になる。
		 要素xから遷移できる要素がない場合はsize=0のvを渡すことになるが、
		 その場合でも正しいグランディ数が得られる(結果は0が返ってくる)。
		**/
		static long long Grundy(vector<long long>& v)
		{
			long long res = 0;
			sort(v.begin(), v.end());
			for (auto& e : v)
			{
				if (res < e) break;
				else res++;
			}
			return res;
		}
	};
}
