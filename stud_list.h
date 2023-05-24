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

	void studsubmenu(const int& index) {
		student& stud = students[index];
		int smchoice = -1;
		for (; smchoice != 0;) {
			CinDel
			system("cls");
			cout << stud << '\n';
			cout << "---------------------------------------------------\n";
			cout << "�������� ��������:\n";
			cout << "1. �������� �������������� ����� ��������\n";
			cout << "2. �������� ��� ��������\n";
			cout << "3. �������� ������� ��������\n";
			cout << "4. �������� ��� ��������\n";
			cout << "5. �������� �������� ��������\n";
			cout << "6. �������� ��� ��������\n";
			cout << "7. �������� ���� �������� � �������\n";
			cout << "8. �������� ������ � �������\n";
			cout << "9. �������� ���. ������\n";
			cout << "---------------------------------------------------\n";
			cout << "10.�������� ������� ���������� � ������� ��������\n";
			cout << "---------------------------------------------------\n";
			cout << "11.�������� ��������\n";
			cout << "12.�������� �������\n";
			cout << "13.�������� ������\n";
			cout << "14.�������� Id ���������\n";
			cout << "15.�������� �������� ���������\n";
			cout << "16.�������� ���� �����������\n";
			cout << "17.�������� ������� ����\n";
			cout << "18.�������� ������� �������\n";
			cout << "---------------------------------------------------\n";
			cout << "0. ����� � ��������� � ������ � ����� ������\n";
			cout << "---------------------------------------------------\n";
			cout << ">";
			smchoice = readIntV(" ", [](int c) {return c >= 0 && c <= 18; });
			switch (smchoice) {
			case 1: {cout << endl; CinDel stud.num = readStrW("������� ���������������� ����� (������: 00�0000):  ", [this](const string& n) { return validnum(n); }); system("pause"); break; }
			case 2: {cout << endl; CinDel name nfio; cin >> nfio; stud.setfio(nfio); system("pause"); break; }
			case 3: {cout << endl; CinDel string sn = readStrW("������� �������: ", [this](const string& n) { return validnameS(n); }); stud.setsrname(sn); system("pause"); break; }
			case 4: {cout << endl; CinDel string fn = readStrW("������� ���: ", [this](const string& n) { return validnameS(n); }); stud.setfname(fn); system("pause"); break; }
			case 5: {cout << endl; CinDel string pr = readStrW("������� ��������: ", [this](const string& n) { return validnameS(n); }); stud.setpatr(pr); system("pause"); break; }
			case 6: {cout << endl; CinDel unsigned short ngendr = readIntV("������� ��� (0-���., 1-���.): ", [this](const int& g) { return validgendr(g); }); stud.setgendr(ngendr); system("pause"); break; }
			case 7: {cout << endl; CinDel date nborn; unsigned short age; cin >> nborn; stud.setborn(nborn); age = readIntV("������� ������� (������ ���): ", [this](const int& a) { return validage(a); }); stud.setage(age); system("pause"); break; }
			case 8: {stud.progsubmenu(); break; }
			case 9: {cout << endl; CinDel unsigned short nfizgroup = readIntV("������� ���. ������ (0 - ���., 1 - ����., 2 - ����.): ", [this](const int& f) { return validfizgroup(f); }); stud.setfizgroup(nfizgroup); system("pause"); break; }
			case 10: {cout << endl; stud.prfull(); system("pause"); break; }
			case 11: {cout << endl; CinDel stud.changeinstitut(); system("pause"); break; }
			case 12: {cout << endl; CinDel stud.changekaf(); system("pause"); break; }
			case 13: {cout << endl; CinDel stud.changegroup(); system("pause"); break; }
			case 14: {cout << endl; CinDel stud.changeprogid(); system("pause"); break; }
			case 15: {cout << endl; CinDel stud.changeprogname(); system("pause"); break; }
			case 16: {cout << endl; CinDel stud.changepostup(); system("pause"); break; }
			case 17: {cout << endl; CinDel stud.changecurkurs(); system("pause"); break;  }
			case 18: {cout << endl; CinDel stud.changekursem(); system("pause"); break; }
			case 0: {students[index] = stud; cout << "\n����������� � ������� ����." << endl; return; system("pause"); }
			default: {cout << "\n����������� ��������!\n"; system("pause"); CinDel break; }
			}
		}
	}
};