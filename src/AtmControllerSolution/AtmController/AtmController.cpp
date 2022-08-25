// AtmController.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "AtmController.h"
#include <iostream>

using namespace std;


// This is an example of an exported variable
ATMCONTROLLER_API int nAtmController=0;

// This is an example of an exported function.
ATMCONTROLLER_API int fnAtmController(void)
{
    return 0;
}

// This is the constructor of a class that has been exported.
CAtmController::CAtmController(BankAPI* bank)
{
    this->bank = bank;
}

void CAtmController::foo()
{
    cout << "foo" << endl;
}

int CAtmController::sayFive()
{
    return 5;
}

bool CAtmController::isAlive()
{
    return bank->isAlive();
}

void CAtmController::readCard()
{
    cardInserted = true;
    cardInfo = "Younghyo Kim, 1234-1234-1234-1234";
}

string CAtmController::showCardInfo()
{
    return cardInfo;
}

void CAtmController::enterPINcode(string pin)
{
    isAuth = bank->checkPinCode(cardInfo, pin);
}

bool CAtmController::isAuthenticated()
{
    return isAuth;
}

string CAtmController::showAllAccounts()
{
    return bank->showAllAccounts(cardInfo);
}

void CAtmController::selectAccount(string account)
{
    this->account = account;
}

string CAtmController::currentAccount()
{
    return account;
}

int CAtmController::showBalance()
{
    return bank->showBalance(cardInfo);
}

void CAtmController::deposit(int val)
{
    bank->deposit(cardInfo, val);
}

void CAtmController::withdraw(int val)
{
    bank->withdraw(cardInfo, val);
}
