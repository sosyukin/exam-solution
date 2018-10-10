#pragma once
#include "SolutionBase.h"
#include <unordered_set>
class SolutionB :
	public SolutionBase
{
public:
	SolutionB();
	virtual ~SolutionB();
	virtual void Run();
	bool isRight(const int& A, const int& B, const int& C)
	{
		unordered_set<int> set;
		int tmp = A % B;
		if (tmp == C) return true;
		set.insert(tmp);
		int i = 2;
		while (true)
		{
			int k = (tmp * i) % B;
			if (set.count(k)) return false;
			if (k == 0)
			{
				if (C == 0) return true;
				else
				{
					i++;
					continue;
				}
			}
			set.insert(k);
			if (C && C % k == 0) return true;
			i++;
		}
	}
};

