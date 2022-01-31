#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <Windows.h>
#include "Header.h"
#include "TVopros.h"
#include "TBilet.h"

ostream& operator << (ostream& out, TBilet& bilet) {
	for (int i = 0; i < bilet.Qs.size(); i++) {
		if (bilet.Qs[i].getLevel() == 0) {
			out << i + 1 << ") " << bilet.Qs[i].getQuestion() << "\nСложность: " << bilet.Qs[i].getLevel() << "\n" << endl;
		}
		else {
			out << i + 1 << ")* " << bilet.Qs[i].getQuestion() << "\nСложность: " << bilet.Qs[i].getLevel() << "\n" << endl;
		}
	}
	return out;
}

ofstream& operator << (ofstream& off, TBilet& bilet)
{
	for (int i = 0; i < bilet.Qs.size(); i++)
	{
		off << bilet.Qs[i];
	}
	return off;
}

ifstream& operator>> (ifstream& iff, TBilet& V)
{
	TVopros q;

	do
	{	
		q.Clean();
		iff >> q;
		V.Qs.push_back(q);
	} while (q.Poisk("___") != 1);
	V.Qs.erase(V.Qs.begin() + V.Qs.size() - 1);
	return iff;
}
