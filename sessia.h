//sessia.h
#pragma once
#include "misc.h"
using namespace std;


class sessia {
    struct predza {
        string name;
        bool zach;
    };

    struct predex {
        string name;
        unsigned short mark;
    };
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
    bool SessiaToFileTXT(const char* filename) {
        FILE* file;
        errno_t err = fopen_s(&file, filename, "w");
        if (err) {
            cout << "Не удалось открыть текстовый файл для записи." << endl;
            return false;
        }
        if (file != NULL) {
            fprintf(file, "%d %d\n", kurs, semestr);
            fprintf(file, "%d\n", examsCount);
            for (int i = 0; i < examsCount; i++) {
                fprintf(file, "%s %hu\n", exams[i].name.c_str(), exams[i].mark);
            }
            fprintf(file, "%d\n", zachsCount);
            for (int i = 0; i < zachsCount; i++) {
                fprintf(file, "%s %d\n", zachs[i].name.c_str(), zachs[i].zach);
            }
            fclose(file);
            cout << "Сессия записана. ВНИМАНИЕ!!! Данный метод лишь для наглядности, в самом задании говорится об использовании бинарных фалов!" << endl;
            return true;
        }
        else {
            cout << "Не удалось записать в текстовый файл." << endl;
            return false;
        }
    }

    bool SessiaFromFileTXT(const char* filename) {
        FILE* file;
        errno_t err = fopen_s(&file, filename, "r");
        if (err) {
            cout << "Не удалось открыть текстовый файл для чтения." << endl;
            return false;
        }
        if (file != NULL) {
            fscanf_s(file, "%d %d", &kurs, &semestr);
            fscanf_s(file, "%d", &examsCount);
            exams = new predex[examsCount];
            for (int i = 0; i < examsCount; i++) {
                char name[666];
                unsigned short mark;
                fscanf_s(file, "%[^\n] %hu\n", name, &mark);
                exams[i].name = name;
                exams[i].mark = mark;
            }
            fscanf_s(file, "%d", &zachsCount);
            zachs = new predza[zachsCount];
            for (int i = 0; i < zachsCount; i++) {
                char name[666];
                int zach;
                fscanf_s(file, "%[^\n] %d\n", name, &zach);
                zachs[i].name = name;
                zachs[i].zach = zach;
            }
            fclose(file);
            cout << "Сессия прочитана из файла. ВНИМАНИЕ!!! Данный метод лишь для наглядности, в самом задании говорится об использовании бинарных фалов!" << endl;
            return true;
        }
        else {
            cout << "Не удалось открыть текстовый файл для чтения." << endl;
            return false;
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
        fwrite(exams, sizeof(predex), examsCount, file);
        fwrite(zachs, sizeof(predza), zachsCount, file);
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
        exams = new predex[examsCount];
        fread_s(exams, sizeof(predex) * examsCount, sizeof(predex), examsCount, file);
        zachs = new predza[zachsCount];
        fread_s(zachs, sizeof(predza) * zachsCount, sizeof(predza), zachsCount, file);
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
        cout << "Уже достигнуто максимальное количество экзаменов!" << endl;
    }
    void changeExam(int index, predex& exam) {
        if (index < 1 || index > examsCount) {
            cout << "Некорректный индекс экзамена." << endl;
            return;
        }
        if (!validmark(exam.mark)) {
            cout << "Некорректная оценка." << endl;
            return;
        }
        exams[index-1] = exam;
    }
    void changeExamMark(int index, int mark) {
        if (index < 1 || index > examsCount) {
            cout << "Некорректный индекс экзамена." << endl;
            return;
        }
        if (!validmark(mark)) {
            cout << "Некорректная оценка." << endl;
            return;
        }
        exams[index-1].mark = mark;
    }
    void changeExamName(int index, string name) {
        if (index < 1 || index > examsCount) {
            cout << "Некорректный индекс экзамена." << endl;
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
        cout << "Уже достигнуто максимальное количество зачётов!"<< endl;
    }
    void changeZach(const int& index, const predza& zach) {
        if (index < 1 || index > zachsCount) {
            cout << "Некорректный индекс зачета." << endl;
            return;
        }
        zachs[index-1] = zach;
    }
    void changeZachZ(const int& index, int zach) {
        if (index < 1 || index > zachsCount) {
            cout << "Некорректный индекс зачета." << endl;
            return;
        }
        if (!validzach(zach)) {
            cout << "Некорректное значение зачета." << endl;
            return;
        }
        zachs[index-1].zach = zach;
    }
    void changeZachName(const int &index, const string& name) {
        if (index < 1 || index > zachsCount) {
            cout << "Некорректный индекс зачета." << endl;
            return;
        }
        zachs[index-1].name = name;
    }
    int getExamsCount() const {
        return examsCount;
    }
    int getZachsCount() const {
        return zachsCount;
    }
    const predex& getExam(int index) const {
        return exams[index];
    }
    const predza& getZach(int index) const {
        return zachs[index];
    }
    bool validmark(const int& mark) { return mark >= 1 && mark <= 5; }
    bool validzach(const int& zach) { return (zach == 0 || zach == 1); } 
    bool validkurs() { return kurs > 0 && kurs <= 8; }
    bool validkurs(const int& k) { return k > 0 && k <= 8; }
    bool validsemestr() { return semestr > 0 && semestr <= 16; }
    bool validsemestr(const int& s) { return s > 0 && s <= 16; }

    void makesessia() {
        kurs = readIntV("Введите курс (до 4 - бакалавр., 5 - спец., 6 магистр., до 8 - аспирант.): ", [this](int k) { return validkurs(k); });

        semestr = readIntV("Введите семестр (должен соответсвовать курсу): ", [this](int s) { return validsemestr(s); });


        cout << "\nКурс: " << kurs << ", Семестр: " << semestr << " \n";
        
        int ec = 0;
        ec = readIntV("\nВведите количество экзаменов (1 - 5): ", [this](int a) { return validmark(a); });
        for (int i = 0; i < ec; i++) {
            predex exam;
            cout << "Введите название экзамена №" << i + 1 << ": "; 
            getline(cin, exam.name);
            while (exam.name.empty()) {
                getline(cin, exam.name);
            }
            exam.mark = readIntV("Введите оценку за экзамен (1 - 5): ", [this](int m) { return validmark(m); });
            addExam(exam);
        }
        CinDel
        int zc = 0;
        zc = readIntV("\nВведите количество зачётов(1 - 5): ", [this](int c) { return validmark(c); });

        for (int i = 0; i < zc; i++) {
            predza zach;
            cout << "Введите название зачёта №" << i + 1 << ": ";
            getline(cin, zach.name);
            while (zach.name.empty()) {
                getline(cin, zach.name);
            }
            zach.zach = readIntV("Получен ли зачёт(1 - да, 0 - нет): ", [this](int z) { return validzach(z); });
            addZach(zach);
        }
        CinDel
    }
};