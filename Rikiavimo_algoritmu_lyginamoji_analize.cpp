#include <iostream>   
#include <fstream>    
#include <chrono>     // Laiko matavimui

using namespace std;
using namespace chrono;

const int MAX = 50000;

// Insertion Sort algoritmas
void insertionSort(int masyvas[], int n, long long& palyginimai, long long& sukeitimai) {
    for (int i = 1; i < n; i++) {
        int elementas = masyvas[i];
        int j = i - 1;

        while (j >= 0) {
            palyginimai++;

            if (masyvas[j] > elementas) {
                masyvas[j + 1] = masyvas[j];
                sukeitimai++;
                j--;
            } else {
                break;
            }
        }

        masyvas[j + 1] = elementas;
    }
}

// Sujungia dvi surikiuotas masyvo dalis
void merge(int masyvas[], int kaire, int vidurys, int desine, long long& palyginimai) {
    //sukuriami laikini masyvai
    int kaireDalis[MAX];
    int desineDalis[MAX];

    int n1 = vidurys - kaire + 1;
    int n2 = desine - vidurys;
    //kaire dalis kompijuojama i laikina masyva kaireDalis MAX
    for (int i = 0; i < n1; i++) {
        kaireDalis[i] = masyvas[kaire + i];
    }
    //dasine dalis kompjuojama i laikina masyva desineDalis MAX
    for (int j = 0; j < n2; j++) {
        desineDalis[j] = masyvas[vidurys + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = kaire;

    while (i < n1 && j < n2) {
        palyginimai++;

        if (kaireDalis[i] <= desineDalis[j]) {
            masyvas[k] = kaireDalis[i];
            i++;
        } else {
            masyvas[k] = desineDalis[j];
            j++;
        }

        k++;
    }

    while (i < n1) {
        masyvas[k] = kaireDalis[i];
        i++;
        k++;
    }

    while (j < n2) {
        masyvas[k] = desineDalis[j];
        j++;
        k++;
    }
}

// Merge Sort algoritmas
void mergeSort(int masyvas[], int kaire, int desine, long long& palyginimai) {
    if (kaire < desine) {
        int vidurys = (kaire + desine) / 2;

        mergeSort(masyvas, kaire, vidurys, palyginimai);
        mergeSort(masyvas, vidurys + 1, desine, palyginimai);

        merge(masyvas, kaire, vidurys, desine, palyginimai);
    }
}

// Nuskaito skaicius is failo
int skaitytiIsFailo(string failoPavadinimas, int masyvas[]) {
    ifstream failas(failoPavadinimas);

    int kiekis = 0;

    if (!failas) {
        cout << "Nepavyko atidaryti failo: " << failoPavadinimas << endl;
        return 0;
    }

    while (failas >> masyvas[kiekis] && kiekis < MAX) {
        kiekis++;
    }

    failas.close();

    return kiekis;
}

// Nukopijuoja viena masyva i kita
void kopijuotiMasyva(int isKur[], int iKur[], int n) {
    for (int i = 0; i < n; i++) {
        iKur[i] = isKur[i];
    }
}

// Testuoja abu algoritmus
void testuotiAlgoritmus(string failoPavadinimas, string duomenuTipas) {
    //sukuriami masyvai
    int pradinisMasyvas[MAX];
    int masyvas1[MAX];
    int masyvas2[MAX];
    
    int kartojimai = 5;

    int n = skaitytiIsFailo(failoPavadinimas, pradinisMasyvas);

    if (n == 0) {
        cout << "Failas tuscias arba nepavyko nuskaityti duomenu." << endl;
        return;
    }

    long long insertionLaikas = 0;
    long long insertionPalyginimai = 0;
    long long insertionSukeitimai = 0;

    long long mergeLaikas = 0;
    long long mergePalyginimai = 0;
    //Testas kartojamas 5 kartus
    for (int i = 0; i < kartojimai; i++) {
        kopijuotiMasyva(pradinisMasyvas, masyvas1, n);
        kopijuotiMasyva(pradinisMasyvas, masyvas2, n);

        long long palyginimai1 = 0;
        long long sukeitimai1 = 0;
        //Pradedamas laiko matavimas
        auto pradzia1 = high_resolution_clock::now();

        insertionSort(masyvas1, n, palyginimai1, sukeitimai1);
        //Uzbaigiamas laiko matavimas
        auto pabaiga1 = high_resolution_clock::now();
        //Apskaiciuojamas veikimo laikas
        long long laikas1 = duration_cast<microseconds>(pabaiga1 - pradzia1).count();
        //Rezultatai pridedami prie bendros sumos
        insertionLaikas += laikas1;
        insertionPalyginimai += palyginimai1;
        insertionSukeitimai += sukeitimai1;

        long long palyginimai2 = 0;

        auto pradzia2 = high_resolution_clock::now();

        mergeSort(masyvas2, 0, n - 1, palyginimai2);

        auto pabaiga2 = high_resolution_clock::now();

        long long laikas2 = duration_cast<microseconds>(pabaiga2 - pradzia2).count();

        mergeLaikas += laikas2;
        mergePalyginimai += palyginimai2;
    }

    cout << "Failas: " << failoPavadinimas << endl;
    cout << "Duomenu tipas: " << duomenuTipas << endl;
    cout << "Elementu kiekis: " << n << endl;

    cout << endl;

    cout << "Insertion Sort:" << endl;
    cout << "Vidutinis laikas: " << insertionLaikas / kartojimai << " mikrosekundziu" << endl;
    cout << "Vidutinis palyginimu skaicius: " << insertionPalyginimai / kartojimai << endl;
    cout << "Vidutinis sukeitimu skaicius: " << insertionSukeitimai / kartojimai << endl;

    cout << endl;

    cout << "Merge Sort:" << endl;
    cout << "Vidutinis laikas: " << mergeLaikas / kartojimai << " mikrosekundziu" << endl;
    cout << "Vidutinis palyginimu skaicius: " << mergePalyginimai / kartojimai << endl;
    cout << "Sukeitimu skaicius: 0" << endl;

    cout << "----------------------------------------" << endl;
}

int main() {

    string kelias = "C:\\Users\\elzeg\\Documents\\rikiavimo_duomenu_failai\\";

    testuotiAlgoritmus(kelias + "nesurikiuoti_5000.txt", "Nesurikiuoti duomenys");
    testuotiAlgoritmus(kelias + "nesurikiuoti_10000.txt", "Nesurikiuoti duomenys");
    testuotiAlgoritmus(kelias + "nesurikiuoti_50000.txt", "Nesurikiuoti duomenys");

    testuotiAlgoritmus(kelias + "atvirkstiniai_5000.txt", "Atvirksciai surikiuoti duomenys");
    testuotiAlgoritmus(kelias + "atvirkstiniai_10000.txt", "Atvirksciai surikiuoti duomenys");
    testuotiAlgoritmus(kelias + "atvirkstiniai_50000.txt", "Atvirksciai surikiuoti duomenys");

    testuotiAlgoritmus(kelias + "surikiuoti_5000.txt", "Jau surikiuoti duomenys");
    testuotiAlgoritmus(kelias + "surikiuoti_10000.txt", "Jau surikiuoti duomenys");
    testuotiAlgoritmus(kelias + "surikiuoti_50000.txt", "Jau surikiuoti duomenys");

    return 0;
}