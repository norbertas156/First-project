#ifndef MainPrototipai_H_INCLUDED
#define MainPrototipai_H_INCLUDED

#include "Library.h"
#include "Ivedimai.cpp"
#include "Isvedimas.cpp"


void SkaitymasIsFailo(deque<studentai> & stud, string FileName);
void AtsitiktinisFailas(int sk);
void Isvedimas(deque<studentai> & stud);
void IsvedimasIFaila(deque<studentai> & stud);


#endif