#include "pch.h"
#include "FakeBankAPI.h"

bool FakeBankAPI::isAlive()
{
	return true;
}

bool FakeBankAPI::checkPinCode(string cardInfo, string pin)
{
	if (pin == "2580") return true;
	return false;
}

string FakeBankAPI::showAllAccounts(string cardInfo)
{
	return string("{1234-5678-1234-5678, 0000-0000-1234-9876}");
}

int FakeBankAPI::showBalance(string cardInfo)
{
	return bal;
}

void FakeBankAPI::deposit(string cardInfo, int val)
{
	bal += val;
}

void FakeBankAPI::withdraw(string cardInfo, int val)
{
	bal -= val;
}

void FakeBankAPI::setBalance(int val)
{
	this->bal = val;
}
