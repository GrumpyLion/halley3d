#include "game_stage.h"

void GameStage::init()
{
	world = createWorld("stages/game_world");
	auto factory = EntityFactory(*world, getResources());
	factory.createScene(getResource<Scene>("hello_world"), true);
	factory.createEntity("camera");

	world->addService(std::make_shared<ScreenService>(this));

	meshRenderer = std::make_shared<MeshRenderer>();
	meshRenderer->setMesh(getResources().get<Mesh>("flight_helmet.gltf"));
}

void GameStage::onFixedUpdate(Time t)
{
	world->step(TimeLine::FixedUpdate, t);
}

void GameStage::onVariableUpdate(Time t)
{
	curTime += t;

	world->step(TimeLine::VariableUpdate, t);

	meshRenderer->update(t);
}

void GameStage::onRender(RenderContext& rc) const
{
	world->render(rc);

	const float c = std::cos(float(curTime));
	const float s = std::sin(float(curTime));
	const float r = 0.5f;
	const Vector3f p = Vector3f(r * s, 0.5f, r * -c);
	const Vector3f t = Vector3f(0, 0.5f, 0);
	const auto q = Quaternion::lookAt(t - p, Vector3f(0, 1, 0));

	Camera cam;
	cam.setCameraType(CameraType::Perspective).setFieldOfView(Angle1f::fromDegrees(90.0f));
	cam.setPosition(p);
	cam.setRotation(q);

	rc.with(cam).bind([&](Painter& painter)
		{
			//painter.clear(Colour4f(0, 0, 0, 1));
			meshRenderer->render(painter);
		});

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
