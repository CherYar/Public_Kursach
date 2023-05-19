//sessia_list.h
#pragma once
#include "sessia.h"
using namespace std;

class SessionList: public sessia {
protected:
    sessia* sessions;
    unsigned short sessionCount;
    const unsigned short capacity = 10;
public:
    SessionList() {
        sessionCount = 0;
        sessions = new sessia[capacity];
    }
    ~SessionList() {delete[] sessions;}
    SessionList(const SessionList& other) {
        sessionCount = other.sessionCount;
        sessions = new sessia[capacity];
        for (int i = 0; i < sessionCount; i++) {
            sessions[i] = other.sessions[i];
        }
    }
    SessionList& operator=(const SessionList& other) {
        if (this != &other) {
            sessionCount = other.sessionCount;
            delete[] sessions;
            sessions = new sessia[capacity];
            for (int i = 0; i < sessionCount; i++) {
                sessions[i] = other.sessions[i];
            }
        }
        return *this;
    }
    sessia* getSession(const int& index) {
        if (index >= 0 && index < sessionCount) {
            return &sessions[index];
        }
        else {
            cout << "Некорректный индекс сессии" << endl;
            return nullptr;
        }
    }
    void addSession(const sessia& session)  {
        if (sessionCount >= capacity) {
            cout << "Невозможно добавить, достигнут предел количества сессий!" << endl; return;
        }
        sessions[sessionCount] = session;
        sessionCount++;
    }
    void removeSession(int index) {
        if (index >= 0 && index < sessionCount) {
            for (int i = index; i < sessionCount - 1; i++) {
                sessions[i] = sessions[i + 1];
            }
            sessionCount--;
            return;
        }
        cout << "Некорректный индекс сессии" << endl;
    }
    void updateSession(const int& index, const sessia& session) {
        if (index >= 0 && index < sessionCount) {
            sessions[index] = session; return;
        }
        cout << "Ошибка при изменении сессии!" << endl;
    }
    friend ostream& operator<<(ostream& os, const SessionList& s) {
        if (s.sessionCount != 0) {
            for (int i = 0; i < s.sessionCount; i++) {
                string sessionNumber = " Сессия №" + to_string(i + 1) + " ";
                os << setfill('-') << '|' << setw(52) <<right<< sessionNumber << setw(53 - sessionNumber.length()) << '|' << endl;
                os << setfill(' ') << s.sessions[i];
            }
            os << '|' << setfill('-') << setw(94) << right << '|' << endl << setfill(' ');
        }
        return os;
    }


const bool Troeshnik() const {
        double totalMark = 0;
        int markCount = 0;
        int failedZachs = 0;
        int totalZachs = 0;
        for (int i = 0; i < sessionCount; i++) {
            for (int j = 0; j < sessions[i].getExamsCount(); j++) {
                totalMark += sessions[i].getExam(j).mark;
                markCount++;
            }
            for (int j = 0; j < sessions[i].getZachsCount(); j++) {
                if (!sessions[i].getZach(j).zach) {
                    failedZachs++;
                }
                totalZachs++;
            }
        }
        double averageMark = markCount > 0 ? totalMark / markCount : 0;
        double failedZachRatio = totalZachs > 0 ? (double)failedZachs / totalZachs : 0;
        return averageMark < 3.6 || failedZachRatio > 0.2;
    }
    
    bool SessionListToFileTXT(const string& filename) {
        ofstream file(filename);
        if (!file.is_open()) {
            cout << "Не удалось открыть текстовый файл для записи." << endl;
            return false;
        }
        file << sessionCount << '\n';
        for (int i = 0; i < sessionCount; i++) {
            file << sessions[i].kurs << ' ' << sessions[i].semestr << '\n';
            file << sessions[i].getExamsCount() << '\n';
            for (int j = 0; j < sessions[i].getExamsCount(); j++) {
                file << sessions[i].getExam(j).name << '\n' << sessions[i].getExam(j).mark << '\n';
            }
            file << sessions[i].getZachsCount() << '\n';
            for (int j = 0; j < sessions[i].getZachsCount(); j++) {
                file << sessions[i].getZach(j).name << '\n' << sessions[i].getZach(j).zach << '\n';
            }
        }
        file.close();
        cout << "Список сессий записан в текстовый файл." << endl;
        return true;
    }

    bool SessionListFromFileTXT(const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cout << "Не удалось открыть текстовый файл для чтения." << endl;
            return false;
        }
        file >> sessionCount;
        string line;
        getline(file, line);
        for (int i = 0; i < sessionCount; i++) {
            file >> sessions[i].kurs >> sessions[i].semestr;
            getline(file, line);
            int examsCount;
            file >> examsCount;
            getline(file, line);
            for (int j = 0; j < examsCount; j++) {
                predex exam;
                getline(file, exam.name);
                file >> exam.mark;
                getline(file, line);
                sessions[i].addExam(exam);
            }
            int zachsCount;
            file >> zachsCount;
            getline(file, line);
            for (int j = 0; j < zachsCount; j++) {
                predza zach;
                getline(file, zach.name);
                file >> zach.zach;
                getline(file, line);
                sessions[i].addZach(zach);
            }
        }
        file.close();
        cout << "Список сессий прочитан из текстового файла." << endl;
        return true;
    }

    void sortSessions() {
        for (int i = 0; i < sessionCount - 1; i++) {
            for (int j = 0; j < sessionCount - i - 1; j++) {
                if (sessions[j].kurs > sessions[j + 1].kurs || (sessions[j].kurs == sessions[j + 1].kurs && sessions[j].semestr > sessions[j + 1].semestr)) {
                    swap(sessions[j], sessions[j + 1]);
                }
            }
        }
    }

    bool SessionListToFile(const string& filename) {
        ofstream file(filename, ios::binary);
        if (!file.is_open()) {
            cout << "Не удалось открыть файл для записи.\n";
            return false;
        }
        file.write(reinterpret_cast<const char*>(&sessionCount), sizeof(sessionCount));
        for (int i = 0; i < sessionCount; i++) {
            file.write(reinterpret_cast<const char*>(&sessions[i]), sizeof(sessia));
            for (int j = 0; j < sessions[i].getExamsCount(); j++) {
                file.write(reinterpret_cast<const char*>(&sessions[i].getExam(j)), sizeof(predex));
            }
            for (int j = 0; j < sessions[i].getZachsCount(); j++) {
                file.write(reinterpret_cast<const char*>(&sessions[i].getZach(j)), sizeof(predza));
            }
        }
        file.close();
        return true;
    }
    bool SessionListFromFile(const string& filename) {
        ifstream file(filename, ios::binary);
        if (!file.is_open()) {
            cout << "Не удалось открыть файл для чтения.\n";
            return false;
        }
        file.read(reinterpret_cast<char*>(&sessionCount), sizeof(sessionCount));
        for (int i = 0; i < sessionCount; i++) {
            file.read(reinterpret_cast<char*>(&sessions[i]), sizeof(sessia));
            for (int j = 0; j < sessions[i].getExamsCount(); j++) {
                predex exam;
                file.read(reinterpret_cast<char*>(&exam), sizeof(predex));
                sessions[i].addExam(exam);
            }
            for (int j = 0; j < sessions[i].getZachsCount(); j++) {
                predza zach;
                file.read(reinterpret_cast<char*>(&zach), sizeof(predza));
                sessions[i].addZach(zach);
            }
        }
        file.close();
        return true;
    }
    void writeToFile(ostream& out) const {
        out << sessionCount << endl;
        for (int i = 0; i < sessionCount; i++) {
            sessions[i].writeToFile(out);
        }
    }

    void readFromFile(istream& in) {
        in >> sessionCount;

        sessions = new sessia[sessionCount];
        for (int i = 0; i < sessionCount; i++) {
            sessions[i].readFromFile(in);
        }
    }
    void makesessions() {
        int n;
        function<bool(int)> validator = [](const int& n) { return n <= 10 && n > 0; };
        n = readIntV("Введите количество сессий: ", validator);
        for (int i = 0; i < n; i++) {
            string p = to_string(i + 1);
            cout << "Сессия №" + p + '.' << endl;
            sessia s;
            s.makesessia();
            addSession(s);
        }
        this->sortSessions();
    }
    void writeToFileBinary(ostream& out) const {
        out.write(reinterpret_cast<const char*>(&sessionCount), sizeof(sessionCount));
        for (int i = 0; i < sessionCount; i++) {
            sessions[i].writeToFileBinary(out);
        }
    }

    void readFromFileBinary(istream& in) {
        in.read(reinterpret_cast<char*>(&sessionCount), sizeof(sessionCount));

        sessions = new sessia[sessionCount];
        for (int i = 0; i < sessionCount; i++) {
            sessions[i].readFromFileBinary(in);
        }
    }
    const double &average() const {
        double sum = 0;
        unsigned short count = 0;
        for (int i = 0; i < sessionCount; i++) {
            for (int j = 0; j < sessions[i].getExamsCount(); j++) {
                sum += sessions[i].getExam(j).mark;
                count++;
            }
        }
        return count > 0 ? sum / count : 0;
    }
};
