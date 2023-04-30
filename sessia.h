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
            return;
        }
        cout << "Уже достигнуто максимальное количество экзаменов!\n";
    }
    void changeExam(int index, predex& exam) {
        if (index < 1 || index > examsCount) {
            cout << "Некорректный индекс экзамена.\n" << endl;
            return;
        }
        if (!validmark(exam.mark)) {
            cout << "Некорректная оценка.\n" << endl;
            return;
        }
        exams[index-1] = exam;
    }
    void changeExamMark(int index, int mark) {
        if (index < 1 || index > examsCount) {
            cout << "Некорректный индекс экзамена.\n" << endl;
            return;
        }
        if (!validmark(mark)) {
            cout << "Некорректная оценка.\n" << endl;
            return;
        }
        exams[index-1].mark = mark;
    }
    void changeExamName(int index, string name) {
        if (index < 1 || index > examsCount) {
            cout << "Некорректный индекс экзамена.\n" << endl;
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
        cout << "Уже достигнуто максимальное количество зачётов!\n";
    }
    void changeZach(const int& index, const predza& zach) {
        if (index < 1 || index > zachsCount) {
            cout << "Некорректный индекс зачета.\n" << endl;
            return;
        }
        zachs[index-1] = zach;
    }
    void changeZachZ(const int& index, int zach) {
        if (index < 1 || index > zachsCount) {
            cout << "Некорректный индекс зачета.\n" << endl;
            return;
        }
        if (!validzach(zach)) {
            cout << "Некорректное значение зачета.\n" << endl;
            return;
        }
        zachs[index-1].zach = zach;
    }
    void changeZachName(const int &index, const string& name) {
        if (index < 1 || index > zachsCount) {
            cout << "Некорректный индекс зачета.\n" << endl;
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
        return kurs > 0 && kurs <= 8;
    }
    bool validkurs(const int& k) {
        return k > 0 && k <= 8;
    }
    bool validsemestr() {
        return semestr > 0 && semestr <= 16;
    }
    bool validsemestr(const int& s) {
        return s > 0 && s <= 16;
    }

    void makesessia() {
        string check;
        cout << "Введите курс: ";
        while (cin >> check) {
            if (ValidIntModernised(check)) {
                int k = stoi(check);
                if (validkurs(k)) {
                    kurs = k;
                    break;
                }
                else {
                    cout << "Некорректное значение курса. Пожалуйста, введите заново: ";
                }
            }
            else {
                cout << "Введённое значение не является числом. Пожалуйста, введите заново: ";
            }
        }
        CinDel;check = '\0';
        cout << "Введите семестр: ";
        while (cin >> check) {
            if (ValidIntModernised(check)) {
                int s = stoi(check);
                if (validsemestr(s)) {
                    semestr = s;
                    break;
                }
                else {
                    cout << "Некорректное значение семестра. Пожалуйста, введите заново: ";
                }
            }
            else {
                cout << "Введённое значение не является числом. Пожалуйста, введите заново: ";
            }
        }
        cout << "\nКурс " << kurs << ", Семестр " << semestr << " \n";
        CinDel; check = '\0';int ec = 0;
        cout << "Введите количество экзаменов: ";
        while (cin >> check) {
            if (ValidIntModernised(check)) {
                int c = stoi(check);
                if (c >= 0 && c <= 5) {
                    ec = c;
                    break;
                }
                else {
                    cout << "Некорректное количество. Пожалуйста, введите заново: ";
                }
            }
            else {
                cout << "Введённое значение не является числом. Пожалуйста, введите заново: ";
            }
        }
        CinDel; check = '\0';
        for (int i = 0; i < ec; i++) {
            predex exam;
            cout << "Введите название экзамена №" << i + 1 << ": ";
            CinDel;
            getline(cin, exam.name);
            while (exam.name.empty()) {
                cout << "Название экзамена не может быть пустым. Пожалуйста, введите заново: ";
                getline(cin, exam.name);
            }
            while (cin >> check) {
                if (ValidIntModernised(check)) {
                    int m = stoi(check);
                    if (validmark(m)) {
                        exam.mark = m;
                        break;
                    }
                    else {
                        cout << "Некорректное количество. Пожалуйста, введите заново: ";
                    }
                }
                else {
                    cout << "Введённое значение не является числом. Пожалуйста, введите заново: ";
                }
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
};//Это не работает)))))