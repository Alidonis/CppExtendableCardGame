#include <exception>
#include "CommonHeaders.h"
#include "OperatorOverloadingTest.h"

OperatorOverloadingTest OperatorOverloadingTest::operator+(int other)
{
    count += other;
    return OperatorOverloadingTest();
}

OperatorOverloadingTest OperatorOverloadingTest::operator+(bool other)
{
    throw std::exception("Cannot convert boolean to int, you absolute dumbass ! Really, you tried to add a fucking boolean to a number! Either you're a fucking idiot, or a nerd!");
    return OperatorOverloadingTest();
}
