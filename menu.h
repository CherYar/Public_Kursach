//Честно адаптированное меню Филатова (он сам предложил его использовать).
//Он посоветовал использвать "форвардное" объявление

#pragma once
#include "misc.h"
using namespace std;



int menu() {
	string choice;
	int mchoice = -1;
	for (;mchoice!=0;) 
	{
		system("cls");
		cout << "Укажите:\n";
		cout << "1.Задание №1\n";
		cout << "2.Задание №2\n";
		cout << "3.Задание №3\n";
		cout << "4.Задание №4\n";
		cout << "5.Задание №5\n";
		cout << "6.Задание №6\n";
		cout << "7.Выход\n";
		cout << "> ";
		getline(cin, choice);//Филатов рекомендовал использовать getline, а не просто cin. Из за пробелов. getline нормально обрабатывает пробелы
		if (ValidInt(choice))
			mchoice = stoi(choice);
		else { cout << "\nНекорректная команда!\n"; system("pause"); CinDel; return 666; }
		switch (mchoice)
		{
		case 1: {return 1; system("pause"); break; }//пока что это просто тест, меню ничего не делает
		case 2: {return 2; system("pause"); break; }
		case 3: {return 3; system("pause"); break; }
		case 4: {return 4; system("pause"); break; }
		case 5: {return 5; system("pause"); break; }
		case 6: {return 6; system("pause"); break; }
		case 7: {return 7; system("pause"); break; }
		default: {cout << "\nНеизвестная операция!\n"; system("pause"); break; }

		}
		CinDel;
	}
	return 0;
}