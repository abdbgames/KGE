#include "testChild.h"
#include "engine.h"

Testchild::Testchild(const std::string &name)
{
	m_name = name;
}

void Testchild::start()
{
	kg::Engine::debug("I am a child! I was made!" + m_name);
}

void Testchild::update()
{

}