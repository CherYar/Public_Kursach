//main
//#include "date_name.h"
//#include "sessia_list.h"
//#include "student.h"
#include "stud_list.h"
//#include "menu.h"
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
StudentsList a, a1,a2;
a.addStudent(s); a.addStudent(s1); a.addStudent(s2);
a.ListToFileBin("test_full_list1.bin");
s.writeToFile("bruh.txt");
s1.writeToFile("bruh2.txt");
s2.writeToFile("bruh3.txt");
s.writeToFileBinary("bruh.bin");
s1.writeToFileBinary("bruh2.bin");
s2.writeToFileBinary("bruh3.bin");
student st, st1, st2, sb,sb1,sb2;
st.readFromFile("bruh.txt");
st1.readFromFile("bruh2.txt");
st2.readFromFile("bruh3.txt");
sb.readFromFileBinary("bruh.bin");
sb1.readFromFileBinary("bruh2.bin");
sb2.readFromFileBinary("bruh3.bin");
a1.addStudent(st); a1.addStudent(st1); a1.addStudent(st2); a1.addStudent(sb); a1.addStudent(sb1); a1.addStudent(sb2);
//a1.printStudent(0); a1.printStudent(1); a1.printStudent(2); a1.printStudent(3); a1.printStudent(4); a1.printStudent(5); a1.printStudent(6); a1.printStudent(7);
a2.ListFromFileBin("file.bin");
//a2.printMNOGO();
//a2.printAll();
//splitStudentsByGrades(a, 0, 9999);
//a2.prbasic(0);
//a2.printStudent(0);
//Decrypt();
//a.printStudent(0); a.printStudent(1); a.printStudent(2); //И даже тут вроде всё норм.
//a1.ListFromFileBin("test_full_list.bin");//Бинарник работает
//a1.printStudent(0); a1.printStudent(1); a1.printStudent(2);// a1.printStudent(1); a1.printStudent(2);
//a1.ListFromFileBin("test_full_list1.bin");
//a1.printStudent(0); a1.printStudent(1); a1.printStudent(2); a1.printStudent(3); a1.printStudent(4);
//splitStudentsByGrades(a, 1984, 2034);
}