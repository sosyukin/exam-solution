#pragma once
#include "SolutionBase.h"
#include <set>
class SolutionG :
	public SolutionBase
{
public:
	SolutionG();
	set<pair<int, int>> bvec;
	set<pair<int, int>> wvec;
	struct table
	{
		pair<int, int> id;
		bool operator==(pair<int, int> _id) { return id == _id; }
		int cntRow;
		int cntCol;
		int cntTopLeft;
		int cntTopRight;
	};
	set<table> btab;
	set<table> wtab;
	int CntRow(set<pair<int, int>> & vec, set<table>& tab, pair<int, int> id)
	{
		set<table>::iterator it = find(tab.begin(), tab.end(), id);
		if (it != tab.end())
		{
			return it->cntRow;
		}
		else
		{
			int cnt = CntLeft(vec, id) + CntRight(vec, pair<int, int>(id.first + 1, id.second));
			it->cntRow = cnt;
		}
	}
	int CntLeft(set<pair<int, int>> & vec, pair<int, int> id)
	{
		if (find(vec.begin(), vec.end(), id) != vec.end())
		{
			return 1 + CntLeft(vec, pair<int, int>(id.first - 1, id.second));
		}
		else return 0;
	}
	int CntRight(set<pair<int, int>> & vec, pair<int, int> id)
	{
		if (find(vec.begin(), vec.end(), id) != vec.end())
		{
			return 1 + CntRight(vec, pair<int, int>(id.first + 1, id.second));
		}
		else return 0;
	}
	int CntTop(set<pair<int, int>> & vec, pair<int, int> id)
	{
		if (find(vec.begin(), vec.end(), id) != vec.end())
		{
			return 1 + CntTop(vec, pair<int, int>(id.first, id.second - 1));
		}
		else return 0;
	}
	int CntBottom(set<pair<int, int>> & vec, pair<int, int> id)
	{
		if (find(vec.begin(), vec.end(), id) != vec.end())
		{
			return 1 + CntBottom(vec, pair<int, int>(id.first, id.second + 1));
		}
		else return 0;
	}
	int CntTopLeft(set<pair<int, int>> & vec, pair<int, int> id)
	{
		if (find(vec.begin(), vec.end(), id) != vec.end())
		{
			return 1 + CntTopLeft(vec, pair<int, int>(id.first - 1, id.second - 1));
		}
		else return 0;
	}
	int CntTopRight(set<pair<int, int>> & vec, pair<int, int> id)
	{
		if (find(vec.begin(), vec.end(), id) != vec.end())
		{
			return 1 + CntTopRight(vec, pair<int, int>(id.first + 1, id.second - 1));
		}
		else return 0;
	}
	int CntBottomLeft(set<pair<int, int>> & vec, pair<int, int> id)
	{
		if (find(vec.begin(), vec.end(), id) != vec.end())
		{
			return 1 + CntBottomLeft(vec, pair<int, int>(id.first - 1, id.second + 1));
		}
		else return 0;
	}
	int CntBottomRight(set<pair<int, int>> & vec, pair<int, int> id)
	{
		if (find(vec.begin(), vec.end(), id) != vec.end())
		{
			return 1 + CntBottomRight(vec, pair<int, int>(id.first + 1, id.second + 1));
		}
		else return 0;
	}

	
	virtual void Run();
	virtual ~SolutionG();
};

