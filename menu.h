//menu.h
#pragma once
#include "zadanie.h";
#include "crypto.h"
using namespace std;

 // instisubmenu(), progsubmenu(), sessiasubmenu();


int menu() {
	Decrypt();
	StudentsList list("file.bin");//Пока что тестовый файл с одинаковыми студентами.
	cout << "База данных расшифрована. Программа готова к работе." << endl; system("pause");
	string choice;
	int mchoice = -1;
	
	for (;mchoice!=0;) 
	{
		 static unsigned short lsiz = list.getSize(); static string lsize = to_string(lsiz + 1);
		system("cls");
		cout << "Текущее количество студентов в базе данных:" + lsize << '\n';
		cout << "-------------------------------------------------------------\n";
		cout << "Выберете действие:\n";
		cout << "1.Вывод краткой информации о всех студентах\n";
		cout << "2.Вывод полной информации о всех студентах\n";
		cout << "3.Вывод полной информации о конкретном студенте\n";
		cout << "4.Изменение данных конкретного студента\n";
		cout << "5.Добавление нового студента с вводом с клавиатуры\n";
		cout << "6.Удаление студента из базы данных\n";
		cout << "7.Выполнить задание варианта 69 (разбиение и сортировка)\n";
		cout << "-------------------------------------------------------------\n";
		cout << "0.Выход из программы, с последующим шифрованием базы данных\n";
		cout << "> ";
		getline(cin, choice);
		if (ValidIntModernised(choice)) 
			mchoice = stoi(choice);
		else { cout << "\nНекорректная команда!\n"; system("pause"); CinDel;}
		switch (mchoice)
		{
		case 1: {cout << endl; list.printAll(); system("pause"); break; }
		case 2: {cout << endl; list.printMNOGO(); system("pause"); break; }
		case 3: {cout << endl; string prompt = "Введите номер студента(1 - " + lsize + "): ";
			unsigned short index = readIntV(prompt, [](int i) { return i >= 1 && i <= (lsiz); });
			list.printStudent(index + 1); system("pause"); break; }
		case 4: {cout << endl; string prompt = "Введите номер студента(1 - " + lsize + "): ";
			unsigned short index = readIntV(prompt, [](int i) { return i >= 1 && i <= (lsiz); }); list.studsubmenu(index); system("pause"); break; }
		case 5: {if (lsiz >= 15) { cout << "\nНевозможно добавить студента, достигнут предел." << endl; system("pause"); break; } else { student nstud; nstud.makestudent(); list.addStudent(nstud); cout << "\nСтудент добавлен\n"; system("pause"); break;}  }
		case 6:{cout << endl; string prompt = "Введите номер студента(1 - " + lsize + "): ";
			unsigned short index = readIntV(prompt, [](int i) { return i >= 1 && i <= (lsiz); }); list.removeStudent(index); cout << "\nСтудент удалён." << endl; system("pause"); break;  }
		case 7: {unsigned int mx, mi; mi = readIntV("Введите минимальный год поступления для сортировки:", [](int y) { return y >= 1984 && y <= 2030; });
			mx = readIntV("Введите максимальный год поступления для сортировки:", [](int y) { return y >= 1984 && y <= 2030; });
			splitStudentsByGrades(list, mi, mx); system("pause"); break; }
		case 0: {list.writeToFileBinary("file.bin"); Crypt(); cout << "\nРабота программы завершена, база данных зашифрована."; return 0; system("pause"); }
		default: {cout << "\nНеизвестная операция!\n"; system("pause"); break; }
		}
		CinDel;
	}
	return 0;
}

int progsubmenu() {//Изменение данных о сессииях студента
	string pchoice;
	int pmchoice = -1;
	for (; pmchoice != 0;)
		system("cls");
	cout << "Выберете действие:\n";
	cout << "1.Добавить новую сессию с вводом с клавиатуры\n";
	cout << "2.Удалить сессию\n";
	cout << "3.Заменить существующию сессию на введённую с клавиатуры\n";
	cout << "4.Изменить данные в конкретной сессии\n";
	cout << "5.Повторно вывести все сессии студента\n"
	cout << "0.Выйти и вернуться к работе с студентом\n";
	cout << "> ";
	switch (pmchoice) {
	case 1: {if list.students[i].prog.getsize() < blah blah должна быть нормалная проверка количества сессий. sessia nsessia; nssessia.makesessia(); list.students[i].prog.addsessia(nsessia);  }
	case 2: {cout << list.students[i].prog; readIntV("Введите номер сессии для удаления:") }
	case 3: {sessia nsessia; if list.students[i].prog.getsize < blah blah должна быть нормалная проверка введённого номера сессии с ReadIntV сессий.nssessia.makesessia(); list.students[i].prog.addsessia(nsessia);  }
	case 4: {sessiasubmenu(); }
	case 5: {cout << prog??? }
	case 0: {/*????????*/}
	default: {cout << "\nНеизвестная операция!\n"; system("pause"); break; }
	}
}
int sessiasubmenu() {//изменение данных об отдельной сессии
	string lchoice;
	int lmchoice = -1;
	for (; lmchoice != 0;)
		system("cls");
	cout << "Выберете действие:\n";
	cout << "1.Добавить зачёт\n";
	cout << "2.Добавить экзамен\n";
	cout << "3.Удалить зачёт\n";
	cout << "4.Удалить экзамен\n";
	cout << "5.Изменить зачёт с вводом с клавиатуры\n";
	cout << "6.Изменить экзамен с вводом с клавиатуры\n";
	cout << "7.Повторно вывести текущую сессию\n"
	cout << "0.Выйти и вернуться к работе с cписком сессий\n";
	cout << "> ";
	switch (pmchoice) {
	case 1: {sessia::predza newz; if this? ? ? getzachcount < 5 ReadStrW("Введите название зачёта:") и т.п. }
	case 2: {sessia::predex newx; if this ? ? ? getexamcount < 5 ReadStrW("Введите название экзамена:") и т.п. }
	case 3: {unsigned short index }
	case 4: {unsigned short index }
	case 5: {cout << prog ? ? ? }
	case 6: {cout << this???? }
	case 7: {cout << this ? ? ? ? }
	case 0: {/*????????*/}
	default: {cout << "\nНеизвестная операция!\n"; system("pause"); break; }
	}
}


