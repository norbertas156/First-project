# 1-as Laboratorinis darbas
## Objektionio programavimo v0.1 uždutis
Programa,kuri apskaičiuoja studentų vidurkį ir medianą pagal jų namų darbų pažymius ir egzaminą
# Programos veikimas
1. Pirmiausia vartotojas įveda studento vardą ir pavardę
2. Pasirenkama ar studento pažymiai yra žinomi ar ne
3. Tada įvedami studento pažymiai ir egzamino rezultatas arba pasirenkama, jog programa pati sugeneruotų pažymius ir egzamino pažymį
4. Galiausiai pasirenkama ar norite matyti rezultatų lentelę pagal apskaičiuotą vidurkį, medianą arba pagal abu metodus
## Programos realizavimas
Uždavinys buvo realizuotas dviem metodais, kai studento duomenys buvo saugomi masyve, kituatveju vektoriuje
## Programos paleidimas
Programa buvo realizuota VS Code platformoje, todėl paleidimas yra toks:
1. Pirmiausia atsisiunčiamas failas(-ai) su Library.h failu
2. Tada komandinė eilutėje suvedama
3. g++ masyvai.cpp -o masyvai   // jei paleidžiamas failas masyvai.cpp
4. g++ vektoriai.cpp vektoriai  // jei paleidžiamas failas vektoriai.cpp
5. Tuomet paleisti failą įvedame ./masyvai   // masyvai.cpp faile
6. ./vektoriai // vektoriai.cpp faile
## Objektionio programavimo v0.2 uždutis
1. Programoje neliko duomenų įrašimų į masayvus
2. Idėta galimybė duomenis nuskaityti iš failo ir juos apdorojos įrašyti į failą
3. Implementuota funkcija studentus išrykiuoti pagal vardus.
## Objektionio programavimo v0.3 uždutis
1. Failų prototipai ir funkcijos išskaidytos į atskirus failus
2. Implementuotas Exception Handling
