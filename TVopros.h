#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <Windows.h>
#include "Header.h"

using namespace std;

class TVopros
{
	string question;
	int category;
	bool level;

public:

	friend istream& operator>>(istream& in, TVopros& v);

	friend ostream& operator<< (ostream& out, const TVopros v);

	friend ofstream& operator << (ofstream& off, const TVopros v);

	friend ifstream& operator>> (ifstream& iff, TVopros& v);

	void Clean();

	bool getLevel()
	{
		return level;
	};


	string getQuestion()
	{
		return question;
	};

	bool CheckCategory(int a)
	{
		if (category == a)
			return 1;
		else return 0;
	}

	bool Poisk(string key)
	{
		if (question.find(key) != -1)
			return 1;
		else return 0;
	}

	void ChangeVopros();

	template <typename T>
	void Sort(vector <TVopros>& Base, T TVopros::* f)
	{
		TVopros v;
		for (int i = 0; i < Base.size() ; i++) {
			for (int j = 0; j < Base.size() - 1; j++)
				if (Base[++j].*f < Base[j].*f)
				{
					v = Base[j];
					Base[j] = Base[++j];
					Base[++j] = v;
				}
		}
	};

	void sortCategory(vector <TVopros>& Base)
	{
		Sort(Base, &TVopros::category);
	};

	void sortLevel(vector <TVopros>& Base)
	{
		Sort(Base, &TVopros::level);
	};
};

