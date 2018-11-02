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
struct C
{};
class D
{
	virtual void f() {}// ...
	virtual void g() {}// 8
	char c;
};

const shared_ptr<int>& f(shared_ptr<int>& p)
{
	return p;
}
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
	cout << "C : " << sizeof(C) << endl;
	cout << "D : " << sizeof(D) << endl;

	const int a = 0;
	int const b = 0;
	int e = 0;

	int const *c = &a;
	const int *d = &b;
	// 以上都是常量指针，可以任意指向常量或变量，通过常量指针指向的对象不能被该指针修改
	// const除了自身是最左边的修饰符外，都只对他左边的东西起作用
	int * const f = &e;
	// 指针常量，指针f是一个常量，
	d = &e;
	c = &e;

	int max_a = INT_MAX;
	cout << max_a << endl;
	int max_b = max_a * 3;
	cout << max_b << endl;
	cout << -10 % 3 << endl;
	vector<int> vec;
	string s1(5, '0');
	s1.insert(s1.begin(), '1');

	try
	{
		throw std::exception("I'm a exception");
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << endl;
	}
	
	MyClass* receiver = new MyClass;
	Command* aCommand = new SimpleCommand<MyClass>(receiver, &MyClass::Action);
	aCommand->Execute();
	delete aCommand;
	delete receiver;

	MacroCommand macroCommand;
	X x1;
	Command* bCommand = new ACommand(&x1);
	macroCommand.Add(bCommand);
	macroCommand.Execute();

	
}


SegmentSet::~SegmentSet()
{
}
