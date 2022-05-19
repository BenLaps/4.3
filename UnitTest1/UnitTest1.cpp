#include "pch.h"
#include "CppUnitTest.h"
#include "../4.3/4.3.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			char f[6] = "f.dat";
			PrintTXT(f);
		}
	};
}
