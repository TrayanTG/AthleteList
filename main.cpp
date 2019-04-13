#include "AthleteList.h"

#include <iostream>

using namespace std;

int main()
{
	/*AthleteList aList("fileName.txt");
	cout << aList << endl;*/

	AthleteList aList(2);
	aList.addAthlere(Athlete("Djonko", 170));
	cout << aList << endl;
	aList.addAthlere(Athlete("Ivan", 175));
	cout << aList << endl;
	if (!aList.addAthlere(Athlete("Ivan", 175)))cout << "whoops!\n";
	cout << aList << endl;
	aList.addAthlere(Athlete("Peter", 180));
	cout << aList << endl;
	aList.print("fileName.txt");
	system("pause");
}