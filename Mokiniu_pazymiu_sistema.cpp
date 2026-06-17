#include <iostream>
#include <string>
using namespace std;
int main(){
//masyvai
string vardai[100];//vienmatis masyvas kuris saugo mokiniu vardus
int pazymiai [100][10];//dvimatis masyvas 
int kiekis [100];
//kintamieji
int mok =0;
int p;//pasirinkimas
//ciklas, kad kartotusi programa kol nepasirenkama 5
do{
    cout<<" Pasirinkite ką norite atlikti "<<endl;
    cout<<"1. Įvesti mokinių vardus ir pažymius "<<endl;
    cout<<"2. Peržiūrėti visų mokinių arba konkretaus mokinio pažymius "<<endl;
    cout<<"3. Atnaujinti konkretų pažimį konkrečiaum mokiniui "<<endl;
    cout<<"4. Pašalinti mokinį iš sąrašo "<<endl;
    cout<<"5. Baigti "<<endl;

    cout<<"Įveskite pasirinkimą: "<<endl;
    cin>>p;

    //pirmas pasirinkimas
    if(p==1){ 
       
        cout<<"Įveskite mokinio vardą: "<<endl;
        cin>> vardai[mok];

        cout<<"Įveskite kiek mokinys turi pažymių: "<<endl;
        cin>>kiekis[mok];
        if(kiekis[mok]>10){
            kiekis[mok]=10;
        }
        cout<<"Įveskite mokinio pažymius: "<<endl;
        for (int i=0; i<kiekis[mok]; i++){
            cin>> pazymiai[mok][i];
        }
        cout<<"Mokinys pridėtas "<<endl;
        mok++;
    }
    
    //antras pasirinkimas
    if(p==2){
        int a;
    cout<<"Pasirinkite ką norite atlikti: "<<endl;
    cout<<"1. Visi mokiniai "<<endl;
    cout<<"2. Vienas mokinys "<<endl;
    cin>> a;
    
        if(a==1){
        for(int i=0; i<mok; i++){
            cout<<vardai[i]<<": ";
            for(int j=0; j< kiekis[i]; j++){
                cout<<pazymiai[i][j]<<" ";
            }
            cout<<endl;
        }
        
        }
        if(a==2){
            string var;
            cout<<"Įveskite mokinio vardą: "<<endl;
            cin>>var;

            int r = -1;//-1 reiskia kad nera rastas

            for(int i=0; i<mok;i++){
                if(vardai[i]==var){
                    r=i;
                    break;
                }
            }
            if (r==-1){
                cout<<"Tokio mokinio nėra "<<endl;
            } else{
                cout<<vardai[r]<<": "<<endl;
                for(int j=0; j<kiekis[r]; j++){
                    cout<<pazymiai[r][j]<<" ";
                }
                cout<<endl;
            }
        }
    }

    //trecias pasirinkimas
    if(p==3){
        string var;
        cout<<"Įveskite mokinio vardą: "<<endl;
        cin>> var;

        for(int i=0; i<mok; i++){
            if (vardai[i]==var){
                int nr, naujas;
                cout<<"Kurio pažymio numeri keisti? "<<endl;
                cin>>nr;
                if (nr>=1 && nr<=kiekis[i]){
                    cout<<"Įveskite naują pažymį: "<<endl;
                    cin>>naujas;
                    pazymiai[i][nr - 1]= naujas;
                    cout<<"Pažimys pakeistas. "<<endl;
                }
            }
        }
    }

    //ketvirtas pasirinkimas
    if(p==4){
        string var;
        cout<<"Įveskite mokinio vardą: "<<endl;
        cin>> var;
        for(int i=0; i<mok; i++){
            if(vardai[i]==var){
                for(int j=i; j<mok-1;j++){
                    vardai[j]=vardai[j+1];
                    kiekis[j]=kiekis[j+1];
                    for(int k=0; k<10; k++){
                        pazymiai[j][k]=pazymiai[j+1][k];
                    }
                }
                mok--;
                cout<<"Mokinys pašalintas "<<endl;
                break;
            }
           
        }
        
    }
}while(p !=5);
return 0;
}