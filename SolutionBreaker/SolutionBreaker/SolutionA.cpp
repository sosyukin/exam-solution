#include "pch.h"
#include "SolutionA.h"


SolutionA::SolutionA()
{
}

void SolutionA::Run()
{
	cout << "Yes." << endl;
	/*int x[] = { 1, 2, 3, 4, 5, 6 };
	int size = sizeof(x) / sizeof(int);
	int res = lcm(x, size);
*/
	int n = 0;

	cin >> n;
	long long m = n;
	long long lcmx = n + 1;
	long long lcmy = 1;
	for (long long i = 2; i <= n + 1; i++)
	{
		lcmy = lcm(lcmy, i);
	}
	cout << "loop" << endl;
	while (true)
	{
		m++;
		if (m > n + 1)
		{
			lcmx = lcm(lcmx, m);
		}
		lcmy = lcm(lcmy, m);
		if (lcmx == lcmy)
		{
			cout << m;
			return;
		}
	}


}


SolutionA::~SolutionA()
{
}
