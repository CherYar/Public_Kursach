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
		num = "00B0000";
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
	~student() {};
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
			!isdigit(static_cast<unsigned char>(group[0])) &&
			!isdigit(static_cast<unsigned char>(group[1])) &&
			!isdigit(static_cast<unsigned char>(group[2])) &&
			!isdigit(static_cast<unsigned char>(group[3])) &&
			group[4] == '-' &&
			isdigit(static_cast<unsigned char>(group[5])) &&
			isdigit(static_cast<unsigned char>(group[6])) &&
			group[7] == '-' &&
			isdigit(static_cast<unsigned char>(group[8])) &&
			isdigit(static_cast<unsigned char>(group[9]));
	}
	bool validinsti(const string& ist) { return ist.length() >= 2 && ist.length() <= 5; }
	bool validprogname(const string& prg) { return prg.length() >= 5 && prg.length() <= 25; }

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
		if (num != "00F0000" and validnum(num)) { cout << *this; }
	}

	void prfull()
	{
		if (num != "00F0000" and validnum(num)) {
			const int w = 90;
			cout << "|----------------------------------------- ID:" << num << " ----------------------------------------|" << endl;
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
	}
	void makestudent() {
		cout << "Введите данные о студенте:" << endl;
		num = readStrW("Идентификационный номер (Пример: 00А0000):  ", [this](const string& n) { return validnum(n); });
		cout << "ФИО: ";
		cin >> fio;
		cout << "Дата рождения: ";
		cin >> born;
		age = readIntV("Возраст (полных лет): ", [this](const int& a) { return validage(a); });
		gendr = readIntV("Пол (0-муж., 1-жен.): ", [this](const int& g) { return validgendr(g); });
		uch.postup = readIntV("Год поступления: ", [this](const int& p) { return validpostup(p); });
		CinDel;
		uch.institut = readStrW("Институт: ", [this](const string& i) { return validinsti(i); });
		uch.kaf = readIntV("Кафедра № ", [this](const int& k) { return validkaf(k); });
		CinDel;
		uch.group = readStrW("Группа (Пример: АБВГ-01-23): ", [this](const string& g) { return validgroup(g); });
		fizgroup = readIntV("Физ. группа (0 - осн., 1 - подг., 2 - спец.): ", [this](const int& k) { return validkaf(k); });
		uch.progid = readIntLV("Номер учебной программы (6ти значное число): ", [this](const long& pi) { return validprogid(pi); });
		CinDel;
		uch.progname = readStrW("Название учебной программы: ", [this](const string& p) { return validprogname(p); });
		uch.curkurs = readIntV("Текущий курс ", [this](const int& k) { return sessia::validkurs(k); });
		uch.cursemestr = readIntV("Текущий семестр ", [this](const int& s) { return sessia::validsemestr(s); });
		cout << "Введите данные о сессиях студента:" << endl;
		prog.makesessions();
	}
	void changeinstitut() { this->uch.institut = readStrW("Введите название института: ", [this](const string& i) { return validinsti(i); }); }//для меню, для него потребуются и другие методы

	void writeToFile(const string& filename) const {
		ofstream file(filename);
		if (!file.is_open()) {
			cerr << "Не удалось открыть файл для записи" << endl;
			return;
		}
		file << num << endl;
		file << fname << endl;
		file << srname << endl;
		file << patrn << endl;
		file << born.getyear() << ' ' << born.getmonth() << ' ' << born.getday() << endl;
		file << age << endl;
		file << uch.postup << endl;
		file << uch.institut << endl;
		file << uch.kaf << endl;
		file << uch.group << endl;
		file << gendr << endl;
		file << uch.progname << endl;
		file << uch.progid << endl;
		file << uch.curkurs << endl;
		file << uch.cursemestr << endl;
		file << fizgroup << endl;

		prog.writeToFile(file);

		file.close();
	}

	void readFromFile(const string& filename) {
		ifstream file(filename);
		if (!file.is_open()) {
			cerr << "Не удалось открыть файл для чтения" << endl;
			return;
		}
		getline(file, num);
		getline(file, fname);
		getline(file, srname);
		getline(file, patrn);

		int year, month, day;
		file >> year >> month >> day;
		born.setyear(year);
		born.setsmon(month);
		born.setday(day);

		file >> age;
		file >> uch.postup;

		file.ignore((numeric_limits<streamsize>::max)(), '\n');
		getline(file, uch.institut);

		file >> uch.kaf;

		file.ignore((numeric_limits<streamsize>::max)(), '\n');
		getline(file, uch.group);

		file >> gendr;

		file.ignore((numeric_limits<streamsize>::max)(), '\n');
		getline(file, uch.progname);

		file >> uch.progid >> uch.curkurs >> uch.cursemestr >> fizgroup;

		prog.readFromFile(file);

		file.close();
	}
	void writeToFileBinary(const string& filename) const {
		ofstream file(filename, ios::binary);
		if (!file.is_open()) {
			cerr << "Не удалось открыть файл для записи" << endl;
			return;
		}

		size_t len = num.size();
		file.write(reinterpret_cast<const char*>(&len), sizeof(len));
		file.write(num.c_str(), len);

		len = fname.size();
		file.write(reinterpret_cast<const char*>(&len), sizeof(len));
		file.write(fname.c_str(), len);

		len = srname.size();
		file.write(reinterpret_cast<const char*>(&len), sizeof(len));
		file.write(srname.c_str(), len);

		len = patrn.size();
		file.write(reinterpret_cast<const char*>(&len), sizeof(len));
		file.write(patrn.c_str(), len);

		int year = born.getyear();
		unsigned short month = born.getmonth();
		unsigned short day = born.getday();
		file.write(reinterpret_cast<const char*>(&year), sizeof(year));
		file.write(reinterpret_cast<const char*>(&month), sizeof(month));
		file.write(reinterpret_cast<const char*>(&day), sizeof(day));

		file.write(reinterpret_cast<const char*>(&age), sizeof(age));
		file.write(reinterpret_cast<const char*>(&uch.postup), sizeof(uch.postup));

		len = uch.institut.size();
		file.write(reinterpret_cast<const char*>(&len), sizeof(len));
		file.write(uch.institut.c_str(), len);

		file.write(reinterpret_cast<const char*>(&uch.kaf), sizeof(uch.kaf));

		len = uch.group.size();
		file.write(reinterpret_cast<const char*>(&len), sizeof(len));
		file.write(uch.group.c_str(), len);

		file.write(reinterpret_cast<const char*>(&gendr), sizeof(gendr));

		len = uch.progname.size();
		file.write(reinterpret_cast<const char*>(&len), sizeof(len));
		file.write(uch.progname.c_str(), len);

		file.write(reinterpret_cast<const char*>(&uch.progid), sizeof(uch.progid));
		file.write(reinterpret_cast<const char*>(&uch.curkurs), sizeof(uch.curkurs));
		file.write(reinterpret_cast<const char*>(&uch.cursemestr), sizeof(uch.cursemestr));
		file.write(reinterpret_cast<const char*>(&fizgroup), sizeof(fizgroup));

		prog.writeToFileBinary(file);

		file.close();
	}

	void readFromFileBinary(const string& filename) {
		ifstream file(filename, ios::binary);
		if (!file.is_open()) {
			cerr << "Не удалось открыть файл для чтения" << endl;
			return;
		}

		size_t len;
		file.read(reinterpret_cast<char*>(&len), sizeof(len));
		num.resize(len);
		file.read(&num[0], len);

		file.read(reinterpret_cast<char*>(&len), sizeof(len));
		fname.resize(len);
		file.read(&fname[0], len);

		file.read(reinterpret_cast<char*>(&len), sizeof(len));
		srname.resize(len);
		file.read(&srname[0], len);

		file.read(reinterpret_cast<char*>(&len), sizeof(len));
		patrn.resize(len);
		file.read(&patrn[0], len);

		int year;
		unsigned short month;
		unsigned short day;
		file.read(reinterpret_cast<char*>(&year), sizeof(year));
		file.read(reinterpret_cast<char*>(&month), sizeof(month));
		file.read(reinterpret_cast<char*>(&day), sizeof(day));
		born.setyear(year);
		born.setsmon(month);
		born.setday(day);

		file.read(reinterpret_cast<char*>(&age), sizeof(age));
		file.read(reinterpret_cast<char*>(&uch.postup), sizeof(uch.postup));

		file.read(reinterpret_cast<char*>(&len), sizeof(len));
		uch.institut.resize(len);
		file.read(&uch.institut[0], len);

		file.read(reinterpret_cast<char*>(&uch.kaf), sizeof(uch.kaf));

		file.read(reinterpret_cast<char*>(&len), sizeof(len));
		uch.group.resize(len);
		file.read(&uch.group[0], len);

		file.read(reinterpret_cast<char*>(&gendr), sizeof(gendr));

		file.read(reinterpret_cast<char*>(&len), sizeof(len));
		uch.progname.resize(len);
		file.read(&uch.progname[0], len);

		file.read(reinterpret_cast<char*>(&uch.progid), sizeof(uch.progid));
		file.read(reinterpret_cast<char*>(&uch.curkurs), sizeof(uch.curkurs));
		file.read(reinterpret_cast<char*>(&uch.cursemestr), sizeof(uch.cursemestr));
		file.read(reinterpret_cast<char*>(&fizgroup), sizeof(fizgroup));

		prog.readFromFileBinary(file);

		file.close();
	}
	void writeToFileBinary(ostream& out) const {
		size_t len = num.size();
		out.write(reinterpret_cast<const char*>(&len), sizeof(len));
		out.write(num.c_str(), len);

		len = fname.size();
		out.write(reinterpret_cast<const char*>(&len), sizeof(len));
		out.write(fname.c_str(), len);

		len = srname.size();
		out.write(reinterpret_cast<const char*>(&len), sizeof(len));
		out.write(srname.c_str(), len);

		len = patrn.size();
		out.write(reinterpret_cast<const char*>(&len), sizeof(len));
		out.write(patrn.c_str(), len);

		int year = born.getyear();
		unsigned short month = born.getmonth();
		unsigned short day = born.getday();
		out.write(reinterpret_cast<const char*>(&year), sizeof(year));
		out.write(reinterpret_cast<const char*>(&month), sizeof(month));
		out.write(reinterpret_cast<const char*>(&day), sizeof(day));

		out.write(reinterpret_cast<const char*>(&age), sizeof(age));
		out.write(reinterpret_cast<const char*>(&uch.postup), sizeof(uch.postup));

		len = uch.institut.size();
		out.write(reinterpret_cast<const char*>(&len), sizeof(len));
		out.write(uch.institut.c_str(), len);

		out.write(reinterpret_cast<const char*>(&uch.kaf), sizeof(uch.kaf));

		len = uch.group.size();
		out.write(reinterpret_cast<const char*>(&len), sizeof(len));
		out.write(uch.group.c_str(), len);

		out.write(reinterpret_cast<const char*>(&gendr), sizeof(gendr));

		len = uch.progname.size();
		out.write(reinterpret_cast<const char*>(&len), sizeof(len));
		out.write(uch.progname.c_str(), len);

		out.write(reinterpret_cast<const char*>(&uch.progid), sizeof(uch.progid));
		out.write(reinterpret_cast<const char*>(&uch.curkurs), sizeof(uch.curkurs));
		out.write(reinterpret_cast<const char*>(&uch.cursemestr), sizeof(uch.cursemestr));
		out.write(reinterpret_cast<const char*>(&fizgroup), sizeof(fizgroup));

		prog.writeToFileBinary(out);
	}
	void readFromFileBinary(istream& in) {
		size_t len;
		in.read(reinterpret_cast<char*>(&len), sizeof(len));
		num.resize(len);
		in.read(&num[0], len);

		in.read(reinterpret_cast<char*>(&len), sizeof(len));
		fname.resize(len);
		in.read(&fname[0], len);

		in.read(reinterpret_cast<char*>(&len), sizeof(len));
		srname.resize(len);
		in.read(&srname[0], len);

		in.read(reinterpret_cast<char*>(&len), sizeof(len));
		patrn.resize(len);
		in.read(&patrn[0], len);

		int year;
		unsigned short month;
		unsigned short day;
		in.read(reinterpret_cast<char*>(&year), sizeof(year));
		in.read(reinterpret_cast<char*>(&month), sizeof(month));
		in.read(reinterpret_cast<char*>(&day), sizeof(day));
		born.setyear(year);
		born.setsmon(month);
		born.setday(day);

		in.read(reinterpret_cast<char*>(&age), sizeof(age));
		in.read(reinterpret_cast<char*>(&uch.postup), sizeof(uch.postup));

		in.read(reinterpret_cast<char*>(&len), sizeof(len));
		uch.institut.resize(len);
		in.read(&uch.institut[0], len);

		in.read(reinterpret_cast<char*>(&uch.kaf), sizeof(uch.kaf));

		in.read(reinterpret_cast<char*>(&len), sizeof(len));
		uch.group.resize(len);
		in.read(&uch.group[0], len);

		in.read(reinterpret_cast<char*>(&gendr), sizeof(gendr));

		in.read(reinterpret_cast<char*>(&len), sizeof(len));
		uch.progname.resize(len);
		in.read(&uch.progname[0], len);

		in.read(reinterpret_cast<char*>(&uch.progid), sizeof(uch.progid));
		in.read(reinterpret_cast<char*>(&uch.curkurs), sizeof(uch.curkurs));
		in.read(reinterpret_cast<char*>(&uch.cursemestr), sizeof(uch.cursemestr));
		in.read(reinterpret_cast<char*>(&fizgroup), sizeof(fizgroup));

		prog.readFromFileBinary(in);
	}

	const date& getBorn() const {
		return born;
	}
	const SessionList& getProg() const {
		return prog;
	}
};
