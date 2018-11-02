#include "pch.h"
#include "SolutionG.h"


SolutionG::SolutionG()
{
}


void SolutionG::Run()
{
	char grid[15][15];
	int cnt = 0;
	int bcnt = 0;
	int wcnt = 0;
	int lb = 0;
	int lw = 0;
	int bwin = false;
	int wwin = false;
	for (size_t i = 0; i < 15; i++)
	{
		for (size_t j = 0; j < 15; j++)
		{
			cin >> grid[i][j];
			if (grid[i][j] != '.')
				cnt++;
			else
			{
				lb = 0;
				lw = 0;
			}
			if (grid[i][j] == 'B')
			{
				bvec.insert(pair<int, int>(i, j));
				bcnt++;
				lw = 0;
				lb++;
				if (lb > 4) bwin = true;
			}
			else if (grid[i][j] == 'W')
			{
				wvec.insert(pair<int, int>(i, j));
				wcnt++;
				lb = 0;
				lw++;
				if (lw > 4) wwin = true;
			}
		}
	}
	if (bcnt - wcnt > 1 || bcnt < wcnt)
	{
		cout << "invalid grid" << endl;
		return 0;
	}
	if (bwin)
	{
		cout << "black win" << endl;
		return 0;
	}
	if (wwin)
	{
		cout << "white win" << endl;
		return 0;
	}
	if (cnt == 15 * 15)
	{
		cout << "draw" << endl;
		return 0;
	}
	for (size_t j = 0; j < 15; j++)
	{
		for (size_t i = 0; i < 15; i++)
		{
			grid[i][j]
		}
	}
	cout << "not finished" << endl;
	return 0;
}


SolutionG::~SolutionG()
{
}


#include <stdio.h>

int main()
{
	char grid[15][15];
	int nW = 0, nB = 0;
	bool Bk = false, Wh = false;
	for (size_t i = 0; i < 15; i++)
	{
		for (size_t j = 0; j < 15; j++)
		{
			cin >> grid[i][j];
			switch (grid[i][j])
			{
			case '.':
				grid[0][i] = 0;
				break;
			case 'B':
				grid[0][i] = 1;
				nB++;
				break;
			case 'W':
				grid[0][i] = 2;
				nW++;
				break;
			}
		}
	}
	if (nW != nB && nW != nB - 1)
	{
		printf("invalid grid");
		return 0;
	}
	for (int i = 0; i < 15; i++)
	{
		for (int k = 0; k < 15; k++)
		{
			if (grid[i][k] != 0 && (grid[i][k] & 0x80) == 0) {
				int n = 0;
				for (int j = i; j >= 0 && (grid[j][k] & 3) == (grid[i][k] & 3); j--) {
					grid[j][k] |= 0x80;
					n++;
				}
				for (int j = i + 1; j < 15 && (grid[j][k] & 3) == (grid[i][k] & 3); j++) {
					grid[j][k] |= 0x80;
					n++;
				}
				if (n > 9)
				{
					Wh = 1;
					Bk = 1;
				}
				if (n >= 5)
				{
					if ((grid[i][k] & 3) == 2)
						Wh = 1;
					else
						Bk = 1;
				}
				n = 0;
				for (int j = k; j >= 0 && (grid[i][j] & 3) == (grid[i][k] & 3); j--) {
					grid[i][j] |= 0x80;
					n++;
				}
				for (int j = k + 1; j < 15 && (grid[i][j] & 3) == (grid[i][k] & 3); j++) {
					grid[i][j] |= 0x80;
					n++;
				}
				if (n > 9)
				{
					Wh = 1;
					Bk = 1;
				}
				if (n >= 5)
				{
					if ((grid[i][k] & 3) == 2)
						Wh = 1;
					else
						Bk = 1;
				}
				n = 0;
				for (int j = 0; i + j < 15 && k + j < 15 && (grid[i + j][k + j] & 3) == (grid[i][k] & 3); j++) {
					grid[i + j][k + j] |= 0x80;
					n++;
				}
				for (int j = 1; i - j >= 0 && k - j >= 0 && (grid[i - j][k - j] & 3) == (grid[i][k] & 3); j++) {
					grid[i - j][k - j] |= 0x80;
					n++;
				}
				if (n > 9)
				{
					Wh = 1;
					Bk = 1;
				}
				if (n >= 5)
				{
					if ((grid[i][k] & 3) == 2)
						Wh = 1;
					else
						Bk = 1;
				}
				n = 0;
				for (int j = 0; i + j < 15 && k - j >= 0 && (grid[i + j][k - j] & 3) == (grid[i][k] & 3); j++) {
					grid[i + j][k - j] |= 0x80;
					n++;
				}
				for (int j = 1; i - j >= 0 && k + j < 15 && (grid[i - j][k + j] & 3) == (grid[i][k] & 3); j++) {
					grid[i - j][k + j] |= 0x80;
					n++;
				}
				if (n > 9)
				{
					Wh = 1;
					Bk = 1;
				}
				if (n >= 5)
				{
					if ((grid[i][k] & 3) == 2)
						Wh = 1;
					else
						Bk = 1;
				}
			}
		}
	}

	if (Bk && Wh)
	{
		printf("invalid grid");
		return 0;
	}
	if (Bk)
	{
		printf("black win");
		return 0;
	}
	if (Wh)
	{
		printf("white win");
		return 0;
	}
	if (nB + nW == 225)
	{
		printf("draw");
		return 0;
	}
	printf("not finished");
	return 0;

}