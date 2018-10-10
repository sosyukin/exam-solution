#pragma once
#include "SolutionBase.h"
class SolutionC :
	public SolutionBase
{
public:
	SolutionC();
	virtual ~SolutionC();
};

#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <climits>
#include <list>
#include <memory.h>
#include <unordered_set>

using namespace std;
bool map[2005][2005];
int n, m;
void help()
{
	bool flag = false;
	while (!flag)
	{
		flag = true;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (i == j) continue;
				if (!map[i][j]) continue;
				for (int k = 0; k < n; ++k)
				{
					if (k == j || k == i) continue;
					if (map[j][k] && !map[i][k])
					{
						flag = false;
						map[i][k] = true;
					}
				}
			}
		}
	}


}
int cnt()
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		int in = 0, out = 0;
		for (int j = 0; j < n; ++j)
		{
			if (i == j) continue;
			if (map[i][j]) out++;
			if (map[j][i]) in++;
		}
		if (in > out) count++;
	}
	return count;
}
int main()
{

	memset(map, 0, sizeof(map));
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		int x, y;
		cin >> x >> y;
		map[x - 1][y - 1] = 1;
	}
	help();
	int res = cnt();
	cout << res;
	return 0;
}