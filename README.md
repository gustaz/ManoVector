# ManoVector klasės implementacija

Ši klasė iš esmės yra STL bibliotekoje randamos vector bibliotekos re-implementacija. Perkurtos visos member ir non-member functions, išlaikytas duomenų dinamiškumas, pritaikymas C++11 standartui.

## Ištestuoti metodai

Programoje testuojami penki metodai, pasirinkti pagal jų implementacijos sudėtingumą.

### emplace
Parinktas dėl to, jog turi sudėtingą iteratorinę implementaciją ir buvo introduktuotas C++11 standarte.
### member swap
Parinktas dėl laiko kaštų ir iteratorių validumo, įsitikinama, jog tiek member, tiek non-member funkcijos veikia vienodai.
### non-member swap
Parinktas dėl laiko kaštų ir iteratorių validumo, įsitikinama, jog tiek member, tiek non-member funkcijos veikia vienodai.
### shrink_to_fit
C++11 standarto metodas, turintis kiek sudėtingesnę implementaciją.
### crend
C++11 standarto metodas, gerai ištestuojantis iteratorių veikimą.


## ManoVector klasės palyginimas su STL Vector

| **STL Vector**                              | 10 000    | 100 000 | 1 000 000 | 10 000 000 | 100 000 000 |
| ------------------------------------------- | --------- | ------- | --------- | ---------- | ----------- |
| push_back truko                             | 0.00018s  | 0.0024s | 0.022s    | 0.165s     | 1.752s      |
| Atminties perskirstymų buvo                 | 14        | 17      | 20        | 24         | 27          |

| **ManoVector**                              | 10 000    | 100 000 | 1 000 000 | 10 000 000 | 100 000 000 |
| ------------------------------------------- | --------- | ------- | --------- | ---------- | ----------- |
| push_back truko                             | 0.00017s  | 0.0014s | 0.012s    | 0.160s     | 1.519s      |
| Atminties perskirstymų buvo                 | 13        | 16      | 19        | 23         | 26          |

## Antrosios užduoties re-implementacija naudojant ManoVector

| **STL Vector**                        | 100 000 |
| ------------------------------------- | ------- |
| Bendras vykdymo laikas                | 1.732s  |
| Nuskaitymas                           | 1.120s  |
| Išrūšiavimas                          | 0.407s  |
| Išvedimas                             | 0.204s  |

| **ManoVector**                        | 100 000 |
| ------------------------------------- | ------- |
| Bendras vykdymo laikas                | 52.392s |
| Nuskaitymas                           | 17.225s |
| Išrūšiavimas                          | 8.693s  |
| Išvedimas                             | 26.474s |

Nors ir mano sukurta vector re-implementacija turtinga funkcijomis, jai, panašu, trūksta visų optimizacijos metodų, kurie buvo taikomi kuriant STL Vector, todėl programos vykdymas viską perkonvertavus į ManoVector tapo net **50x** lėtesnis. Pagrindiniai trūkumai matomi skaityme ir rašyme.

