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

	// T ����lineList
	// �ж�ÿ�����ཻ
	// ά����

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
		  Line  �߶�����        Q ���㼯��
			 L ɨ����״̬��      E  �¼�����ȱ� 
	{
		SORT(Line, E); // ���߶�Line�����2n���˵㰴x,y�ֵ����򱣴���E�У�
		L = null;
		A = null;  //A��ʼΪ�գ���ʱ���浱ǰL�����߶εĽ���
		while (!EMPTY(E))  //��E�ǿ�
		{
			P = MIN(E);  //  ȡ����ǰ�¼���
			if (LEFT(P, Line, S)) //PΪLine���߶�S��˵�
			{
				INSERT(S, L)��//��S����L��  
					S1 = ABOVE(S, L);
				S2 = BELOW(S, L);
				JIAODIAN(S, S1, A);//���㽻�㲢����A��
				JIAODIAN(S, S2, A);// ���㽻�㲢����A��
			}
			else if (RIGHT(P, Line, S)) //PΪLine���߶�S�Ҷ˵�
			{
				S1 = ABOVE(S, L);
				S2 = BELOW(S, L);
				JIAODIANRIGHT(S1, S2, A);//��S1��S2�ཻ��P���ұߣ���������A����
				DELETE(S, L);//��L��ɾȥS�߶�
			}
			else    //PΪ�߶�֮����
			{
				JIAODIANP(E, P, S1, S2);//PΪS1��S2�Ľ���
				if (UP(S1, S2, L)) //��P��S1λ��S2������
				{
					S3 = ABOVE(S1, L);
					S4 = BELOW(S2, L);
					JIAODIAN(S3, S2, A);//���㽻�㲢����A��
					JIAODIAN(S4, S1, A);// ���㽻�㲢����A��
					SWAP(S1, S2, L);
				}  //��L�н���S1��S2��λ��
			}
			while (!EMPTY(A))
			{
				GETFIRST(A, X);     //ȡ��A�еĽ��㣬�õ�X����
				if (!MEMBER(X, E))  // �����һ�μ���ó�
					INSERT(X, E);
			}
		}
	}
	*/
	virtual ~SolutionE();
};

