//misc.h
#pragma once
#include <iostream>
#include <string>
#include <limits>
#include <functional>
#include <algorithm>
#include <cctype>
#include <windows.h>
#include <iomanip>
#include <fstream>
using namespace std;
#define CinDel cin.ignore((numeric_limits<streamsize>::max)(), '\n');//По идее чистит буфер ввода.

bool ValidInt(string num) {
	if (num == "" || num.length() > 9)
		return 0;
	num.append("a");
	if (num.find_first_not_of("0123456789+-") != num.length() - 1)
		return 0;
	return 1;
}

bool ValidIntModernised(const string& num) {
    if (num.empty() || num.size() > 9) {
        return false;
    }
    size_t start = 0;
    if (num[0] == '-' || num[0] == '+') {
        if (num.size() == 1 || num[1] == '0') {
            return false;
        }
        start = 1;
    }
    for (size_t i = start; i < num.size(); i++) {
        if (num[i] < '0' || num[i] > '9') {
            return false;
        }
    }
    return true;
}

bool ValidFloat(string num) {
	if (num == "" || num.length() > 9)
		return 0;
	num.append("a");
	if (num.find_first_not_of("0123456789.-+") != num.length() - 1)
		return 0;
	return 1;
}

bool ValidFloatModernised(const string& num) {
    if (num.empty()) {
        return false;
    }
    size_t start = 0;
    if (num[0] == '-' || num[0] == '+') {
        start = 1;
    }
    size_t decimal_count = 0;
    for (size_t i = start; i < num.size(); i++) {
        if (num[i] == '.') {
            decimal_count++;
            if (decimal_count > 1) {
                return false;
            }
        }
        else if (num[i] < '0' || num[i] > '9') {
            return false;
        }
    }
    return true;
}
int readIntV(const string& prompt, const function<bool(int)>& validator) {
    string input;
    cout << prompt;
    while (cin >> input) {
        if (ValidIntModernised(input)) {
            int value = stoi(input);
            if (validator(value)) {
                return value;
            }
        }
        cout << "Некорректное значение. Пожалуйста, введите заново: ";
    }
    CinDel
    return 0;
}
int readIntLV(const string& prompt, const function<bool(long)>& validator) {
    string input;
    cout << prompt;
    while (cin >> input) {
        if (ValidIntModernised(input)) {
            long value = stol(input);
            if (validator(value)) {
                return value;
            }
        }
        cout << "Некорректное значение. Пожалуйста, введите заново: ";
    }
    CinDel
    return 0;
}

int readIntV(const string& prompt, const function<bool(int)>& validator, const int& defaultValue) {
    string input;
    cout << prompt;
    while (cin >> input) {
        if (ValidIntModernised(input)) {
            int value = stoi(input);
            if (validator(value)) {
                return value;
            }
        }
        cout << "Некорректное значение. Пожалуйста, введите заново: ";
    }
    CinDel
    return defaultValue;
}
int readInt(const string& prompt) {
    string input;
    cout << prompt;
    while (cin >> input) {
        if (ValidIntModernised(input)) {
            int value = stoi(input);
            return value;
           }
        cout << "Некорректное значение. Пожалуйста, введите заново: ";
    }
    CinDel
    return 0;
}
string readStr(const string& prompt) {
    string input;
    cout << prompt;
    while (getline(cin, input)) {
        if (!input.empty()) {
            return input;
            }
        }
    CinDel
}

string readStrV(const string& prompt, const function<bool(string)>& validator) {
    string input;
    cout << prompt;
    while (getline(cin, input)) {
        if (!input.empty()) {
            if (validator(input)) {
                return input;
            }
        }
        cout << "Некорректное значение. Пожалуйста, введите заново: ";
    }
    CinDel
}
string readStrW(const string& prompt, const function<bool(const string&)>& validator) {
    string input;
    while (true) {
        cout << prompt;
        getline(cin, input);
        if (validator(input)) {
            return input;
        }
        cout << "Некорректное значение. Пожалуйста, введите заново." << endl;
    }
    CinDel
}