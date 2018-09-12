#pragma once
#include "SolutionBase.h"
class SolutionA :
	public SolutionBase
{
public:
	SolutionA(vector<int> pushV, vector<int> popV);
	virtual void Run();
	bool IsPopOrder(vector<int> pushV, vector<int> popV);
	virtual ~SolutionA();
private:
	stack<int> s;
};

