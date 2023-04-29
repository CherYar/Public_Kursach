//list.h
#pragma once
#include "student.h"

class StudentsList {
private:
	student* students;
	unsigned int capacity;
	unsigned int size;
public:
	StudentsList() {
		capacity = 10;
		size = 0;
		students = new student[capacity];
	}
	~StudentsList() {
		delete[] students;
	}
	void addStudent(const student& stud) {
		if (size == capacity) {
			capacity *= 2;
			student* newStudents = new student[capacity];
			for (int i = 0; i < size; i++) {
				newStudents[i] = students[i];
			}
			delete[] students;
			students = newStudents;
		}
		students[size] = stud;
		size++;
	}
	void removeStudent(int index) {
		if (index >= 0 && index < size) {
			for (int i = index; i < size - 1; i++) {
				students[i] = students[i + 1];
			}
			size--;
		}
	}

	void updateStudent(int index, const student& stud) {
		if (index >= 0 && index < size) {
			students[index] = stud;
		}
	}

	void printStudent(int index) {
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
			if (size > capacity) {
				capacity = size;
				delete[] students;
				students = new student[capacity];
			}
			for (int i = 0; i < size; i++) {
				fread(&students[i], sizeof(student), 1, file);
			}
		}
		fclose(file);
	}

	StudentsList(const string& filename) {
		capacity = 10;
		size = 0;
		students = new student[capacity];
		ListFromFile(filename);
	}
};