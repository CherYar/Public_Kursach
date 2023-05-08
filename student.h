//student.h
#pragma once
#include "name.h"
#include "sessia_list.h"
using namespace std;

class student : public SessionList, public name, public date {
	struct insti {
		string institut;
		unsigned short kaf;
		string group;
		unsigned long progid;
		string progname;
		unsigned short postup;
		unsigned short curkurs;
		unsigned short cursemestr;

	};
public:
	string num;
protected:
	insti uch;
	name fio;
	date born;
	SessionList prog;
	unsigned short gendr; // 0 - ���., 1 - ���., 2 - �������., 3 - �� ������� (��������: �����). 
	unsigned short age;
	unsigned short fizgroup;// 0 - ���, 1 - ��������, 2 - ����, 3 - ���������.

public:
	student()
	{
		num = "00F0000";
		fio.addfio("��������", "������", "����������");//�� ������� �������� ������ 90�, unnessesary due to standard constructor
		born.adddatef(1, 1, 2000);//unnessesary due to standard constructor
		age = 23;
		uch.postup = 2020;
		uch.institut = "���";
		uch.kaf = 2;
		uch.group = "����-01-20";
		gendr = 0;
		uch.progname = "��������� ��� � ��������� ���";
		uch.progid = 133777;
		uch.curkurs = 6;
		uch.cursemestr = 15;
		fizgroup = 0;

	};
	~student() {cout << "\n class student destructor debug" << endl; };
	bool validprogid() {
		return (uch.progid >= 100000 && uch.progid <= 999999);
	}
	bool validpostup() {
		return uch.postup >= 1900 && uch.postup <= 2100;
	}
	bool validkaf() {
		return uch.kaf >= 1 && uch.kaf <= 100;
	}
	bool validgendr() {
		return gendr >= 0 && gendr <= 3;
	}
	bool validage() {
		return age >= 16 && age <= 100;
	}
	bool validfizgroup() {
		return fizgroup >= 0 && fizgroup <= 3;
	}
	bool validgroup() {
		return uch.group.length() == 10 &&
			isalpha(static_cast<unsigned char>(uch.group[0])) &&
			isalpha(static_cast<unsigned char>(uch.group[1])) &&
			isalpha(static_cast<unsigned char>(uch.group[2])) &&
			isalpha(static_cast<unsigned char>(uch.group[3])) &&
			uch.group[4] == '-' &&
			isdigit(static_cast<unsigned char>(uch.group[5])) &&
			isdigit(static_cast<unsigned char>(uch.group[6])) &&
			uch.group[7] == '-' &&
			isdigit(static_cast<unsigned char>(uch.group[8])) &&
			isdigit(static_cast<unsigned char>(uch.group[9]));
	}

	bool validnum(const string& proof)
	{
		unsigned short len;
		len = proof.length();
		if (len == 7 && !isdigit(static_cast<unsigned char>(proof[2]))) {
			for (int i = 0; i < len; i++) {
				if (i != 2 && !isdigit(static_cast<unsigned char>(proof[i]))) return false;
			}
			return true;
		}
		else return false;
	}
	friend ostream& operator<<(ostream& out, const student& s) {
		out << left << s.num << " " << s.fio << endl;
		return out;
	}
	void prbasic()
	{
		if (num != "00F0000" and validnum(num)) { cout << this; }
		
		else { cout << "\n������������ ����������������� �����!" << endl; }
	}

	void prfull()
	{
		if (num != "00F0000" and validnum(num)) {
			cout << "|----------- �������:" << num << " -----------|" << endl;
			cout << '|' << fio << cout.width(fio.fiolength() - 10) << right << '|' << endl << left;
			cout << '|' << "����. " << born << ", �������: " << age << " ���/����"; cout.width(born.datelength() + to_string(age).length()-4); cout << right << '|' << endl << left;
			switch (gendr)
			{
			case 0: {cout << '|'; cout.width(39); cout << "���: ���." << right << '|' << endl << left; break; }
			case 1: {cout << '|'; cout.width(39); cout << "���: ���." << right << '|' << endl << left; break; }
			case 2: {cout << '|'; cout.width(39); cout << "���: �������." << right << '|' << endl << left; break; }
			case 3: {cout << '|'; cout.width(39); cout << "���: �� �������" << right << '|' << endl << left; break; }
			default: {cout << "|������ � ���� ������, ������������ ���!|" << endl; break; }
			}
			cout << '|'; cout << left << "��������(�) � " << uch.postup << " �."; cout.width(19); cout << right << '|' << endl << left;
			cout << '|' << "��������:" << uch.institut; cout.width(31 - uch.institut.length()); cout << right << '|' << endl << left;
			cout << '|' << "������� �" << uch.kaf; cout.width(30); cout <<  right << '|' << endl << left;
			cout << '|' << "������: " << uch.group; cout.width(22); cout << right << '|' << endl << left;
				switch (fizgroup)
				{
				case 0: {cout << '|'; cout.width(39); cout << "���. ������: �������� " << right << '|' << endl << left; break; }
				case 1: {cout << '|'; cout.width(39); cout << "���. ������: ���������������� " << right << '|' << endl << left; break; }
				case 2: {cout << '|'; cout.width(39); cout << "���. ������: ������ " << right << '|' << endl << left; break; }
				case 3: {cout << '|'; cout.width(39); cout << "���. ������: �� �������. " << right << '|' << endl << left; break; }
				default: {cout << "|������ � ���� ������, �������� ���.���!|" << endl; break; }
				}
			cout << "|---���������, ������ � ������������: --|" << endl;
			cout << "| " << uch.progname; cout.width(39- uch.progname.length()); cout << right<< '|' << endl << left;
			cout << "| ����� ���������: " << uch.progid; cout.width(16);cout << right << '|' << endl << left; 
			cout << "| ����: " << prog.kurs << " | �������: " << prog.semestr; if (prog.semestr >= 10) cout.width(18); else cout.width(19); cout << right << '|' << endl << left;
			cout.fill('-'); cout << '|'; cout.width(40); cout << right << '|' << endl << left; cout.fill(' ');
			cout << "| �������:                  �����/������|" << endl; 
		}
		else { cout << "\n ������������ ����������������� �����!"<<endl; }
	}
	void makestudent() {
		cout << "������� ����� ��������: ";
		cin >> num;
		while (!validnum(num)) {
			cout << "������������ ����� ��������. ����������, ������� ������: ";
			cin >> num;
		}
		cout << "������� ����� ���������: ";
		cin >> uch.progid;
		while (!validprogid()) {
			cout << "������������ ����� ���������. ����������, ������� ������: ";
			cin >> uch.progid;
		}
		string tempn;
		string tempsn;
		string temppt;
		cout << "������� ������� ��������: ";
		cin.ignore();
		getline(cin, tempsn); fio.setsrname(tempsn);
		while (!fio.validsrname())
		{
			cout << "������������ �������. ��������� ����: ";
			getline(cin, tempsn); fio.setsrname(tempsn);
		}

		cout << "������� ��� ��������: ";
		getline(cin, tempn); fio.setfname(tempn);
		while (!fio.validfname())
		{
			cout << "������������ ���. ��������� ����: ";
			getline(cin, tempn); fio.setfname(tempn);
		}

		cout << "������� �������� ��������: ";
		getline(cin, temppt); fio.setsrname(temppt);
		while (!fio.validpatr())
		{
			cout << "������������ ��������. ��������� ����: ";
			getline(cin, temppt); fio.setpatr(temppt);
		}

		


		// ���������
	}
};
