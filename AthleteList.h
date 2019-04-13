#pragma once
#include "Athlete.h"

const int DEF_MAX_SIZE = 64;

class AthleteList
{
	Athlete *athletes;
	int count;
	int listSize;
public:
	AthleteList(int listSize = DEF_MAX_SIZE);
	AthleteList(const AthleteList &other);
	AthleteList& operator= (const AthleteList &other);
	~AthleteList();
	AthleteList(const char *filePath, const int maxNameLenght = DEF_MAX_SIZE);

	friend std::ostream& operator<<(std::ostream &os, const AthleteList &aList);
	bool addAthlere(const Athlete &newAthlete);
	void print(const char *filePath)const;
};