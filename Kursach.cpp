//kursach.ccp
#include "menu.h"

int main() {
SetConsoleCP(1251); SetConsoleOutputCP(1251);
if (!SetConsoleCtrlHandler((PHANDLER_ROUTINE)CrashHandler, TRUE)) {
    std::cerr << "Не удалось активировать защиту от нештатного завершения программы." << std::endl;
    return 1;
}
menu();
}