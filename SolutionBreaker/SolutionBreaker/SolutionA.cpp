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
#include "pch.h"
#include "SolutionA.h"


SolutionA::SolutionA(vector<int> pushV, vector<int> popV)
{
	int pushId = 0;
	for (size_t i = 0; i < popV.size(); i++)
	{
		while (s.empty() || s.top() != popV[i])
		{
			s.push(pushId++);
			if (pushId == pushV.size())
			{
				return;
			}
		}
		
		
	}
}

void SolutionA::Run()
{
	
}

bool SolutionA::IsPopOrder(vector<int> pushV, vector<int> popV)
{
	int pushId = 0;
	for (size_t i = 0; i < popV.size(); i++)
	{
		while (s.empty() || s.top() != popV[i])
		{
			s.push(pushId++);
			if (pushId == pushV.size())
			{
				return false;
			}
		}
		s.pop();
	}
	return s.empty();
}


SolutionA::~SolutionA()
{
}
