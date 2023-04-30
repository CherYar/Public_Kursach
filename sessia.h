//sessia.h
#pragma once 
#include "struct.h"
#include "misc.h"
#include <string>

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
        kurs = 0;
        semestr = 0;
        examsCount = 0;
        exams = new predex[5];
        zachsCount = 0;
        zachs = new predza[5];
    }

    sessia(const sessia& s) {
        kurs = s.kurs;
        semestr = s.semestr;
        examsCount = s.examsCount;
        zachsCount = s.zachsCount;
        exams = new predex[5];
        zachs = new predza[5];
        for (int i = 0; i < examsCount; i++) {
            exams[i] = s.exams[i];
        }
        for (int i = 0; i < zachsCount; i++) {
            zachs[i] = s.zachs[i];
        }
    }
    bool SessiaToFile(const char* filename) {
        FILE* file;
        errno_t err = fopen_s(&file, filename, "wb");
        if (err) {
            cout << "�� ������� ������� ���� ��� ������.\n";
            return false;
        }
        fwrite(this, sizeof(sessia), 1, file);
        fclose(file);
        return true;
    }
    bool SessiaFromFile(const char* filename) {
        FILE* file;
        errno_t err = fopen_s(&file, filename, "rb");
        if (err) {
            cout << "�� ������� ������� ���� ��� ������.\n";
            return false;
        }
        fread_s(this, sizeof(sessia), sizeof(sessia), 1, file);
        fclose(file);
        return true;
    }

    sessia(const char* filename) { SessiaFromFile(filename); }

    ~sessia() {
        delete[] exams;
        delete[] zachs;
        cout << " sessia destructor debug ";
    }

    void addExam(const predex& e) {
        if (examsCount < 5) {
            exams[examsCount] = e;
            examsCount++;
            return;
        }
        cout << "��� ���������� ������������ ���������� ���������!\n";
    }
    void changeExam(int index, predex& exam) {
        if (index < 1 || index > examsCount) {
            cout << "������������ ������ ��������.\n" << endl;
            return;
        }
        if (!validmark(exam.mark)) {
            cout << "������������ ������.\n" << endl;
            return;
        }
        exams[index-1] = exam;
    }
    void changeExamMark(int index, int mark) {
        if (index < 1 || index > examsCount) {
            cout << "������������ ������ ��������.\n" << endl;
            return;
        }
        if (!validmark(mark)) {
            cout << "������������ ������.\n" << endl;
            return;
        }
        exams[index-1].mark = mark;
    }
    void changeExamName(int index, string name) {
        if (index < 1 || index > examsCount) {
            cout << "������������ ������ ��������.\n" << endl;
            return;
        }
        exams[index-1].name = name;
    }
    void addZach(const predza& z) {
        if (zachsCount < 5) {
            zachs[zachsCount] = z;
            zachsCount++;
            return;
        }
        cout << "��� ���������� ������������ ���������� �������!\n";
    }
    void changeZach(const int& index, const predza& zach) {
        if (index < 1 || index > zachsCount) {
            cout << "������������ ������ ������.\n" << endl;
            return;
        }
        zachs[index-1] = zach;
    }
    void changeZachZ(const int& index, int zach) {
        if (index < 1 || index > zachsCount) {
            cout << "������������ ������ ������.\n" << endl;
            return;
        }
        if (!validzach(zach)) {
            cout << "������������ �������� ������.\n" << endl;
            return;
        }
        zachs[index-1].zach = zach;
    }
    void changeZachName(const int &index, const string& name) {
        if (index < 1 || index > zachsCount) {
            cout << "������������ ������ ������.\n" << endl;
            return;
        }
        zachs[index-1].name = name;
    }

    bool validmark(const int& mark) {
        return mark >= 0 && mark <= 5;
    }

    bool validzach(const int& zach) {
        return (zach == 0 || zach == 1);
    }

    bool validkurs() {
        return kurs > 0 && kurs <= 6;
    }
    bool validkurs(const int& k) {
        return k > 0 && k <= 6;
    }
    //bool validkurs(const string& s) {
   //     if (!ValidInt(s)) cout <<"�������� �������� �� �������� ������. ����������, ������� ������: "
   // }

    bool validsemestr() {
        return semestr > 0 && semestr <= 16;
    }
    bool validsemestr(const int& s) {
        return s > 0 && s <= 16;
    }

    void makesessia() {
        string check = "\0";
        cout << "������� ����: ";
        cin >> check;
        while (!ValidInt(check) && kurs == 0) {
            cout << "�������� �������� �� �������� ������. ����������, ������� ������: ";
            cin >> check;
            if (ValidInt(check)) {
                int k = stoi(check);
                bool a = validkurs(k);
                switch (a) {
                case true: { kurs = k; break; }
                case false: { cout << "������������ �������� �����. ����������, ������� ������: "; cin >> check; break; }
                }
            }
        }
        cout << "\n" << kurs << "\n";

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
            getline(cin, zachet.name);
            while (zachet.name.empty()) {
                cout << "�������� ������ �� ����� ���� ������. ����������, ������� ������: ";
                getline(cin, zachet.name);
            }
            cout << "������� �� ����� (1 - ��, 0 - ���): ";
            cin >> zachet.zach;
            while (!validzach(zachet.zach)) {
                cout << "����� ��� ����, ��� ��� ���. ����������, ������� ������: ";
                cin >> zachet.zach;
            }
            addZach(zachet);
        }
    }
};