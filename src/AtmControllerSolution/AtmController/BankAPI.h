#pragma once

#ifdef ATMCONTROLLER_EXPORTS
#define ATMCONTROLLER_API __declspec(dllexport)
#else
#define ATMCONTROLLER_API __declspec(dllimport)
#endif


class ATMCONTROLLER_API BankAPI
{
public:
	virtual bool isAlive() = 0;
};
