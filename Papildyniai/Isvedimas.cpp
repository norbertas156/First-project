#include "Library.h"
#include "Prototipai.h"


  void Isvedimas(vector<studentai> & stud){
  int kiekis = stud.size();
  cout<<"Kaip norite matyti rezultata? Iveskite:(v-pagal vidurki, m-pagal mediana, a-pagal abu)"<<endl;
char rezultatas = RezultatuTikrinimas();
  if(rezultatas == 'v'){
    cout<<left<<setw(15)<<"Vardas"<<left<<setw(15)<<"Pavarde"<<left<<setw(15)<<"Galutinis(vid.)"<<endl;
    cout<<"-----------------------------------"<<endl;
    for(int i = 0; i < kiekis; i++){
      if(stud[i].vidurkis > 0){
      cout<<left<<setw(15)<<stud[i].vardas;
    	cout<<left<<setw(15)<<stud[i].pavarde;
	    cout<<left<<setw(15)<<fixed<<setprecision(2)<<stud[i].vidurkis<<endl;
      }
    } 
  }else if(rezultatas == 'm'){
        cout<<left<<setw(15)<<"Vardas"<<left<<setw(15)<<"Pavarde"<<left<<setw(15)<<"Galutinis(med.)"<<endl;
    cout<<"-----------------------------------"<<endl;
    for(int i = 0; i < kiekis; i++){
      if(stud[i].mediana > 0){
      cout<<left<<setw(15)<<stud[i].vardas;
    	cout<<left<<setw(15)<<stud[i].pavarde;
	    cout<<left<<setw(15)<<fixed<<setprecision(2)<<stud[i].mediana<<endl;
      }
    }
  }else if(rezultatas == 'a'){
     cout<<left<<setw(15)<<"Vardas"<<left<<setw(15)<<"Pavarde"<<left<<setw(15)<<"Galutinis(vid.)"<<" / "<<left<<setw(15)<<"Galutinis(med.)"<<endl;
    cout<<"--------------------------------------------------"<<endl;
    for(int i = 0; i < kiekis; i++){
      if(stud[i].mediana > 0 && stud[i].vidurkis > 0){
      cout<<left<<setw(15)<<stud[i].vardas;
    	cout<<left<<setw(15)<<stud[i].pavarde;
	    cout<<left<<setw(15)<<fixed<<setprecision(2)<<stud[i].vidurkis;
      cout<<left<<setw(15)<<fixed<<setprecision(2)<<stud[i].mediana<<endl;
      }
    }
    }

}