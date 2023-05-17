//main
//#include "date_name.h"
//#include "sessia_list.h"
//#include "student.h"
//#include "stud_list.h"
#include "menu.h"
//#include "sessia.h"
using namespace std;


int main() {
SetConsoleCP(1251); SetConsoleOutputCP(1251);
sessia t1, t2,t3,t4;
t1.SessiaFromFileTXT("s1.txt");
t3 = t1;
t2.SessiaFromFileTXT("s2.txt");
t4 = t2;
SessionList b; b.addSession(t1); b.addSession(t2); b.addSession(t3); b.addSession(t4);
b.SessionListToFileTXT("l1.txt");
SessionList b2;
b2.SessionListFromFileTXT("l1.txt");
student s, s1, s2;
s.addprog(b); s1.addprog(b2); s2 = s1;
StudentsList a, a1;
a.addStudent(s); a.addStudent(s1); a.addStudent(s2);
a.ListToFileTXT("test_full_list.txt");
a.ListToFileBin("test_full_list1.bin");
//a.printStudent(0); a.printStudent(1); a.printStudent(2); //И даже тут вроде всё норм.
//a1.ListFromFileBin("test_full_list.bin");//Бинарник работает
//a1.printStudent(0); a1.printStudent(1); a1.printStudent(2);// a1.printStudent(1); a1.printStudent(2);
a1.ListFromFileTXT("test_full_list.txt");//Видимо тут у нас и начинаются приколы. Он считывает плохо.
a1.printStudent(0); a1.printStudent(1); a1.printStudent(2);
//splitStudentsByGrades(a, 1984, 2034);
}