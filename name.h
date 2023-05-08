//name.h
#pragma once
#include "date.h"
using namespace std;

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
	void addfio(const string& sn, const string& fn, const string& pr) { fname = fn; srname = sn; patrn = pr; }
	unsigned short fiolength() { unsigned short l; l = fname.length() + srname.length() + patrn.length(); return l; }
	unsigned short fnamelen() { unsigned short l; l = fname.length(); return l; }
	unsigned short srnamelen() { unsigned short l; l = srname.length(); return l; }
	unsigned short partrlen() { unsigned short l; l = patrn.length(); return l; }
	bool validfio() {
		return !fname.empty() && fname.length() <= 20 && all_of(fname.begin(), fname.end(), [](char c) { return !isdigit(static_cast<unsigned char>(c)); }) &&
			!srname.empty() && srname.length() <= 20 && all_of(srname.begin(), srname.end(), [](char c) { return !isdigit(static_cast<unsigned char>(c)); }) &&
			!patrn.empty() && patrn.length() <= 20 && all_of(patrn.begin(), patrn.end(), [](char c) { return !isdigit(static_cast<unsigned char>(c)); });
	}
	void setfname(const string& n) { fname = n; }
	void setsrname(const string& s) { srname = s; }
	void setpatr(const string& p) { patrn = p; }
	string& getfname() { return fname; }
	string& getsrname() { return srname; }
	string& getpatr() { return patrn; }
	bool validfname() { return !fname.empty() && fname.length() <= 20 && all_of(fname.begin(), fname.end(), [](char c) { return !isdigit(static_cast<unsigned char>(c)); }); }
	bool validsrname() { return !srname.empty() && srname.length() <= 20 && all_of(srname.begin(), srname.end(), [](char c) { return !isdigit(static_cast<unsigned char>(c)); }); }
	bool validpatr() { return !patrn.empty() && patrn.length() <= 20 && all_of(patrn.begin(), patrn.end(), [](char c) { return !isdigit(static_cast<unsigned char>(c)); }); }
	bool validnameS(const string& s) { return !s.empty() && s.length() <= 20 && all_of(s.begin(), s.end(), [](char c) { return !isdigit(static_cast<unsigned char>(c)); }); }
	name& operator=(const name& other) {
		if (&other != this) {
			fname = other.fname;
			srname = other.srname;
			patrn = other.patrn;
		}
		return *this;
	}

	bool operator==(const name& other) const {
		return (fname == other.fname) && (srname == other.srname) && (patrn == other.patrn);
	}

	bool operator!=(const name& other) const {
		return !(*this == other);
	}
	friend istream& operator>>(istream& in, name& n) {
		function<bool(const string&)> validator = [](const string& s) { return !s.empty() && s.length() <= 20 && all_of(s.begin(), s.end(), [](char c) { return !isdigit(static_cast<unsigned char>(c)); }); };
		n.srname = readStrW("Введите фамилию: ", validator);
		n.fname = readStrW("Введите имя: ", validator);
		n.patrn = readStrW("Введите отчество: ", validator);
		return in;
	}

	friend ostream& operator<<(ostream& out, const name& n) {
		out << left << n.srname << " " << n.fname << " " << n.patrn;
		return out;
	}
};