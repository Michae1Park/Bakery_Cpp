#include "stdafx.h"
#include "CppUnitTest.h"
#include "Bread.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
	TEST_CLASS(BreadTest)
	{
	public:
		
		TEST_METHOD(getTypeTest)
		{

			Assert::AreEqual(1, Bread::getType());
		}

		TEST_METHOD(getLableTest)
		{
			Assert::AreNotEqual(10, Bread::getLabel());
		}

	};
}