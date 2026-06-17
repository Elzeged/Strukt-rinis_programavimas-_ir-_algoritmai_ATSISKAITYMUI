#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

struct menuItemType{
    string menuItem; //Patiekalo pavadinimas
    double menuPrice; //Patiekalo kaina (2 sk. po kablelio)
};

int getData(menuItemType menuList[]){ //menuList yra masyvas kuris skaito is meniu.txt
    ifstream file("C:\\Users\\elzeg\\Desktop\\helloworld\\Darbai_atsiskaitymui\\meniu.txt"); //Atidaromas failas
    int n = 0;

    // patikrina ar failas tikrai rastas
    if (!file) {
        cout << "KLAIDA: failo nerado!" << endl;
        return 0;
    }

    
        while (file >> menuList[n].menuItem >> menuList[n].menuPrice){
            n++; //pereina prie kito elemento
         }
    file.close();//uzdaro faila
    return n; //grazinam kiek patiekalu
    }

int showMenu(menuItemType menuList[],int n){
    cout<< "Sveiki atvyke į restoraną \"Upė\""<<endl<<endl;
    cout<<" MENIU "<<endl;

    for(int i=0;i<n;i++){
        cout<<i+1<< ". "
        <<left<<setw(37)<<menuList[i].menuItem //lygiuoja teksta i kaire ir rezervuoja 37 simbolius
        <<fixed <<setprecision(2) //2 sk po kablelio
        <<menuList[i].menuPrice<< "EUR"<<endl; //kaina
    }
    cout<<"Įveskite numeri ir kiekį.Baigus pasirinkimą spauskite 0."<<endl<<endl;
    return 0;
}


double printCheck(menuItemType menuList[], int n){
    ofstream file("C:\\Users\\elzeg\\Desktop\\helloworld\\Darbai_atsiskaitymui\\kvitas.txt"); //failas kvitui

    if (!file) {
    cout << "Nepavyko sukurti kvitas.txt" << endl;
    return 0;
    }

    int nr; //paskirtas numeris
    int kiekis; //kiek porciju
    double suma = 0; //bendra suma

    
        bool pirmas = true; // patikrina ar pirmas pasirinkimas

        while (true){  //Ciklas leidzia pasirinkti daug kartu
            cout<<"Numeris: ";
            cin>>nr;

            if(nr==0) break; //jeigu paraso 0 baigiasi 

            // JEIGU tai pirmas pasirinkimas, tik tada rodoma sąskaitą
            if (pirmas) {
                cout << endl << "SĄSKAITA" << endl;
                file << "SASKAITA" << endl;
                pirmas = false;
            }

    

            cout<<"Kiekis:";
            cin>>kiekis;

            double kaina = menuList[nr-1].menuPrice * kiekis; //apskaiciuojamas vieno pasirinkimo kaina
            suma+= kaina;

            cout<< kiekis<< " " //rodo ekrane
            <<left << setw(37) <<menuList[nr-1].menuItem
            <<fixed<< setprecision(2)
            <<kaina<<" EUR"<<endl;

            file<<kiekis<<" " // israso i faila
            <<left << setw(37) <<menuList[nr-1].menuItem
            <<fixed<< setprecision(2)
            <<kaina<<" EUR"<<endl;
        }
    double pvm = suma * 0.21; // skaiciuoja pvm
    double galutine = suma + pvm;

    cout<< endl<<"Mokesčiai (21%) "<<pvm<<" EUR"<<endl;
    cout<< " Galutinė suma "<<galutine<<" EUR"<<endl;

    file<<endl<< "Mokesčiai (21%) "<<pvm<< " EUR"<<endl;
    file<< " Galutinė suma "<<galutine<<" EUR"<<endl;
    file.close();
    cout << "Failas irasytas" << endl;
    return galutine;
}

int main(){
    menuItemType menuList[20]; // masyvas meniu
    int n = getData(menuList); // nuskaitomas meniu is failo
    showMenu(menuList, n); // parodo meniu
    printCheck(menuList, n); // skaiciuoja saskaita
    
    return 0;
}