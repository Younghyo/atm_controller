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

	// Inherited via BankAPI
	virtual int showBalance(string cardInfo) override;
	virtual void deposit(string cardInfo, int val) override;
	virtual void withdraw(string cardInfo, int val) override;

	void setBalance(int val);
private:
	int bal = 0;
};

