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
		born.adddatef(1, 1, 2000);//unnessesary due to standard constructor
		age = 23;
		uch.postup = 2020;
		uch.institut = "ИКБ";
		uch.kaf = 2;
		uch.group = "АБВГ-01-20";
		gendr = 0;
		uch.progname = "Безопасность радиоканалов";
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
		cout << "Введите данные о студенте:" << endl;
		num = readStrW("Идентификационный номер (Пример: 00А0000):  ", [this](const string& n) { return validnum(n); });
		cout << "ФИО: ";
		cin >> fio;
		cout << "Дата рождения: ";
		cin >> born;
		age = readIntV("Возраст: ", [this](const int& a) { return validage(a); });
		uch.group = readStrW("Группа (Пример: АБВГ-01-23): ", [this](const string& g) { return validgroup(g); });
		cout << "Год поступления: ";
		//postup = readIntV("Введите год поступления: ", validpostup);
		cout << "Введите данные о сессиях студента:" << endl;
		prog.makesessions();
	}
	void changeinstitut() { this->uch.institut = readStr("Введите название института: "); }//для меню, для него потребуются и другие методы

};
