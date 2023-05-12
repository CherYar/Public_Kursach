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
	unsigned short gendr; // 0 - муж., 1 - жен., 2 - небинар., 3 - не человек (например: ангел). 
	unsigned short age;
	unsigned short fizgroup;// 0 - осн, 1 - подготов, 2 - особ, 3 - нечеловеч.

public:
	student()
	{
		num = "00F0000";
		fio.addfio("Дефолтов", "Дефолт", "Дефолтович");//По заветам рыночных реформ 90х, unnessesary due to standard constructor
		born.adddatef(0, 0, 0);//unnessesary due to standard constructor
		age = 4000;
		uch.postup = 2020;
		uch.institut = "ИКБ";
		uch.kaf = 2;
		uch.group = "АБВГ-01-20";
		gendr = 3;
		uch.progname = "Черепной тонус ахахахахахаха";
		uch.progid = 133777;
		uch.curkurs = 666;
		uch.cursemestr = 1024;
		fizgroup = 1;

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
	void addfio(const string& sn, const string& fn, const string& pr) { this->fio.addfio(sn, fn, pr); }
	void addprog(const SessionList& sl) { prog = sl; }
	void prbasic()
	{
		if (num != "00F0000" and validnum(num)) { cout << this; }
		
		else { cout << "Некорректный идентификационный номер!" << endl; }
	}

	void prfull()
	{
		if (num != "00F0000" and validnum(num)) {
			const int w = 90;
			cout << "|-------------------------------------- Студент:" << num << " --------------------------------------|" << endl;
			cout << left << "| " << fio << " |" << " Рожд. " << born << ", Возраст: " << age << " лет/года" << " |" << setw(w - fio.fiolength() - 41 - to_string(age).length());
			switch (gendr)
			{
			case 0: {cout <<  " Пол: муж." << right << '|' << endl << left; break; }
			case 1: {cout << " Пол: жен." << right << '|' << endl << left; break; }
			case 2: {cout << " Пол: небинар." << right << '|' << endl << left; break; }
			case 3: {cout << " Пол: не человек" << right << '|' << endl << left; break; }
			default: {cout <<" Пол: неизв." << right << '|' << endl << left; break; }
			}
			cout << "| Поступил(а) в " << uch.postup << " г.| Институт: " << uch.institut << " | Кафедра №" << uch.kaf << " | Группа: " << uch.group; switch (fizgroup)
			{
			case 0: { cout << " | Физ. груп.: осн. " << setw(w - uch.institut.length() - to_string(uch.kaf).length() - to_string(uch.postup).length() - uch.group.length() - 69) << right << '|' << endl; break; }
			case 1: { cout << " | Физ. груп.: подг. " << setw(w - uch.institut.length() - to_string(uch.kaf).length() - to_string(uch.postup).length()- uch.group.length() - 70) << right << '|' << endl; break; }
			case 2: { cout << " | Физ. груп.: спец. " << setw(w - uch.institut.length() - to_string(uch.kaf).length() - to_string(uch.postup).length()- uch.group.length() - 70) << right << '|'<< endl; break; }
			case 3: { cout << " | Физ. груп.: неч. " << setw(w - uch.institut.length() - to_string(uch.kaf).length() - to_string(uch.postup).length()- uch.group.length() - 69) << right << '|' << endl; break; }
			default: {cout << " | Физ. груп.: неизв. " << setw(w - uch.institut.length() - to_string(uch.kaf).length() - to_string(uch.postup).length()- uch.group.length() - 71) << right << '|' << endl; break; }
			}
			cout<< "|----------------------------- Программа, оценки и успеваемость: -----------------------------|" << endl;
			cout << "| Номер программы:" << uch.progid << " | Название программы: " << uch.progname << setw(w - to_string(uch.progid).length() - uch.progname.length() - 36) << " |" << endl;
			cout << "| Текущий курс: " << uch.curkurs << setw(46) <<"| Текущий семестр: " << uch.cursemestr << setw(w - to_string(uch.curkurs).length() - to_string(uch.cursemestr).length()-57) << " |" << endl;
			cout << prog;
		}
		else { cout << "\nНекорректный идентификационный номер!"<<endl; }
	}
	void makestudent() {
		cout << "Введите номер студента: ";
		cin >> num;
		while (!validnum(num)) {
			cout << "Некорректный номер студента. Пожалуйста, введите заново: ";
			cin >> num;
		}
		cout << "Введите номер программы: ";
		cin >> uch.progid;
		while (!validprogid()) {
			cout << "Некорректный номер программы. Пожалуйста, введите заново: ";
			cin >> uch.progid;
		}
		string tempn;
		string tempsn;
		string temppt;
		cout << "Введите фамилию студента: ";
		cin.ignore();
		getline(cin, tempsn); fio.setsrname(tempsn);
		while (!fio.validsrname())
		{
			cout << "Некорректная фамилия. Повторите ввод: ";
			getline(cin, tempsn); fio.setsrname(tempsn);
		}

		cout << "Введите имя студента: ";
		getline(cin, tempn); fio.setfname(tempn);
		while (!fio.validfname())
		{
			cout << "Некорректное имя. Повторите ввод: ";
			getline(cin, tempn); fio.setfname(tempn);
		}

		cout << "Введите отчество студента: ";
		getline(cin, temppt); fio.setsrname(temppt);
		while (!fio.validpatr())
		{
			cout << "Некорректное отчество. Повторите ввод: ";
			getline(cin, temppt); fio.setpatr(temppt);
		}

		


		// Недоделка
	}

};
