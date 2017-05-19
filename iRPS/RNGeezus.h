#pragma once
#ifndef RNG_H
#define RNG_H
#include <iostream>
#include<random>

class RNG																//Random number generator code
{
public:
	RNG::RNG() : gen(std::random_device()()) {} 
	int getRandom(int x, int y)
	{
		int min, max;
		if (x > y)
		{
			max = x;
			min = y;
		}
		else
		{
			max = y;
			min = x;
		}
		std::uniform_int_distribution<int> dis(min, max);
		int random = dis(gen);
		return random;
	}

private: 
	std::mt19937 gen;
};

#endif // !RNG
