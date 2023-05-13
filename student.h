//student.h
#pragma once
#include "name.h"
#include "sessia_list.h"
using namespace std;

class student : public SessionList, public name, public date {
public:
	string num;
protected:
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
		uch.progname = "������������ ������������";
		uch.progid = 133777;
		uch.curkurs = 3;
		uch.cursemestr = 7;
		fizgroup = 0;

	};
	~student() {cout << "\n class student destructor debug" << endl; };
	bool validprogid(const long& progid) {
		return (progid >= 100000 && progid <= 999999);
	}
	bool validpostup(const int& postup) {
		return postup >= 1900 && postup <= 2100;
	}
	bool validkaf(const int &kaf) {
		return kaf >= 1 && kaf <= 100;
	}
	bool validgendr(const int &gender) {
		return gender >= 0 && gender <= 3;
	}
	bool validage(const int &ages) {
		return ages >= 16 && ages <= 100;
	}
	bool validfizgroup(const int& fzgroup) {
		return fzgroup >= 0 && fzgroup <= 3;
	}
	bool validgroup(const string &group) {
		return group.length() == 10 &&
			isalpha(static_cast<unsigned char>(group[0])) &&
			isalpha(static_cast<unsigned char>(group[1])) &&
			isalpha(static_cast<unsigned char>(group[2])) &&
			isalpha(static_cast<unsigned char>(group[3])) &&
			group[4] == '-' &&
			isdigit(static_cast<unsigned char>(group[5])) &&
			isdigit(static_cast<unsigned char>(group[6])) &&
			group[7] == '-' &&
			isdigit(static_cast<unsigned char>(group[8])) &&
			isdigit(static_cast<unsigned char>(group[9]));
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
	void addfio(const string& sn, const string& fn, const string& pr) { this->fio.addfio(sn, fn, pr); }
	void addprog(const SessionList& sl) { prog = sl; }
	void prbasic()
	{
		if (num != "00F0000" and validnum(num)) { cout << this; }
		
		else { cout << "������������ ����������������� �����!" << endl; }
	}

	void prfull()
	{
		if (num != "00F0000" and validnum(num)) {
			const int w = 90;
			cout << "|-------------------------------------- �������:" << num << " --------------------------------------|" << endl;
			cout << left << "| " << fio << " |" << " ����. " << born << ", �������: " << age << " ���/����" << " |" << setw(w - fio.fiolength() - 41 - to_string(age).length());
			switch (gendr)
			{
			case 0: {cout <<  " ���: ���." << right << '|' << endl << left; break; }
			case 1: {cout << " ���: ���." << right << '|' << endl << left; break; }
			case 2: {cout << " ���: �������." << right << '|' << endl << left; break; }
			case 3: {cout << " ���: �� �������" << right << '|' << endl << left; break; }
			default: {cout <<" ���: �����." << right << '|' << endl << left; break; }
			}
			cout << "| ��������(�) � " << uch.postup << " �.| ��������: " << uch.institut << " | ������� �" << uch.kaf << " | ������: " << uch.group; switch (fizgroup)
			{
			case 0: { cout << " | ���. ����.: ���. " << setw(w - uch.institut.length() - to_string(uch.kaf).length() - to_string(uch.postup).length() - uch.group.length() - 69) << right << '|' << endl; break; }
			case 1: { cout << " | ���. ����.: ����. " << setw(w - uch.institut.length() - to_string(uch.kaf).length() - to_string(uch.postup).length()- uch.group.length() - 70) << right << '|' << endl; break; }
			case 2: { cout << " | ���. ����.: ����. " << setw(w - uch.institut.length() - to_string(uch.kaf).length() - to_string(uch.postup).length()- uch.group.length() - 70) << right << '|'<< endl; break; }
			case 3: { cout << " | ���. ����.: ���. " << setw(w - uch.institut.length() - to_string(uch.kaf).length() - to_string(uch.postup).length()- uch.group.length() - 69) << right << '|' << endl; break; }
			default: {cout << " | ���. ����.: �����. " << setw(w - uch.institut.length() - to_string(uch.kaf).length() - to_string(uch.postup).length()- uch.group.length() - 71) << right << '|' << endl; break; }
			}
			cout<< "|----------------------------- ���������, ������ � ������������: -----------------------------|" << endl;
			cout << "| ����� ���������:" << uch.progid << " | �������� ���������: " << uch.progname << setw(w - to_string(uch.progid).length() - uch.progname.length() - 36) << " |" << endl;
			cout << "| ������� ����: " << uch.curkurs << setw(46) <<"| ������� �������: " << uch.cursemestr << setw(w - to_string(uch.curkurs).length() - to_string(uch.cursemestr).length()-57) << " |" << endl;
			cout << prog;
		}
		else { cout << "\n������������ ����������������� �����!"<<endl; }
	}
	void makestudent() {
		cout << "������� ������ � ��������:" << endl;
		num = readStrW("����������������� ����� (������: 00�0000):  ", [this](const string& n) { return validnum(n); });
		cout << "���: ";
		cin >> fio;
		cout << "���� ��������: ";
		cin >> born;
		age = readIntV("�������: ", [this](const int& a) { return validage(a); });
		uch.group = readStrW("������ (������: ����-01-23): ", [this](const string& g) { return validgroup(g); });
		cout << "��� �����������: ";
		//postup = readIntV("������� ��� �����������: ", validpostup);
		cout << "������� ������ � ������� ��������:" << endl;
		prog.makesessions();
	}
	void changeinstitut() { this->uch.institut = readStr("������� �������� ���������: "); }//��� ����, ��� ���� ����������� � ������ ������

};
