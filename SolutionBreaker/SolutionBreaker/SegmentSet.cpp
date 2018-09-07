#include "pch.h"
#include "SegmentSet.h"


SegmentSet::SegmentSet()
{
	const char str1[] = "abc";
	const char str2[] = "abc";
	const char *p1 = "abc";
	const char *p2 = "abc";
	cout << "str1[] : 0x" << (void *)&str1[0] << endl;
	cout << "str2[] : 0x" << (void *)&str2[0] << endl;
	cout << "p1 : 0x" << (void *)p1 << endl;
	cout << "p2 : 0x" << (void *)p2 << endl;
}


SegmentSet::~SegmentSet()
{
}
