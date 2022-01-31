#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <Windows.h>
#include "TVopros.h"

using namespace std;
template <typename T>
T GetNumber(T min, T max)
{
	T x;
	do
	{
		while (!(cin >> x))
		{
			cout << "¬ведите верное значение" << endl;
			cin.clear();
			cin.ignore();
		}
	} while (x < min || x > max);
	return x;
}
