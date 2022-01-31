#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <Windows.h>
#include "Header.h"
#include "TVopros.h"
#include "TBilet.h"

using namespace std;

void CreatMenu() {
	cout << "\n0- Выйти из программы\n1- Добавить вопрос в базу вопросов\n2- Вывести базу вопросов\n3- Отредактировать вопрос\n4- Cгенирировать билет\n5- Cохранить базу вопросов в файл\n6- Cчитать базу из файла\n7- Отсортировать базу\n8- Просмотр вопросов определенной категории/сложности\n9- Поиск по ключевой фразе\n10- вывод базы билетов из файла\n11- Запись базы билетов в файл\n12- замена вопроса в билете " << endl;
}

void Baseout(const vector <TVopros> Base)
{
	for (int i = 0; i < Base.size(); i++) {
		cout << "Вопрос " << i + 1 << endl;
		cout << Base[i];
	};

}

bool IsBaseExist(const vector <TVopros>& DBase) {
	bool b = true;
	if (DBase.size() == 0) {
		cout << "База пуста. Нажмите 1, чтобы добавить\n" << endl;
		b = false;
	}
	return b;
}

void WriteToFile(const vector <TVopros>& DBase, string name) {
	ofstream fout(name);
	for (int i = 0; i < DBase.size(); i++)
	{
		fout << "Вопроc " << endl;
		fout << DBase[i];
		fout << "" << endl;
	}

	fout.close();
}

void ReadOutFile(vector <TVopros>& Base, string name) {
	string NumberOfQuestion, st;
	ifstream fin(name);
	TVopros v;
	if (!fin.is_open())
		cout << "Файл не может быть открыт или не существует!\n";
	else {
		while (!fin.eof()) {
			getline(fin, NumberOfQuestion);
			fin >> v;
			fin >> st;
			Base.push_back(v);
		}
		cout << "Данные из файла записаны в базу\n" << endl;
	}
	fin.close();
}

TBilet CreatBilet(int count, vector <TVopros>  Base) {

	TBilet Bilet;
	while (Bilet.Qs.size() != (count - 1)) {
		int j = rand() % Base.size();
		if (Base[j].getLevel() == 0) {
			Bilet.Qs.push_back(Base[j]);
			Base.erase(Base.begin() + j);
		}
	};
	while (!(Bilet.Qs.size() == count)) {
		int j = rand() % Base.size();
		if (Base[j].getLevel() == 1 || Base[j].getLevel() == 0) {
			Bilet.Qs.push_back(Base[j]);
			Base.erase(Base.begin() + j);
		};
	};
	return Bilet;

}

void GetTest(vector <TBilet>& Bilet)
{
	{

		string Namefile;
		string t;
		TBilet Variant;
		int QuestionNumber;
		cout << "Введите имя файла с расширением .txt \n";
		cin.ignore();
		getline(cin, Namefile);
		ifstream fin(Namefile, ios::in);//начало файла
		if (!fin.is_open())
			cout << "Возникла проблема с файлом\n";
		else
		{
			string w;
			while (!fin.eof())
			{
				fin >> Variant;
				Bilet.push_back(Variant);
				Variant.Qs.erase(Variant.Qs.begin(), Variant.Qs.end());
			}
		}
		fin.close();
	}
}

void PrintVariantToFile(vector <TBilet>& Contr)
{
	TVopros Question;
	string Namefile;
	cout << "Введите имя файла с расширением .txt \n";
	cin.ignore();
	getline(cin, Namefile);
	ofstream fout(Namefile, ios::trunc);//удалить содержимое файла, если он существует
	if (!fout.is_open())
		cout << "Возникла проблема с файлом\n";
	else
		for (auto& v : Contr)
		{
			fout << v;
			fout << "___\n\n0\n0";
		}
	fout.close();
}


void printTest1(vector <TBilet>& BiletBase,  string Namefile)
{
	ofstream fout(Namefile, ios::trunc);
	if (!fout.is_open())
		cout << "Возникла проблема с файлом\n";
	else {
		for (int j = 0; j < BiletBase.size(); j++) {
			fout << "________________Вариант №" << j + 1 << "________________\n" ;
			for (int i = 0; i < BiletBase[j].Qs.size(); i++) {
				if (BiletBase[j].Qs[i].getLevel() == 0) {
					fout << i + 1 << ") " << BiletBase[j].Qs[i].getQuestion() << "\n";
				}
				else {
					fout << i + 1 << ")* " << BiletBase[j].Qs[i].getQuestion() << "\n";
				}
			}
			fout << "___________________________________________\n" << endl;
		};
	}
}

void printTest2(vector <TBilet>& BiletBase,string Namefile)
{
	ofstream fout(Namefile, ios::trunc);
	if (!fout.is_open())
		cout << "Возникла проблема с файлом\n";
	else {
		for (int j = 0; j < BiletBase.size(); j++) {
			fout << "Контрольная работа\n" << "Вариант " << j + 1 << "\n" ;
			for (int i = 0; i < BiletBase[j].Qs.size(); i++) {
				if (BiletBase[j].Qs[i].getLevel() == 0) {
					fout << i + 1 << ") " << BiletBase[j].Qs[i].getQuestion() << "\n";
				}
				else {
					fout << i + 1 << ")* " << BiletBase[j].Qs[i].getQuestion() << "\n";
				}
			}
			fout << "___________________________________________\n" << endl;
		};
	}
}

void printTest3(vector <TBilet>& BiletBase, string Namefile)
{
	 ofstream fout(Namefile, ios::trunc);
	 if (!fout.is_open())
		 cout << "Возникла проблема с файлом\n";
	 else {
		 for (int j = 0; j < BiletBase.size(); j++) {
			 fout << "Контрольная работа\n" << "Вариант " << j + 1 << "\n" ;
			 for (int i = 0; i < BiletBase[j].Qs.size(); i++) {
				 if (BiletBase[j].Qs[i].getLevel() == 0) {
					 fout << i + 1 << ") " << BiletBase[j].Qs[i].getQuestion() << "\n";
				 }
				 else {
					 fout << i + 1 << ")* " << BiletBase[j].Qs[i].getQuestion() << "\n";
				 }
			 }
			 fout << "Зав.кафедрой _________________\n" << endl;
			 cout << " " << endl;
		 };
	 };
}


typedef void (*MyPrints)(vector <TBilet>&, string);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	TBilet Bilet;
	vector <TVopros> DBase;
	vector <TBilet> BiletBase;
	while (1) {
		CreatMenu();
		switch (GetNumber(0, 12))
		{
		case 0:
			return 0;
		case 1:
		{
			TVopros Vopros;
			cin >> Vopros;
			DBase.push_back(Vopros);
			break;
		}
		case 2:
			if (!IsBaseExist(DBase)) {
				break;
			}
			else
				Baseout(DBase);
			break;
		case 3:
			int k;
			if (!IsBaseExist(DBase)) {
				break;
			}
			else {
				cout << " 1 - Найти билет по номеру в базе\n 2 - Найти билет по фразе\n";
				switch (GetNumber(1, 2))
				{
				case 1:
				{
					cout << "Введите номер вопроса, который хотите отредактировать.\n";
					int z = DBase.size();
					int n = GetNumber(1, z);
					cout << DBase[n];
					cout << "Редактировать или удалить? (1 - редактировать, 2 - удалить).\n";
					switch (GetNumber(1, 2))
					{
					case 1:
					{
						DBase[n].ChangeVopros();
						break;
					}
					case 2:
					{
						DBase.erase(DBase.begin() + n);
						break;
					}
					};

				}
				case 2:
				{
					string key;
					cout << "Какое слово вы хотите найти?\n";
					cin.ignore();
					getline(cin, key);
					for (int i = 0; i < DBase.size(); i++)
					{
						if (DBase[i].Poisk(key))
						{
							cout << DBase[i];
							cout << "Редактировать или удалить? (1 - редактировать, 2 - удалить).\n";
							switch (GetNumber(1, 2))
							{
							case 1:
							{
								DBase[i].ChangeVopros();
								break;
							}
							case 2:
							{
								DBase.erase(DBase.begin() + i);
								break;
							}
							}
						}
					}
					break;
				}
				}
				break;
			}
		case 4:
			int numberOfVariants; //Кол-во вариантов
			int quantityOfQuestions; //Количество вопросов в билете
			int tipe;//Тип оформления билета
			if (!IsBaseExist(DBase)) {
				break;
			}
			else {
				cout << "Какое количество вариантов(1-60)" << endl;
				numberOfVariants = GetNumber(1, 60);
				cout << "Количество вопросов в билете (1-5)" << endl;
				quantityOfQuestions = GetNumber(1, 5);
				for (int j = 0; j < numberOfVariants; j++) {
					BiletBase.push_back(CreatBilet(quantityOfQuestions, DBase));
				};
				cout << "\nБаза билетов создана. Теперь вы можете записать ее в файл. Для этого нажмите 11\n";
				break;
			}
			break;
		case 5:
			if (!IsBaseExist(DBase)) {
				break;
			}
			else {
				cout << "Введите имя файла" << endl;
				string name;
				cin >> name;
				WriteToFile(DBase, name);
			}
			cout << "Файл cоздан\n" << endl;
			cout << "Для просмотра файла, откройте его в папке\n" << endl;
			break;

		case 6: {
			string name;
			cout << "Из какого файла считать базу?" << endl;
			cin >> name;
			ReadOutFile(DBase, name);
			break;
		}

		case 7: {
			TVopros Base;
			cout << "1-По сложности \n2-По категориям\n";
			if (GetNumber(1, 2) == 1) {
				Base.sortLevel(DBase);
			}
			else {
				Base.sortCategory(DBase);
			}
			break;
		}
		case 8: {
			if (!IsBaseExist(DBase)) {
				break;
			}
			else {
				cout << "Вопросы какой категории вывести (1-3)\n";
				int cat = GetNumber(1, 3);
				cout << "А какой сложности?  (0 - легкий, 1 - сложный, 2 - и то,и то)\n";
				int lev = GetNumber(0, 2);
				if (lev == 2)
				{
					int control = 0;
					for (int i = 0; i < DBase.size(); i++)
						if (DBase[i].CheckCategory(cat))
						{
							cout << (DBase[i]);
							control++;
						}
					if (control == 0)
						cout << "Таких вопросов нет\n";
				}
				else
				{
					int control = 0;
					for (int i = 0; i < DBase.size(); i++)
						if (DBase[i].CheckCategory(cat) && DBase[i].getLevel() == lev)
						{
							cout << DBase[i];
							control++;
						}
					if (control == 0)
						cout << "Таких вопросов нет\n";
				};
			};
			break;
		}

		case 9: {
			if (!IsBaseExist(DBase)) {
				break;
			}
			else {
				string key;
				cout << "Поиск по какой ключевой фразе выполнить?\n";
				cin.ignore();
				getline(cin, key);
				for (int i = 0; i < DBase.size(); i++)
				{
					if (DBase[i].Poisk(key))
					{
						cout << DBase[i];
					}
				}
			};

			break;
		}
		case 10: {
			GetTest(BiletBase);
			break;
		}
		case 11: {

			if (BiletBase.size() == 0) {
				cout << "Нет базы билетов\n";
				break;
			}
			else {
				cout << "1-Для дальнейшей работы\n2- Для печати\n";
				switch (GetNumber(1, 2))
				{
				case 1: {
					PrintVariantToFile(BiletBase);
					break;
				};
				case 2: {
					MyPrints MPs[] = { printTest1, printTest2, printTest3 };
					cout << "Оформить контрольную по типу 1-3" << endl;
					tipe = GetNumber(1, 3);
					string Namefile;
					cout << "Введите имя файла с расширением .txt \n";
					cin.ignore();
					getline(cin, Namefile);
					switch (tipe) {
						case 1:
							MPs[tipe - 1](BiletBase, Namefile);
							break;
						case 2:
							MPs[tipe - 1](BiletBase, Namefile);
							break;
						case 3:
							MPs[tipe - 1](BiletBase, Namefile);
							break;
						};
						break;
					};
				};

			}
			break;
		}
		case 12: {
			if (BiletBase.size() == 0 || !IsBaseExist(DBase)) {
				cout << "В базе нет билетов или база вопросов пуста\n";
				break;
			}
			else {
				vector <TVopros> Zamena;
				int f = BiletBase.size();
				cout << "В каком билете вы хотите поменять вопрос?\n";
				int VariantNumber = GetNumber(1, f);
				int d = BiletBase[VariantNumber - 1].Qs.size();
				cout << "Какой вопрос вы хотите поменять?\n";
				int QuestionNumber = GetNumber(1, d);
				int r = 0;
				cout << "Вопросы для замены:\n";
				for (int i = 0; i < DBase.size(); i++)
				{
					if (DBase[i].getLevel() == BiletBase[VariantNumber - 1].Qs[QuestionNumber - 1].getLevel())
					{
						cout << r + 1 << ")\n";
						cout << DBase[i];
						Zamena.push_back(DBase[i]);
						r++;
					}
				}
				if (r == 0)
					cout << "Таких вопросов нет\n";
				else
				{
					cout << "На какой из этих вопросов вы хотите заменить выбранный вами?\n";
					int Z = Zamena.size();
					int k = GetNumber(1, Z);
					BiletBase[VariantNumber - 1].Qs[QuestionNumber - 1] = Zamena[k - 1];
				}
			}
			break;
		}
		}
	}
}