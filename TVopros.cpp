#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <Windows.h>
#include "Header.h"
#include "TVopros.h"

using namespace std;

istream& operator>>(istream& in, TVopros& v)
{
	cout << "Введите текст вопроса\n Текст может быть многострочным\n Для завершения оставьте 2 пустые строки\n";
	string s;
	in.ignore();
	do
	{
		getline(in, s);
		v.question = v.question + s + "\n";
	} while (s != "");
	cout << "Category (1-15)\n";
	v.category = GetNumber(1, 15);
	v.level = 0;
	return in;
}


ostream& operator<<(ostream& out, const TVopros v) {
	out << "Вопрос: " << v.question << endl;
	out << "Категория: " << v.category << endl;
	out << "Уровень сложности: " << v.level <<"\n" << endl;
	return out;
}




ifstream& operator>>(ifstream& iff, TVopros& q)
{
	string s;
	q.question = "";
	do
	{
		getline(iff, s);
		q.question = q.question + s + "\n";
	} while (s != "");    
	iff >> q.category;
	iff.get();
	iff >> q.level;
	iff.get();
	iff.peek();
	return iff;
}

ofstream& operator << (ofstream& off, const TVopros v)
{
	off << v.question << endl;
	off << v.category << endl;
	off << v.level << endl;
	return off;
}

void TVopros::Clean() {
	question = "";
}

void TVopros::ChangeVopros() {
	cout << "1-Отредактировать вопрос\n2-Изменить категорию\n3-Поменять сложность" << endl;
	switch (GetNumber(1, 3))
	{
	case 1:
		cin.ignore();
		cout << "Ваш новый вопрос" << endl;
		getline(cin, question);
		break;

	case 2:
		cout << "Так какая это категория?" << endl;
		category = GetNumber(1, 3);
		break;
	case 3:
		level = !level;
		break;
	}
}

