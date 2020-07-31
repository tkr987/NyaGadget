#include <bits/stdc++.h>
using namespace std;

namespace NyaGadget
{
	/***** MOD �^���C�u���� *****/

	template<long long mod> struct NT_ModLL
	{	// ��^�e���v���[�g�p�����[�^
		long long x;

		// �R���X�g���N�^
		NT_ModLL() { x = 0; }
		NT_ModLL(long long x_)
		{
			x = x_ % mod + mod;
			if (x >= mod)
				x -= mod;
		}

		// ����
		NT_ModLL operator + () const { return x; }
		NT_ModLL operator - () const { return (-x < 0) ? mod - x : -x; }

		// �����揜���Z�q
		NT_ModLL& operator += (NT_ModLL r)
		{
			if ((x += r.x) >= mod) x -= mod;
			return *this;
		}
		NT_ModLL& operator -= (NT_ModLL r)
		{
			if ((x -= r.x) < 0) x += mod;
			return *this;
		}
		NT_ModLL& operator *= (NT_ModLL r)
		{
			x = (unsigned long long) x * r.x % mod;
			return *this;
		}
		NT_ModLL& operator /= (NT_ModLL r)
		{
			x = x * Inv(r.x, mod) % mod;
			return *this;
		}

		NT_ModLL operator + (NT_ModLL r) const { return NT_ModLL(*this) += r; }
		NT_ModLL operator - (NT_ModLL r) const { return NT_ModLL(*this) -= r; }
		NT_ModLL operator * (NT_ModLL r) const { return NT_ModLL(*this) *= r; }
		NT_ModLL operator / (NT_ModLL r) const { return NT_ModLL(*this) /= r; }

		// �t�� x^{-1} (��ɏ��Z���Z�q�Ŏg�p)
		long long Inv(long long a, long long m)
		{
			long long b = m, u = 1, v = 0;

			while (b)
			{
				long long t = a / b;
				a -= t * b; swap(a, b);
				u -= t * v; swap(u, v);
			}

			u %= m;

			return (u < 0) ? u + m : u;
		}

		// ��r���Z�q
		bool operator == (NT_ModLL& r) const { return x == r.x; }
		bool operator != (NT_ModLL& r) const { return x != r.x; }
		bool operator <  (NT_ModLL& r) const { return x < r.x; }
		bool operator <= (NT_ModLL& r) const { return x <= r.x; }
		bool operator >  (NT_ModLL& r) const { return x > r.x; }
		bool operator >= (NT_ModLL& r) const { return x >= r.x; }

		// ���o�͉��Z�q
		friend ostream& operator << (ostream& s, NT_ModLL<mod> a)
		{
			s << a.x;
			return s;
		}
		friend istream& operator >> (istream& s, NT_ModLL<mod>& a)
		{
			s >> a.x;
			return s;
		}

		NT_ModLL Pow(long long x, long long n)
		{
			NT_ModLL res = 1;
			if (0 < n)
			{
				res = Pow(x, n / 2);
				res = res * res;
				if (n % 2 != 0) res *= x;
			}
			return res;
		}
	};

	/***** MOD �֐����C�u���� *****/

	struct NT_Mod
	{
		static long long Add(long long x, long long y, long long mod)
		{
			x = (x + y) % mod;
			if (x >= mod) x -= mod;
			return x;
		}

		static long long Sub(long long x, long long y, long long mod)
		{
			x = (x - y) % mod;
			if (x < 0) x += mod;
			return x;
		}

		static long long Mul(long long x, long long y, long long mod)
		{
			x = (unsigned long long) x * y % mod;
			return x;
		}

		static long long Div(long long x, long long y, long long mod)
		{
			x = x * Inv(y, mod) % mod;
			return x;
		}

		static long long Pow(long long x, long long n, long long mod)
		{
			long long res = 1;
			if (0 < n)
			{
				res = Pow(x, n / 2, mod);
				res = Mul(res, res, mod);
				if (n % 2 != 0) res = Mul(res, x, mod);
			}
			return res;
		}

		static long long Inv(long long a, long long mod)
		{
			long long b = mod, u = 1, v = 0;

			while (b)
			{
				long long t = a / b;
				a -= t * b; swap(a, b);
				u -= t * v; swap(u, v);
			}

			u %= mod;
			return (u < 0) ? u + mod : u;
		}
	};
}
