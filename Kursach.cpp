//main
//#include "date_name.h"
//#include "sessia_list.h"
#include "student.h"
//#include "stud_list.h"
#include "menu.h"
//#include "sessia.h"
using namespace std;


int main() {
SetConsoleCP(1251); SetConsoleOutputCP(1251);
student test;
test.num = "91Ж1337";
test.addfio("АААААААААа", "ббббббббббБББ", "ВВввв");
sessia s, s1;
s.SessiaFromFileTXT("test_sessia_mk2.txt"); s1.SessiaFromFileTXT("test2.txt");
SessionList b; b.addSession(s); b.addSession(s1);
test.addprog(b);
test.prfull();
menu();
}