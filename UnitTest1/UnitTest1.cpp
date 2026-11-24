#include "pch.h"
#include "CppUnitTest.h"
#include "../PR10.1B/FileName.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod_CountSatisfactory_Mixed)
		{
			const int N = 3;
			Student p[N];

			p[0].spec = KN;
			p[0].fizyka = 3;
			p[0].matematika = 4;
			p[0].prog = 3;

			p[1].spec = INF;
			p[1].fizyka = 3;
			p[1].matematika = 3;
			p[1].chys_metody = 5;

			p[2].spec = ME;
			p[2].fizyka = 5;
			p[2].matematika = 4;
			p[2].pedagogika = 3;

			int fizyka, matematika, prog, chys_metody, pedagogika;

			CountSatisfactory(p, N, fizyka, matematika, prog, chys_metody, pedagogika);

			Assert::AreEqual(2, fizyka);       
			Assert::AreEqual(1, matematika);   
			Assert::AreEqual(1, prog);        
			Assert::AreEqual(0, chys_metody);
			Assert::AreEqual(1, pedagogika);  
		}
		TEST_METHOD(TestMethod_CountSatisfactory_NoThrees)
		{
			const int N = 2;
			Student p[N];

			p[0].spec = FI;
			p[0].fizyka = 5;
			p[0].matematika = 4;
			p[0].pedagogika = 5;

			p[1].spec = INF;
			p[1].fizyka = 4;
			p[1].matematika = 5;
			p[1].chys_metody = 4;

			int fizyka, matematika, prog, chys_metody, pedagogika;

			CountSatisfactory(p, N, fizyka, matematika, prog, chys_metody, pedagogika);

			Assert::AreEqual(0, fizyka);
			Assert::AreEqual(0, matematika);
			Assert::AreEqual(0, prog);
			Assert::AreEqual(0, chys_metody);
			Assert::AreEqual(0, pedagogika);
		}
	};
}