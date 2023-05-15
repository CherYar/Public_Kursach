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
/*student test;
test.num = "91Ж1337";
test.addfio("АААААААААа", "ббббббббббБББ", "ВВввв");
sessia s, s1;
s.SessiaFromFileTXT("test_sessia_mk2.txt"); s1.SessiaFromFileTXT("test2.txt");
SessionList b; b.addSession(s); b.addSession(s1);
test.addprog(b);
test.prfull();
test.makestudent();
test.prfull();
//system("pause");
//test.makestudent();
//test.prfull();
*/
sessia t, t1, t2,t3,t4;
//t.makesessia();
//t.SessiaToFileTXT("s1.txt");
t1.SessiaFromFileTXT("s1.txt");
t2 = t4 = t1;
t3.SessiaFromFileTXT("s2.txt");
SessionList b; b.addSession(t1); b.addSession(t2); b.addSession(t3); b.addSession(t4);
b.SessionListToFileTXT("l1.txt");
SessionList b2;
b2.SessionListFromFileTXT("l1.txt");
student s, s1, s2;
s.addprog(b); s1.addprog(b2); s2 = s1;
StudentsList a;
a.addStudent(s); a.addStudent(s1); a.addStudent(s2);
a.writeToFile("test_full_list.txt");
a.writeToFileBinary("test_full_list1.bin");
s.prfull(); s1.prfull(); s2.prfull();
//StudentsList a1("test_full_list1.bin");
splitStudentsByGrades(a, 1984, 2034);
// for (int i = 0; i < 3; i++) { a.printStudent(i); }
}