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
