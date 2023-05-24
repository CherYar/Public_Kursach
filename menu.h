//menu.h
#pragma once
#include "zadanie.h";
#include "crypto.h"
using namespace std;
StudentsList list;

BOOL CrashHandler(DWORD fdwCtrlType) {//Для сохранения и шифрования данных в случае нештатного завершения программы
	switch (fdwCtrlType) {
	case CTRL_CLOSE_EVENT:
		list.ListToFileBin("database.bin"); Crypt();
		cout << "Данные сохранены и зашифрованы из за нештатного завершения программы!" << endl;
		return TRUE;
	default:
		return FALSE;
	}
}


int menu() {//Главное меню
	Decrypt();
	list.ListFromFileBin("database.bin");//Пока что тестовый файл с одинаковыми студентами.
	cout << "База данных расшифрована. Программа готова к работе." << endl; system("pause");
	int mchoice = -1;
	for (;mchoice!=0;) 
	{
		CinDel
		unsigned short lsiz = list.getSize(); string lsize = to_string(lsiz);
		system("cls");
		cout << "Текущее количество студентов в базе данных: " + lsize << '\n';
		cout << "-------------------------------------------------------------\n";
		cout << "Выберете действие:\n";
		cout << "-------------------------------------------------------------\n";
		cout << "1.Вывод краткой информации о всех студентах\n";
		cout << "2.Вывод полной информации о всех студентах (не рекомендуется)\n";
		cout << "3.Вывод полной информации о конкретном студенте\n";
		cout << "-------------------------------------------------------------\n";
		cout << "4.Изменение данных конкретного студента\n";
		cout << "5.Добавление нового студента с вводом с клавиатуры\n";
		cout << "6.Удаление студента из базы данных\n";
		cout << "-------------------------------------------------------------\n";
		cout << "7.Выполнить задание варианта 69 (разбиение и сортировка)\n";
		cout << "-------------------------------------------------------------\n";
		cout << "0.Выход из программы, с последующим шифрованием базы данных\n";
		cout << "-------------------------------------------------------------\n";
		cout << ">";
		mchoice = readIntV(" ", [](int c) {return c >= 0 && c <= 7; });
		switch (mchoice)
		{
		case 1: {cout << endl; list.printAll(); system("pause"); break; }
		case 2: {cout << endl; list.printMNOGO(); system("pause"); break; }
		case 3: {CinDel cout << endl; string prompt = "Введите номер студента(1 - " + lsize + "): ";
			unsigned short index = readIntV(prompt, [&](int i) { return i >= 1 && i <= (lsiz); });
			list.printStudent(index - 1); system("pause"); break; }
		case 4: {CinDel cout << endl; string prompt = "Введите номер студента(1 - " + lsize + "): ";
			unsigned short index = readIntV(prompt, [&](int i) { return i >= 1 && i <= (lsiz); }); list.studsubmenu(index - 1); cout << "\nСтудент изменён" << endl; system("pause"); break; }
		case 5: {if (lsiz >= 15) { cout << "\nНевозможно добавить студента, достигнут предел." << endl; system("pause"); break; } else { CinDel student nstud; nstud.makestudent(); list.addStudent(nstud); cout << "\nСтудент добавлен" << endl; system("pause"); break; }  }
		case 6:{ CinDel cout << endl; string prompt = "Введите номер студента(1 -  " + lsize + "): ";
			unsigned short index = readIntV(prompt, [&](int i) { return i >= 1 && i <= (lsiz); }); list.removeStudent(index-1); cout << "\nСтудент удалён." << endl; system("pause"); break;  }
		case 7: { CinDel cout << endl; unsigned int mx, mi; mi = readIntV("Введите минимальный год рождения для сортировки:", [](int y) { return y >= 1950 && y <= 2030; });
			mx = readIntV("Введите максимальный год рождения для сортировки:", [](int y) { return y >= 1950 && y <= 2030; });
			splitStudentsByGrades(list, mi, mx); system("pause"); break; }
		case 0: { list.ListToFileBin("database.bin"); Crypt(); cout << "\nРабота программы завершена, база данных зашифрована."; return 0; system("pause"); }
		default: {cout << "\nНеизвестная операция!\n"; CinDel break; }
		}
	}
	return 0;
}



