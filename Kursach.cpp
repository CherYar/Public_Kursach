//main
//#include "date_name.h"
//#include "sessia_list.h"
#include "student.h"
//#include "stud_list.h"
//#include "menu.h"
//#include "sessia.h"
using namespace std;


int main() {
SetConsoleCP(1251); SetConsoleOutputCP(1251);
/*sessia s;
s.makesessia();
s.SessiaToFile("test_sessia.bin");
s.SessiaToFileTXT("test_sessia.txt");
sessia s2;
s2.SessiaFromFile("test_sessia.bin");
s2.SessiaToFileTXT("test_sessia2.txt");//Проверка, совместимы ли методы вообще блинб
return 0;*/ 
student test;
test.num = "91Ж1337";
test.addfio("Тонус", "Череп", "Кек");
sessia s; //s.SessiaFromFileTXT("test_sessia.txt");
SessionList b; b.addSession(s);
test.prfull();
cout << s;
}