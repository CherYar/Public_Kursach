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
            zachs[i] = s.zachs[i];
        }
    }
    bool SessiaToFile(const char* filename) {
        FILE* file;
        errno_t err = fopen_s(&file, filename, "wb");
        if (err) {
            cout << "Не удалось открыть файл для записи.\n";
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
            cout << "Не удалось открыть файл для чтения.\n";
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
        }
        cout << "Уже достигнуто максимальное количество экзаменов!"; return;
    }
    void changeExam(int index, predex& exam) {
        if (index < 0 || index >= examsCount) {
            cout << "Некорректный индекс экзамена." << endl;
            return;
        }
        if (!validmark(exam.mark)) {
            cout << "Некорректная оценка." << endl;
            return;
        }
        exams[index] = exam;
    }
    void changeExamMark(int index, int mark) {
        if (index < 0 || index >= examsCount) {
            cout << "Некорректный индекс экзамена." << endl;
            return;
        }
        if (!validmark(mark)) {
            cout << "Некорректная оценка." << endl;
            return;
        }
        exams[index].mark = mark;
    }
    void changeExamName(int index, string name) {
        if (index < 0 || index >= examsCount) {
            cout << "Некорректный индекс экзамена." << endl;
            return;
        }
        exams[index].name = name;
    }
    void addZach(const predza& z) {
        if (zachsCount < 5) {
            zachs[zachsCount] = z;
            zachsCount++;
        }
        cout << "Уже достигнуто максимальное количество зачётов!"; return;
    }
    void changeZach(int index, const predza& zach) {
        if (index < 0 || index >= zachsCount) {
            cout << "Некорректный индекс зачета." << endl;
            return;
        }
        zachs[index] = zach;
    }
    void changeZachZ(int index, int zach) {
        if (index < 0 || index >= zachsCount) {
            cout << "Некорректный индекс зачета." << endl;
            return;
        }
        if (!validzach(zach)) {
            cout << "Некорректное значение зачета." << endl;
            return;
        }
        zachs[index].zach = zach;
    }
    void changeZachName(int index, const string& name) {
        if (index < 0 || index >= zachsCount) {
            cout << "Некорректный индекс зачета." << endl;
            return;
        }
        zachs[index].name = name;
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
        cout << "Введите курс: ";
        cin >> kurs;
        while (!validkurs()) {
            cout << "Некорректный курс. Пожалуйста, введите заново: ";
            cin >> kurs;
        }

        cout << "Введите семестр: ";
        cin >> semestr;
        while (!validsemestr()) {
            cout << "Некорректный семестр. Пожалуйста, введите заново: ";
            cin >> semestr;
        }

        cout << "Введите количество экзаменов: ";
        int ec;
        cin >> ec;
        while (ec < 0 || ec > 5) {
            cout << "Некорректное количество. Пожалуйста, введите заново: ";
            cin >> ec;
        }
        for (int i = 0; i < ec; i++) {
            predex exam;
            cout << "Введите название экзамена №" << i + 1 << ": ";
            CinDel;
            getline(cin, exam.name);
            while (exam.name.empty()) {
                cout << "Название экзамена не может быть пустым. Пожалуйста, введите заново: ";
                getline(cin, exam.name);
            }
            cout << "Введите оценку по экзамену(1 - 5): ";
            cin >> exam.mark;
            while (!validmark(exam.mark)) {
                cout << "Некорректная оценка. Пожалуйста, введите заново: ";
                cin >> exam.mark;
            }
            addExam(exam);
        }

        cout << "Введите количество зачетов: ";
        int zc;
        cin >> zc;
        while (zc < 0 || zc > 5) {
            cout << "Некорректное количество. Пожалуйста, введите заново: ";
            cin >> zc;
        }
        for (int i = 0; i < zc; i++) {
            predza zachet;
            CinDel;
            cout << "Введите название зачёта №" << i + 1 << ": ";
            getline(cin, zachet.name);
            while (zachet.name.empty()) {
                cout << "Название зачёта не может быть пустым. Пожалуйста, введите заново: ";
                getline(cin, zachet.name);
            }
            cout << "Получен ли зачёт (1 - да, 0 - нет): ";
            cin >> zachet.zach;
            while (!validzach(zachet.zach)) {
                cout << "Зачёт или есть, или его нет. Пожалуйста, введите заново: ";
                cin >> zachet.zach;
            }
            addZach(zachet);
        }
    }
};