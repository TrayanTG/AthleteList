#pragma once

#include <iostream>

class Athlete
{
	char *name;
	int height;
public:
	Athlete(const char *name = "", int height = 0);
	Athlete(const Athlete &other);
	Athlete& operator=(const Athlete &other);
	~Athlete();

	friend std::ostream& operator<<(std::ostream &os, const Athlete &athl);
	bool operator ==(const Athlete &other)const;
	void setAthlete(const char *name, int height);
};