#include "pch.h"
#include "CppUnitTest.h"

#include "../AtmController/AtmController.h"
#pragma comment (lib, "../x64/Debug/AtmController.lib")

#include "FakeBankAPI.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(TestSayFive)
		{
			auto ctrl = new CAtmController(nullptr);
			Assert::AreEqual(5, ctrl->sayFive());
		}

		TEST_METHOD(TestAtmCtrlAlive)
		{
			auto fakeBank = new FakeBankAPI();
			auto ctrl = new CAtmController(fakeBank);
			
			Assert::IsTrue(ctrl->isAlive());
		}

		TEST_METHOD(TestAtmReadCard)
		{
			auto fakeBank = new FakeBankAPI();
			auto ctrl = new CAtmController(fakeBank);

			Assert::AreEqual(string(""), ctrl->showCardInfo());
			ctrl->readCard();
			Assert::AreEqual(string("Younghyo Kim, 1234-1234-1234-1234"), ctrl->showCardInfo());
		}

		TEST_METHOD(TestAtmAuthentication)
		{
			auto fakeBank = new FakeBankAPI();
			auto ctrl = new CAtmController(fakeBank);

			ctrl->readCard();
			ctrl->enterPINcode("9999");
			Assert::IsFalse(ctrl->isAuthenticated());
			ctrl->enterPINcode("2580");
			Assert::IsTrue(ctrl->isAuthenticated());
		}

		TEST_METHOD(TestAtmShowAllAcounts)
		{
			auto fakeBank = new FakeBankAPI();
			auto ctrl = new CAtmController(fakeBank);

			ctrl->readCard();
			ctrl->enterPINcode("2580");
			Assert::AreEqual(string("{1234-5678-1234-5678, 0000-0000-1234-9876}"), 
				ctrl->showAllAccounts());

		}

		TEST_METHOD(TestAtmSelectAcount)
		{
			auto fakeBank = new FakeBankAPI();
			auto ctrl = new CAtmController(fakeBank);

			ctrl->readCard();
			ctrl->enterPINcode("2580");
			Assert::AreEqual(string(""),
				ctrl->currentAccount());
			
			ctrl->selectAccount("0000-0000-1234-9876");
			Assert::AreEqual(string("0000-0000-1234-9876"),
				ctrl->currentAccount());
		}

		TEST_METHOD(TestAtmShowBalance)
		{
			auto fakeBank = new FakeBankAPI();
			auto ctrl = new CAtmController(fakeBank);

			ctrl->readCard();
			ctrl->enterPINcode("2580");
			ctrl->selectAccount("0000-0000-1234-9876");

			fakeBank->setBalance(500);
			Assert::AreEqual(500, ctrl->showBalance());
			
		}
	};
}
