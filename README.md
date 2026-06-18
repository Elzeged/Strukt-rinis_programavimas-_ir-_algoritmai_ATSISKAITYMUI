
Kompiuterinių žaidimų katalogas

PROJEKTO TIKSLAS
Sukurti c++ konsolinę programą, kuri leidžia valdyti kompiuterinių žaidimų katalogą. Rašant programą buvo naudojami struktūrinio programavimo principai: funkcijos, masyvai, struktūra, ciklai, sąlyginiai sakiniai ir darbas su tekstiniu failu.

PASIRINKTOS TEMOS APRAŠYMAS
Tema - kompiuterinių žaidimų katalogas. Programoje yra saugoma informacija apie kompiuterinius žaidimus: žaidimo ID, pavadinimas, žanras, išleidimo metai ir įvertinimas.
Pasirinkta tema leidžia patogiai pritaikyti CRUD operacijas ir papildomas duomenų paribojimo funkcijas, tokias kaip paieška, rikiavimas, bei statistikos skaičiavimą.

PROGRAMINIO FUNKCIONALUMO APRAŠYMAS

Programoje galima atlikti šiuos veiksmus:

Peržiūrėti visus žaidimus,
Pridėti naują žaidimą,
Redaguoti esamo žaidimo informaciją,
Ištrinti žaidimą pagal jo ID,
Ieškoti žaidimų pagal žanrą,
Ieškoti žaidimų pagal pavadinimą ar jo dalį,
Rikiuoti žaidimus pagal įvertinimą nuo geriausio iki blogiausio,
Peržiūrėti statistiką,
išsaugoti duomenis į tekstinį failą,
Atstatyti žaidimų sąrašą į pradinę tvarką iš failo.

CRUD funkcionalumas

Programoje yra pritaikytos visos CRUS operacijos

Create - naujo žaidimo pridėjimas
Read - visų žaidimų peržiūra
Update - žaidimo informacijos redagavimas pagal ID
Delate - žaidimo ištrynimas pagal ID

NAUDOJAMI FAILAI
Kompiuteriniu_zaidimų_katalogas_projektas.cpp - pagrindinis proramos kodas.
zaidimu_duomenys.txt - tekstinis duomenų failas, kuriame yra saugomi žaidimų įrašai.
README.md - projekto aprašymas.

Duomenų failo struktūra

Duomenys faile zaidimu_duomenys.txt saugomi struktūruotu tekstiniu formatu. Kiekviena eilutė reiškia vieną žaidimą. Duomenys atskiriami kabliataškiu ;.

Duomenų formatas:

ID;Pavadinimas;Žanras;Metai;Įvertinimas

Pavyzdys:

1;Counter-Strike 2;FPS;2023;8.5

Naudotos programavimo konstrukcijos

Programoje panaudota:

kintamieji;
pagrindiniai duomenų tipai: int, string, double, bool;
sąlyginiai sakiniai if, else, switch;
ciklai for, while, do-while;
funkcijos;
struktūra struct zaidimas;
masyvas zaidimas zaidimai[Max];
duomenų nuskaitymas iš failo;
duomenų įrašymas į failą.

PROGRAMOS PALEIDIMO INSTRUKCIJA

Atsisiųsti arba atsidaryti projekto failus.
Įsitikinti, kad .cpp failas ir zaidimu_duomenys.txt yra tame pačiame aplanke.
Atidaryti .cpp failą C++ programavimo aplinkoje, pavyzdžiui, Visual Studio Code.
Paleisti programą.
Konsolės meniu pasirinkti norimą veiksmą įvedant skaičių.
Norint išsaugoti pakeitimus, pasirinkti meniu punktą 9. Išsaugoti duomenis.
Norint baigti programą, pasirinkti 0. Baigti.

PAPILDOMŲ FUNKCIJŲ APRAŠYMAS

Programoje įgyvendintos penkios papildomos funkcijos:

1. Paieška pagal žanrą

Vartotojas gali įvesti norimą žanrą, pavyzdžiui, RPG, FPS arba Action. Programa peržiūri visus žaidimus ir parodo tik tuos, kurie priklauso pasirinktam žanrui.

2. Paieška pagal pavadinimą

Vartotojas gali įvesti visą žaidimo pavadinimą arba jo dalį. Programa ieško atitikmenų ir parodo rastus žaidimus.

Pavyzdžiui, įvedus „Counter“, bus rastas žaidimas „Counter-Strike 2“.

3. Rikiavimas pagal įvertinimą

Programa surikiuoja visus žaidimus pagal jų įvertinimą nuo geriausio iki blogiausio. Ši funkcija leidžia greitai pamatyti aukščiausiai įvertintus žaidimus.

4. Statistikos skaičiavimas

Programa apskaičiuoja:

bendrą žaidimų kiekį;
vidutinį visų žaidimų įvertinimą;
geriausiai įvertintą žaidimą.

Ši funkcija leidžia greitai gauti bendrą informaciją apie kataloge esančius žaidimus.

5. Pradinės tvarkos atstatymas

Jeigu vartotojas surikiuoja arba pakeičia duomenų tvarką programoje, gali pasirinkti funkciją „Atstatyti pradinę tvarką iš failo“. Tuomet programa iš naujo nuskaito duomenis iš failo ir atkuria pradinę jų tvarką.

IŠVADA
Projektas įgyvendina kompiuterinių žaidimų katalogo valdymo programą. Programa nuskaito duomenis iš tekstinio failo, leidžia vygdyti visas CRUD operacijas, turi papildomas duomenų apdorojimo funkcijas ir leidžia išsaugoti pakeistus duomenis faile.

