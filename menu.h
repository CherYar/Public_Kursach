//menu.h
#pragma once
#include "zadanie.h";
#include "crypto.h"
using namespace std;

int studsubmenu(), instisubmenu(), progsubmenu(), sessiasubmenu();



int menu() {
	//decrypt() //А что расшифровывать если базы данных нет... Ну точнее она есть, но не готова
	StudentsList list("file.bin");//Пока что тестовый файл с одинаковыми студентами.
	cout << "База данных расшифрована. Программа готова к работе." << endl; system("pause");
	string choice;
	int mchoice = -1;
	static unsigned short lsiz = list.getSize(); static string lsize = to_string(lsiz + 1);
	for (;mchoice!=0;) 
	{
		system("cls");
		cout << "Выберете действие:\n";
		cout << "1.Вывод краткой информации о всех студентах\n";
		cout << "2.Вывод полной информации о всех студентах\n";
		cout << "3.Вывод полной информации о конкретном студенте\n";
		cout << "4.Изменение данных конкретного студента\n";
		cout << "5.Добавление нового студента с вводом с клавиатуры\n";
		cout << "6.Удаление студента из базы данных\n";
		cout << "5.Выполнить задание варианта 69 (разбиение и сортировка)\n";
		cout << "0.Выход из программы, с последующим шифрованием базы данных\n";
		cout << "> ";
		getline(cin, choice);//Филатов рекомендовал использовать getline, а не просто cin. Из за пробелов. getline нормально обрабатывает пробелы
		if (ValidIntModernised(choice)) 
			mchoice = stoi(choice);
		else { cout << "\nНекорректная команда!\n"; system("pause"); CinDel; return 666; }
		switch (mchoice)
		{
		case 1: {cout << endl; list.printAll(); system("pause"); break; }
		case 2: {cout << endl; list.printMNOGO(); system("pause"); break; }
		case 3: {cout << endl; string prompt = "Введите номер студента(1 - " + lsize + "): ";
			unsigned short index = readIntV(prompt, [](int i) { return i >= 1 && i <= (lsiz + 1); });
			list.printStudent(index + 1); break; }
		case 4: {studsubmenu(); system("pause"); break; }
		case 5: {unsigned int mx, mi; mi = readIntV("Введите минимальный год поступления для сортировки:", [](int y) { return y >= 1984 && y <= 2030; });
			mx = readIntV("Введите максимальный год поступления для сортировки:", [](int y) { return y >= 1984 && y <= 2030; });
			splitStudentsByGrades(list, mi, mx); system("pause"); break; }
		case 6:{}
		case 0: {/*crypt() что шифровать если базы данных нет... Ну точнее она есть, но не готова*/ cout << "\nРабота программы завершена, база данных зашифрована."; return 0; system("pause"); mchoice = 0; break;/*Я НЕ МОГУ ПОНЯТЬ КАК ВЫХОДИТЬ ИЗ МЕНЮ ААААААААААААААААААААААААААААААААААА*/ }
		default: {cout << "\nНеизвестная операция!\n"; system("pause"); break; }

		}
		CinDel;
	}
	return 0;
}
int studsubmenu() { // Для изменения данных о студенте
	//a.prfull();
	string schoice;
	int smchoice = -1;
	for (; smchoice != 0;)
	system("cls");
	cout << "Выберете действие:\n";
	cout << "1. Изменить индивидуальный номер студента\n";
	cout << "2. Изменить ФИО студента\n";
	cout << "3. Изменить фамилию студента\n";
	cout << "4. Изменить имя студента\n";
	cout << "5. Изменить отчество студента\n";
	cout << "6. Изменить пол студента\n";
	cout << "7. Изменить дату рождения и возраст\n";
	cout << "8. Изменить данные об институте/группе\n";
	cout << "9. Изменить данные о сессиях\n";
	cout << "10.Изменить физ. группу\n";
	cout << "0. Выйти и вернуться к работе с базой данных\n";
	cout << "> ";
	switch (smchoice) {
	case 1: {string nnum; }
	case 2: {name nfio; }
	case 3: {string nf; }
	case 4: {string ni; }
	case 5: {string no; }
	case 6: {unsigned short ngendr; }
	case 7: {date nborn; }
	case 8: {instisubmenu(); }
	case 9: {progsubmenu(); }
	case 10: {unsigned short nfizgroup; }
	case 0: {/*????????*/}
	default: {cout << "\nНеизвестная операция!\n"; system("pause"); break; }
	}
}
int instisubmenu(){//Изменение данных об иснтитуте и группе студента
	string ichoice;
	int imchoice = -1;
	for (; imchoice != 0;)
	system("cls");
	cout << "Выберете действие:\n";
	cout << "1.Изменить институт\n";
	cout << "2.Изменить кафедру\n";
	cout << "3.Изменить группу\n";
	cout << "4.Изменить Id программы\n";
	cout << "5.Изменить название программы\n";
	cout << "6.Изменить дату поступления\n";
	cout << "7.Изменить текущий курс\n";
	cout << "8.Изменить текущий семестр\n";
	cout << "9.Ещё раз вывести информацию об институте/группе\n";
	cout << "0.Выйти и вернуться к работе с студентом\n";
	cout << "> ";
	switch (imchoice) {
	case 1: {string ninsti; }
	case 2: {unsigned short nkaf; }
	case 3: {string ngroup; }
	case 4: {unsigned long nprogid; }
	case 5: {string no; }
	case 6: {unsigned short ngendr; }
	case 7: {unsigned short nckurs; }
	case 8: {unsigned short ncsem; }
	case 9:{list.studentws[i]printinsti}
	case 10: {unsigned short nfizgroup; }
	case 0: {/*????????*/}
	default: {cout << "\nНеизвестная операция!\n"; system("pause"); break; }
	}
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
	cout << "5.Ещё раз показать сессии студента\n"
	cout << "0.Выйти и вернуться к работе с студентом\n";
	cout << "> ";
	switch (pmchoice) {
	case 1: {sessia nsessia;if list.students[i].prog.getsize < blah blah должна быть нормалная проверка количества сессий. nssessia.makesessia();list.students[i].prog.addsessia(nsessia);  }
	case 2: {cout << list.students[i].prog; readIntV("Введите номер сессии для удаления:") }
	case 3: {sessia nsessia; if list.students[i].prog.getsize < blah blah должна быть нормалная проверка количества сессий.nssessia.makesessia(); list.students[i].prog.addsessia(nsessia);  }
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
	cout << "5.Изменить экзамен с вводом с клавиатуры\n";
	cout << "6.Ещё раз вывести сессию\n"
	cout << "0.Выйти и вернуться к работе с cписком сессий\n";
	cout << "> ";
	switch (pmchoice) {
	case 1: {sessia::predza newz; if this? ? ? getzachcount < 5 ReadStrW("Введите название зачёта:") и т.п. }
	case 2: {sessia::predex newx; if this ? ? ? getexamcount < 5 ReadStrW("Введите название экзамена:") и т.п. }
	case 3: {unsigned short index }
	case 4: {unsigned short index }
	case 5: {cout << prog ? ? ? }
	case 6: {cout << this???? }
	case 0: {/*????????*/}
	default: {cout << "\nНеизвестная операция!\n"; system("pause"); break; }
	}
}


