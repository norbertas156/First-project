#include "Papildyniai/Library.h"
#include "Papildyniai/Prototipai.h"
#include "Papildyniai/MainPrototipai.h"


int main(){

  vector <studentai> student;
  vector <studentai> kietekai;
  vector <studentai> nelaimingieji;

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
            auto st1 = std::chrono::high_resolution_clock::now();
            AtsitiktinisFailas(sk);
            std::chrono::duration<double> df1 = std::chrono::high_resolution_clock::now()-st1;
            std::cout << "Failo sugeneravimas uzruko: "<< df1.count() << " s\n";  
            VisasLaikas += df1.count(); 
      }
    SkaitymasIsFailo(student);
};

// auto st2 = std::chrono::high_resolution_clock::now();
// std::sort(student.begin(), student.end(),[](studentai a, studentai b){
//   return a.vardas < b.vardas;
//   });
//   std::chrono::duration<double> df2 = std::chrono::high_resolution_clock::now()-st2; // Skirtumas (s)
//   std::cout << "Failo surusiavimas uzruko: "<< df2.count() << " s\n";

    auto st3 = std::chrono::high_resolution_clock::now();
    Paskirstymas(student,kietekai,nelaimingieji);
    std::chrono::duration<double> df3 = std::chrono::high_resolution_clock::now()-st3; // Skirtumas (s)
     std::cout << "Studentu paskirstymas i kietekus ir nelaiminguosisu uztruko: "<< df3.count() << " s\n";

    auto st4 = std::chrono::high_resolution_clock::now();
    IsvedimasIFaila(kietekai,"kietekai");
    IsvedimasIFaila(nelaimingieji,"nelaimingieji");
    std::chrono::duration<double> df4 = std::chrono::high_resolution_clock::now()-st4; // Skirtumas (s)
     std::cout << "Studentu surasymas i atskirus failus uztruko: "<< df4.count() << " s\n";

      VisasLaikas = df3.count() + df4.count();
     cout<<"Viso sugaista laiko: "<< VisasLaikas<<endl;

}