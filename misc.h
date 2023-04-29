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

bool ValidFloat(string num) {
	if (num == "" || num.length() > 9)
		return 0;
	num.append("a");
	if (num.find_first_not_of("0123456789.-+") != num.length() - 1)
		return 0;
	return 1;
}
