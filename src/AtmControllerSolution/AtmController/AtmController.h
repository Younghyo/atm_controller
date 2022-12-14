// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the ATMCONTROLLER_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// ATMCONTROLLER_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef ATMCONTROLLER_EXPORTS
#define ATMCONTROLLER_API __declspec(dllexport)
#else
#define ATMCONTROLLER_API __declspec(dllimport)
#endif

#include <string>
using namespace std;

#include "BankAPI.h"

// This class is exported from the dll
class ATMCONTROLLER_API CAtmController {
public:
	CAtmController(BankAPI *bank);
	// TODO: add your methods here.

	// for tests
	void foo();
	int sayFive();

	// 
	bool isAlive();
	void readCard();
	string showCardInfo();
	void enterPINcode(string pin);
	bool isAuthenticated();
	string showAllAccounts();
	void selectAccount(string);
	string currentAccount();
	int showBalance();
	void deposit(int val);
	void withdraw(int val);

private:
	BankAPI* bank = nullptr;
	bool cardInserted = false;
	string cardInfo = "";
	bool isAuth = false;
	string account = "";
};

extern ATMCONTROLLER_API int nAtmController;

ATMCONTROLLER_API int fnAtmController(void);
