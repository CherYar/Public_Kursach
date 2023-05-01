//main
#include "sessia.h"
//#include "menu.h"
#include <windows.h>
using namespace std;


int main() {
SetConsoleCP(1251); SetConsoleOutputCP(1251);
sessia* s = new sessia;
s->makesessia();
s->SessiaToFile("test_sessia.bin");
s->SessiaToFileTXT("test_sessia.txt");
delete s;
sessia s2;
s2.SessiaFromFile("test_sessia.bin");
s2.SessiaToFileTXT("test_sessia2.txt");//Проверка, совместимы ли методы вообще блинб
return 0; 

}