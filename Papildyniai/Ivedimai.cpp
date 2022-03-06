#include "Library.h"
#include "Prototipai.h"


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
  std::cout << "Buferio padalijimas i eiluciu vektoriu uztruko: "<< diff.count() << " s\n";
}