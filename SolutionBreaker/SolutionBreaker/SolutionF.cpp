#include "pch.h"
#include "SolutionF.h"


SolutionF::SolutionF()
{
}

void SolutionF::Run()
{
	int N;
	cin >> N;
	int arr[50];
	for (size_t i = 0; i < N; i++)
	{
		arr[i];
	}
	bool jishu = false;
	int d = 0;
	int start = 0;
	if ((arr[0] + arr[2]) / arr[1] % 0x01 == 0)
	{
		jishu = true;
		d = (arr[2] - arr[0]) / 2;
		start = 1;
	}
	else
	{
		jishu = false;
		d = arr[3] - arr[1] / 2;
		start = 2;
	}
	for (size_t i = start; i < N; i += 2)
	{
		arr[i] = arr[i - 1] + d;
	}
	if (!jishu)
	{
		arr[0] = arr[1] - d;
	}
	for (size_t i = 0; i < N; i++)
	{
		cout << arr[i] << endl;
	}
	return;
}


SolutionF::~SolutionF()
{
}
