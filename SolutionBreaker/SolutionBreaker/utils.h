#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <sstream>
#include <queue>
#include <stack>
#include <cmath>

using namespace std;
template<typename T>
ostream & operator<<(ostream & out, vector<T> & v)
{
	out << "[";
	for (size_t i = 0; i < v.size() - 1; i++)
	{
		out << v[i] << ", ";
	}
	out << v[v.size() - 1] << "]\n";
	return out;
}

template<typename T1, typename T2>
T2 from(const T1 & t)
{
	stringstream ss;
	ss << t;
	T2 res;
	ss >> res;
	return res;
}
