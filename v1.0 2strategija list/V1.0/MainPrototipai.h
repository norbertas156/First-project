#ifndef MainPrototipai_H_INCLUDED
#define MainPrototipai_H_INCLUDED

#include "Library.h"
#include "Ivedimai.cpp"
#include "Isvedimas.cpp"


void SkaitymasIsFailo(list<studentai> & stud, string FileName);
void AtsitiktinisFailas(int sk);
void Isvedimas(list<studentai> & stud);
void IsvedimasIFaila(list<studentai> & stud);


#endif