#pragma once
#include "SolutionBase.h"
class SolutionD :
	public SolutionBase
{
public:
	SolutionD();

	int GetCnt(int i, int np, int nq, int nr);
	virtual void Run();
	virtual ~SolutionD();
};

