#pragma once
#include "student.h"
//возможно так будет удобнее

student :: void changeinstitut(student& a) { a.uch.institut = ReadStr("Введите название института: ";); }