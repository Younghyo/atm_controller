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
	};
}
