#include "pch.h"
#include "SolutionB.h"

#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <climits>
#include <list>
#include <unordered_set>

SolutionB::SolutionB()
{
}


SolutionB::~SolutionB()
{
}

void SolutionB::Run()
{
	size_t t;
	int A, B, C;
	cin >> t;
	for (size_t i = 0; i < t; i++)
	{
		cin >> A >> B >> C;
		if (isRight(A, B, C))
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
}


using namespace std;

bool help(int a, int b, int c)
{
	unordered_set<int> iset;
	int tp = a % b;
	if (tp == c) return true;
	iset.insert(tp);
	int i = 2;
	while (1)
	{
		int k = (tp*i) % b;
		if (iset.count(k)) return false;
		if (k == 0)
		{
			if (c == 0) return true;
			else
			{
				i++;
				continue;
			}
		}
		iset.insert(k);
		if (c && c % k == 0) return true;
		++i;
	}

}
int main()
{
	int n;
	scanf("%d", &n);
	while (n--)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		if (help(a, b, c)) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
