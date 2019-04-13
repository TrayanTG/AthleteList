#include "AthleteList.h"
#include <fstream>
#include <iostream>

AthleteList::AthleteList(int listSize)
{
	std::cout << listSize << std::endl;
	this->listSize = listSize;
	athletes = new Athlete[listSize];
	count = 0;
}

AthleteList::AthleteList(const AthleteList &other)
{
	listSize = other.listSize;
	athletes = new Athlete[other.listSize];
	for (count = 0; count < other.count; count++)
	{
		athletes[count] = other.athletes[count];
	}
}

AthleteList& AthleteList::operator= (const AthleteList &other)
{
	if (this == &other)return *this;
	delete[] athletes;

	listSize = other.listSize;
	athletes = new Athlete[other.listSize];
	for (count = 0; count < other.count; count++)
	{
		athletes[count] = other.athletes[count];
	}

	return *this;
}

AthleteList::~AthleteList()
{
	delete[] athletes;
}

AthleteList::AthleteList(const char *filePath, const int maxLenghtName)
{
	std::ifstream iFile(filePath);
	if (iFile)
	{
		listSize = DEF_MAX_SIZE;
		athletes = new Athlete[listSize];
		count = 0;
		char *tempStr = new char[maxLenghtName + 1];
		int tempInt;
		while (iFile)
		{
			iFile.getline(tempStr, maxLenghtName, ',');
			iFile >> tempInt;
			iFile.get();
			addAthlere(Athlete(tempStr, tempInt));
		}
		count--; //by some reason it counts 1 bonus and so, we just hide it
	}
	iFile.close();
}

bool AthleteList::addAthlere(const Athlete &newAthlete)
{
	for (int i = 0;i < count;i++)
	{
		if (newAthlete == athletes[i])
		{
			return false;
		}
	}
	if (count >= listSize)
	{
		Athlete *tempAthletes = new Athlete[listSize << 1]; //listSize*2
		for (int i = 0;i < listSize;i++)tempAthletes[i] = athletes[i];
		delete[] athletes;
		athletes = tempAthletes;
		listSize *= 2;
	}
	athletes[count++] = newAthlete;
	return true;
}

void AthleteList::print(const char *filePath)const
{
	std::ofstream oFile(filePath);
	if (oFile)
	{
		for (int i = 0;i < count;i++)
		{
			oFile << athletes[i] << std::endl;
		}
	}
	oFile.close();
}

std::ostream& operator<<(std::ostream &os, const AthleteList &aList)
{
	os << aList.count << " out of " << aList.listSize << std::endl;
	for (int i = 0;i < aList.count;i++)os << i <<"-th  "<<aList.athletes[i] << std::endl;
	return os;
}
