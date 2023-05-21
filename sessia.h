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
            file << exams[i].name << '\n' << exams[i].mark << '\n';
        }
        file << zachsCount << '\n';
        for (int i = 0; i < zachsCount; i++) {
            file << zachs[i].name << '\n' << zachs[i].zach << '\n';
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
        string line;
        getline(file, line);
        for (int i = 0; i < examsCount; i++) {
            getline(file, exams[i].name);
            file >> exams[i].mark;
            getline(file, line);
        }
        file >> zachsCount;
        zachs = new predza[zachsCount];
        getline(file, line);
        for (int i = 0; i < zachsCount; i++) {
            getline(file, zachs[i].name);
            file >> zachs[i].zach;
            getline(file, line);
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

    sessia(const string &filename) { this->SessiaFromFile(filename); }

    ~sessia() {delete[] exams;delete[] zachs;}

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
    void removeExam(unsigned short index) {
        if (index >= examsCount) {
            cout << "Некорректный индекс экзамена." << endl;
            return;
        }
        for (unsigned short i = index; i < examsCount - 1; i++) {
            exams[i] = exams[i + 1];
        }
        examsCount--;
    }

    void removeZach(unsigned short index) {
        if (index >= zachsCount) {
            cout << "Некорректный индекс зачёта." << endl;
            return;
        }
        for (unsigned short i = index; i < zachsCount - 1; i++) {
            zachs[i] = zachs[i + 1];
        }
        zachsCount--;
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
            CinDel;
            exam.name = readStrW("Введите название экзамена №" + to_string(i + 1) + ": ", [](const string& s) { return s.length() <= 20 && !s.empty(); });
            exam.mark = readIntV("Введите оценку за экзамен (1 - 5): ", [this](int m) { return validmark(m); });
            addExam(exam);
        }

        int zc = 0;
        zc = readIntV("\nВведите количество зачётов      (1 - 5): ", [this](int c) { return validmark(c); });

        for (int i = 0; i < zc; i++) {
            predza zach;
            CinDel;
            zach.name = readStrW("Введите название зачёта №" + to_string(i + 1) + ": ", [](const string& s) { return s.length() <= 20 && !s.empty(); });
            zach.zach = readIntV("Получен ли зачёт(1 - да, 0 - нет): ", [this](int z) { return validzach(z); });
            addZach(zach);
        }
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
        os << "| Курс: " << s.kurs << setw(20) << "| семеместр: " << s.semestr << setw(20) << "| экзаменов: " << s.examsCount << setw(20) << "| зачётов: " << s.zachsCount << setw(25 - to_string(s.kurs).length() - to_string(s.semestr).length()) << '|' << endl;
        os << "| Экзамены: -------------------------- Оценка: | Зачёты: ---------------- Зачтено/не зачтено: |" << endl;
        int maxCount = max(s.examsCount, s.zachsCount);
        for (int i = 0; i < maxCount; i++) {
            if (i < s.examsCount) {
                os << '|' << left << setw(44) << " " + s.exams[i].name << right << s.exams[i].mark << " ";//работает - не трогай
            }
            else {
                os << "|||||||||||||||||||||||||||||||||||||||||||||||";//дилетанство, но я ЗАДОЛБАЛСЯ с setfill
            }
            if (i < s.zachsCount) {
                os << '|' << left << setw(38) << " " + s.zachs[i].name << setw(8) << (s.zachs[i].zach ? "зач. " : "незач. ") << '|';//почти работает - не трогай
            }
            else {
                os << "||||||||||||||||||||||||||||||||||||||||||||||||";
            }
            os << endl;
        }
        return os;
    }
    friend istream& operator>>(istream& is, sessia& s) { s.makesessia(); return is; }
    void writeToFile(ostream& out) const {
        out << kurs << ' ' << semestr << ' ' << examsCount << ' ' << zachsCount << endl;

        for (int i = 0; i < examsCount; i++) {
            out << exams[i].name << endl;
            out << exams[i].mark << endl;
        }

        for (int i = 0; i < zachsCount; i++) {
            out << zachs[i].name << endl;
            out << zachs[i].zach << endl;
        }
    }

    void readFromFile(istream& in) {
        in >> kurs >> semestr >> examsCount >> zachsCount;

        exams = new predex[examsCount];
        for (int i = 0; i < examsCount; i++) {
            in.ignore((numeric_limits<streamsize>::max)(), '\n');
            getline(in, exams[i].name);
            in >> exams[i].mark;
        }

        zachs = new predza[zachsCount];
        for (int i = 0; i < zachsCount; i++) {
            in.ignore((numeric_limits<streamsize>::max)(), '\n');
            getline(in, zachs[i].name);
            in >> zachs[i].zach;
        }
    }

    void writeToFileBinary(ostream& out) const {
        out.write(reinterpret_cast<const char*>(&kurs), sizeof(kurs));
        out.write(reinterpret_cast<const char*>(&semestr), sizeof(semestr));
        out.write(reinterpret_cast<const char*>(&examsCount), sizeof(examsCount));
        out.write(reinterpret_cast<const char*>(&zachsCount), sizeof(zachsCount));

        for (int i = 0; i < examsCount; i++) {
            size_t len = exams[i].name.size();
            out.write(reinterpret_cast<const char*>(&len), sizeof(len));
            out.write(exams[i].name.c_str(), len);
            out.write(reinterpret_cast<const char*>(&(exams[i].mark)), sizeof(exams[i].mark));
        }

        for (int i = 0; i < zachsCount; i++) {
            size_t len = zachs[i].name.size();
            out.write(reinterpret_cast<const char*>(&len), sizeof(len));
            out.write(zachs[i].name.c_str(), len);
            out.write(reinterpret_cast<const char*>(&(zachs[i].zach)), sizeof(zachs[i].zach));
        }
    }
    void readFromFileBinary(istream& in) {
        in.read(reinterpret_cast<char*>(&kurs), sizeof(kurs));
        in.read(reinterpret_cast<char*>(&semestr), sizeof(semestr));
        in.read(reinterpret_cast<char*>(&examsCount), sizeof(examsCount));
        in.read(reinterpret_cast<char*>(&zachsCount), sizeof(zachsCount));

        exams = new predex[examsCount];
        for (int i = 0; i < examsCount; i++) {
            size_t len;
            in.read(reinterpret_cast<char*>(&len), sizeof(len));
            exams[i].name.resize(len);
            in.read(&exams[i].name[0], len);
            in.read(reinterpret_cast<char*>(&(exams[i].mark)), sizeof(exams[i].mark));
        }

        zachs = new predza[zachsCount];
        for (int i = 0; i < zachsCount; i++) {
            size_t len;
            in.read(reinterpret_cast<char*>(&len), sizeof(len));
            zachs[i].name.resize(len);
            in.read(&zachs[i].name[0], len);
            in.read(reinterpret_cast<char*>(&(zachs[i].zach)), sizeof(zachs[i].zach));
        }
    }

};