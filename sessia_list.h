//sessia_list.h
#pragma once
#include "sessia.h"
using namespace std;

class SessionList: public sessia {
protected:
    sessia* sessions;
    int sessionCount;
    int capacity;
public:
    SessionList() {
        sessionCount = 0;
        capacity = 10;
        sessions = new sessia[capacity];
    }
    ~SessionList() {
        delete[] sessions;
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
            cout << "Достигнут предел количества сессий!" << endl; return;
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
    bool Troeshnik() {
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
};
