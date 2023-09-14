#pragma once

#include <halley.hpp>
using namespace Halley;

class GameStage : public EntityStage, public IScreenServiceInterface {
public:
	void init() override;

	void onFixedUpdate(Time dt) override;
	void onVariableUpdate(Time) override;
	void onRender(RenderContext&) const override;

	Vector2i getGameResolution() final;
	Vector2i getScreenResolution() const final;
	Vector2i getUIResolution() final;
	float getZoomLevel() const final;

private:
	std::unique_ptr<World> world;
};
