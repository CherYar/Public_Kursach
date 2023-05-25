//zadanie.h
#pragma once
#include "stud_list.h"

using namespace std;

struct Node {
    student data;
    Node* next;
    Node* prev;
};

class DLList {
public:
    Node* head;
    Node* tail;
    int size;

    DLList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    ~DLList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    void add(const student& data) {
        Node* newNode = new Node{ data, nullptr, tail };
        if (tail != nullptr) {
            tail->next = newNode;
        }
        tail = newNode;
        if (head == nullptr) {
            head = newNode;
        }
        size++;
    }

    void sort() {
        if (size > 1) {
            for (int i = 0; i < size - 1; i++) {
                Node* current = head;
                for (int j = 0; j < size - i - 1; j++) {
                    if (current->data.num > current->next->data.num) {
                        swap(current->data, current->next->data);
                    }
                    current = current->next;
                }
            }
        }
    }
};

void splitStudentsByGrades(StudentsList& studentsList, int minBirthYear, int maxBirthYear) {
    DLList goodStudents;
    DLList badStudents;

    for (int i = 0; i < studentsList.getSize(); i++) {
        student stud = studentsList.getStudent(i);
        if (stud.getBorn().getyear() >= minBirthYear && stud.getBorn().getyear() <= maxBirthYear) {
            if (stud.getProg().Troeshnik()) {
                badStudents.add(stud);
            }
            else {
                goodStudents.add(stud);
            }
        }
    }

    goodStudents.sort();
    badStudents.sort();


    cout << "Хорошисты и отличники:" << endl;
    Node* current = goodStudents.head;
    while (current != nullptr) {
        cout << current->data << " Средний балл: "  + to_string(current->data.getProg().average()) << endl;
        current = current->next;
    }

    cout << "Троечники:" << endl;
    current = badStudents.head;
    while (current != nullptr) {
        cout << current->data << " Средний балл: "  + to_string(current->data.getProg().average()) << endl;
        current = current->next;
    }
}



