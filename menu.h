//menu.h
#pragma once
#include "zadanie.h";
#include "crypto.h"
using namespace std;

 // instisubmenu(), progsubmenu(), sessiasubmenu();



int menu() {
	Decrypt();
	StudentsList list("file.bin");//���� ��� �������� ���� � ����������� ����������.
	cout << "���� ������ ������������. ��������� ������ � ������." << endl; system("pause");
	string choice;
	int mchoice = -1;
	
	for (;mchoice!=0;) 
	{
		static unsigned short lsiz = list.getSize(); static string lsize = to_string(lsiz + 1);
		system("cls");
		cout << "������� ���������� ��������� � ���� ������:" + lsize << '\n';
		cout << "�������� ��������:\n";
		cout << "1.����� ������� ���������� � ���� ���������\n";
		cout << "2.����� ������ ���������� � ���� ���������\n";
		cout << "3.����� ������ ���������� � ���������� ��������\n";
		cout << "4.��������� ������ ����������� ��������\n";
		cout << "5.���������� ������ �������� � ������ � ����������\n";
		cout << "6.�������� �������� �� ���� ������\n";
		cout << "7.��������� ������� �������� 69 (��������� � ����������)\n";
		cout << "0.����� �� ���������, � ����������� ����������� ���� ������\n";
		cout << "> ";
		getline(cin, choice);
		if (ValidIntModernised(choice)) 
			mchoice = stoi(choice);
		else { cout << "\n������������ �������!\n"; system("pause"); CinDel;}
		switch (mchoice)
		{
		case 1: {cout << endl; list.printAll(); system("pause"); break; }
		case 2: {cout << endl; list.printMNOGO(); system("pause"); break; }
		case 3: {cout << endl; string prompt = "������� ����� ��������(1 - " + lsize + "): ";
			unsigned short index = readIntV(prompt, [](int i) { return i >= 1 && i <= (lsiz); });
			list.printStudent(index + 1); break; }
		case 4: {cout << endl; string prompt = "������� ����� ��������(1 - " + lsize + "): ";
			unsigned short index = readIntV(prompt, [](int i) { return i >= 1 && i <= (lsiz); }); list.updateStudent(index, studsubmenu(list.getStudent(index))); system("pause"); break; }
		case 5: {if (lsiz >= 15) { cout << "\n���������� �������� ��������, ��������� ������." << endl; break; } else { student nstud; nstud.makestudent(); list.addStudent(nstud); } break; }
		case 6:{cout << endl; string prompt = "������� ����� ��������(1 - " + lsize + "): ";
			unsigned short index = readIntV(prompt, [](int i) { return i >= 1 && i <= (lsiz); }); list.removeStudent(index); cout << "\n������� �����." << endl; system("pause"); break;  }
		case 7: {unsigned int mx, mi; mi = readIntV("������� ����������� ��� ����������� ��� ����������:", [](int y) { return y >= 1984 && y <= 2030; });
			mx = readIntV("������� ������������ ��� ����������� ��� ����������:", [](int y) { return y >= 1984 && y <= 2030; });
			splitStudentsByGrades(list, mi, mx); system("pause"); break; }
		case 0: {list.writeToFileBinary("file.bin"); Crypt(); cout << "\n������ ��������� ���������, ���� ������ �����������."; return 0; system("pause"); }
		default: {cout << "\n����������� ��������!\n"; system("pause"); break; }
		}
		CinDel;
	}
	return 0;
}








/*student studsubmenu(student stud) { // ��� ��������� ������ � ��������
	string schoice;
	int smchoice = -1;
	for (; smchoice != 0;) {
		system("cls");
		cout << stud.num << '\n';
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
		cout << "11.�������� ������� ���������� � ������� ��������.";
		cout << "0. ����� � ��������� � ������ � ����� ������\n";
		cout << "> ";
		getline(cin, schoice);
		if (ValidIntModernised(schoice)) smchoice = stoi(schoice);
		else { cout << "\n������������ �������!\n"; system("pause"); CinDel; }
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
		case 11: {stud.prfull(); break; }
		case 0: {cout << "\n����������� � ������� ����." << endl; return stud; system("pause"); }
		default: {cout << "\n����������� ��������!\n"; system("pause"); break; }
		}
	}
}*/
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
	cout << "9.�������� ������� ���������� �� ���������/������\n";
	cout << "0.����� � ��������� � ������ � ���������\n";
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
	case 9:{list.studentws[i]printinsti/*����� ������� �� ������ ������ ���*/}
	case 10: {unsigned short nfizgroup; }
	case 0: {/*????????*/}
	default: {cout << "\n����������� ��������!\n"; system("pause"); break; }
	}
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
	cout << "5.�������� ������� ��� ������ ��������\n"
	cout << "0.����� � ��������� � ������ � ���������\n";
	cout << "> ";
	switch (pmchoice) {
	case 1: {if list.students[i].prog.getsize() < blah blah ������ ���� ��������� �������� ���������� ������. sessia nsessia; nssessia.makesessia(); list.students[i].prog.addsessia(nsessia);  }
	case 2: {cout << list.students[i].prog; readIntV("������� ����� ������ ��� ��������:") }
	case 3: {sessia nsessia; if list.students[i].prog.getsize < blah blah ������ ���� ��������� �������� ��������� ������ ������ � ReadIntV ������.nssessia.makesessia(); list.students[i].prog.addsessia(nsessia);  }
	case 4: {sessiasubmenu(); }
	case 5: {cout << prog??? }
	case 0: {/*????????*/}
	default: {cout << "\n����������� ��������!\n"; system("pause"); break; }
	}
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
	cout << "5.�������� ����� � ������ � ����������\n";
	cout << "6.�������� ������� � ������ � ����������\n";
	cout << "7.�������� ������� ������� ������\n"
	cout << "0.����� � ��������� � ������ � c������ ������\n";
	cout << "> ";
	switch (pmchoice) {
	case 1: {sessia::predza newz; if this? ? ? getzachcount < 5 ReadStrW("������� �������� ������:") � �.�. }
	case 2: {sessia::predex newx; if this ? ? ? getexamcount < 5 ReadStrW("������� �������� ��������:") � �.�. }
	case 3: {unsigned short index }
	case 4: {unsigned short index }
	case 5: {cout << prog ? ? ? }
	case 6: {cout << this???? }
	case 7: {cout << this ? ? ? ? }
	case 0: {/*????????*/}
	default: {cout << "\n����������� ��������!\n"; system("pause"); break; }
	}
}


