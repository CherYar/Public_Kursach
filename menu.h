//menu.h
#pragma once
#include "zadanie.h";
#include "crypto.h"
using namespace std;
StudentsList list;

BOOL CrashHandler(DWORD fdwCtrlType) {//��� ���������� � ���������� ������ � ������ ���������� ���������� ���������
	switch (fdwCtrlType) {
	case CTRL_CLOSE_EVENT:
		list.ListToFileBin("file.bin"); Crypt();
		cout << "������ ��������� � ����������� �� �� ���������� ���������� ���������!" << endl;
		return TRUE;
	default:
		return FALSE;
	}
}


int menu() {//������� ����
	Decrypt();
	list.ListFromFileBin("file.bin");//���� ��� �������� ���� � ����������� ����������.
	cout << "���� ������ ������������. ��������� ������ � ������." << endl; system("pause");
	int mchoice = -1;
	for (;mchoice!=0;) 
	{
		CinDel
		unsigned short lsiz = list.getSize(); string lsize = to_string(lsiz);
		system("cls");
		cout << "������� ���������� ��������� � ���� ������: " + lsize << '\n';
		cout << "-------------------------------------------------------------\n";
		cout << "�������� ��������:\n";
		cout << "-------------------------------------------------------------\n";
		cout << "1.����� ������� ���������� � ���� ���������\n";
		cout << "2.����� ������ ���������� � ���� ��������� (�� �������������)\n";
		cout << "3.����� ������ ���������� � ���������� ��������\n";
		cout << "-------------------------------------------------------------\n";
		cout << "4.��������� ������ ����������� ��������\n";
		cout << "5.���������� ������ �������� � ������ � ����������\n";
		cout << "6.�������� �������� �� ���� ������\n";
		cout << "-------------------------------------------------------------\n";
		cout << "7.��������� ������� �������� 69 (��������� � ����������)\n";
		cout << "-------------------------------------------------------------\n";
		cout << "0.����� �� ���������, � ����������� ����������� ���� ������\n";
		cout << "-------------------------------------------------------------\n";
		cout << ">";
		mchoice = readIntV(" ", [](int c) {return c >= 0 && c <= 7; });
		switch (mchoice)
		{
		case 1: {cout << endl; list.printAll(); system("pause"); break; }
		case 2: {cout << endl; list.printMNOGO(); system("pause"); break; }
		case 3: {CinDel cout << endl; string prompt = "������� ����� ��������(1 - " + lsize + "): ";
			unsigned short index = readIntV(prompt, [&](int i) { return i >= 1 && i <= (lsiz); });
			list.printStudent(index - 1); system("pause"); break; }
		case 4: {CinDel cout << endl; string prompt = "������� ����� ��������(1 - " + lsize + "): ";
			unsigned short index = readIntV(prompt, [&](int i) { return i >= 1 && i <= (lsiz); }); list.studsubmenu(index - 1); cout << "\n������� ������" << endl; system("pause"); break; }
		case 5: {if (lsiz >= 15) { cout << "\n���������� �������� ��������, ��������� ������." << endl; system("pause"); break; } else { CinDel student nstud; nstud.makestudent(); list.addStudent(nstud); cout << "\n������� ��������\n"; system("pause"); break;}  }
		case 6:{ CinDel cout << endl; string prompt = "������� ����� ��������(1 -  " + lsize + "): ";
			unsigned short index = readIntV(prompt, [&](int i) { return i >= 1 && i <= (lsiz); }); list.removeStudent(index-1); cout << "\n������� �����." << endl; system("pause"); break;  }
		case 7: { CinDel cout << endl; unsigned int mx, mi; mi = readIntV("������� ����������� ��� ����������� ��� ����������:", [](int y) { return y >= 1984 && y <= 2030; });
			mx = readIntV("������� ������������ ��� ����������� ��� ����������:", [](int y) { return y >= 1984 && y <= 2030; });
			splitStudentsByGrades(list, mi, mx); system("pause"); break; }
		case 0: { list.ListToFileBin("file.bin"); Crypt(); cout << "\n������ ��������� ���������, ���� ������ �����������."; return 0; system("pause"); }
		default: {cout << "\n����������� ��������!\n"; CinDel break; }
		}
	}
	return 0;
}



