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

void IsvedimasIFaila(vector<studentai> & stud){
  cout<<"Kaip norite matyti rezultata? Iveskite:(v-pagal vidurki, m-pagal mediana, a-pagal abu)"<<endl;
  char rezultatas = RezultatuTikrinimas();
auto start = std::chrono::high_resolution_clock::now(); auto st=start;
  ofstream fr ("Rezultatai.txt");
  int kiekis = stud.size();
  if(rezultatas == 'v'){
    fr<<left<<setw(15)<<"Vardas"<<left<<setw(15)<<"Pavarde"<<left<<setw(15)<<"Galutinis(vid.)"<<endl;
    fr<<"-----------------------------------"<<endl;
    for(int i = 0; i < kiekis; i++){
      if(stud[i].vidurkis > 0){
      fr<<left<<setw(15)<<stud[i].vardas;
    	fr<<left<<setw(15)<<stud[i].pavarde;
	    fr<<left<<setw(15)<<fixed<<setprecision(2)<<stud[i].vidurkis<<endl;
      }
    } 
  }else if(rezultatas == 'm'){
        fr<<left<<setw(15)<<"Vardas"<<left<<setw(15)<<"Pavarde"<<left<<setw(15)<<"Galutinis(med.)"<<endl;
    fr<<"-----------------------------------"<<endl;
    for(int i = 0; i < kiekis; i++){
      if(stud[i].mediana > 0){
      fr<<left<<setw(15)<<stud[i].vardas;
    	fr<<left<<setw(15)<<stud[i].pavarde;
	    fr<<left<<setw(15)<<fixed<<setprecision(2)<<stud[i].mediana<<endl;
      }
    }
  }else if(rezultatas == 'a'){
     fr<<left<<setw(15)<<"Vardas"<<left<<setw(15)<<"Pavarde"<<left<<setw(15)<<"Galutinis(vid.)"<<" / "<<left<<setw(15)<<"Galutinis(med.)"<<endl;
    fr<<"--------------------------------------------------"<<endl;
    for(int i = 0; i < kiekis; i++){
      if(stud[i].mediana > 0 && stud[i].vidurkis > 0){
      fr<<left<<setw(15)<<stud[i].vardas;
    	fr<<left<<setw(15)<<stud[i].pavarde;
	    fr<<left<<setw(15)<<fixed<<setprecision(2)<<stud[i].vidurkis;
      fr<<left<<setw(15)<<fixed<<setprecision(2)<<stud[i].mediana<<endl;
      }
    }
    }
    std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now()-start; // Skirtumas (s)
     std::cout << "Irasymas i faila uztruko: "<< diff.count() << " s\n";
}