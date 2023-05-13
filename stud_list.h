//stud_list.h
#pragma once
#include "student.h"

class StudentsList : public student {
private:
	student* students;
	const unsigned short capacity = 10;
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
			cout << "ƒостигнут предел количества студентов!" << endl;
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

	void ListToFile(const string& filename) {
		FILE* file;
		fopen_s(&file, filename.c_str(), "wb");
		if (file != nullptr) {
			fwrite(&size, sizeof(size), 1, file);
			for (int i = 0; i < size; i++) {
				fwrite(&students[i], sizeof(student), 1, file);
			}
		}
		fclose(file);
	}

	void ListFromFile(const string& filename) {
		FILE* file;
		fopen_s(&file, filename.c_str(), "rb");
		if (file != nullptr) {
			fread(&size, sizeof(size), 1, file);
			for (int i = 0; i < size; i++) {
				fread(&students[i], sizeof(student), 1, file);
			}
		}
		fclose(file);
	}

	StudentsList(const string& filename) {
		size = 0;
		students = new student[capacity];
		ListFromFile(filename);
	}
};