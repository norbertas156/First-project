#include "Library.h"
#include "Prototipai.h"


double Vidurkis(studentai & stud){
  double vidurkis = 0;
  double galutinis;
  int pazymiuSk = stud.pazymiai.size();
  for(int j = 0; j < pazymiuSk; j++){
    vidurkis += stud.pazymiai[j];
  }
  vidurkis = vidurkis / (pazymiuSk);
  galutinis = 0.4*vidurkis + stud.egzaminas * 0.6;

  return galutinis;
}

double Mediana(studentai& stud){
double mediana;
double galutinis;
int pazymiuSk = stud.pazymiai.size();
std::sort(stud.pazymiai.begin(),stud.pazymiai.end() );
if((pazymiuSk + 1 )% 2 == 0){
  mediana = stud.pazymiai[pazymiuSk / 2];
}else{
  mediana = (stud.pazymiai[pazymiuSk / 2 - 1] + stud.pazymiai[(pazymiuSk / 2 ) ]) /2.0;
}
galutinis = mediana * 0.4 + stud.egzaminas * 0.6;

return galutinis;
}

void Paskirstymas (deque<studentai> &student, deque<studentai> &kietekai, deque<studentai> &nelaimingieji){

int StudentuSk = student.size();
  for(int i=0; i<StudentuSk; i++){
	  if(student[i].vidurkis>=5.00 || student[i].mediana>= 5.00){
		  kietekai.push_back(student[i]);
	  }
	  else {
		  nelaimingieji.push_back(student[i]);
	  }
  }
  student.clear();
}