#pragma once
#include <random>

class RandomNumberGenerater
{
	std::random_device rd;
	std::default_random_engine re;

public:
	RandomNumberGenerater() { re.seed(rd()); }

	template <typename T>
	T GetRandom(T min, T max) {
		std::uniform_real_distribution<T> distribution(min, max);
		return distribution(re);
	}

	sf::Uint8 GetRandomInt(int min, int max) {
		std::uniform_int_distribution<int> distribution(min, max);
		return static_cast<sf::Uint8>(distribution(re));
	}
};