#include "testParent.h"
#include "testChild.h"

#include <stdio.h>

TestParent::TestParent()
{
	m_string = "id: ";
	m_children = 0;
}

void TestParent::start()
{

}

void TestParent::update()
{
	char *name = new char[50];
	sprintf(name, "%c %d\0", m_string.c_str(), m_children);
	addChild(name, new Testchild(name));
	++m_children;
}