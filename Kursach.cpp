﻿#include "menu.h"

int main() {
SetConsoleCP(1251); SetConsoleOutputCP(1251);
if (!SetConsoleCtrlHandler((PHANDLER_ROUTINE)CrashHandler, TRUE)) {
    std::cerr << "Не удалось активировать защиту от нештатного завершения программы." << std::endl;
    return 1;
}
/*student s;
s.readFromFile("bruh.txt");
StudentsList b;
b.addStudent(s); b.addStudent(s); b.addStudent(s); b.addStudent(s); b.addStudent(s); b.addStudent(s); b.addStudent(s);
b.ListToFile("file.bin");
StudentsList b1; b1.ListFromFile("file.bin");
cout << b1;*/
//menu();
student s1; s1.readFromFile("bruh.txt");
StudentsList b2,b3; b2.addStudent(s1); b2.addStudent(s1); b2.addStudent(s1); b2.addStudent(s1); b2.addStudent(s1);
b2.ListToFile("file.bin");
b2.printAll();
b3.ListFromFile("file.bin");
}