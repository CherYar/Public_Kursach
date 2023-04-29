//date_name.h
#pragma once 
#include <string>
#include "misc.h"

class date {
protected:
	int year;
	unsigned short month;
	unsigned short day;
public:
	date() { year = 2000; month = 1; day = 1; }
	~date() {};
	void printdatef() { cout << left << day << '.' << month << '.' << year; }
	void adddatef(unsigned short d, unsigned short m, short y) { year = y; month = m; day = d; }
	unsigned short datelength() { unsigned short l; l = to_string(year).length() + to_string(month).length() + to_string(day).length(); return l; }
	bool validdate() {
		if (day < 1 || day > 31) return false;
		if (month < 1 || month > 12) return false;
		if (year < 1) return false;
		int daysInMonth = 31;
		if (month == 4 || month == 6 || month == 9 || month == 11) daysInMonth = 30;
		if (month == 2) {
			daysInMonth = 28;
			if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) daysInMonth = 29; // Високосный год
		}
		if (day > daysInMonth) return false;
		return true;

	}
	bool validyear() {
		return year >= 1900 && year <= 2100;
	}
	bool validmonth() {
		return month >= 1 && month <= 12;
	}
	bool validday() {
		return day >= 1 && day <= 31;
	}
	date(const date& x) { day = x.day; month = x.month; year = x.year; }
};
class name {
protected:
	string fname;
	string srname;
	string patrn;
public:
	~name() {};
	name() { fname = "Иван"; srname = "Петров"; patrn = "Сергеевич"; }
	name(const name& n) { fname = n.fname; srname = n.srname; patrn = n.patrn; }
	void printfio() {
		cout << left << srname << ' ' << fname << ' ' << patrn;
	}
	void addfio(string ln, string fn, string pr) { fname = fn; srname = ln; patrn = pr; }
	unsigned short fiolength() { unsigned short l; l = fname.length() + srname.length() + patrn.length(); return l; }
	unsigned short fnamelen() { unsigned short l; l = fname.length(); return l; }
	unsigned short srnamelen() { unsigned short l; l = srname.length(); return l; }
	unsigned short partrlen() { unsigned short l; l = patrn.length(); return l; }
	bool validfio() {
		return !fname.empty() && fname.length() <= 20 && all_of(fname.begin(), fname.end(), [](char c) { return !isdigit(static_cast<unsigned char>(c)); }) &&
			!srname.empty() && srname.length() <= 20 && all_of(srname.begin(), srname.end(), [](char c) { return !isdigit(static_cast<unsigned char>(c)); }) &&
			!patrn.empty() && patrn.length() <= 20 && all_of(patrn.begin(), patrn.end(), [](char c) { return !isdigit(static_cast<unsigned char>(c)); });
	}
	void setfname(string n) { fname = n; }
	void setsrname(string s) { srname = s; }
	void setpatr(string p) { patrn = p; }
	string getfname() { return fname; }
	string getsrname() { return srname; }
	string getpatr() { return patrn; }
	bool validfname() { return !fname.empty() && fname.length() <= 20 && all_of(fname.begin(), fname.end(), [](char c) { return !isdigit(static_cast<unsigned char>(c)); }); }
	bool validsrname() { return !srname.empty() && srname.length() <= 20 && all_of(srname.begin(), srname.end(), [](char c) { return !isdigit(static_cast<unsigned char>(c)); }); }
	bool validpatr() { return !patrn.empty() && patrn.length() <= 20 && all_of(patrn.begin(), patrn.end(), [](char c) { return !isdigit(static_cast<unsigned char>(c)); });}
};