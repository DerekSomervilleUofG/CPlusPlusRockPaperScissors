#pragma once
#include "Output.h"
#include <iostream>
#include <string>
using namespace std;
class ConsoleOutput :
    virtual public Output
{
public:
    ConsoleOutput() {

    }
    void output(string message) const override {
        cout << message;
    }
};

