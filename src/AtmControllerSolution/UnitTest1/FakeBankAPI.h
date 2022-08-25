#pragma once

#include "../AtmController/BankAPI.h"

class FakeBankAPI : public BankAPI
{
	// Inherited via BankAPI
	virtual bool isAlive() override;
};

