#include "Library.h"


void PrintToFile(string file_name, std::stringstream& data)
{
    ofstream fr(file_name);
    fr << data.rdbuf();
    fr.close();
}



void IsvedimasIFaila(list<studentai> & stud, string FileName){




  list<studentai>::iterator it;

stringstream outputas;
outputas<<std::left << std::setw(20)<< "Vardas";
outputas<<std::left << std::setw(20)<< "Pavarde";
outputas<<std::left << std::setw(20)<< "Galutinis(vid.)";
outputas<<std::left << std::setw(20)<< "Galutinis(Med.)";
outputas<<endl;

for( it=stud.begin() ; it != stud.end(); it++){
  outputas<<std::left << std::setw(20)<< it->vardas;
outputas<<std::left << std::setw(20)<< it->pavarde;
outputas<<std::left << std::setw(20)<< it->vidurkis;
outputas<<std::left << std::setw(20)<< it->mediana;
outputas<<endl;
}

PrintToFile(FileName + ".txt", outputas);
    
}

