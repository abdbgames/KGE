#ifndef testChild_h
#define testChild_h

#include "object.h"

struct Testchild : kg::Object
{
	Testchild(const std::string &name);
	void start();
	void update();

private:
	std::string m_name;
};

#endif