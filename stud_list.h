//stud_list.h
#pragma once
#include "student.h"

class StudentsList : public student {
private:
	student* students;
	const unsigned short capacity = 15;
	unsigned short size;
public:
	StudentsList() {
		size = 0;
		students = new student[capacity];
	}
	~StudentsList() {
		delete[] students;
	}
	void addStudent(const student& stud) {
		if (size >= capacity) {
			cout << "Достигнут предел количества студентов!" << endl;
			return;
		}
		students[size] = stud;
		size++;
	}
	void removeStudent(const int& index) {
		if (index >= 0 && index < size) {
			for (int i = index; i < size - 1; i++) {
				students[i] = students[i + 1];
			}
			size--;
		}
	}

	void updateStudent(const int& index, const student& stud) {
		if (index >= 0 && index < size) {
			students[index] = stud;
		}
	}

	void printStudent(const int& index) {
		if (index >= 0 && index < size) {
			students[index].prfull();
		}
	}
	void prbasic(const int& index) {
		if (index >= 0 && index < size) students[index].prbasic();
	}
	void printAll() { for (int i = 0; i < size; i++) { cout << i + 1 << ". "; students[i].prbasic(); } }
	void printMNOGO() { for (int i = 0; i < size; i++) { cout << '|' << setfill('-') << setw(55) << "    Студент №" + to_string(i + 1) + "   " << setw(40 - to_string(i + 1).length()) << right << '|' << endl; cout.fill(' '); students[i].prfull(); } }

	void ListToFileBin(const string& filename) {
		ofstream file(filename, ios::binary);
		if (!file.is_open()) {
			cerr << "Не удалось открыть файл для записи" << endl;
			return;
		}

		file.write(reinterpret_cast<const char*>(&size), sizeof(size));
		for (int i = 0; i < size; i++) {
			students[i].writeToFileBinary(file);
		}

		file.close();
	}

	void ListFromFileBin(const string& filename) {
		ifstream file(filename, ios::binary);
		if (!file.is_open()) {
			cerr << "Не удалось открыть файл для чтения" << endl;
			return;
		}

		file.read(reinterpret_cast<char*>(&size), sizeof(size));
		for (int i = 0; i < size; i++) {
			students[i].readFromFileBinary(file);
		}

		file.close();
	}

	StudentsList(const string& filename) {
		size = 0;
		students = new student[capacity];
		ListFromFileBin(filename);
	}
	const int& getSize() const {
		return size;
	}

	const student& getStudent(int index) const {
		return students[index];
	}

	void ListToFile(const char* filename) {
		FILE* file;
		errno_t err = fopen_s(&file, filename, "wb");
		if (err != 0) {
			printf("Ошибка открытия файла\n");
			return;
		}
		fwrite(&size, sizeof(unsigned short), 1, file);
		for (int i = 0; i < size; i++) {
			student& s = students[i];
			fwrite(s.num.c_str(), sizeof(char), s.num.size() + 1, file);
			fwrite(s.getFio().getfname().c_str(), sizeof(char), s.getFio().getfname().size() + 1, file);
			fwrite(s.getFio().getsrname().c_str(), sizeof(char), s.getFio().getsrname().size() + 1, file);
			fwrite(s.getFio().getpatr().c_str(), sizeof(char), s.getFio().getpatr().size() + 1, file);
			int year = s.getBorn().getyear();
			unsigned short month = s.getBorn().getmonth();
			unsigned short day = s.getBorn().getday();
			fwrite(&year, sizeof(int), 1, file);
			fwrite(&month, sizeof(unsigned short), 1, file);
			fwrite(&day, sizeof(unsigned short), 1, file);
			unsigned short age = s.getAge();
			fwrite(&age, sizeof(unsigned short), 1, file);
			unsigned short postup = s.getUch().postup;
			fwrite(&postup, sizeof(unsigned short), 1, file);
			fwrite(s.getUch().institut.c_str(), sizeof(char), s.getUch().institut.size() + 1, file);
			unsigned short kaf = s.getUch().kaf;
			fwrite(&kaf, sizeof(unsigned short), 1, file);
			fwrite(s.getUch().group.c_str(), sizeof(char), s.getUch().group.size() + 1, file);
			unsigned short gendr = s.getGendr();
			fwrite(&gendr, sizeof(unsigned short), 1, file);
			fwrite(s.getUch().progname.c_str(), sizeof(char), s.getUch().progname.size() + 1, file);
			unsigned long progid = s.getUch().progid;
			fwrite(&progid, sizeof(unsigned long), 1, file);
			unsigned short curkurs = s.getUch().curkurs;
			fwrite(&curkurs, sizeof(unsigned short), 1, file);
			unsigned short cursemestr = s.getUch().cursemestr;
			fwrite(&cursemestr, sizeof(unsigned short), 1, file);
			unsigned short fizgroup = s.getFizgroup();
			fwrite(&fizgroup, sizeof(unsigned short), 1, file);


			SessionList& prog = const_cast<SessionList&>(s.getProg());
			unsigned short sessionCount = prog.getcount();
			fwrite(&sessionCount, sizeof(unsigned short), 1, file);

			for (int j = 0; j < sessionCount; j++) {
				sessia* session = prog.getSession(j);

				unsigned short examsCount = session->getExamsCount();
				unsigned short zachsCount = session->getZachsCount();
				unsigned short kurs = session->kurs;
				unsigned short semestr = session->semestr;


				fwrite(&examsCount, sizeof(unsigned short), 1, file);
				fwrite(&zachsCount, sizeof(unsigned short), 1, file);
				fwrite(&kurs, sizeof(unsigned short), 1, file);
				fwrite(&semestr, sizeof(unsigned short), 1, file);


				for (int k = 0; k < examsCount; k++) {
					const sessia::predex& exam = session->getExam(k);

					string name = exam.name;
					unsigned short mark = exam.mark;


					fwrite(name.c_str(), sizeof(char), name.size() + 1, file);
					fwrite(&mark, sizeof(unsigned short), 1, file);
				}


				for (int k = 0; k < zachsCount; k++) {
					const sessia::predza& zach = session->getZach(k);

					string name = zach.name;
					bool zachBool = zach.zach;


					fwrite(name.c_str(), sizeof(char), name.size() + 1, file);
					fwrite(&zachBool, sizeof(bool), 1, file);
				}
			}
		}
		fclose(file);
	}

	void ListFromFile(const char* filename) {
		FILE* file;
		errno_t err = fopen_s(&file, filename, "rb");
		if (err != 0) {
			printf("Ошибка открытия файла\n");
			return;
		}
		fread_s(&size, sizeof(unsigned short), sizeof(unsigned short), 1, file);

		for (int i = 0; i < size; i++) {
			student& s = students[i];
			char buffer[100];
			fread_s(buffer, sizeof(buffer), sizeof(char), 100, file);
			s.num = buffer;
			fread_s(buffer, sizeof(buffer), sizeof(char), 100, file);
			s.setfname(buffer);
			fread_s(buffer, sizeof(buffer), sizeof(char), 100, file);
			s.setsrname(buffer);
			fread_s(buffer, sizeof(buffer), sizeof(char), 100, file);
			s.setpatr(buffer);
			int year;
			unsigned short month;
			unsigned short day;
			fread_s(&year, sizeof(int), sizeof(int), 1, file);
			fread_s(&month, sizeof(unsigned short), sizeof(unsigned short), 1, file);
			fread_s(&day, sizeof(unsigned short), sizeof(unsigned short), 1, file);
			s.setyear(year);
			s.setsmon(month);
			s.setday(day);
			unsigned short age;
			fread_s(&age, sizeof(unsigned short), sizeof(unsigned short), 1, file);
			s.setage(age);
			unsigned short postup;
			fread_s(&postup, sizeof(unsigned short), sizeof(unsigned short), 1, file);
			student::insti uch = s.getUch();
			uch.postup = postup;
			fread_s(buffer, sizeof(buffer), sizeof(char), 100, file);
			uch.institut = buffer;
			unsigned short kaf;
			fread_s(&kaf, sizeof(unsigned short), sizeof(unsigned short), 1, file);
			uch.kaf = kaf;
			fread_s(buffer, sizeof(buffer), sizeof(char), 100, file);
			uch.group = buffer;
			unsigned short gendr;
			fread_s(&gendr, sizeof(unsigned short), sizeof(unsigned short), 1, file);
			s.setgendr(gendr);
			fread_s(buffer, sizeof(buffer), sizeof(char), 100, file);
			uch.progname = buffer;
			unsigned long progid;
			fread_s(&progid, sizeof(unsigned long), sizeof(unsigned long), 1, file);
			uch.progid = progid;
			unsigned short curkurs;
			fread_s(&curkurs, sizeof(unsigned short), sizeof(unsigned short), 1, file);
			uch.curkurs = curkurs;
			unsigned short cursemestr;
			fread_s(&cursemestr, sizeof(unsigned short), sizeof(unsigned short), 1, file);
			uch.cursemestr = cursemestr;
			unsigned short fizgroup;
			fread_s(&fizgroup, sizeof(unsigned short), sizeof(unsigned short), 1, file);
			s.setfizgroup(fizgroup);
			s.setUch(uch);


			SessionList& prog = const_cast<SessionList&>(s.getProg());
			unsigned short sessionCount;
			fread_s(&sessionCount, sizeof(unsigned short), sizeof(unsigned short), 1, file);

			for (int j = 0; j < sessionCount; j++) {
				sessia session;

				unsigned short examsCount;
				unsigned short zachsCount;
				unsigned short kurs;
				unsigned short semestr;


				fread_s(&examsCount, sizeof(unsigned short), sizeof(unsigned short), 1, file);
				fread_s(&zachsCount, sizeof(unsigned short), sizeof(unsigned short), 1, file);
				fread_s(&kurs, sizeof(unsigned short), sizeof(unsigned short), 1, file);
				fread_s(&semestr, sizeof(unsigned short), sizeof(unsigned short), 1, file);

				session.kurs = kurs;
				session.semestr = semestr;


				for (int k = 0; k < examsCount; k++) {
					sessia::predex exam;

					string name;
					unsigned short mark;


					fread_s(buffer, sizeof(buffer), sizeof(char), 100, file);
					name = buffer;
					fread_s(&mark, sizeof(unsigned short), sizeof(unsigned short), 1, file);

					exam.name = name;
					exam.mark = mark;

					session.addExam(exam);
				}


				for (int k = 0; k < zachsCount; k++) {
					sessia::predza zach;

					string name;
					bool zachBool;


					fread_s(buffer, sizeof(buffer), sizeof(char), 100, file);
					name = buffer;
					fread_s(&zachBool, sizeof(bool), sizeof(bool), 1, file);

					zach.name = name;
					zach.zach = zachBool;

					session.addZach(zach);
				}

				prog.addSession(session);
			}
	}
	fclose(file);
}

	void studsubmenu(const int& index) {
		student& stud = students[index];
		int smchoice = -1;
		for (; smchoice != 0;) {
			CinDel
			system("cls");
			cout << stud << '\n';
			cout << "---------------------------------------------------\n";
			cout << "Выберете действие:\n";
			cout << "1. Изменить индивидуальный номер студента\n";
			cout << "2. Изменить ФИО студента\n";
			cout << "3. Изменить фамилию студента\n";
			cout << "4. Изменить имя студента\n";
			cout << "5. Изменить отчество студента\n";
			cout << "6. Изменить пол студента\n";
			cout << "7. Изменить дату рождения и возраст\n";
			cout << "8. Изменить данные о сессиях\n";
			cout << "9. Изменить физ. группу\n";
			cout << "---------------------------------------------------\n";
			cout << "10.Повторно вывести информацию о текущем студенте\n";
			cout << "---------------------------------------------------\n";
			cout << "11.Изменить институт\n";
			cout << "12.Изменить кафедру\n";
			cout << "13.Изменить группу\n";
			cout << "14.Изменить Id программы\n";
			cout << "15.Изменить название программы\n";
			cout << "16.Изменить дату поступления\n";
			cout << "17.Изменить текущий курс\n";
			cout << "18.Изменить текущий семестр\n";
			cout << "---------------------------------------------------\n";
			cout << "0. Выйти и вернуться к работе с базой данных\n";
			cout << "---------------------------------------------------\n";
			cout << ">";
			smchoice = readIntV(" ", [](int c) {return c >= 0 && c <= 18; });
			switch (smchoice) {
			case 1: {cout << endl; CinDel stud.num = readStrW("Введите дентификационный номер (Пример: 00А0000):  ", [this](const string& n) { return validnum(n); }); system("pause"); break; }
			case 2: {cout << endl; CinDel name nfio; cin >> nfio; stud.setfio(nfio); system("pause"); break; }
			case 3: {cout << endl; CinDel string sn = readStrW("Введите фамилию: ", [this](const string& n) { return validnameS(n); }); stud.setfname(sn); system("pause"); break; }
			case 4: {cout << endl; CinDel string fn = readStrW("Введите имя: ", [this](const string& n) { return validnameS(n); }); stud.setsrname(fn); system("pause"); break; }
			case 5: {cout << endl; CinDel string pr = readStrW("Введите отчество: ", [this](const string& n) { return validnameS(n); }); stud.setpatr(pr); system("pause"); break; }
			case 6: {cout << endl; CinDel unsigned short ngendr = readIntV("Введите пол (0-муж., 1-жен.): ", [this](const int& g) { return validgendr(g); }); stud.setgendr(ngendr); system("pause"); break; }
			case 7: {cout << endl; CinDel date nborn; unsigned short age; cin >> nborn; stud.setborn(nborn); age = readIntV("Введите возраст (полных лет): ", [this](const int& a) { return validage(a); }); stud.setage(age); system("pause"); break; }
			case 8: {stud.progsubmenu(); break; }
			case 9: {cout << endl; CinDel unsigned short nfizgroup = readIntV("Введите физ. группу (0 - осн., 1 - подг., 2 - спец.): ", [this](const int& f) { return validfizgroup(f); }); stud.setfizgroup(nfizgroup); system("pause"); break; }
			case 10: {cout << endl; stud.prfull(); system("pause"); break; }
			case 11: {cout << endl; CinDel stud.changeinstitut(); system("pause"); break; }
			case 12: {cout << endl; CinDel stud.changekaf(); system("pause"); break; }
			case 13: {cout << endl; CinDel stud.changegroup(); system("pause"); break; }
			case 14: {cout << endl; CinDel stud.changeprogid(); system("pause"); break; }
			case 15: {cout << endl; CinDel stud.changeprogname(); system("pause"); break; }
			case 16: {cout << endl; CinDel stud.changepostup(); system("pause"); break; }
			case 17: {cout << endl; CinDel stud.changecurkurs(); system("pause"); break;  }
			case 18: {cout << endl; CinDel stud.changekursem(); system("pause"); break; }
			case 0: {students[index] = stud; cout << "\nВозвращение в главное меню." << endl; return; system("pause"); }
			default: {cout << "\nНеизвестная операция!\n"; system("pause"); CinDel break; }
			}
		}
	}
};