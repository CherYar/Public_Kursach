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
    ~SessionList() {
        delete[] sessions;
        cout << "\n SESSION LIST destructor debug" << endl;
    }
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
            cout << "������������ ������ ������" << endl;
            return nullptr;
        }
    }
    void addSession(const sessia& session)  {
        if (sessionCount >= capacity) {
            cout << "���������� ��������, ��������� ������ ���������� ������!" << endl; return;
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
        cout << "������������ ������ ������" << endl;
    }
    void updateSession(const int& index, const sessia& session) {
        if (index >= 0 && index < sessionCount) {
            sessions[index] = session; return;
        }
        cout << "������ ��� ��������� ������!" << endl;
    }
    friend ostream& operator<<(ostream& os, const SessionList& s) {
        if (s.sessionCount != 0) {
            for (int i = 0; i < s.sessionCount; i++) {
                os << setfill('-') << "|------------------------------------ ������ �" << i + 1 << " " << setw(48 - to_string(i).length()) << '|' << endl;
               os << setfill(' ') << s.sessions[i];
            }
            os << '|' << os.fill('-') << setw(94) << '|' << os.fill(' ') << endl;
        }
        return os;
    }
    /*bool Troeshnik() {
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
        return averageMark < 3.7 || failedZachRatio > 0.2;
    }
    �� ����� ���� ����� ������ �� �������, ���� bool ������ ����� �� �������.*/
    bool SessionListToFileTXT(const string& filename) {
        ofstream file(filename);
        if (!file.is_open()) {
            cout << "�� ������� ������� ��������� ���� ��� ������." << endl;
            return false;
        }
        file << sessionCount << '\n';
        for (int i = 0; i < sessionCount; i++) {
            file << sessions[i].kurs << ' ' << sessions[i].semestr << '\n';
            file << sessions[i].getExamsCount() << '\n';
            for (int j = 0; j < sessions[i].getExamsCount(); j++) {
                file << sessions[i].getExam(j).name << ' ' << sessions[i].getExam(j).mark << '\n';
            }
            file << sessions[i].getZachsCount() << '\n';
            for (int j = 0; j < sessions[i].getZachsCount(); j++) {
                file << sessions[i].getZach(j).name << ' ' << sessions[i].getZach(j).zach << '\n';
            }
        }
        file.close();
        cout << "������ ������ ������� � ��������� ����." << endl;
        return true;
    }

    bool SessionListFromFileTXT(const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cout << "�� ������� ������� ��������� ���� ��� ������." << endl;
            return false;
        }
        file >> sessionCount;
        for (int i = 0; i < sessionCount; i++) {
            file >> sessions[i].kurs >> sessions[i].semestr;
            int examsCount;
            file >> examsCount;
            for (int j = 0; j < examsCount; j++) {
                predex exam;
                file >> exam.name >> exam.mark;
                sessions[i].addExam(exam);
            }
            int zachsCount;
            file >> zachsCount;
            for (int j = 0; j < zachsCount; j++) {
                predza zach;
                file >> zach.name >> zach.zach;
                sessions[i].addZach(zach);
            }
        }
        file.close();
        cout << "������ ������ �������� �� ���������� �����." << endl;
        return true;
    }
    bool SessionListToFile(const string& filename) {
        ofstream file(filename, ios::binary);
        if (!file.is_open()) {
            cout << "�� ������� ������� ���� ��� ������.\n";
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
            cout << "�� ������� ������� ���� ��� ������.\n";
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
};
