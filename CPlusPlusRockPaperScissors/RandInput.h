#pragma once
#include"Input.h"
#include <string>
using namespace std;
class RandInput : virtual public Input
{
public:
	string getInputString() const override {
		return to_string(rand() % 3);
	}
};

