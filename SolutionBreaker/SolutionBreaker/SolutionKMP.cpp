#include "pch.h"
#include "SolutionKMP.h"


SolutionKMP::SolutionKMP()
{
}

void SolutionKMP::Run()
{
	vector<int> next;
	string s = "mississippi";
	string p = "issip";
	int pos = strStr(s, p);
	/*for (size_t i = 0; i < next.size(); i++)
	{
		cout << next[i] << " ";
	}
	cout << endl;*/
	cout << '0' << endl;
	cout << '1' << endl;
	cout << pos << endl;
	int select = 1;
	cout << (select + 1) % 2 << endl;
	return;
}


SolutionKMP::~SolutionKMP()
{
}

int SolutionKMP::strStr(string haystack, string needle) {
	if (needle.empty()) return -1;
	if (haystack.empty()) return -1;
	int i = 0, j = 0;
	vector<int> next;
	GetNext(needle, next);
	while (i < haystack.length() && j < static_cast<int>(needle.length()))
	{
		if (j == -1 || haystack[i] == needle[j])
		{
			i++; j++;
		}
		else
		{
			j = next[j];
		}
	}
	if (j == needle.length())
	{
		return i - needle.length();
	}
	return -1;
}

void SolutionKMP::GetNext(const string& pattern, vector<int>& next)
{
	next.resize(pattern.size());
	int i = 0;
	next[0] = -1;
	int j = -1;
	while (i < pattern.length() - 1)
	{
		if (j == -1 || pattern[i] == pattern[j])
		{
			i++; j++;
			if (pattern[i] != pattern[j])
			{
				next[i] = j;
			}
			else
			{
				next[i] = next[j];
			}
		}
		else j = next[j];
	}
}