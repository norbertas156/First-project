#include "Library.h"
#include "Prototipai.h"

void PrintToFile(string file_name, std::stringstream& data)
{
    ofstream fr(file_name);
    fr << data.rdbuf();
    fr.close();
}

void IsvedimasIFaila(deque<studentai> & stud, string FileName){


  deque<studentai>::iterator it;

stringstream outputas;
outputas<<std::left << std::setw(20)<< "Vardas";
outputas<<std::left << std::setw(20)<< "Pavarde";
outputas<<std::left << std::setw(20)<< "Galutinis(vid.)";
outputas<<std::left << std::setw(20)<< "Galutinis(Med.)";
outputas<<endl;

for(auto& studentai : stud){
  outputas<<std::left << std::setw(20)<< studentai.vardas;
outputas<<std::left << std::setw(20)<< studentai.pavarde;
outputas<<std::left << std::setw(20)<< studentai.vidurkis;
outputas<<std::left << std::setw(20)<< studentai.mediana;
outputas<<endl;
}

PrintToFile(FileName + ".txt", outputas);
    
}

