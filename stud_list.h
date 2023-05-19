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

	void studsubmenu(int index) {
		student& stud = students[index];
		string schoice;
		int smchoice = -1;
		for (; smchoice != 0;) {
			system("cls");
			cout << stud << '\n';
			cout << "Выберете действие:\n";
			cout << "1. Изменить индивидуальный номер студента\n";
			cout << "2. Изменить ФИО студента\n";
			cout << "3. Изменить фамилию студента\n";
			cout << "4. Изменить имя студента\n";
			cout << "5. Изменить отчество студента\n";
			cout << "6. Изменить пол студента\n";
			cout << "7. Изменить дату рождения и возраст\n";
			cout << "8. Изменить данные об институте/группе\n";
			cout << "9. Изменить данные о сессиях\n";
			cout << "10.Изменить физ. группу\n";
			cout << "11.Повторно вывести информацию о текущем студенте.";
			cout << "0. Выйти и вернуться к работе с базой данных\n";
			cout << "> ";
			getline(cin, schoice);
			if (ValidIntModernised(schoice)) smchoice = stoi(schoice);
			else { cout << "\nНекорректная команда!\n"; system("pause"); CinDel; }
			switch (smchoice) {
			case 1: {num = readStrW("Идентификационный номер (Пример: 00А0000):  ", [this](const string& n) { return validnum(n); }); }
			case 2: {cin >> fio; }
			case 3: {string fn; }
			case 4: {string ni; }
			case 5: {string no; }
			case 6: {unsigned short ngendr; }
			case 7: {date nborn; }
			case 8: {instisubmenu(); }
			case 9: {progsubmenu(); }
			case 10: {unsigned short nfizgroup; }
			case 11: {stud.prfull(); break; }
			case 0: {cout << "\nВозвращение в главное меню." << endl; return; system("pause"); }
			default: {cout << "\nНеизвестная операция!\n"; system("pause"); break; }
		}
	}


};