#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

//Maksimalus žaidimų kiekis masyve
const int MAX = 100;

//Vieno žaidimo  duomenų saugojimas
struct zaidimas{
    int id; //žaidimo kodas
    string pav; //Pavadinimas
    string z; //žanras
    int m; // metai
    double i; //Įvertinimas
};
//Parodo vieną žaidimą
int rodyti (zaidimas zaid){
    cout<< zaid.id<< ". "
    <<zaid.pav<< " | "
    <<zaid.z<< " | "
    <<zaid.m<< " | "
    <<zaid.i<< endl;
    return 0;
}
//nuskaito duomenis iš failo
int nuskaityti (zaidimas zaidimai[]){
    ifstream failas ("zaidimu_duomenys.txt");
    string eilute;
    int kiek = 0;
        if (!failas){
            cout<< "Failas zaidimu_duomenys.txt nerastas."<< endl;
            return 0;
        }
      while (getline(failas, eilute) && kiek < MAX) {
        string laikinas;
        stringstream ss(eilute);

        getline(ss, laikinas, ';');
        zaidimai[kiek].id = stoi(laikinas);

        getline(ss, zaidimai[kiek].pav, ';');
        getline(ss, zaidimai[kiek].z, ';');

        getline(ss, laikinas, ';');
        zaidimai[kiek].m = stoi(laikinas);

        getline(ss, laikinas, ';');
        zaidimai[kiek].i = stod(laikinas);

        kiek++;
    }

    failas.close();
    return kiek;
}
//Išsaugo duomenis į failą
int issaugoti(zaidimas zaidimai[], int kiek){
    ofstream failas("zaidimu_duomenys.txt");
        if (!failas){
            cout<< "Nepavyko išsaugoti duomenų."<< endl;
            return 0;
        }

    for (int a = 0; a < kiek; a++) {
        failas << zaidimai[a].id << ";"
               << zaidimai[a].pav << ";"
               << zaidimai[a].z << ";"
               << zaidimai[a].m << ";"
               << zaidimai[a].i << endl;
    }

    failas.close();
    return 1;
}
//Randa žaidimą pagal id
int rasti(zaidimas zaidimai[], int kiek, int id){
    for (int a=0; a<kiek; a++){
        if (zaidimai[a].id == id){
            return a;
        }
    }
    return -1;
}
//Rodo visus zaidimus
int rodytiVisus(zaidimas zaidimai[], int kiek) {
    if (kiek == 0) {
        cout << "Zaidimu nera." << endl;
        return 0;
    }

    for (int a = 0; a < kiek; a++) {
        rodyti(zaidimai[a]);
    }

    return 0;
}
//create prideda nauja zaidima
int prideti(zaidimas zaidimai[], int kiek) {
    if (kiek >= MAX) {
        cout << "Daugiau žaidimų pridėti negalima." << endl;
        return kiek;
    }

    zaidimai[kiek].id = kiek + 1;

    cin.ignore();

    cout << "Įveskite pavadinimą: ";
    getline(cin, zaidimai[kiek].pav);

    cout << "Įveskite žanrą: ";
    getline(cin, zaidimai[kiek].z);

    cout << "Įveskite metus: ";
    cin >> zaidimai[kiek].m;

    cout << "Įveskite įvertinimą: ";
    cin >> zaidimai[kiek].i;

    kiek++;

    cout << "Žaidimas pridetas." << endl;

    return kiek;
}
// UPDATE - redaguoja zaidima pagal ID
int redaguoti(zaidimas zaidimai[], int kiek) {
    int id;

    cout << "Įveskite redaguojamo žaidimo ID: ";
    cin >> id;

    int vieta = rasti(zaidimai, kiek, id);

    if (vieta == -1) {
        cout << "Žaidimas nerastas." << endl;
        return 0;
    }

    cin.ignore();

    cout << "Naujas pavadinimas: ";
    getline(cin, zaidimai[vieta].pav);

    cout << "Naujas žanras: ";
    getline(cin, zaidimai[vieta].z);

    cout << "Nauji metai: ";
    cin >> zaidimai[vieta].m;

    cout << "Naujas įvertinimas: ";
    cin >> zaidimai[vieta].i;

    cout << "Žaidimas atnaujintas." << endl;

    return 0;
}
//DELETE ištrina žaidimą pagal Id
int istrinti(zaidimas zaidimai[], int kiek) {
    int id;

    cout << "Įveskite trinamo žaidimo ID: ";
    cin >> id;

    int vieta = rasti(zaidimai, kiek, id);

    if (vieta == -1) {
        cout << "Žaidimas nerastas." << endl;
        return kiek;
    }
//Visi žaidimai po ištrinto žaidimo pastumiami viena viema į kairę
 for (int a = vieta; a < kiek - 1; a++) {
        zaidimai[a] = zaidimai[a + 1];
    }

    kiek--;

    cout << "Žaidimas ištrintas." << endl;

    return kiek;
}
// Papildoma funkcija paieska pagal žanra
int ieskotiZanro(zaidimas zaidimai[], int kiek) {
    string zanras;
    bool rastas = false;

    cin.ignore();

    cout << "Įveskite Žanra: ";
    getline(cin, zanras);

    for (int a = 0; a < kiek; a++) {
        if (zaidimai[a].z == zanras) {
            rodyti(zaidimai[a]);
            rastas = true;
        }
    }

    if (rastas == false) {
        cout << "Tokio žanro žaidimų nerasta." << endl;
    }

    return 0;
}
//Papildoma funkcija paieška pagal pavadinimą
int ieskotiPav(zaidimas zaidimai[], int kiek) {
    string tekstas;
    bool rastas = false;

    cin.ignore();

    cout << "Įveskite pavadinimą arba jo dali: ";
    getline(cin, tekstas);

    for (int a = 0; a < kiek; a++) {
        if (zaidimai[a].pav.find(tekstas) != string::npos) {
            rodyti(zaidimai[a]);
            rastas = true;
        }
    }

    if (rastas == false) {
        cout << "Žaidimų nerasta." << endl;
    }

    return 0;
}
//Papildoma funkcija rikiavimas pagal įvertinimą
int rikiuoti(zaidimas zaidimai[], int kiek){
    for(int a=1; a<kiek -1; a++){
        for (int b=a+1; b< kiek; b++){
            if (zaidimai[a].i< zaidimai[b].i){
                zaidimas laikinas = zaidimai[b];
                zaidimai[a] = zaidimai[b];
                zaidimai[b] = laikinas;
            }
        }
    }
    cout<<"žaidimai surikiuoti pagal įvertinimą."<< endl;
    return 0;
}
//Papildoma funkcija statistika
int statistika(zaidimas zaidimai[], int kiek){
    if (kiek == 0){
        cout<< "Nrėra duomenų."<< endl;
        return 0;
    }
    double suma = 0;
    int geriausias = 0;

    for (int a = 0; a< kiek; a++){
        suma = suma + zaidimai[a].i;
         if (zaidimai[a].i> zaidimai[geriausias].i){
             geriausias = a;
         }
    }
    cout << "Žaidimų kiekis: "<<kiek<< endl;
    cout<< "Vidutinis įvertinimas: "<< suma/kiek<<endl;
    cout<< " Geriausias žaidimas: "
        << zaidimai[geriausias].pav
        <<"("<<zaidimai[geriausias].i<<")"<<endl;
        return 0;
}
//MENIU
int meniu(){
    cout<< endl;
    cout<<" ŽAIDIMŲ KATALOGAS "<<endl;
    cout<<" 1. Rodyti visus žaidimus"<<endl;
    cout<<" 2. Pridėti žaidimą"<<endl;
    cout<<" 3. Redaguoti žaidimo informaiją"<<endl;
    cout<<" 4. Ištrinti žaidimą"<<endl;
    cout<<" 5. Ieškoti pagal žanrą"<<endl;
    cout<<" 6. Ieškoti pagal pavadinimą"<<endl;
    cout<<" 7. Rikiuoti pagal įvertinimą"<<endl;
    cout<<" 8. Statistika"<<endl;
    cout<<" 9. Išaugoti duomenis"<<endl;
    cout<<" 0. Baigti "<< endl;
    cout<<" Pasirinkimas: ";
    return 0;
}
int main(){
    zaidimas zaidimai[MAX];
    int kiek;
    int p;
    //Nuskaitomi duomenys iš failo
    kiek = nuskaityti(zaidimai);

    //Programa kartojasi kol nėra paspaudžiamas 0
    do{
        meniu();
        cin>>p;

        switch (p){
            case 1:
            rodytiVisus(zaidimai, kiek);
            break;

            case 2:
            kiek = prideti(zaidimai, kiek);
            break;

            case 3:
            redaguoti(zaidimai, kiek);
            break;

            case 4:
            kiek = istrinti(zaidimai, kiek);
            break;

            case 5:
            ieskotiZanro(zaidimai, kiek);
            break;

            case 6:
            ieskotiPav(zaidimai, kiek);
            break;

            case 7: 
            rikiuoti(zaidimai, kiek);
            rodytiVisus(zaidimai, kiek);
            break;

            case 8: 
            statistika(zaidimai, kiek);
            break;

            case 9:
            if (issaugoti(zaidimai, kiek)==1){
                cout<<" Duomenys išsaugoti."<< endl;
            }
            break;

            case 0:
            issaugoti(zaidimai, kiek);
            cout<<" Programa baigta. Duomenys yra išsaugoti."<<endl;
            break;

            default:
            cout<< "Tokio pasirinkimo nėra. "<<endl;
        }
    }while (p !=0);
    return 0;
}