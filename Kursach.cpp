#include "menu.h"

int main() {
SetConsoleCP(1251); SetConsoleOutputCP(1251);
if (!SetConsoleCtrlHandler((PHANDLER_ROUTINE)CrashHandler, TRUE)) {
    std::cerr << "Не удалось активировать защиту от нештатного завершения программы." << std::endl;
    return 1;
}
student s1, s2; //s1.makestudent(); s1.writeToFile("student1.txt");
//s1.prfull();
cout <<"\n\n\n";
s2.readFromFile("student9.txt");
s2.prfull();
system("pause");
}