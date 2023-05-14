//date.h
#pragma once 
#include "misc.h"
using namespace std;

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
			if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) daysInMonth = 29; // ¬исокосный год
		}
		if (day > daysInMonth) return false;
		return true;

	}
	int getyear() const { return year; }
	unsigned short getmonth() const { return month; }
	unsigned short getday() const { return day; }
	void setyear(int y) { year = y; }
	void setsmon(unsigned short m) { month = m; }
	void setday(unsigned short d) { day = d; }
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
	date(date* d) { year = d->year; day = d->day, month = d->month; }
	bool operator<(const date& other) const {
		if (year < other.year) return true;
		if (year > other.year) return false;
		if (month < other.month) return true;
		if (month > other.month) return false;
		return day < other.day;
	}

	bool operator>(const date& other) const {
		return other < *this;
	}

	bool operator<=(const date& other) const {
		return !(*this > other);
	}

	bool operator>=(const date& other) const {
		return !(*this < other);
	}

	bool operator==(const date& other) const {
		return year == other.year && month == other.month && day == other.day;
	}

	bool operator!=(const date& other) const {
		return !(*this == other);
	}

	date& operator=(const date& other) {
		if (this != &other) {
			year = other.year;
			month = other.month;
			day = other.day;
		}
		return *this;
	}
	friend istream& operator>>(istream& in, date& d) {
		function<bool(int)> validator = [](const int& s) { return s > 0 && s < 2100; };
		string prompt = "¬ведите год: ";
		d.year = readIntV(prompt, validator);

		prompt = "¬ведите мес€ц: ";
		validator = [](const int& s) { return s >= 1 && s <= 12; };
		d.month = readIntV(prompt, validator);

		prompt = "¬ведите день: ";
		validator = [](const int& s) { return s >= 1 && s <= 31; };
		d.day = readIntV(prompt, validator);

		return in;
	}

	friend ostream& operator<<(ostream& out, const date& d) {
		out << setfill('0') << setw(4) << d.year << '.' << setw(2) << d.month << '.' << setw(2) << d.day << setfill(' ');
		return out;
	}
};


