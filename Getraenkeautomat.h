#ifndef GETRAENKEAUTOMAT_H_INCLUDED
#define GETRAENKEAUTOMAT_H_INCLUDED
#include <string>
#include <thread>
#include <chrono>
#include <iostream>
#include "Person.h"
using namespace std;
// Template function überdenken
template<unsigned price>
class Getraenkeautomat
{
public:
	Getraenkeautomat(const string& gt, unsigned stk, Person* Pf);
	Getraenkeautomat() : empty(true), preis(0), getraenk(""), ReferencePerson(nullptr) { }
	void print() const;
	void getraenkKaufen(unsigned);
	~Getraenkeautomat();
	const unsigned getGetraenke() const { return getraenkeanzahl; }
	bool isAviable() const { return empty; }
private:
	int preis;
	bool empty;
	unsigned getraenkeanzahl;
	string getraenk;
	Person* ReferencePerson;
};

// Konstruktor der Klasse - Die Attribute mit Standartwerten initialisieren
template<unsigned price>
Getraenkeautomat< price>::Getraenkeautomat(const string& gt, unsigned stk,  Person* Pf)
	: getraenk(gt), empty(false), getraenkeanzahl(stk), preis(price), ReferencePerson(Pf)
{
	cout << getraenk << " Getränkeautomat wurde aufgestellt." << endl;
}

// Person die dinge Kaufen wird mit übergeben
template<unsigned price>
void Getraenkeautomat<price>::print() const
{
	cout << "-----------------------------------------";
	cout << "\nGetränk     :" << getraenk;
	cout << "\nAnzahl Stück:" << getraenkeanzahl;
	cout << "\nPreis für 1 :" << preis;
	cout << "\n-----------------------------------------\n";
}

// Getränkeautomaten Klasse- void function
template<unsigned price>
void Getraenkeautomat<price>::getraenkKaufen(unsigned anz)
{
	if (getraenkeanzahl == 0)
	{
		empty = true;
		cout << "\nGetränke Automat ist Leer.\n";
		cout << "Programm wird beendet!\n";
		this_thread::sleep_for(chrono::seconds(10));
		exit(0);
	}
	else
	{
		if (anz > getraenkeanzahl)
		{
			cout << "\nZu große getränke Anzahl.\n" << endl;
			cout << "Schleife wird neugestartet.\n" << endl;
		}
		else if (ReferencePerson->guthaben < (anz* preis))
		{
			cout << "\nNicht genug guthaben für den kauf von "
				<< anz << " " << getraenk << "(s)\n" << endl;
		}
		else
		{
			ReferencePerson->guthaben -= price*anz;
			getraenkeanzahl -= anz;
			cout << endl <<  ReferencePerson->name << " hat erfolgreich " << anz
				<< getraenk << "(e/r/s)" << " gekauft." << endl;
		}
	}
}


// Destruktor der Klasse- Konstrukt
template<unsigned price>
Getraenkeautomat< price>::~Getraenkeautomat()
{
	cout << getraenk << " Getraenkeautomat wurde zerstört.\n";
}
#endif // GETRAENKEAUTOMAT_H_INCLUDED

