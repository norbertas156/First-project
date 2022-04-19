# 1-as Laboratorinis darbas
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
## Objektinio programavimo v0.4 užduotis
1. Implementuota galimybė sugeneruoti studentų failus
2. Implementuotas studentų išskirtymas į kietekus ir nelaiminguosius
3. Idiegta laiko matavimai programos veikimui apskaičiuoti
4. Prie failų įkeltos nuotraukos, kaip programa veikia skirtingai nuo studentų skaičiaus
## Objektinio programavimo v0.5 užduotis
1. Sukurti papildomi du projektai, kuriuose vietoj Vector yra naudojama Deque ir List
2. Projektuose nuimti nereikalingi matavimai
3. Palikti tik failo nuskaitymas ir suskirstymas į Kietekus ir nelaiminguosius
## Kompiuterio parametrai:
1. CPU Intel Core i7-4720HQ
2. RAM 16Gb DDR3 1600MHz
3. SSD CT500MX
## Rezultatai:
### List
1. 1000 studentu - Duomenu nuskaitymas is failo: 0.0042056 s
2. 10000 studentu - Duomenu nuskaitymas is failo: 0.0447653s / Studentu paskirstymas i kietekus ir nelaiminguosisu uztruko: 0.0073578s / Viso sugaista laiko: 0.0521231
3. 100000 studentu - Duomenu nuskaitymas is failo: 0.288472s / Studentu paskirstymas i kietekus ir nelaiminguosisu uztruko: 0.0642274s / Viso sugaista laiko: 0.352699
4. 1000000 studentu - Duomenu nuskaitymas is failo: 2.3069s / Studentu paskirstymas i kietekus ir nelaiminguosisu uztruko: 0.647582s / Viso sugaista laiko: 2.95449
5. 10000000 studentu -Duomenu nuskaitymas is failo: 3.30988s / Studentu paskirstymas i kietekus ir nelaiminguosisu uztruko: 0.899878s / Viso sugaista laiko: 4.20976
### Deque
1. 1000 studentu - Duomenu nuskaitymas is failo: 0s / Studentu paskirstymas i kietekus ir nelaiminguosisu uztruko: 0.008225s / Viso sugaista laiko: 0.008225
2. 10000 studentu - Duomenu nuskaitymas is failo: 0.0401088s / Studentu paskirstymas i kietekus ir nelaiminguosisu uztruko: 0s / Viso sugaista laiko: 0.0401088
3. 100000 studentu - Duomenu nuskaitymas is failo: 0.294101s / Studentu paskirstymas i kietekus ir nelaiminguosisu uztruko: 0.0423433s / Viso sugaista laiko: 0.336445
4. 1000000 studentu - Duomenu nuskaitymas is failo: 5.62935s / Studentu paskirstymas i kietekus ir nelaiminguosisu uztruko: 0.95156s / Viso sugaista laiko: 6.58091
5. 10000000 studentu - Duomenu nuskaitymas is failo: 47.8196s / Studentu paskirstymas i kietekus ir nelaiminguosisu uztruko: 5.50122s / Viso sugaista laiko: 53.3208
### Vector
1. 1000 studentu - Duomenu nuskaitymas is failo: 0s / Studentu paskirstymas i kietekus ir nelaiminguosisu uztruko: 0s / Viso sugaista laiko: 0
2. 10000 studentu - Duomenu nuskaitymas is failo: 0.0946022 s / Studentu paskirstymas i kietekus ir nelaiminguosisu uztruko: 0.0088725 s / Viso sugaista laiko: 0.103475
3. 100000 studentu - Duomenu nuskaitymas is failo: 0.733248s / Studentu paskirstymas i kietekus ir nelaiminguosisu uztruko: 0.0639959s / Viso sugaista laiko: 0.797244
4. 1000000 studentu - Duomenu nuskaitymas is failo: 3.83374s / Studentu paskirstymas i kietekus ir nelaiminguosisu uztruko: 0.566098s / Viso sugaista laiko: 4.39984
5. 10000000 studentu - Duomenu nuskaitymas is failo: 40.8572s / Studentu paskirstymas i kietekus ir nelaiminguosisu uztruko: 4.0638 s / Viso sugaista laiko: 44.921
## Objektinio programavimo v1.0 užduotis
1. Užduotyje implementuota 2 strategija
2. Ši strategija paskirstymą į kietekus ir nelaiminguosius apdorojo greičiau nei pirma strategija
3. Sukurtas make failas
### Rezultatai
#### 1 strategijos rezultatai
##### List
| Dydis                 |     1000     |    10000   |    100000   |  1000000  |  10000000 |
|-----------------------|--------------|------------|-------------|-----------|-----------|
| Duomenų nuskaitymas   |  0.0049962 s | 0.040975 s | 0.0410081 s | 2.24283 s | 26.4953 s |
| Paskirstymas į grupes |      0 s     | 0.0049974 s| 0.0039971 s | 0.419751 s| 4.07016 s |
##### Vector
| Dydis                 |     1000    |    10000    |   100000   |  1000000   |  10000000 |
|-----------------------|-------------|-------------|------------|-----------|------------|
| Duomenų nuskaitymas   | 0.0060019 s | 0.0479712 s | 0.326681 s | 2.35484 s  | 25.6369 s |
| Paskirstymas į grupes |     0 s     | 0.0043053 s | 0.0329817 s| 0.444055 s | 2.80435 s |
##### Deque
| Dydis                 |     1000    |    10000    |   100000   |   1000000  |  10000000 |
|-----------------------|-------------|-------------|------------|------------|-----------|
| Duomenų nuskaitymas   | 0.0059952 s | 0.0359881 s | 0.307366 s | 2.11982 s  | 26.4953 s |
| Paskirstymas į grupes | 0.0009987 s | 0.0030194 s | 0.0419739 s| 0.406783 s | 4.07016 s |
#### 2 strategija (+optimizuotai)
##### List
| Dydis                 |     1000    |    10000    |    100000   |   1000000  |  10000000 |
|-----------------------|-------------|-------------|-------------|------------|-----------|
| Duomenų nuskaitymas   | 0.0049962 s | 0.0239871 s | 0.497723 s  | 2.35505 s  | 22.9561 s |
| Paskirstymas į grupes |     0 s     | 0.0039988 s | 0.0039253 s | 0.413997 s | 3.98719 s |
##### Vector
| Dydis                 |    1000    |    10000    |    100000   |  1000000   |  10000000 |
|-----------------------|------------|-------------|-------------|------------|-----------|
| Duomenų nuskaitymas   | 0.006982 s | 0.0549687 s | 0.231862 s  | 2.12901 s  | 22.2613 s |
| Paskirstymas į grupes |     0 s    | 0.0039984 s | 0.0254955 s | 0.275081 s | 2.42888 s |
##### Deque
| Dydis                 |     1000    |    10000    |   100000   |   1000000  |  10000000 |
|-----------------------|-------------|-------------|------------|------------|-----------|
| Duomenų nuskaitymas   | 0.0053445 s | 0.0219878 s | 0.342888 s | 2.05666 s  | 21.3296 s |
| Paskirstymas į grupes |     0 s     | 0.0019979 s | 0.02799 s  | 0.273129 s | 2.88583 s |
