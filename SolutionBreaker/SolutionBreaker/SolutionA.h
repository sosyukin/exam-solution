#pragma once
#include "SolutionBase.h"
class SolutionA :
	public SolutionBase
{
public:
	SolutionA();
	virtual void Run();
	virtual ~SolutionA();

	inline int lcm(int x[], int size)
	{
		if (size <= 0) return 0;
		if (size == 1) return x[0];
		for (size_t i = 1; i < size; i++)
		{
			x[0] = lcm(x[0], x[i]);
		}
		return x[0];
	}
	inline int lcm(vector<int> x)
	{
		if (x.size() < 3) return 0;
		for (size_t i = 1; i < x.size(); i++)
		{
			x[0] = lcm(x[0], x[i]);
		}
		return x[0];
	}
	inline long long lcm(long long x, long long y)
	{
		cout << "call lcm" << x << " " << y << " ";
		return x / GCD(x, y) * y;
	}
	inline long long gcd(long long x, long long y)
	{
		cout << "call gcd" << x << " " << y << endl;
		if (x > y && x % y == 0) return y;
		if (x < y && y % x == 0) return x;
		while (x != y)
		{
			if (x > y) x = x - y;
			else
				y = y - x;
		}
		return x;
	}
	inline long long GCD(long long x, long long y) { cout << "call gcd" << x << " " << y << endl; long long t; while (y > 0) { t = x % y; x = y; y = t; } return x; }
	vector<int> get_primes(int N)
	{
		// Sieve of Erathostenes to find all the necessary prime numbers:
		vector<int> res;
		vector<bool> composite(N + 1, false);

		for (int p = 2; p <= N; p++) {
			if (!composite[p]) {
				for (int i = p + p; i <= N; i += p) {
					composite[i] = true;
				}
				res.push_back(p);
			}
		}
		return res;

	}

	int get_exponent(int x, int p)
	{
		int r = 0;
		while (x % p == 0) {
			r++;
			x /= p;
		}
		return r;
	}

	int getMin(int N)
	{
		int res = 2;
		// For each prime number <= N:
		for (int p : get_primes(N)) {
			// first find the maximum exponent of p  among numbers <= N
			// (in the explanation , this max_exp is c)
			int max_exp = 0;
			int i = p;
			while (i <= N) {
				max_exp = std::max(max_exp, get_exponent(i, p));
				i += p;
			}
			// seek the minimum i such that get_exponent(i,p) >= max_exp:
			while (get_exponent(i, p) < max_exp) {
				i += p;
			}
			// the maximum for all ps is the result:
			res = std::max(res, i);
		}
		return res;
	}

	//int Pollard(int n) { if (Miller_Rabbin(n)) return n; if (!(n & 1)) return 2; int i, x, y, ret; i = 1; while (true) { x = i++; y = func(x, n); ret = gcd(y - x, n); while (ret == 1) { x = func(x, n); y = func(func(y, n), n); ret = gcd((y - x + n) % n, n) % n; } if (0 < ret && ret < n) return ret; } }
};

