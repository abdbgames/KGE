#ifndef testParent_h
#define testParent_h

#include "object.h"
#include "engine.h"

struct TestParent : kg::Object
{
	TestParent();

	void start();
	void update();

private:
	std::string m_string;
	int m_children;
};

#endif