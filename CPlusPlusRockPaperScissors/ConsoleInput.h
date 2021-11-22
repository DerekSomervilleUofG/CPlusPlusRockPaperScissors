#pragma once
#include"Input.h"
#include <iostream>
#include <string>
using namespace std;
class ConsoleInput : virtual public Input {
public:
	ConsoleInput() {

	}
	string getInputString() const override {
		string result;
		cin >> result;
		return result;
	}
};

