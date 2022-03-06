#include "Library.h"

struct studentai{
string vardas, pavarde;
int egzaminas;
vector <int>pazymiai;
double vidurkis,mediana;
};

char RaidesTikrinimas(char x, char y);
void Ivedimas(studentai & stud);
void Isvedimas(vector<studentai> & stud);
int SkaiciausTikrinimams();
int PazymioTikrinimas();


int main(){
  char tikrinimas;
  vector <studentai> student;


  while(tikrinimas != 'n'){
  studentai stud;
  Ivedimas(stud);
  student.push_back(stud);
  cout<<"Ar dar bus studentu ? Iveskite: (t-taip, n-ne)"<<endl;
  tikrinimas = RaidesTikrinimas('t','n');
  if(tikrinimas == 'n')
  break;
  }
    Isvedimas(student);
}

char RezultatuTikrinimas(){
char r;
cin>>r;
  while(r!='v' || r!='m'|| r !='a'){
      if(r=='v'){
        break;
      }else if(r=='m'){
        break;
      }else if(r == 'a'){
        break;
      }else{
        cout<<"Bloga ivestis. Iveskite:(v-pagal vidurki, m-pegalmediana, a-pagal abu)"<<endl;
        cin>>r;
      }
  };
  return r;
}

char RaidesTikrinimas(char x, char y){
char raide;
cin>>raide;
  while(raide!=x || raide!=y){
      if(raide==x){
        break;
      }else if(raide==y){
        break;
      }else{
        cout<<"Bloga ivestis. Iveskite:("<<x<<" arba "<<y<<endl;
        cin>>raide;
      }
  };
  return raide;
}

int SkaiciausTikrinimams(){
  int sk;
  cin>>sk;
  while (sk < 0 || isdigit(sk)==false)
  {
    if(sk > 0 || isdigit(sk)==true){
      break;
    }else{
    cin.clear();
    cin.ignore();
    cout<<"Bloga ivestis. Iveskite skaiciu, kuris butu didesnis uz 0:"<<endl;
    cin>>sk;
    }
  };
  return sk;
}

int PazymioTikrinimas(){
  int paz;
  cin>>paz;
  while (paz < 0 || paz > 10)
  {
    if (paz > 0 && paz <= 10)
    {
      break;
    }else{
      cout<<"Iveskite skaiciu nuo 1 iki 10"<<endl;
      cin>>paz;
    }   
  }
  return paz;
}
double Vidurkis(studentai & stud, int pazymiuSk){
  double vidurkis = 0;
  double galutinis;
  for(int j = 0; j < pazymiuSk; j++){
    vidurkis += stud.pazymiai[j];
  }
  vidurkis = vidurkis / (pazymiuSk);
  galutinis = 0.4*vidurkis + stud.egzaminas * 0.6;

  return galutinis;
}

double Mediana(studentai& stud, int pazymiuSk){
double mediana;
double galutinis;
std::sort(stud.pazymiai.begin(),stud.pazymiai.end() );
if((pazymiuSk + 1 )% 2 == 0){
  mediana = stud.pazymiai[pazymiuSk / 2];
}else{
  mediana = (stud.pazymiai[pazymiuSk / 2 - 1] + stud.pazymiai[(pazymiuSk / 2 ) ]) /2.0;
}
galutinis = mediana * 0.4 + stud.egzaminas * 0.6;

return galutinis;
}




void Ivedimas(studentai & stud){

  unsigned seed =std::chrono::system_clock::now().time_since_epoch().count();
	std::mt19937 generator(seed);
	std::uniform_int_distribution<int> distribution(1, 10);
  int kiekis=0;
  int pazymiuSk;
  cout<<"Iveskite studento varda"<<endl;
  cin>>stud.vardas;
  cout<<"Iveskite studento pavarde"<<endl;
  cin>>stud.pavarde;
  cout<<"Ar studento pazymiu skaicius yra zinomas ? Iveskite:(t-taip, n-ne)"<<endl;
  char ats = RaidesTikrinimas('t','n');
      if(ats=='t'){
        cout<<"Iveskite pazymiu skaiciu"<<endl;
        pazymiuSk = SkaiciausTikrinimams();
        cout<<"Ar norite, kad pazymiai ir egzamino pazymys butu sugeneruoti ar rasomi ranka? Ivestike:(t-sugeneruoti, n-ivesti ranka)"<<endl;
        ats = RaidesTikrinimas('t','n');
        if(ats == 't'){
          for (int j = 0; j < pazymiuSk; j++)
          {
            int pazymys = distribution(generator);
            stud.pazymiai.insert(stud.pazymiai.begin(), pazymys);
            cout<<j+1<<"-as sugeneruotas pazymys "<<stud.pazymiai[0]<<" ; ";
          }
          cout<<endl;
          stud.egzaminas=distribution(generator);
          cout<<"Egzamino sugeneruotas pazymys: "<<stud.egzaminas<<endl;
        } else if(ats == 'n'){
          for(int j = 0; j < pazymiuSk;j++){
          cout<<"Iveskite "<<j+1<< "-a(-i) pazymi:"<<endl;
            stud.pazymiai.insert(stud.pazymiai.begin(), PazymioTikrinimas());
          }
          cout<<"Iveskite Egzamino rezultata: "<<endl;
          stud.egzaminas = PazymioTikrinimas();
        }  
      }
      else if(ats=='n'){
          char paz = 't';
          int kiekis = 0;
        cout<<"Ar norite, kad pazymiai ir egzamino pazymys butu sugeneruoti ar rasomi ranka? Ivestike:(t-sugeneruoti, n-ivesti ranka)"<<endl;
        ats = RaidesTikrinimas('t','n');
        if(ats == 't'){
            while(paz != 'n'){
              int pazymys = distribution(generator);
              stud.pazymiai.insert(stud.pazymiai.begin(),pazymys);
              cout<<kiekis + 1<<"-as sugeneruotas pazymys = "<<stud.pazymiai[0]<<endl;
              kiekis++;
              cout<<"Ar norite sugeneruoti dar viena pazymi? Iveskite:(t-taip, n-ne)"<<endl;
              paz = RaidesTikrinimas('t','n');
              if(paz == 'n')
              break;
            }
            pazymiuSk = kiekis;
            stud.egzaminas=distribution(generator);
          cout<<"Egzamino sugeneruotas pazymys: "<<stud.egzaminas<<endl;
        }else if(ats == 'n'){
            while(paz != 'n'){
              cout<<"Ivskite "<<kiekis+1<<"-a(-i) pazymi: "<<endl;
            stud.pazymiai.insert(stud.pazymiai.begin(),PazymioTikrinimas());
            kiekis++;
            cout<<"Ar norite dar ivesti pazymiu? Iveskite:(t-taip, n-ne)"<<endl;
            paz = RaidesTikrinimas('t','n');
            if(paz == 'n')
            break;
            }
            pazymiuSk = kiekis;
            cout<<"Iveskite Egzamino rezultata: "<<endl;
            stud.egzaminas = PazymioTikrinimas();
        }
        pazymiuSk = kiekis;     
      };
       stud.vidurkis= Vidurkis(stud,pazymiuSk);
       stud.mediana = Mediana(stud,pazymiuSk);

}

void Isvedimas(vector<studentai> & stud){
  int kiekis = stud.size();
  cout<<"Kaip norite matyti rezultata? Iveskite:(v-pagal vidurki, m-pagal mediana, a-pagal abu)"<<endl;
char rezultatas = RezultatuTikrinimas();
  if(rezultatas == 'v'){
    cout<<left<<setw(15)<<"Vardas"<<left<<setw(15)<<"Pavarde"<<left<<setw(15)<<"Galutinis(vid.)"<<endl;
    cout<<"-----------------------------------"<<endl;
    for(int i = 0; i < kiekis; i++){
      cout<<left<<setw(15)<<stud[i].vardas;
    	cout<<left<<setw(15)<<stud[i].pavarde;
	    cout<<left<<setw(15)<<fixed<<setprecision(2)<<stud[i].vidurkis<<endl;
    } 
  }else if(rezultatas == 'm'){
        cout<<left<<setw(15)<<"Vardas"<<left<<setw(15)<<"Pavarde"<<left<<setw(15)<<"Galutinis(med.)"<<endl;
    cout<<"-----------------------------------"<<endl;
    for(int i = 0; i < kiekis; i++){
      cout<<left<<setw(15)<<stud[i].vardas;
    	cout<<left<<setw(15)<<stud[i].pavarde;
	    cout<<left<<setw(15)<<fixed<<setprecision(2)<<stud[i].mediana<<endl;
    }
  }else if(rezultatas == 'a'){
     cout<<left<<setw(15)<<"Vardas"<<left<<setw(15)<<"Pavarde"<<left<<setw(15)<<"Galutinis(vid.)"<<" / "<<left<<setw(15)<<"Galutinis(med.)"<<endl;
    cout<<"--------------------------------------------------"<<endl;
    for(int i = 0; i < kiekis; i++){
      cout<<left<<setw(15)<<stud[i].vardas;
    	cout<<left<<setw(15)<<stud[i].pavarde;
	    cout<<left<<setw(15)<<fixed<<setprecision(2)<<stud[i].vidurkis;
      cout<<left<<setw(15)<<fixed<<setprecision(2)<<stud[i].mediana<<endl;
    }
    }

}