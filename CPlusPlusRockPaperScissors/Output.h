#pragma once
#include <string>
using namespace std;
class Output
{
public:
	Output() {}
	virtual ~Output(){}
	virtual void output(string message) const = 0;
};

