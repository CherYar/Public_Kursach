//������ �������������� ���� �������� (�� ��� ��������� ��� ������������).
//�� ����������� ����������� "����������" ����������

#pragma once
#include "misc.h"
using namespace std;



int menu() {
	string choice;
	int mchoice = -1;
	for (;mchoice!=0;) 
	{
		system("cls");
		cout << "�������:\n";
		cout << "1.������� �1\n";
		cout << "2.������� �2\n";
		cout << "3.������� �3\n";
		cout << "4.������� �4\n";
		cout << "5.������� �5\n";
		cout << "6.������� �6\n";
		cout << "7.�����\n";
		cout << "> ";
		getline(cin, choice);//������� ������������ ������������ getline, � �� ������ cin. �� �� ��������. getline ��������� ������������ �������
		if (ValidIntModernised(choice)) 
			mchoice = stoi(choice);
		else { cout << "\n������������ �������!\n"; system("pause"); CinDel; return 666; }
		switch (mchoice)
		{
		case 1: {return 1; system("pause"); break; }//���� ��� ��� ������ ����, ���� ������ �� ������
		case 2: {return 2; system("pause"); break; }
		case 3: {return 3; system("pause"); break; }
		case 4: {return 4; system("pause"); break; }
		case 5: {return 5; system("pause"); break; }
		case 6: {return 6; system("pause"); break; }
		case 7: {return 7; system("pause"); break; }
		default: {cout << "\n����������� ��������!\n"; system("pause"); break; }

		}
		CinDel;
	}
	return 0;
}