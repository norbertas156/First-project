#include "Papildyniai/Library.h"
#include "Papildyniai/Prototipai.h"
#include "Papildyniai/MainPrototipai.h"


int main(){

  list<studentai> student;
  list<studentai> kietekai;
  list<studentai> nelaimingieji;


  char tikrinimas;
  cout<<"Ar studentai bus rasomi ranka ar skaitomi is failo ? Iveskite: (i-ivedami, s-skaitomi is failo )"<<endl;
  char raide = RaidesTikrinimas('i','s');
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
      cout<<"Ar norite, kad studentu failas butu sugeneruotas. Iveskite: (t-taip, n-ne)"<<endl;
      raide = RaidesTikrinimas('t','n');
      if(raide == 'n'){
        SkaitymasIsFailo(student);
      } else{

            cout<<"Iveskite studentu skaiciu"<<endl;
            int sk = SkaiciausTikrinimams();
            AtsitiktinisFailas(sk);
            SkaitymasIsFailo(student);
      }
};


    auto st3 = std::chrono::high_resolution_clock::now();
    Paskirstymas(student,kietekai,nelaimingieji);
    std::chrono::duration<double> df3 = std::chrono::high_resolution_clock::now()-st3;
     std::cout << "Studentu paskirstymas i kietekus ir nelaiminguosisu uztruko: "<< df3.count() << " s\n";


    IsvedimasIFaila(kietekai,"kietekai");
    IsvedimasIFaila(nelaimingieji,"nelaimingieji");


      VisasLaikas += df3.count();
     cout<<"Viso sugaista laiko: "<< VisasLaikas<<endl;

}