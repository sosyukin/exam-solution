#include "pch.h"
#include "SolutionD.h"


SolutionD::SolutionD()
{
}

int SolutionD::GetCnt(int i, int np, int nq, int nr)
{
	int cnt = 0;
	if (np < 0 || nq < 0 || nr < 0) return 0;
	cnt++;
	if (i == 0)// p
	{
		cnt += GetCnt(1, np, nq - 1, nr);
		cnt += GetCnt(2, np, nq, nr - 1);
	}
	else if (i == 1)// q
	{
		cnt += GetCnt(0, np - 1, nq, nr);
		cnt += GetCnt(2, np, nq, nr -1);
	}
	else if (i == 2)// r
	{
		cnt += GetCnt(0, np - 1, nq, nr);
		cnt += GetCnt(1, np, nq - 1, nr);
	}
	return cnt;
}

void SolutionD::Run()
{
	int np = 2;
	int nq = 1;
	int nr = 1;
	cout << GetCnt(0, np - 1, nq, nr) + GetCnt(1, np, nq - 1, nr) + GetCnt(2, np, nq, nr - 1) << endl;
}


SolutionD::~SolutionD()
{
}
