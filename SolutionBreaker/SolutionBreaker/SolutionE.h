#pragma once
#include "SolutionBase.h"
class SolutionE :
	public SolutionBase
{
public:
	SolutionE();
	/*
	struct Line
	{
		Line(const int& _x1, const int& _y1, const int& _x2, const int& _y2)
			: x1(_x1), y1(_y1), x2(_x2), y2(_y2)
		{}
		int x1, y1, x2, y2, group;
		bool operator<(const struct Line& line)
		{
			return x1 < line.x1 || y1 < line.y1 || x2 < line.x2 || y2 < line.y2;
		}

	};
	bool isCross()
	vector<Line> lineList;
	vector<int> group;

	int addLine(const int& x1, const int& y1, const int& x2, const int& y2)
	{
		lineList.push_back(Line(x1, y1, x2, y2));
		for (vector<Line>::iterator it = lineList.begin(); it != lineList.end() - 1; it++)
		{

		}

	}
	
	vector<Line> l;
	vector<int> e;

	// T 加入lineList
	// 判断每个线相交
	// 维护组

	int getMin(vector<int>& vec)
	{
		vector<int>::iterator minIt;
		int min = INT_MAX;
		for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		{
			if (*it < min)
			{
				min = *it;
				minIt = it;
			}
		}
		vec.erase(minIt);
		return min;
	}
	bool left(int p, vector<Line>& lineList, vector<Line>::iterator& s)
	{
		for (vector<Line>::iterator it = lineList.begin(); it != lineList.end(); it++)
		{
			if (p == it->x1)
			{
				s = it;
				return p;
			}
		}
		return false;
	}
	int Jiaodian(vector<Line>& lineList)
	{
		sort(lineList.begin(), lineList.end());
		for (size_t i = 0; i < lineList.size(); i++)
		{
			e.push_back(lineList[i].x1);
		}
		// L
		// A
		while (!e.empty())
		{
			int p = getMin(e);
			vector<Line>::iterator s;
			if (left(p, lineList, s))
			{
				l.insert(l.end(), s, s + 1);
				lineList.erase(s);

			}
		}
	}
	int jiaodian_lines(LINE Line[n], POINT *Q)
		  Line  线段数组        Q 交点集合
			 L 扫描线状态表      E  事件点进度表 
	{
		SORT(Line, E); // 将线段Line数组的2n个端点按x,y字典排序保存至E中；
		L = null;
		A = null;  //A初始为空，暂时保存当前L表中线段的交点
		while (!EMPTY(E))  //若E非空
		{
			P = MIN(E);  //  取出当前事件点
			if (LEFT(P, Line, S)) //P为Line中线段S左端点
			{
				INSERT(S, L)；//将S插入L中  
					S1 = ABOVE(S, L);
				S2 = BELOW(S, L);
				JIAODIAN(S, S1, A);//计算交点并存入A中
				JIAODIAN(S, S2, A);// 计算交点并存入A中
			}
			else if (RIGHT(P, Line, S)) //P为Line中线段S右端点
			{
				S1 = ABOVE(S, L);
				S2 = BELOW(S, L);
				JIAODIANRIGHT(S1, S2, A);//若S1和S2相交于P的右边，交点送入A集合
				DELETE(S, L);//在L中删去S线段
			}
			else    //P为线段之交点
			{
				JIAODIANP(E, P, S1, S2);//P为S1和S2的交点
				if (UP(S1, S2, L)) //在P左S1位于S2的上面
				{
					S3 = ABOVE(S1, L);
					S4 = BELOW(S2, L);
					JIAODIAN(S3, S2, A);//计算交点并存入A中
					JIAODIAN(S4, S1, A);// 计算交点并存入A中
					SWAP(S1, S2, L);
				}  //在L中交换S1和S2的位置
			}
			while (!EMPTY(A))
			{
				GETFIRST(A, X);     //取出A中的交点，得到X坐标
				if (!MEMBER(X, E))  // 交点第一次计算得出
					INSERT(X, E);
			}
		}
	}
	*/
	virtual ~SolutionE();
};

