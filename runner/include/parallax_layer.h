#pragma once
#include "entity.h"
#include "RNG.h"
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
	RandomNumberGenerater rng;
	static constexpr float top = 50.0f;

public:
	void Setup(const LayerSetupParams& params);
	void Move(float m_deltatime) override;
};