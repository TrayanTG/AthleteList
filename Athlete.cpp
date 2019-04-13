#include "Athlete.h"
#include <iostream>
#include <cstring>

void Athlete::setAthlete(const char *name, int height)
{
	this->name = new char[strlen(name) + 1];
	memcpy(this->name, name, strlen(name) + 1);
	this->height = height;
}

Athlete::Athlete(const char *name, int height)
{
	setAthlete(name, height);
}

Athlete::Athlete(const Athlete &other)
{
	setAthlete(other.name, other.height);
}

Athlete& Athlete::operator=(const Athlete &other)
{
	if (this == &other)return *this;
	delete[] name;
	setAthlete(other.name, other.height);
	return *this;
}

Athlete::~Athlete()
{
	delete[] name;
}

bool Athlete::operator ==(const Athlete &other)const
{
	return !strcmp(name, other.name) && height == other.height;
}

std::ostream& operator<<(std::ostream &os, const Athlete &athl)
{
	return os << athl.name << ", " << athl.height;
}