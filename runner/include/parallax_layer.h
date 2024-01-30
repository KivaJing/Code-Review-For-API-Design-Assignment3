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

class Layer: public EntityManager
{
	RandomNumberGenerater rng;
	static constexpr float top = 50.0f;

public:
	Layer();
	Layer& operator=(const Layer& other);
	void GenerateBackground(const LayerSetupParams& params);
};