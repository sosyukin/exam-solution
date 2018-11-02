#pragma once
class Command
{
public:
	virtual ~Command() {}
	virtual void Execute() = 0;
protected:
	Command() {}
};

class X
{
public:
	X() {}
	void Action() { cout << "X::Action()" << std::endl; }
};

class ACommand : public Command
{
public:
	ACommand(X* x)
		: m_x(x)
	{}
	virtual void Execute() { InternalExecute(); }
protected:
	virtual void InternalExecute() { m_x->Action(); }
private:
	X* m_x;
};

class MyClass
{
public:
	void Action()
	{
		std::cout << "MyClass::Action()" << std::endl;
	}
};

template<typename T>
class SimpleCommand : public Command
{
public:
	typedef void (T::* Action)();

	SimpleCommand(T* t, Action a)
		: m_t(t)
		, m_a(a)
	{}

	virtual void Execute()
	{
		(m_t->*m_a)();
	}
private:
	Action m_a;
	T* m_t;
};

class MacroCommand : public Command
{
public:
	MacroCommand() {}
	virtual ~MacroCommand() {}

	virtual void Add(Command* c)
	{
		m_cmds.insert(m_cmds.end(), c);
	}
	virtual void Remove(Command* c)
	{
		delete c;
	}

	virtual void Execute()
	{
		for (std::list<Command*>::iterator i = m_cmds.begin(); i != m_cmds.end(); i++)
		{
			(*i)->Execute();
		}
		for (std::list<Command*>::iterator i = m_cmds.begin(); i != m_cmds.end(); i++)
		{
			Remove(*i);
		}
		m_cmds.clear();
	}

	// virtual void Reverse();
private:
	std::list<Command*> m_cmds;
};