#pragma once
#include "SolutionBase.h"
class SolutionH :
	public SolutionBase
{
public:
	SolutionH();
	~SolutionH();
	string countAndSay(int n);
	void countAndSay(string& s1, string& s2);
};

