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
	void ListToFileTXT(const string& filename) const {
		ofstream file(filename);
		if (!file.is_open()) {
			cerr << "�� ������� ������� ���� ��� ������" << endl;
			return;
		}

		file << size << endl;
		for (int i = 0; i < size; i++) {
			students[i].writeToFile(file);
			file << endl;
		}

		file.close();
	}

	void ListFromFileTXT(const string& filename) {
		ifstream file(filename);
		if (!file.is_open()) {
			cerr << "�� ������� ������� ���� ��� ������" << endl;
			return;
		}

		file >> size;

		file.ignore((numeric_limits<streamsize>::max)(), '\n');
		for (int i = 0; i < size; i++) {
			students[i].readFromFile(file);
		}

		file.close();
	}


	StudentsList(const string& filename) {
		size = 0;
		students = new student[capacity];
		ListFromFileBin(filename);
	}
	const int &getSize() const {
		return size;
	}

	const student& getStudent(int index) const {
		return students[index];
	}
};