//menu.h
#pragma once
#include "zadanie.h";
//#include "crypto.h"// // ��� ���� ���)))))))))))))))))))))))))))))
using namespace std;

int menu() {
	//decrypt() // ��� ���� ���)))))))))))))))))))))))))))))
	cout << "���� ������ ������������." << endl; system("pause");
	string choice;
	int mchoice = -1;
	for (;mchoice!=0;) 
	{
		system("cls");
		cout << "�������� ��������:\n";
		cout << "1.����� ������� ���������� � ���� ���������\n";
		cout << "2.����� ������ ���������� � ���� ���������\n";
		cout << "3.����� ������ ���������� � ���������� ��������\n";
		cout << "4.��������� ������ ����������� ��������\n";
		cout << "5.���������� ������ �������� � ������ � ����������\n";
		cout << "6.�������� �������� �� ���� ������\n";
		cout << "5.��������� ������� �������� 69 (��������� � ����������)\n";
		cout << "0.����� �� ���������, � ����������� ����������� ���� ������\n";
		cout << "> ";
		getline(cin, choice);//������� ������������ ������������ getline, � �� ������ cin. �� �� ��������. getline ��������� ������������ �������
		if (ValidIntModernised(choice)) 
			mchoice = stoi(choice);
		else { cout << "\n������������ �������!\n"; system("pause"); CinDel; return 666; }
		switch (mchoice)
		{
		case 1: {return 1; system("pause"); break; }//���� ��� ��� ������ ����, ���� ������ �� ������((((
		case 2: {return 2; system("pause"); break; }
		case 3: {return 3; system("pause"); break; }
		case 4: {return 4; system("pause"); break; }
		case 5: {return 5; system("pause"); break; }
		case 0: {/*crypt()*/ cout << "\n������ ��������� ���������, ���� ������ �����������."; return 0; system("pause"); break; }
		default: {cout << "\n����������� ��������!\n"; system("pause"); break; }

		}
		CinDel;
	}
	return 0;
}
int studsubmenu() { // ��� ��������� ������ � ��������
	//a.prfull();
	string schoice;
	int smchoice = -1;
	for (; smchoice != 0;)
	system("cls");
	cout << "�������� ��������:\n";
	cout << "1. �������� �������������� ����� ��������\n";
	cout << "2. �������� ��� ��������\n";
	cout << "3. �������� ������� ��������\n";
	cout << "4. �������� ��� ��������\n";
	cout << "5. �������� �������� ��������\n";
	cout << "6. �������� ��� ��������\n";
	cout << "7. �������� ���� �������� � �������\n";
	cout << "8. �������� ������ �� ���������/������\n";
	cout << "9. �������� ������ � �������\n";
	cout << "10.�������� ���. ������\n";
	cout << "0. ����� � ��������� � ������ � ����� ������\n";
	cout << "> ";
	return 0;
}
int instisubmenu(){//��������� ������ �� ��������� � ������ ��������
	string ichoice;
	int imchoice = -1;
	for (; imchoice != 0;)
		system("cls");
	cout << "�������� ��������:\n";
	cout << "1.�������� ��������\n";
	cout << "2.�������� �������\n";
	cout << "3.�������� ������\n";
	cout << "4.�������� Id ���������\n";
	cout << "5.�������� �������� ���������\n";
	cout << "6.�������� ���� �����������\n";
	cout << "7.�������� ������� ����\n";
	cout << "8.�������� ������� �������\n";
	cout << "0.����� � ��������� � ������ � ���������\n";
	cout << "> ";
	return 0;
}

int progsubmenu() {//��������� ������ � �������� ��������
	string pchoice;
	int pmchoice = -1;
	for (; pmchoice != 0;)
		system("cls");
	cout << "�������� ��������:\n";
	cout << "1.�������� ����� ������ � ������ � ����������\n";
	cout << "2.������� ������\n";
	cout << "3.�������� ������������ ������ �� �������� � ����������\n";
	cout << "4.�������� ������ � ���������� ������\n";
	cout << "0.����� � ��������� � ������ � ���������\n";
	cout << "> ";
	return 0;
}
int sessiasubmenu() {//��������� ������ �� ��������� ������
	string lchoice;
	int lmchoice = -1;
	for (; lmchoice != 0;)
		system("cls");
	cout << "�������� ��������:\n";
	cout << "1.�������� �����\n";
	cout << "2.�������� �������\n";
	cout << "3.������� �����\n";
	cout << "4.������� �������\n";
	cout << "5.�������� �����\n";
	cout << "5.�������� �������\n";
	cout << "0.����� � ��������� � ������ � c������ ������\n";
	cout << "> ";
	return 0;
}



