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
			cout << "��������� ������ ���������� ���������!" << endl;
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
	void printMNOGO() { for (int i = 0; i < size; i++) { cout << '|' << setfill('-') << setw(55) << "    ������� �" + to_string(i + 1) + "   " << setw(40 - to_string(i + 1).length()) << right << '|' << endl; cout.fill(' '); students[i].prfull(); } }

	void ListToFileBin(const string& filename) {
		ofstream file(filename, ios::binary);
		if (!file.is_open()) {
			cerr << "�� ������� ������� ���� ��� ������" << endl;
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
			cerr << "�� ������� ������� ���� ��� ������" << endl;
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
			cout << "�������� ��������:\n";
			cout << "1. �������� �������������� ����� ��������\n";
			cout << "2. �������� ��� ��������\n";
			cout << "3. �������� ������� ��������\n";
			cout << "4. �������� ��� ��������\n";
			cout << "5. �������� �������� ��������\n";
			cout << "6. �������� ��� ��������\n";
			cout << "7. �������� ���� �������� � �������\n";
			cout << "8. �������� ������ �� ���������/������\n";
			cout << "9. �������� ������ � �������\n";
			cout << "10.�������� ���. ������\n";
			cout << "11.�������� ������� ���������� � ������� ��������.";
			cout << "0. ����� � ��������� � ������ � ����� ������\n";
			cout << "> ";
			getline(cin, schoice);
			if (ValidIntModernised(schoice)) smchoice = stoi(schoice);
			else { cout << "\n������������ �������!\n"; system("pause"); CinDel; }
			switch (smchoice) {
			case 1: {num = readStrW("����������������� ����� (������: 00�0000):  ", [this](const string& n) { return validnum(n); }); }
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
			case 0: {cout << "\n����������� � ������� ����." << endl; return; system("pause"); }
			default: {cout << "\n����������� ��������!\n"; system("pause"); break; }
		}
	}


};