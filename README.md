# 1-as Laboratorinis darbas
## Objektionio programavimo v0.1 uždutis
Programa,kuri apskaičiuoja studentų vidurkį ir medianą pagal jų namų darbų pažymius ir egzaminą
## Programos veikimas
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
2.1 g++ masyvai.cpp -o masyvai   // jei paleidžiamas failas masyvai.cpp
    g++ vektoriai.cpp vektoriai  // jei paleidžiamas failas vektoriai.cpp
2.2 Tuomet paleisti failą įvedame ./masyvai   // masyvai.cpp faile
                                  ./vektoriai // vektoriai.cpp faile
