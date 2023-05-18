#pragma once
class OperatorOverloadingTest
{
public:
	OperatorOverloadingTest operator+(int other);
	OperatorOverloadingTest operator+(bool other);
	int count = 0;
};
