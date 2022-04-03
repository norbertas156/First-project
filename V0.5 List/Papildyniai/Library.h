#ifndef Library_H_INCLUDE
#define Library_H_INCLUDE



#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <chrono>
#include <random>
#include <sstream>
#include <fstream>
#include <functional>
#include <list>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::sort;
using std::cin;
using std::fixed;
using std::setprecision;
using std::left;
using std::ifstream;
using std::ofstream;
using std::getline;
using std::istringstream;
using std::stringstream;
using std::swap;
using std::setw;
using std::setprecision;
using std::list;
using std::exception;

double VisasLaikas;

struct studentai{
string vardas, pavarde;
float egzaminas;
vector <float>pazymiai;
double vidurkis = 0,mediana = 0;
};

#endif