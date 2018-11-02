#pragma once
#include "SolutionBase.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <sstream>
#include <queue>
#include <stack>
#include <cmath>
#include <Windows.h>
class SolutionSerial :
	public SolutionBase
{
public:
	SolutionSerial();
	virtual void Run();
	~SolutionSerial();
};

struct SerialConfig
{
	std::wstring serialName;
	int speed;
	int databits;
	char parity;
	int stopbits;
	bool isBlocked;
};

class Serial
{
public:
	Serial()
		: m_hCom(INVALID_HANDLE_VALUE)
	{}
	bool Open(const SerialConfig& conf);
	bool Close();
	template<typename T>
	bool Send(const std::vector<T>& buffer)
	{
		if (m_hCom == INVALID_HANDLE_VALUE)
		{
			fprintf(stderr, "Port is not opened.\n");
			return false;
		}
		DWORD byte = buffer.size();
		DWORD dwErrorFlags;
		COMSTAT comstat;
		if (!ClearCommError(m_hCom, &dwErrorFlags, &comstat))
		{
			perror("Can not clear comm error");
			return false;
		}
		if (!WriteFile(m_hCom, &buffer[0], buffer.size(), &byte, NULL))
		{
			perror("WriteFile error.");
			return false;
		}
		fprintf(stdout, "%d bytes sent.", byte);
		if (!PurgeComm(m_hCom, PURGE_TXABORT | PURGE_RXABORT | PURGE_TXCLEAR | PURGE_RXCLEAR))
		{
			perror("Can not PurgeComm");
			return false;
		}
		return true;
	}
	
	template<typename T>
	bool Recv(const std::vector<T>& buffer)
	{
		if (m_hCom == INVALID_HANDLE_VALUE)
		{
			fprintf(stderr, "Port is not opened.\n");
			return false;
		}
		int byte = 0;
		char buf[1024];
		if (!ReadFile(m_hCom, buf, 1024, &byte, NULL))
		{
			perror("ReedFile failed");
			return false;
		}
		buffer.assign(buf, buf + byte);
		fprintf(stdout, "%d bytes recv.", byte);
		return true;
	}
	~Serial() { Close(); }
private:
	bool Config(const SerialConfig& conf);
	HANDLE m_hCom;
};