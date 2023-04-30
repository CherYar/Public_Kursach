//main
#include "sessia.h"
#include "menu.h"
#include <windows.h>
using namespace std;


int main() {
SetConsoleCP(1251); SetConsoleOutputCP(1251);
sessia* s = new sessia;
s->makesessia();
s->SessiaToFile("testing.bin");
delete s;
return 0; 

}