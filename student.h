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
	bool validprogname(const string& prg) { return prg.length() >= 5 && prg.length() <= 40; }

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
	void setfio(const name& n) { fio = n; }
	void setfname(const string& fn) { fio.setfname(fn); }
	void setsrname(const string& sn) { fio.setsrname(sn); }
	void setpatr(const string& pn) { fio.setpatr(pn); }
	void setgendr(const unsigned short& g) { gendr = g; }
	void setborn(const date& b) { born = b; }
	void setage(const unsigned short& a) { age = a; }
	void setUch(const insti& i) { uch = i; }
	void setfizgroup(const unsigned short& f) { fizgroup = f; }
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
			case 1: { cout << " | Физ. груп.: пдг. " << setw(w - uch.institut.length() - to_string(uch.kaf).length() - to_string(uch.postup).length()- uch.group.length() - 69) << right << '|' << endl; break; }
			case 2: { cout << " | Физ. груп.: спц. " << setw(w - uch.institut.length() - to_string(uch.kaf).length() - to_string(uch.postup).length()- uch.group.length() - 69) << right << '|'<< endl; break; }
			case 3: { cout << " | Физ. груп.: неч. " << setw(w - uch.institut.length() - to_string(uch.kaf).length() - to_string(uch.postup).length()- uch.group.length() - 69) << right << '|' << endl; break; }
			default: {cout << " | Физ. груп.: ??? " << setw(w - uch.institut.length() - to_string(uch.kaf).length() - to_string(uch.postup).length()- uch.group.length() - 68) << right << '|' << endl; break; }
			}
			cout<< "|----------------------------- Программа, оценки и успеваемость: -----------------------------|" << endl;
			cout << "| Номер программы: " << uch.progid << " | Название программы: " << uch.progname << setw(w - to_string(uch.progid).length() - uch.progname.length() - 37) << " |" << endl;
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
		fizgroup = readIntV("Физ. группа (0 - осн., 1 - подг., 2 - спец.): ", [this](const int& f) { return validfizgroup(f); });
		uch.progid = readIntLV("Номер учебной программы (6ти значное число): ", [this](const long& pi) { return validprogid(pi); });
		CinDel;
		uch.progname = readStrW("Название учебной программы: ", [this](const string& p) { return validprogname(p); });
		uch.curkurs = readIntV("Текущий курс: ", [this](const int& k) { return sessia::validkurs(k); });
		uch.cursemestr = readIntV("Текущий семестр: ", [this](const int& s) { return sessia::validsemestr(s); });
		cout << "Введите данные о сессиях студента:" << endl;
		prog.makesessions();
	}
	void changeinstitut() { uch.institut = readStrW("Введите название института: ", [this](const string& i) { return validinsti(i); }); }//для меню, для него потребуются и другие методы
	void changekaf() { uch.kaf = readIntV("Введите номер кафедры: ", [this](const int& k) { return validkaf(k); }); }
	void changegroup() { uch.group = readStrW("Введите гуппу (Пример: АБВГ-01-23): ", [this](const string& g) { return validgroup(g); }); }
	void changeprogid() { uch.progid = readIntLV("Введите номер учебной программы (6ти значное число): ", [this](const long& pi) { return validprogid(pi); }); }
	void changeprogname(){ uch.progname = readStrW("Введите название учебной программы: ", [this](const string& p) { return validprogname(p); }); }
	void changepostup(){ uch.postup = readIntV("Введите год поступления: ", [this](const int& p) { return validpostup(p); }); }
	void changecurkurs(){ uch.curkurs = readIntV("Введите текущий курс ", [this](const int& k) { return sessia::validkurs(k); }); }
	void changekursem(){ uch.cursemestr = readIntV("Введите текущий семестр ", [this](const int& s) { return sessia::validsemestr(s); }); }
	void writeToFile(const string& filename) const {
		ofstream file(filename);
		if (!file.is_open()) {
			cerr << "Не удалось открыть файл для записи" << endl;
			return;
		}
		string fname = fio.getfname(); string srname = fio.getsrname(); string patrn = fio.getpatr();
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
		string fname, srname, patrn;
		getline(file, num);
		getline(file, fname);
		getline(file, srname);
		getline(file, patrn);
		fio.setfname(fname);
		fio.setsrname(srname);
		fio.setpatr(patrn);

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
		string fname = fio.getfname(); string srname = fio.getsrname(); string patrn = fio.getpatr();
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
		string fname, srname, patrn;
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
		fio.setfname(fname);
		fio.setsrname(srname);
		fio.setpatr(patrn);
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
		string fname = fio.getfname(); string srname = fio.getsrname(); string patrn = fio.getpatr();
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
		string fname, srname, patrn;
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

		fio.setfname(fname);
		fio.setsrname(srname);
		fio.setpatr(patrn);

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
	const insti& getUch() const { return uch; }
	const date& getBorn() const {
		return born;
	}
	const SessionList& getProg() const {
		return prog;
	}
	const unsigned short& getFizgroup() { return fizgroup; }
	const unsigned short& getAge() { return age; }
	const unsigned short& getGendr() { return gendr; }
	const name& getFio() const { return fio; }
	void progsubmenu() {
		int pmchoice = -1;
		for (; pmchoice != 0;) {
			CinDel
			unsigned short psiz = prog.getcount(); string psize = to_string(psiz + 1);
			system("cls");
			cout << "Текущее количество сессий:" + psize << '\n';
			cout << "--------------------------------------------------------------\n";
			cout << "Выберете действие:\n";
			cout << "--------------------------------------------------------------\n";
			cout << "1.Добавить новую сессию с вводом с клавиатуры\n";
			cout << "2.Удалить сессию\n";
			cout << "3.Заменить существующую сессию на введённую с клавиатуры\n";
			cout << "4.Изменить данные в конкретной сессии\n";
			cout << "--------------------------------------------------------------\n";
			cout << "5.Повторно вывести все сессии студента\n";
			cout << "--------------------------------------------------------------\n";
			cout << "0.Выйти и вернуться к работе с студентом\n";
			cout << "--------------------------------------------------------------\n";
			cout << "> ";
			pmchoice = readIntV(" ", [](int c) {return c >= 0 && c <= 5; });
			switch (pmchoice) {
			case 1: {
				if (psiz >= 10){ cout << "\nНевозможно добавить, достигнут предел количества сессий!" << endl; system("pause"); break; }
				else { CinDel sessia ns; ns.makesessia(); prog.addSession(ns); prog.sortSessions(); cout << "\nСессия добавлена" << endl; system("pause"); break;}
				
			}
			case 2: {CinDel
				cout << endl; string prompt = "Введите номер сессии(1 - " + psize + "): ";
				unsigned short index = readIntV(prompt, [&](int i) { return i >= 1 && i <= (psiz); });
				prog.removeSession(index - 1);
				cout << "\nСессия удалена." << endl; system("pause"); break;
			}
			case 3: {CinDel
				cout << endl; string prompt = "Введите номер сессии(1 - " + psize + "): ";
				unsigned short index = readIntV(prompt, [&](int i) { return i >= 1 && i <= (psiz); });
				sessia nses; cout << endl; nses.makesessia();
				prog.updateSession(index - 1, nses);
				cout << "\nСессия заменена." << endl; system("pause"); break;
			}
			case 4: {CinDel
				cout << endl; string prompt = "Введите номер сессии(1 - " + psize + "): ";
				unsigned short index = readIntV(prompt, [&](int i) { return i >= 1 && i <= (psiz); });
				sessiasubmenu(index - 1); break;
			}
			case 5: {
				cout << endl << prog; system("pause"); break;
			}
			case 0: {
				cout << "\nВозвращение в меню изменения данных студента." << endl;
				system("pause");
				return;
			}
			default: {
				cout << "\nНеизвестная операция!\n";
				system("pause"); CinDel
				break;
			}
			}
		}
	}

};
