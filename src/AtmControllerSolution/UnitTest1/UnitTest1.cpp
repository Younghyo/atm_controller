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
	};
}
