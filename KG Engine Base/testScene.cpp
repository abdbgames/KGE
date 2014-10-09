#include "testScene.h"
#include "testParent.h"

TestScene::TestScene()
{
	sceneObjects->addObject("Parent", new TestParent);
}