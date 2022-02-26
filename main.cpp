#include "Papildyniai/Library.h"
#include "Papildyniai/Prototipai.h"
#include "Papildyniai/MainPrototipai.h"


int main(){
  char tikrinimas;
  vector <studentai> student;
  cout<<"Ar studentai bus rasomi ranka ar skaitomi is failo ? Iveskite: (i-ivedami, s-skaitomi is failo )"<<endl;
  char raide = RaidesTikrinimas('i','s');
  try{

if(raide == 'i'){
  while(tikrinimas != 'n'){
  studentai stud;
  Ivedimas(stud);
  student.push_back(stud);
  cout<<"Ar dar bus studentu ? Iveskite: (t-taip, n-ne)"<<endl;
  tikrinimas = RaidesTikrinimas('t','n');
  if(tikrinimas == 'n')
  break;
    }
  }
  else if(raide == 's'){
    SkaitymasIsFailo(student);
};


std::sort(student.begin(), student.end(),[](studentai a, studentai b){
  return a.vardas < b.vardas;
  });
    Isvedimas(student);
  } catch(std::exception e)
  {
      cout<<"Ivyko kodo veikimo klaidu"<<endl;
  }
}




