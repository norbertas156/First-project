#include "Library.h"

struct studentai{
string vardas, pavarde;
int pazymiuSk=0;
int egzaminas;
vector <int>pazymiai;
double vidurkis,mediana;
};

double Vidurkis(studentai& A);
void Isvedimas(studentai& A,char rezultatas);
void Ivedimas(studentai& A);
double Mediana(studentai& A);
int SkaiciausTikrinimams();
char RaidesTikrinimas();
char RezultatuTikrinimas();



int main(){
int i = 0;
studentai* stud = new studentai[10];
bool tikr;
while (tikr != 'n')
{
    studentai* a = stud + i;
    Ivedimas(*a);
    cout<<"Ar bus dar studentu ? Iveskite:(t-taip, n-ne)"<<endl;
    i++;
    if(RaidesTikrinimas() == 'n'){
      break;
    }
}
cout<<"Kaip norite matyti rezultata? Iveskite:(v-pagal vidurki, m-pagal mediana, a-pagal abu)"<<endl;
char rezultatas = RezultatuTikrinimas();

if(rezultatas == 'v'){
cout<<left<<setw(10)<<"Vardas"<<left<<setw(15)<<"Pavarde"<<left<<setw(15)<<"Galutinis(vid.)"<<endl;
    cout<<"-----------------------------------"<<endl;
    for (studentai* a = stud; a < stud + i; a++)
    {
      Isvedimas(*a,rezultatas);
    }
    }else if(rezultatas == 'm'){
    cout<<left<<setw(10)<<"Vardas"<<left<<setw(15)<<"Pavarde"<<left<<setw(15)<<"Galutinis(med.)"<<endl;
    cout<<"-----------------------------------"<<endl;
    for (studentai* a = stud; a < stud + i; a++)
    {
      Isvedimas(*a,rezultatas);
    }
    }else if(rezultatas == 'a'){
 cout<<left<<setw(10)<<"Vardas"<<left<<setw(15)<<"Pavarde"<<left<<setw(15)<<"Galutinis(vid.)"<<" / "<<left<<setw(15)<<"Galutinis(med.)"<<endl;
    cout<<"--------------------------------------------------"<<endl;
    for (studentai* a = stud; a < stud + i; a++)
    {
      Isvedimas(*a,rezultatas);
    }
    }
    delete[] stud;

return 0;
}

char RaidesTikrinimas(){
char sk;
cin>>sk;
  while(sk!='t' || sk!='n'){
      if(sk=='t'){
        break;
      }else if(sk=='n'){
        break;
      }else{
        cout<<"Bloga ivestis. Iveskite:(t-taip, n-ne)"<<endl;
        cin>>sk;
      }
  };
  return sk;
}

char RezultatuTikrinimas(){
char sk;
cin>>sk;
  while(sk!='v' || sk!='m'|| sk !='a'){
      if(sk=='v'){
        break;
      }else if(sk=='m'){
        break;
      }else if(sk == 'a'){
        break;
      }else{
        cout<<"Bloga ivestis. Iveskite:(v-pagal vidurki, m-pegalmediana, a-pagal abu)"<<endl;
        cin>>sk;
      }
  };
  return sk;
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

double Vidurkis(studentai& A){
  double vidurkis = 0;
  double galutinis;
  for(int j = 0; j < A.pazymiuSk; j++){
    vidurkis += A.pazymiai[j];
  }
  vidurkis = vidurkis / (A.pazymiuSk);
  galutinis = 0.4*vidurkis + A.egzaminas * 0.6;

  return galutinis;
}

double Mediana(studentai& A){
double mediana;
double galutinis;
std::sort(A.pazymiai.begin(),A.pazymiai.end() );
if((A.pazymiuSk + 1 )% 2 == 0){
  mediana = A.pazymiai[A.pazymiuSk / 2];
}else{
  mediana = (A.pazymiai[A.pazymiuSk / 2 - 1] + A.pazymiai[(A.pazymiuSk / 2 ) ]) /2.0;
}
galutinis = mediana * 0.4 + A.egzaminas * 0.6;

return galutinis;
}

void Ivedimas(studentai& A){
  unsigned seed =std::chrono::system_clock::now().time_since_epoch().count();
	std::mt19937 generator(seed);
	std::uniform_int_distribution<int> distribution(1, 10);
  int kiekis=0;
  cout<<"Iveskite studento varda"<<endl;
  cin>>A.vardas;
  cout<<"Iveskite studento pavarde"<<endl;
  cin>>A.pavarde;
  cout<<"Ar studento pazymiu skaicius yra zinomas ? Iveskite:(t-taip, n-ne)"<<endl;
  char ats = RaidesTikrinimas();
      if(ats=='t'){
        cout<<"Iveskite pazymiu skaiciu"<<endl;
        A.pazymiuSk = SkaiciausTikrinimams();
        cout<<"Ar norite, kad pazymiai ir egzamino pazymys butu sugeneruoti ar rasomi ranka? Ivestike:(t-sugeneruoti, n-ivesti ranka)"<<endl;
        ats = RaidesTikrinimas();
        if(ats == 't'){
          for (int j = 0; j < A.pazymiuSk; j++)
          {
            int pazymys = distribution(generator);
            A.pazymiai.insert(A.pazymiai.begin(), pazymys);
            cout<<j+1<<"-as sugeneruotas pazymys "<<A.pazymiai[0]<<" ; ";
          }
          cout<<endl;
          A.egzaminas=distribution(generator);
          cout<<"Egzamino sugeneruotas pazymys: "<<A.egzaminas<<endl;
        } else if(ats == 'n'){
          for(int j = 0; j < A.pazymiuSk;j++){
          cout<<"Iveskite "<<j+1<< "-a(-i) pazymi:"<<endl;
            A.pazymiai.insert(A.pazymiai.begin(), PazymioTikrinimas());
          }
          cout<<"Iveskite Egzamino rezultata: "<<endl;
          A.egzaminas = PazymioTikrinimas();
        }  
      }
      else if(ats=='n'){
          char paz = 't';
          int kiekis = 0;
        cout<<"Ar norite, kad pazymiai ir egzamino pazymys butu sugeneruoti ar rasomi ranka? Ivestike:(t-sugeneruoti, n-ivesti ranka)"<<endl;
        ats = RaidesTikrinimas();
        if(ats == 't'){
            while(paz != 'n'){
              int pazymys = distribution(generator);
              A.pazymiai.insert(A.pazymiai.begin(),pazymys);
              cout<<kiekis + 1<<"-as sugeneruotas pazymys = "<<A.pazymiai[0]<<endl;
              kiekis++;
              cout<<"Ar norite sugeneruoti dar viena pazymi? Iveskite:(t-taip, n-ne)"<<endl;
              paz = RaidesTikrinimas();
              if(paz == 'n')
              break;
            }
            cout<<"keikis"<<kiekis<<endl;
            A.pazymiuSk = kiekis;
            A.egzaminas=distribution(generator);
          cout<<"Egzamino sugeneruotas pazymys: "<<A.egzaminas<<endl;
        }else if(ats == 'n'){
            while(paz != 'n'){
              cout<<"Ivskite "<<kiekis+1<<"-a(-i) pazymi: "<<endl;
            A.pazymiai.insert(A.pazymiai.begin(),PazymioTikrinimas());
            kiekis++;
            cout<<"Ar norite dar ivesti pazymiu? Iveskite:(t-taip, n-ne)"<<endl;
            paz = RaidesTikrinimas();
            if(paz == 'n')
            break;
            }
            A.pazymiuSk = kiekis;
            cout<<"Iveskite Egzamino rezultata: "<<endl;
            A.egzaminas = PazymioTikrinimas();
        }
        A.pazymiuSk = kiekis;     
      };
       A.vidurkis= Vidurkis(A);
       A.mediana = Mediana(A);
}

void Isvedimas(studentai& A,char rezultatas){
  if(rezultatas == 'v'){
      cout<<left<<setw(10)<<A.vardas;
    	cout<<left<<setw(15)<<A.pavarde;
	    cout<<left<<setw(15)<<fixed<<setprecision(2)<<A.vidurkis<<endl;
    
  }else if(rezultatas == 'm'){
      cout<<left<<setw(10)<<"Vardas"<<left<<setw(15)<<"Pavarde"<<left<<setw(15)<<"Galutinis(med.)"<<endl;
      cout<<"-----------------------------------"<<endl;
      cout<<left<<setw(10)<<A.vardas;
    	cout<<left<<setw(15)<<A.pavarde;
	    cout<<left<<setw(15)<<fixed<<setprecision(2)<<A.mediana<<endl;
  }else if(rezultatas == 'a'){
      cout<<left<<setw(10)<<A.vardas;
    	cout<<left<<setw(15)<<A.pavarde;
	    cout<<left<<setw(15)<<fixed<<setprecision(2)<<A.vidurkis;
      cout<<left<<setw(15)<<fixed<<setprecision(2)<<A.mediana<<endl;
    }
  }

