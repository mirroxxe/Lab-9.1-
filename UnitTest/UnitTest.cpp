#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab №9.1 А/Lab №9.1 А.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
    TEST_CLASS(UnitTest)
    {
    public:
        TEST_METHOD(TestMathFunction)
        {
            const int N = 1; 
            Student students[N] = {
                { "Цар", 1, math, 5, 4, 3 },
            };

            double expectedAverageMath = (5 + 4 + 3) / 3.0; 

            double actualAverageMath = Math(students, N);

            Assert::AreEqual(expectedAverageMath, actualAverageMath, L"Не відповідає очікуваному середній бал з математики", LINE_INFO());
        }
    };
}
