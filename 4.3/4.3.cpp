#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <Windows.h> 
#include <time.h>
#include <stdio.h>

using namespace std;

struct Student {
	string  lastname;
	int Note[3];
};

void AddTXT(char* fname);
void PrintTXT(char* fname);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char fname[100];

	int menuItem;
	do {
		cout << "Оберіть дію: " << endl;
		cout << "[1]  Cтворити файл." << endl;
		cout << "[2]  Додати елементи до списку." << endl;
		cout << "[3]  Переглянути список." << endl;

		cout << "[9]  Відкрити файл." << endl;
		cout << "[0]  вихід та завершення роботи програми" << endl << endl;
		cout << "Введіть значення: "; cin >> menuItem;
		switch (menuItem) {
		case 1:
			cout << "Введіть ім'я файлу: "; cin >> fname;
			AddTXT(fname);
			break;
		case 2:
			AddTXT(fname);
			break;
		case 3:
			PrintTXT(fname);
			break;
		case 9:
			cout << "Введіть ім'я файлу: "; cin >> fname;
			break;
		case 0:
			break;
		default:
			cout << "Ви ввели помилкове значення! Слід ввести число - номер вибраного пункту меню" << endl;
		}
	} while (menuItem != 0);

	system("pause");
	cin.get();
	return 0;
}

void AddTXT(char* fname) {
	ofstream fout;
	fout.open(fname, ios::app);

	int k;
	cout << "Кількість елементів: "; cin >> k;
	Student* s = new Student[k];

	for (int i = 0; i < k; i++)
	{
		cin.get();
		cin.sync();

		cout << "Iм'я: "; getline(cin, s[i].lastname);
		fout << ' ' << s[i].lastname;

		for (int j = 0; j < 3; j++)
		{
			cout << "Оцінка з " << j + 1 << "предмету : ";
			cin >> s[i].Note[j];
			fout << ' ' << s[i].Note[j];
		}
		fout << endl;
	}
}

void PrintTXT(char* fname)
{
	ifstream fin(fname);
	string str;
	while (getline(fin, str))
	{
		cout << str << endl;
	}
	cout << endl;
}

