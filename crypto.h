#pragma once
#include <iostream>
#include <windows.h>
#include <string>
#include <time.h>
#include <fstream>
using namespace std;

void Crypt()
{
	srand(time(NULL));
	string pass;
	for (int i = 0; i < 128; i++) {
		switch (rand() % 3) {
		case 0:
			pass += rand() % 10 + '0';
			break;
		case 1:
			pass+= rand() % 26 + 'A';
			break;
		case 2:
			pass+= rand() % 26 + 'a';
		}
	}
	string command = "openssl\\bin\\openssl.exe enc -aes-256-cbc -salt -in file.bin -out file.bin.enc -pass pass:";
	command += pass;
	system(command.c_str());
	if (remove("file.bin") != 0) {
		cout << "[ERROR] - ошибка удаления файла" << endl;
	}
	ofstream file;
	file.open("key.bin", ios::binary);
	file << pass;
	file.close();
	command = "openssl\\bin\\openssl.exe rsautl -encrypt -inkey rsa.public -pubin -in key.bin -out key.bin.enc";
	system(command.c_str());
	if (remove("key.bin") != 0) {
		cout << "[ERROR] - ошибка удаления файла" << endl;
	}
}
void Decrypt()
{
	string command = "openssl\\bin\\openssl.exe rsautl -decrypt -inkey rsa.private -in key.bin.enc -out key.bin";
	system(command.c_str());
	if (remove("key.bin.enc") != 0) {
		cout << "[ERROR] - ошибка удаления файла" << endl;
	}
	string pass;
	ifstream file;
	file.open("key.bin", ios::binary);
	file >> pass;
	file.close();
	if (remove("key.bin") != 0) {
		cout << "[ERROR] - ошибка удаления файла" << endl;
	}
	command = "openssl\\bin\\openssl.exe enc -aes-256-cbc -d -in file.bin.enc -out file.bin -pass pass:";
	command += pass;
	system(command.c_str());
	if (remove("file.bin.enc") != 0) {
		cout << "[ERROR] - ошибка удаления файла" << endl;
	}
}