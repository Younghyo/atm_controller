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
