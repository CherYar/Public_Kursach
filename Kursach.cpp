#include "menu.h"

int main() {
SetConsoleCP(1251); SetConsoleOutputCP(1251);
if (!SetConsoleCtrlHandler((PHANDLER_ROUTINE)CrashHandler, TRUE)) {
    std::cerr << "Не удалось активировать защиту от нештатного завершения программы." << std::endl;
    return 1;
}
/*student s, s1, s2, s3, s4, s5;
s.readFromFile("bruh.txt");
s1.readFromFile("bruh2.txt");
s2.readFromFile("bruh3.txt");
s3.readFromFileBinary("bruh.bin");
s4.readFromFileBinary("bruh2.bin");
s5.readFromFileBinary("bruh3.bin");
StudentsList a;
a.addStudent(s);
a.addStudent(s1);
a.addStudent(s2);
a.addStudent(s3);
a.addStudent(s4);
a.addStudent(s5);
a.ListToFileBin("file.bin");*/
menu();

}