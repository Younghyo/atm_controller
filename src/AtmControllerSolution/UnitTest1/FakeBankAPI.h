#pragma once

#include "../AtmController/BankAPI.h"

class FakeBankAPI : public BankAPI
{
public:
	// Inherited via BankAPI
	virtual bool isAlive() override;

	// Inherited via BankAPI
	virtual bool checkPinCode(string cardInfo, string pin) override;

	// Inherited via BankAPI
	virtual string showAllAccounts(string cardInfo) override;
};

