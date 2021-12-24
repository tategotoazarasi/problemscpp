#include "pch.h"
#include "CppUnitTest.h"
#include "excel_sheet_column_title.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace excel_sheet_column_title;

namespace UnitTest
{
	TEST_CLASS(ExcelSheetColumnTitle)
	{
	public:
		TEST_METHOD(Case1)
		{
			Assert::AreEqual(std::string("A"), Solution::convertToTitle(1));
		}
		TEST_METHOD(Case2)
		{
			Assert::AreEqual(std::string("AB"), Solution::convertToTitle(28));
		}
		TEST_METHOD(Case3)
		{
			Assert::AreEqual(std::string("ZY"), Solution::convertToTitle(701));
		}
		TEST_METHOD(Case4)
		{
			Assert::AreEqual(std::string("FXSHRXW"), Solution::convertToTitle(2147483647));
		}
		TEST_METHOD(Case5)
		{
			Assert::AreEqual(std::string("AZ"), Solution::convertToTitle(52));
		}
	};
}
