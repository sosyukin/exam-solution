#include "pch.h"
#include "SegmentSet.h"

typedef struct list_t
{
	struct list_t *next;
	struct list_t *prev;
	char data[0];
} list_t;

struct A
{
	char a; // 1
	short d; // 2
	// ----------
	int b; // 4
	// ----------
	double c; // 8
	// ----------
	long long e; // 8
	// ----------
};
struct B
{
	int b;
	char a;
};

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

	unsigned short x = 65530;
	unsigned int y = x;
	//cout << ios::hex << x << " " << ios::hex << y << endl;
	printf("%04x %08x\n", x, y);

	cout << "A : " << sizeof(A) << endl;
	cout << "B : " << sizeof(B) << endl;

	const int a = 0;
	int const b = 0;
	int e = 0;

	int const *c = &a;
	const int *d = &b;
	// ���϶��ǳ���ָ�룬��������ָ�����������ͨ������ָ��ָ��Ķ����ܱ���ָ���޸�
	// const��������������ߵ����η��⣬��ֻ������ߵĶ���������
	int * const f = &e;
	// ָ�볣����ָ��f��һ��������
	d = &e;
	c = &e;
}


SegmentSet::~SegmentSet()
{
}
