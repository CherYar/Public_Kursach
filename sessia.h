//sessia.h
#pragma once 
#include "struct.h"
#include "misc.h"

class sessia {
protected:
    predex* exams;
    int examsCount;
    predza* zachs;
    int zachsCount;
public:
    int kurs;
    int semestr;
    sessia() {
        examsCount = 0;
        exams = new predex[5];
        zachsCount = 0;
        zachs = new predza[5];
    }

    sessia(const sessia& s) {
        examsCount = s.examsCount;
        zachsCount = s.zachsCount;
        exams = new predex[5];
        zachs = new predza[5];
        for (int i = 0; i < examsCount; i++) {
            exams[i] = s.exams[i];
            zachs[i] = s.zachs[i];
        }
    }

    ~sessia() {
        delete[] exams;
        delete[] zachs;
        cout << " sessia destructor debug ";
    }

    void addExam(const predex& e) {
        if (examsCount < 5) {
            exams[examsCount] = e;
            examsCount++;
        }
        cout << "��� ���������� ������������ ���������� ���������!"; return;
    }
    void changeExam(int index, predex& exam) {
        if (index < 0 || index >= examsCount) {
            cout << "������������ ������ ��������." << endl;
            return;
        }
        if (!validmark(exam.mark)) {
            cout << "������������ ������." << endl;
            return;
        }
        exams[index] = exam;
    }
    void changeExamMark(int index, int mark) {
        if (index < 0 || index >= examsCount) {
            cout << "������������ ������ ��������." << endl;
            return;
        }
        if (!validmark(mark)) {
            cout << "������������ ������." << endl;
            return;
        }
        exams[index].mark = mark;
    }
    void changeExamName(int index, string name) {
        if (index < 0 || index >= examsCount) {
            cout << "������������ ������ ��������." << endl;
            return;
        }
        exams[index].name = name;
    }
    void addZach(const predza& z) {
        if (zachsCount < 5) {
            zachs[zachsCount] = z;
            zachsCount++;
        }
        cout << "��� ���������� ������������ ���������� �������!"; return;
    }
    void changeZach(int index, const predza& zach) {
        if (index < 0 || index >= zachsCount) {
            cout << "������������ ������ ������." << endl;
            return;
        }
        zachs[index] = zach
    }
    void changeZachZ(int index, int zach) {
        if (index < 0 || index >= zachsCount) {
            cout << "������������ ������ ������." << endl;
            return;
        }
        if (zach != 0 || zach != 1) {
            cout << "������������ �������� ������." << endl;
            return;
        }
        zachs[index].zach = zach;
    }
    void changeZachName(int index, string name) {
        if (index < 0 || index >= zachsCount) {
            cout << "������������ ������ ������." << endl;
            return;
        }
        zachs.name[index] = name;
    }

    bool validmark(int mark) {
        return mark >= 0 && mark <= 5;
    }

    bool validzach(int zach) {
        return (zach == 0 || zach == 1);
    }

    bool validkurs() {
        return kurs > 0 && kurs <= 6;
    }

    bool validsemestr() {
        return semestr > 0 && semestr <= 16;
    }

    void makesessia() {
        cout << "������� ����: ";
        cin >> kurs;
        while (!validkurs()) {
            cout << "������������ ����. ����������, ������� ������: ";
            cin >> kurs;
        }

        cout << "������� �������: ";
        cin >> semestr;
        while (!validsemestr()) {
            cout << "������������ �������. ����������, ������� ������: ";
            cin >> semestr;
        }

        cout << "������� ���������� ���������: ";
        int ec;
        cin >> ec;
        while (ec < 0 || ec > 5) {
            cout << "������������ ����������. ����������, ������� ������: ";
            cin >> ec;
        }
        for (int i = 0; i < ec; i++) {
            predex exam;
            cout << "������� �������� �������� �" << i + 1 << ": ";
            CinDel;
            getline(cin, exam.name);
            while (exam.name.empty()) {
                cout << "�������� �������� �� ����� ���� ������. ����������, ������� ������: ";
                getline(cin, exam.name);
            }
            cout << "������� ������ �� ��������(1 - 5): ";
            cin >> exam.mark;
            while (!validmark(exam.mark)) {
                cout << "������������ ������. ����������, ������� ������: ";
                cin >> exam.mark;
            }
            addExam(exam);
        }

        cout << "������� ���������� �������: ";
        int zc;
        cin >> zc;
        while (zc < 0 || zc > 5) {
            cout << "������������ ����������. ����������, ������� ������: ";
            cin >> zc;
        }
        for (int i = 0; i < zc; i++) {
            predza zachet;
            CinDel;
            cout << "������� �������� ������ �" << i + 1 << ": ";
            getline(cin, exam.name);
            while (zachet.name.empty()) {
                cout << "�������� ������ �� ����� ���� ������. ����������, ������� ������: ";
                getline(cin, zachet.name);
            }
            cout << "������� �� ����� (1 - ��, 0 - ���): ";
            cin >> zachet.zach;
            while (!validzach(zachet.zach)) {
                cout << "����� ��� ����, ��� ��� ���. ����������, ������� ������: ";
                cin >> zachet;
            }
            addZach(zachet);
        }
    }
}//�����