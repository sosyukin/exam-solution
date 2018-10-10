#include "pch.h"
#include "SolutionH.h"


SolutionH::SolutionH()
{
}


SolutionH::~SolutionH()
{
}

string SolutionH::countAndSay(int n) {
	string s[2];
	int select = 0;
	int cnt = 1;
	s[select] = "1";
	while (cnt < n)
	{
		countAndSay(s[select], s[(select + 1) % 2]);
		select = (select + 1) % 2;
			cnt++;
	}
	return s[select];
}
void SolutionH::countAndSay(string& s1, string& s2)
{
	int i = 0;
	s2 = "";
	while (i < s1.length())
	{
		int j = i + 1;
		if (j < s1.length())
		{
			while (s1[i] == s1[j])
			{
				j++;
			}
		}
		s2.push_back(static_cast<char>(j - i + 48));
		s2.push_back(s1[i]);
		i = j;
	}
}