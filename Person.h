#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED
#include <string>
#include <iostream>
using namespace std;
struct Person
{
	Person(const string& n, unsigned gth);
	unsigned guthaben;
	string name;
};

Person::Person(const string& n, unsigned gth) : name(n)
{
	cout << "Person namens " << name << " wurde erzeugt.\n";
}

#endif // PERSON_H_INCLUDED

