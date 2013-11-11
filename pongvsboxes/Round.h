#pragma once

#include <string>

class Round
{
public:
	int nrOfLives;
	int nrOfPoints;
	std::string playerName;

	Round(void);

	void Round::setPlayerName(std::string name);

	~Round(void);
};

