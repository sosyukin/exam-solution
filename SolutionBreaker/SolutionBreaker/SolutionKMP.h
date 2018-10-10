#pragma once
#include "SolutionBase.h"
class SolutionKMP :
	public SolutionBase
{
public:
	SolutionKMP();
	virtual void Run();
	~SolutionKMP();
	int strStr(string haystack, string needle);
	void GetNext(const string& pattern, vector<int>& next);
};

