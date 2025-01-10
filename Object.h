#pragma once

#include <string>

using namespace std;

class Object {
public:
	virtual string getType();
	virtual void setType(string);
private:
	string type;
};

