#pragma once

#ifdef ATMCONTROLLER_EXPORTS
#define ATMCONTROLLER_API __declspec(dllexport)
#else
#define ATMCONTROLLER_API __declspec(dllimport)
#endif

#include <string>
using namespace std;

class ATMCONTROLLER_API BankAPI
{
public:
	virtual bool isAlive() = 0;
	virtual bool checkPinCode(string cardInfo, string pin) = 0;
	virtual string showAllAccounts(string cardInfo) = 0;
};

