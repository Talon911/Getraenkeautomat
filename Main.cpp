#include "Person.h"
#include "Getraenkeautomat.h"
/* Programm muss noch beendet werden */


int main(int argc, char* argv[])
{
	// Personen Objekt erzeugen
	Person* NewPerson = new Person("Talon", 200);
	// Getraenke Automat erzeugen
	Getraenkeautomat<1> *NewAutomat = new Getraenkeautomat<1>("Fanta ", 20, NewPerson);

	if (NewAutomat->getGetraenke() > 0)
	{
		while (!NewAutomat->isAviable())
		{
			if (NewAutomat->getGetraenke() > 0)
			{
				NewAutomat->print();
				unsigned anzahl;
				cin.tie(&cout);
				cout << "\nWie viele Stücke wollen sie Kaufen?:";
				cin >> anzahl;
				NewAutomat->getraenkKaufen(anzahl);
				cin.sync();
				cin.clear();
			}
			else
			{
				cout << "\nGetraenke Automat ist Leer.";
				cout << "\nProgramm wird beendet.!";
				this_thread::sleep_for(chrono::seconds(10));
				exit(1);
			}
		}
	}
	else
	{
		cout << "\nGetraenke Automat ist Leer.\n";
		cout << "Programm wird beendet.!";
		this_thread::sleep_for(chrono::seconds(10));
		exit(1);
	}

	delete NewPerson; // Neue Person löschen
	delete NewAutomat; // Getränke Automat löschen
}
