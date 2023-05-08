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
	unsigned short gendr; // 0 - муж., 1 - жен., 2 - небинар., 3 - не человек (например: ангел). 
	unsigned short age;
	unsigned short fizgroup;// 0 - осн, 1 - подготов, 2 - особ, 3 - нечеловеч.

public:
	student()
	{
		num = "00F0000";
		fio.addfio("Дефолтов", "Дефолт", "Дефолтович");//По заветам рыночных реформ 90х, unnessesary due to standard constructor
		born.adddatef(1, 1, 2000);//unnessesary due to standard constructor
		age = 23;
		uch.postup = 2020;
		uch.institut = "ИКБ";
		uch.kaf = 2;
		uch.group = "АБВГ-01-20";
		gendr = 0;
		uch.progname = "Применине АКМ в городском бою";
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
		
		else { cout << "\nНекорректный идентификационный номер!" << endl; }
	}

	void prfull()
	{
		if (num != "00F0000" and validnum(num)) {
			cout << "|----------- Студент:" << num << " -----------|" << endl;
			cout << '|' << fio << cout.width(fio.fiolength() - 10) << right << '|' << endl << left;
			cout << '|' << "Рожд. " << born << ", Возраст: " << age << " лет/года"; cout.width(born.datelength() + to_string(age).length()-4); cout << right << '|' << endl << left;
			switch (gendr)
			{
			case 0: {cout << '|'; cout.width(39); cout << "Пол: муж." << right << '|' << endl << left; break; }
			case 1: {cout << '|'; cout.width(39); cout << "Пол: жен." << right << '|' << endl << left; break; }
			case 2: {cout << '|'; cout.width(39); cout << "Пол: небинар." << right << '|' << endl << left; break; }
			case 3: {cout << '|'; cout.width(39); cout << "Пол: не человек" << right << '|' << endl << left; break; }
			default: {cout << "|Ошибка в базе данных, некорректный пол!|" << endl; break; }
			}
			cout << '|'; cout << left << "Поступил(а) в " << uch.postup << " г."; cout.width(19); cout << right << '|' << endl << left;
			cout << '|' << "Институт:" << uch.institut; cout.width(31 - uch.institut.length()); cout << right << '|' << endl << left;
			cout << '|' << "Кафедра №" << uch.kaf; cout.width(30); cout <<  right << '|' << endl << left;
			cout << '|' << "Группа: " << uch.group; cout.width(22); cout << right << '|' << endl << left;
				switch (fizgroup)
				{
				case 0: {cout << '|'; cout.width(39); cout << "Физ. группа: основная " << right << '|' << endl << left; break; }
				case 1: {cout << '|'; cout.width(39); cout << "Физ. группа: подготовительная " << right << '|' << endl << left; break; }
				case 2: {cout << '|'; cout.width(39); cout << "Физ. группа: особая " << right << '|' << endl << left; break; }
				case 3: {cout << '|'; cout.width(39); cout << "Физ. группа: не человеч. " << right << '|' << endl << left; break; }
				default: {cout << "|Ошибка в базе данных, неверная физ.грп!|" << endl; break; }
				}
			cout << "|---Программа, оценки и успеваемость: --|" << endl;
			cout << "| " << uch.progname; cout.width(39- uch.progname.length()); cout << right<< '|' << endl << left;
			cout << "| Номер программы: " << uch.progid; cout.width(16);cout << right << '|' << endl << left; 
			cout << "| Курс: " << prog.kurs << " | Семестр: " << prog.semestr; if (prog.semestr >= 10) cout.width(18); else cout.width(19); cout << right << '|' << endl << left;
			cout.fill('-'); cout << '|'; cout.width(40); cout << right << '|' << endl << left; cout.fill(' ');
			cout << "| Предмет:                  Зачёт/оценка|" << endl; 
		}
		else { cout << "\n Некорректный идентификационный номер!"<<endl; }
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
