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
                string sessionNumber = " ������ �" + to_string(i + 1) + " ";
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
            cout << "�� ������� ������� ��������� ���� ��� ������." << endl;
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
        cout << "������ ������ �������� �� ���������� �����." << endl;
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
        n = readIntV("������� ���������� ������: ", validator);
        for (int i = 0; i < n; i++) {
            string p = to_string(i + 1);
            cout << "������ �" + p + '.' << endl;
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
    const unsigned short& getcount() const { return sessionCount; }

    void sessiasubmenu(const int& indx) {//��������� ������ �� ��������� ������
        sessia &ses = sessions[indx];
        int smchoice = -1;
        for (; smchoice != 0;){
        CinDel
        unsigned short excount = ses.getExamsCount(); string excounts = to_string(excount + 1);
        unsigned short zacount = ses.getZachsCount(); string zacounts = to_string(zacount + 1);
        system("cls");
        cout << "������� ���������� �������: " + zacounts << '\n';
        cout << "������� ���������� ���������: " + excounts << '\n';
        cout << "-----------------------------------------------------" << '\n';
        cout << "�������� ��������:\n";
        cout << "-----------------------------------------------------" << '\n';
        cout << "1. �������� �����\n";
        cout << "2. �������� �������\n";
        cout << "-----------------------------------------------------" << '\n';
        cout << "3. ������� �����\n";
        cout << "4. ������� �������\n";
        cout << "-----------------------------------------------------" << '\n';
        cout << "5. �������� ����� � ������ � ����������\n";
        cout << "6. �������� ������� � ������ � ����������\n";
        cout << "-----------------------------------------------------" << '\n';
        cout << "7. �������� ��������� ������\n";
        cout << "8. �������� ������ �� �������\n";
        cout << "-----------------------------------------------------" << '\n';
        cout << "9. �������� ���� ������\n";
        cout << "10.�������� ������� ������\n";
        cout << "-----------------------------------------------------" << '\n';
        cout << "11.�������� ������� ������� ������\n";
        cout << "-----------------------------------------------------" << '\n';
        cout << "0. ����� � ��������� � ������ � c������ ������\n";
        cout << "-----------------------------------------------------" << '\n';
        cout << "> ";
        smchoice = readIntV(" ", [](int c) {return c >= 0 && c <= 11; });
        switch (smchoice) {
        case 1: {if (zacount >= 5) { cout << "\n���������� ��������, ��������� ������ ���������� �������" << endl; system("pause"); break; }
              else {
            CinDel
            predza newz; newz.name = readStrW("������� �������� ������: ", [](const string& s) { return s.length() <= 20 && !s.empty(); }); newz.zach = readIntV("������� �� �����(1 - ��, 0 - ���): ", [this](int z) { return validzach(z); });
            ses.addZach(newz); cout << "\n����� ��������" << endl; system("pause"); break;}
        } 
        case 2: {if (excount >= 5) { cout << "\n���������� ��������, ��������� ������ ���������� ���������" << endl; system("pause"); break; }
              else {
            CinDel
            predex newx; newx.name = readStrW("������� �������� ��������: ", [](const string& s) { return s.length() <= 20 && !s.empty(); }); newx.mark = readIntV("������� ������ �� ������� (1 - 5): ", [this](int m) { return validmark(m); });
            ses.addExam(newx); cout << "\n������� ��������" << endl; system("pause"); break;}
        }
        case 3: {CinDel
            string prompt = "������� ����� ������ (1 - " + zacounts + "): ";
            unsigned short index = readIntV(prompt, [&](int i) { return i >= 1 && i <= (zacount); });
            ses.removeZach(index - 1); cout << "\n����� �����." << endl; system("pause"); break;
        }
        case 4: {CinDel string prompt = "������� ����� �������� (1 - " + excounts + "): ";
            unsigned short index = readIntV(prompt, [&](int i) { return i >= 1 && i <= (excount); });
            ses.removeExam(index - 1); cout << "\n������� �����." << endl; system("pause"); break;
            }
        case 5: {CinDel string prompt = "������� ����� ������ (1 - " + zacounts + "): ";
            unsigned short index = readIntV(prompt, [&](int i) { return i >= 1 && i <= (zacount); });
            predza newz; newz.name = readStrW("������� �������� ������: ", [](const string& s) { return s.length() <= 20 && !s.empty(); });
            newz.zach = readIntV("������� �� �����(1 - ��, 0 - ���): ", [&](const int& z) { return validzach(z); });
            ses.changeZach(index - 1, newz); cout << "\n����� ������." << endl; system("pause"); break; }
        case 6: {CinDel string prompt = "������� ����� �������� (1 - " + excounts + "): ";
            unsigned short index = readIntV(prompt, [&](int i) { return i >= 1 && i <= (excount); });
            predex newx; newx.name = readStrW("������� �������� ��������: ", [](const string& s) { return s.length() <= 20 && !s.empty(); });
            newx.mark = readIntV("������� ������ �� ������� (1 - 5): ", [&](const int& m) { return validmark(m); });
            ses.changeExam(index - 1, newx); cout << "\n������� ������." << endl; system("pause"); break; }
        case 7: {CinDel string prompt = "������� ����� ������ (1 - " + zacounts + "): ";
            unsigned short index = readIntV(prompt, [&](int i) { return i >= 1 && i <= (zacount); });
            predza newz = ses.getZach(index - 1);
            cout << endl << newz.name << endl;
            unsigned short zach = readIntV("������� �� �����(1 - ��, 0 - ���): ", [&](int z) { return validzach(z); });
            ses.changeZachZ(index - 1, zach);
            cout << "\n����� ������." << endl; system("pause"); break;
        }
        case 8: {CinDel string prompt = "������� ����� �������� (1 - " + excounts + "): ";
            unsigned short index = readIntV(prompt, [&](int i) { return i >= 1 && i <= (excount); });
            predex newx = ses.getExam(index - 1);
            cout << endl << newx.name << endl;
            unsigned short mark = readIntV("������� ������ �� ������� (1 - 5): ", [this](int m) { return validmark(m); });
            ses.changeExamMark(index - 1, mark);
            cout << "\n������ ��������." << endl; system("pause"); break; }
        case 9:{CinDel ses.kurs = readIntV("������� ���� (�� 4 - ��������., 5 - ����., 6 �������., �� 8 - ��������.): ", [this](int k) { return validkurs(k); }); }
        case 10:{CinDel ses.semestr = readIntV("������� ������� (������ �������������� �����): ", [this](int s) { return validsemestr(s); }); }
        case 11: {cout << ses; system("pause"); break; }
        case 0: {sessions[indx] = ses; cout << "\n����������� � ���� ������ �� ������� ������" << endl; system("pause"); return; }
        default: {cout << "\n����������� ��������!\n"; system("pause"); CinDel break; }
        }
        }
    }
};
