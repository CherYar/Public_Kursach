//sessia.h
#pragma once
#include "misc.h"
using namespace std;


class sessia {
protected:
    struct predza {
        string name;
        bool zach;
    };

    struct predex {
        string name;
        unsigned short mark;
    };
    predex* exams;
    unsigned short examsCount;
    predza* zachs;
    unsigned short zachsCount;
public:
    unsigned short kurs;
    unsigned short semestr;
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
    bool SessiaToFileTXT(const string& filename) {
        ofstream file(filename);
        if (!file.is_open()) {
            cout << "Не удалось открыть текстовый файл для записи!" << endl;
            return false;
        }
        file << kurs << ' ' << semestr << '\n';
        file << examsCount << '\n';
        for (int i = 0; i < examsCount; i++) {
            file << exams[i].name << ' ' << exams[i].mark << '\n';
        }
        file << zachsCount << '\n';
        for (int i = 0; i < zachsCount; i++) {
            file << zachs[i].name << ' ' << zachs[i].zach << '\n';
        }
        file.close();
        cout << "Сессия записана. ВНИМАНИЕ!!! Данный метод лишь для наглядности, в самом задании говорится об использовании бинарных файлов!" << endl;
        return true;
    }

    bool SessiaFromFileTXT(const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cout << "Не удалось открыть текстовый файл для чтения!" << endl;
            return false;
        }
        file >> kurs >> semestr;
        file >> examsCount;
        exams = new predex[examsCount];
        for (int i = 0; i < examsCount; i++) {
            file >> exams[i].name >> exams[i].mark;
        }
        file >> zachsCount;
        zachs = new predza[zachsCount];
        for (int i = 0; i < zachsCount; i++) {
            file >> zachs[i].name >> zachs[i].zach;
        }
        file.close();
        cout << "Сессия прочитана из файла. ВНИМАНИЕ!!! Данный метод лишь для наглядности, в самом задании говорится об использовании бинарных файлов!" << endl;
        return true;
    }


    bool SessiaToFile(const string& filename) {
        ofstream file(filename, ios::binary);
        if (!file.is_open()) {
            cout << "Не удалось открыть файл для записи!" << endl;
            return false;
        }
        file.write(reinterpret_cast<const char*>(this), sizeof(sessia));
        file.write(reinterpret_cast<const char*>(exams), sizeof(predex) * examsCount);
        file.write(reinterpret_cast<const char*>(zachs), sizeof(predza) * zachsCount);
        file.close();
        return true;
    }

    bool SessiaFromFile(const string& filename) {
        ifstream file(filename, ios::binary);
        if (!file.is_open()) {
            cout << "Не удалось открыть файл для чтения!" << endl;
            return false;
        }
        file.read(reinterpret_cast<char*>(this), sizeof(sessia));
        exams = new predex[examsCount];
        file.read(reinterpret_cast<char*>(exams), sizeof(predex) * examsCount);
        zachs = new predza[zachsCount];
        file.read(reinterpret_cast<char*>(zachs), sizeof(predza) * zachsCount);
        file.close();
        return true;
    }

    sessia(const char* filename) { this->SessiaFromFile(filename); }

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
    void changeExam(const int& index, const predex& exam) {
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
    void changeExamMark(const int& index, const int &mark) {
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
    void changeExamName(const int& index, const string& name) {
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
            return;
        }
        cout << "Уже достигнуто максимальное количество зачётов!"<< endl;
    }
    void changeZach(const int& index, const predza& zach) {
        if (index < 0 || index >= zachsCount) {
            cout << "Некорректный индекс зачета." << endl;
            return;
        }
        zachs[index] = zach;
    }
    void changeZachZ(const int& index, int zach) {
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
    void changeZachName(const int &index, const string& name) {
        if (index < 0 || index >= zachsCount) {
            cout << "Некорректный индекс зачета." << endl;
            return;
        }
        zachs[index].name = name;
    }
    const int& getExamsCount()  {
        return examsCount;
    }
    const int& getZachsCount()  {
        return zachsCount;
    }
    const predex& getExam(const int &index) const {
        return exams[index];
    }
    const predza& getZach(const int &index) const {
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
    sessia& operator=(const sessia& other) {
        if (&other != this) {
            delete[] exams;
            delete[] zachs;
            kurs = other.kurs;
            semestr = other.semestr;
            examsCount = other.examsCount;
            zachsCount = other.zachsCount;
            exams = new predex[5];
            zachs = new predza[5];
            for (int i = 0; i < examsCount; i++) {
                exams[i] = other.exams[i];
            }
            for (int i = 0; i < zachsCount; i++) {
                zachs[i] = other.zachs[i];
            }
        }
        return *this;
    }

    friend ostream& operator<<(ostream& os, const sessia& s) {
        os << '|'  << "Курс: " << s.kurs << "| сем. : " << s.semestr << "| экз. : " << s.examsCount << "| зач. : " << s.zachsCount << '|' << endl;//ЭТО НЕ РАБОАТТЕТВЫТАЫФАТФЫАФАЫФАЫ
        os << "|------------- Экзамены: --------------|" << endl;
        for (int i = 0; i < s.examsCount; i++) {
            os <<'|'<< s.exams[i].name << os.width(38) << right << s.exams[i].mark << '|' << left << endl;
        }
        os << "|-------------- Зачёты: ---------------|" << endl;
        for (int i = 0; i < s.zachsCount; i++) {
            os << '|' << s.zachs[i].name << os.width(38) << right << (s.zachs[i].zach ? "зач." : "незач.") << " |" << left << endl;
        }
        return os;
    }
    friend istream& operator>>(istream& is, sessia& s) { s.makesessia(); return is; }

};