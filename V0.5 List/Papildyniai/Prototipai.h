#ifndef Prototipai_H_INCLUDED
#define Prototipai_H_INCLUDED

#include "Library.h"
#include "Tikrinimai.cpp"
#include "VidMed.cpp"

double Vidurkis(studentai & stud);
double Mediana(studentai& stud);
char RaidesTikrinimas(char x, char y);
int SkaiciausTikrinimams();
int PazymioTikrinimas();
void SkaitymasIsFailo();
void Paskirstymas (list<studentai> &student, list<studentai> &kietekai, list<studentai> &nelaimingieji);

#endif