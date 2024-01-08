#pragma once
#include "entity.h"
#include <random>

struct LayerSetupParams {
	float minWidth;
	float maxWidth;
	float minHeight;
	float maxHeight;
	float speedX;
	bool isHollow;
};

class Layer: public Entity
{
public:
	Layer() noexcept : re(rd()), widthRange(0.0f, 1.0f), heightRange(0.0f, 1.0f), colorRange(0, 255)
	{
	}
	void Setup(const LayerSetupParams& params);
	void Move(float deltatime) override;

private:
	std::random_device rd;
	std::default_random_engine re;
	std::uniform_real_distribution<float> widthRange;
	std::uniform_real_distribution<float> heightRange;
	std::uniform_int_distribution<int> colorRange;
};