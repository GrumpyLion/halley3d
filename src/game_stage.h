#pragma once

#include <halley.hpp>
using namespace Halley;

class GameStage : public EntityStage {
public:
	void init() override;

	void onFixedUpdate(Time dt) override;
	void onVariableUpdate(Time) override;
	void onRender(RenderContext&) const override;

private:
	std::unique_ptr<World> world;
};
