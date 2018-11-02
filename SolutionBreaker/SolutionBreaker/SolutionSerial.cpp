#include "pch.h"
#include "SolutionSerial.h"

#include <time.h>

SolutionSerial::SolutionSerial()
{
}

void SolutionSerial::Run()
{
	SerialConfig conf;
	conf.serialName = L"COM3";
	conf.speed = 115200;
	conf.databits = 8;
	conf.parity = 'N';
	conf.stopbits = 1;
	conf.isBlocked = true;

	Serial serialPort;
	serialPort.Open(conf);
	unsigned char pelcoD[][7] = {
	  {0xff,0x01,0x00,0x08,0x00,0xff,0x08},//上
	  {0xff,0x01,0x00,0x10,0x00,0xff,0x10},//下
	  {0xff,0x01,0x00,0x04,0xff,0x00,0x04},//左
	  {0xff,0x01,0x00,0x02,0xff,0x00,0x02},//右
	  {0xff,0x01,0x00,0x20,0x00,0x00,0x21},//变倍短
	  {0xff,0x01,0x00,0x40,0x00,0x00,0x41},//变倍长
	  {0xff,0x01,0x00,0x80,0x00,0x00,0x81},//聚焦近
	  {0xff,0x01,0x01,0x00,0x00,0x00,0x02},//聚焦远
	  {0xff,0x01,0x02,0x00,0x00,0x00,0x03},//光圈小
	  {0xff,0x01,0x04,0x00,0x00,0x00,0x05},//光圈大
	  {0xff,0x01,0x00,0x0b,0x00,0x01,0x0d},//灯光关
	  {0xff,0x01,0x00,0x09,0x00,0x01,0x0b},//灯光开
	  {0xff,0x01,0x00,0x07,0x00,0x01,0x09},//转至预置点001
	  {0xff,0x01,0x00,0x03,0x00,0x01,0x05},//设置预置点001
	  {0xff,0x01,0x00,0x05,0x00,0x01,0x07},//删除预置点001
	  {0xff,0x01,0x00,0x00,0x00,0x00,0x01}//停命令
	};
	srand(time(0));
	std::vector<unsigned char> sendBuf;
	sendBuf.clear();
	sendBuf.assign(pelcoD[15], pelcoD[15] + 7);
	std::cout << "stop" << std::endl;
	serialPort.Send(sendBuf);
	// up
	sendBuf.clear();
	sendBuf.assign(pelcoD[0], pelcoD[0] + 7);
	std::cout << "up" << std::endl;
	serialPort.Send(sendBuf);
	Sleep(18000);
	sendBuf.clear();
	sendBuf.assign(pelcoD[15], pelcoD[15] + 7);
	std::cout << "stop" << std::endl;
	serialPort.Send(sendBuf);
	// down
	sendBuf.clear();
	sendBuf.assign(pelcoD[1], pelcoD[1] + 7);
	std::cout << "down" << std::endl;
	serialPort.Send(sendBuf);
	Sleep(7000);
	sendBuf.clear();
	sendBuf.assign(pelcoD[15], pelcoD[15] + 7);
	std::cout << "stop" << std::endl;
	serialPort.Send(sendBuf);
	// left
	sendBuf.clear();
	sendBuf.assign(pelcoD[2], pelcoD[2] + 7);
	std::cout << "left" << std::endl;
	serialPort.Send(sendBuf);
	Sleep(25000);
	sendBuf.clear();
	sendBuf.assign(pelcoD[15], pelcoD[15] + 7);
	std::cout << "stop" << std::endl;
	serialPort.Send(sendBuf);
	// right
	sendBuf.clear();
	sendBuf.assign(pelcoD[3], pelcoD[3] + 7);
	std::cout << "right" << std::endl;
	serialPort.Send(sendBuf);
	Sleep(12000);
	sendBuf.clear();
	sendBuf.assign(pelcoD[15], pelcoD[15] + 7);
	std::cout << "stop" << std::endl;
	serialPort.Send(sendBuf);

	sendBuf.clear();
	sendBuf.assign(pelcoD[15], pelcoD[15] + 7);
	std::cout << "stop" << std::endl;
	serialPort.Send(sendBuf);

	while (true)
	{
		int ctrl = rand() % 4;
		int delay = rand() % 7;
		std::cerr << "ctrl " << ctrl << " ";
		std::cerr << "delay " << delay << " ";
		sendBuf.clear();
		sendBuf.assign(pelcoD[ctrl], pelcoD[ctrl] + 7);
		serialPort.Send(sendBuf);
		Sleep(delay * 1000);
		sendBuf.clear();
		sendBuf.assign(pelcoD[15], pelcoD[15] + 7);
		std::cerr << "stop" << std::endl;
		serialPort.Send(sendBuf);
	}
	serialPort.Close();


}


SolutionSerial::~SolutionSerial()
{
}

bool Serial::Open(const SerialConfig& conf)
{
	m_hCom = CreateFile(conf.serialName.c_str(),
		GENERIC_READ | GENERIC_WRITE, // 允许读写
		0, // 独占方式
		NULL,
		OPEN_EXISTING, //打开非创建
		conf.isBlocked ? 0 : FILE_ATTRIBUTE_NORMAL | FILE_FLAG_OVERLAPPED,// 同步异步
		NULL);
	if (m_hCom == INVALID_HANDLE_VALUE)
	{
		perror("Serial can not open");
		return false;
	}
	return Config(conf);
}

bool Serial::Close()
{
	if (m_hCom != INVALID_HANDLE_VALUE)
	{
		if (!CloseHandle(m_hCom))
		{
			perror("Close failed");
			return false;
		}
		m_hCom = INVALID_HANDLE_VALUE;
	}
	return true;
}

bool Serial::Config(const SerialConfig & conf)
{
	// 缓冲区
	if (!SetupComm(m_hCom, 1024, 1024))
	{
		perror("Can not setup Com");
		return false;
	}
	// 超时
	COMMTIMEOUTS timeouts;
	timeouts.ReadIntervalTimeout = 1000;
	timeouts.ReadTotalTimeoutMultiplier = 500;
	timeouts.ReadTotalTimeoutConstant = 5000;
	timeouts.WriteTotalTimeoutMultiplier = 500;
	timeouts.WriteTotalTimeoutConstant = 2000;
	if (!SetCommTimeouts(m_hCom, &timeouts))
	{
		perror("Can not setup timeout");
		return false;
	}

	DCB dcb;
	if (!GetCommState(m_hCom, &dcb))
	{
		perror("Can not get conf");
		return false;
	}
	dcb.BaudRate = conf.speed;
	dcb.fParity = 1;
	dcb.Parity = 0;
	if (conf.databits >= 4 && conf.databits <= 8)
	{
		dcb.ByteSize = conf.databits;
	}
	else
	{
		fprintf(stderr, "Unsupported databits.\n");
		return false;
	}
	
	switch (conf.parity)
	{
	case 'n':
	case 'N':
		dcb.Parity = NOPARITY;
		break;
	case 'o':
	case 'O':
		dcb.Parity = ODDPARITY;
		break;
	case 'e':
	case 'E':
		dcb.Parity = EVENPARITY;
		break;
	case 's':
	case 'S':
	default:
		fprintf(stderr, "Unspported parity.\n");
		return false;
	}

	switch (conf.stopbits)
	{
	case 1:
		dcb.StopBits = ONESTOPBIT;
		break;
	case 2:
		dcb.StopBits = TWOSTOPBITS;
		break;
	case 3:
		dcb.StopBits = ONE5STOPBITS;
		break;
	default:
		fprintf(stderr, "Unspported stopbits.\n");
		return false;
	}

	if (!SetCommState(m_hCom, &dcb))
	{
		perror("Can not set config");
		return false;
	}

	if (!PurgeComm(m_hCom, PURGE_TXCLEAR | PURGE_RXCLEAR))
	{
		perror("Can not purge Comm");
		return false;
	}

	return false;
}
