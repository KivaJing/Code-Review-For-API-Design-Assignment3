#pragma once
#include <random>

class RandomNumberGenerater
{
	std::random_device rd;
	std::default_random_engine re;

public:
	RandomNumberGenerater() { re.seed(rd()); }

	float GetRandomFloat(float min, float max) {
		std::uniform_real_distribution<float> distribution(min, max);
		return distribution(re);
	}

	int GetRandomInt(int min, int max) {
		std::uniform_int_distribution<int> distribution(min, max);
		return distribution(re);
	}
};