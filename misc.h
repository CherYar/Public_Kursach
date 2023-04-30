//misc.h
#pragma once
#include <iostream>
#include <limits>
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
