#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <Windows.h>
#include "Header.h"
#include "TVopros.h"
class TBilet
{
public:
	vector <TVopros> Qs;

	friend ostream& operator<<(ostream& out, TBilet& bilet);

	friend ofstream& operator << (ofstream& off, TBilet& bilet);

	friend ifstream& operator>> (ifstream& iff, TBilet& V);
};

