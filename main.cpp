#include "Library.h"

struct studentai{
string vardas, pavarde;
float egzaminas;
vector <float>pazymiai;
double vidurkis = 0, mediana = 0;
};

void Ivedimas(studentai & stud);
void SkaitymasIsFailo(vector<studentai> & stud);
void Isvedimas(vector<studentai> & stud);
void IsvedimasIFaila(vector<studentai> & stud);
double Vidurkis(studentai & stud);
double Mediana(studentai& stud);
char RaidesTikrinimas(char x, char y);
int SkaiciausTikrinimams();
int PazymioTikrinimas();
void SkaitymasIsFailo();


int main(){
  char tikrinimas;
  vector <studentai> student;
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
        cout<<"Bloga ivestis. Iveskite:("<<x<<" arba "<<y<<")"<<endl;
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
            cout<<"Iveskite Egzamino rezultata: "<<endl;
            stud.egzaminas = PazymioTikrinimas();
        }    
      };
       stud.vidurkis= Vidurkis(stud);
       stud.mediana = Mediana(stud);

}

void SkaitymasIsFailo(vector<studentai> & stud){
  bool good = false;
  cout<<"Iveskite failo pavadinima (be .txt)"<<endl;
  string line;
  string FailoPav;
  int paz;
  stringstream buf;
  cin>>FailoPav;
    auto start = std::chrono::high_resolution_clock::now(); auto st=start;
  while(!good){
    ifstream fs(FailoPav+".txt");
  if(fs.good()){
     buf<<fs.rdbuf();
     fs.close();
    break;
  }
    else{
      cout<<"Tokio failo nera, iveskite egzistuojanti faila"<<endl;
      cin>>FailoPav;
    }
  }
     std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now()-start; // Skirtumas (s)
     std::cout << "Failo nuskaitymas i buferi uztruko: "<< diff.count() << " s\n";
  
  getline(buf, line);

  studentai student;
  int klaida = 0;  // Bus skaiciuojama, kurioje eilute gali buti klaida
  while(getline(buf, line)){
    bool error = false;
    istringstream sk(line);
    sk>>student.vardas>>student.pavarde;
          while (sk>>paz)
          {
            klaida++;
            if(paz>=1 && paz<=10){
              student.pazymiai.push_back(paz);
            }else{
              error = true;
              break;
            }
          }
      if(error){
        cout<<klaida<<" eilute yra blogai suvesti pazymiai"<<endl;
      }else{
        student.pazymiai.pop_back();
        student.egzaminas = paz;
        student.vidurkis= Vidurkis(student);
       student.mediana = Mediana(student);
       student.pazymiai.clear();
        stud.push_back(student);
      }        
  }
  diff = std::chrono::high_resolution_clock::now()-start; // Skirtumas (s)
  std::cout << "Buferio padalijimas i eilučiu vektoriu uztruko: "<< diff.count() << " s\n";
}

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