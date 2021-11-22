#pragma once
#include <string>
using namespace std;
class Input
{
public:
	Input() {}
	virtual ~Input() {}

	int getInputInt() {
		string result = "";
		while (!isdigit(result[0])) {
			result = getInputString();
		}
		return stoi(result);
	}

	virtual string getInputString() const = 0; 

	
};

