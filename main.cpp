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
  cout<<"Kaip noretumete kad butu isvestas rezultatas? Iveskite(f-i faila, k-i komandine eilute)"<<endl;
  raide = RaidesTikrinimas('k','f');
  if(raide == 'k')
  {
    Isvedimas(student);
  } else{
    IsvedimasIFaila(student);
  }
  } catch(std::exception& e){
    std::cerr<<e.what()<<endl;
  }
}




