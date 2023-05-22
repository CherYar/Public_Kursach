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