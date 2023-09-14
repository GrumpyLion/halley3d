#include "game_stage.h"

void GameStage::init()
{
	world = createWorld("stages/game_world");
	auto factory = EntityFactory(*world, getResources());
	factory.createScene(getResource<Scene>("hello_world"), true);

	world->addService(std::make_shared<ScreenService>(this));
}

void GameStage::onFixedUpdate(Time t)
{
	world->step(TimeLine::FixedUpdate, t);
}

void GameStage::onVariableUpdate(Time t)
{
	world->step(TimeLine::VariableUpdate, t);
}

void GameStage::onRender(RenderContext& rc) const
{
	world->render(rc);
}

Vector2i GameStage::getGameResolution()
{
	return Vector2i(1280, 720);
}

Vector2i GameStage::getScreenResolution() const
{
	return getAPI().video->getWindow().getWindowRect().getSize();
}

Vector2i GameStage::getUIResolution()
{
	return getGameResolution();
}

float GameStage::getZoomLevel() const
{
	return 1.0f;
}
