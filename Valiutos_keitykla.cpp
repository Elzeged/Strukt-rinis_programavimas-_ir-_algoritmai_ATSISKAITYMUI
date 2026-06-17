#include <iostream>
using namespace std;
int main(){

double BendrasGBP = 0.8729;
double PirktiGBP = 0.8600;
double ParduotiGBP = 0.9220;

double BendrasUSD = 1.1793;
double PirktiUSD = 1.1460;
double ParduotiUSD = 1.2340;

double BendrasINR = 104.6918;
double PirktiINR = 101.3862;
double ParduotiINR = 107.8546;


double x;//euras
char kartoti;
do{
cout<<"Ką norėtumėt atlikti?"<<endl;
cout<<"1. Valiutos kurso palyginimas su kita valiuta"<<endl;
cout<<"2. Pirkti valiutą"<<endl;
cout<<"3. Parduoti valiutą"<<endl;


int v;// kintamasis
cin>>v;
if(v==1){

cout<<"Valiutos:"<<endl;
cout<<"1.GBP"<<endl;
cout<<"2.USD"<<endl;
cout<<"3.INR"<<endl;

int p;
cin>>p;
if(p==1){

cout<< "1 EUR = "<<BendrasGBP << "GBP"<<endl;
cout<< "1 EUR = "<<PirktiGBP << "Perkant"<<endl;
cout<< "1 EUR = "<<ParduotiGBP<<"Parduodant"<<endl;
}
if(p==2){

cout<< "1 EUR ="<<BendrasUSD<<"USD"<<endl;
cout<< "1 EUR ="<<PirktiUSD<<"Perkant"<<endl;
cout<< "1 EUR ="<<ParduotiUSD<<"Parduodant"<<endl;
}
if(p==3){

cout<< "1 EUR ="<<BendrasINR<<"INR"<<endl;
cout<< "1 EUR ="<<PirktiINR<<"Perkant"<<endl;
cout<< "1 EUR ="<<ParduotiINR<<"Parduodant"<<endl;
}
}

if(v==2){

cout<<"Kuria iš eurų į pasirinktą valiutą norite įsigyti?"<<endl;
cout<<"1.GBP"<<endl;
cout<<"2.USD"<<endl;
cout<<"3.INR"<<endl;

int a;
cin>> a;
if(a==1){

double g;//GBP
cout<< "Įrašykite sumą"<<endl;
cin>> x;
g=x*PirktiGBP;
cout<<"Gauta suma "<<g<<endl;
}

if(a==2){
double u;//usd
cout<< "Įrašykite sumą"<<endl;
cin>> x;
u=x*PirktiUSD;
cout<<"Gauta suma "<<u<<endl;
}

if(a==3){

double i;//INR
cout<< "Įrašykite sumą"<<endl;
cin>> x;
i=x*PirktiINR;
cout<<"Gauta suma "<<i<<endl;
}
}


if(v==3){


cout<<"Pasirinkite kurią valiutą norite iškeisti į EUR"<<endl;
cout<<"1.GBP"<<endl;
cout<<"2.USD"<<endl;
cout<<"3.INR"<<endl;

int w;
cin>> w;
if(w==1){


double e;//is GBP i eur
cout<<"Įrašykite sumą"<<endl;
cin>> x;
e=x/ParduotiGBP;
cout<<"Gauta suma "<<e<<endl;
}

if(w==2){


double r;// is usd i eur
cout<<"Įrašykite sumą"<<endl;
cin>> x;
r=x/ParduotiUSD;
cout<<"Gauta suma "<<r<<endl;
}

if(w==3){


double k;// is INR i eur
cout<<"Įrašykite sumą"<<endl;
cin>> x;
k=x/ParduotiINR;
cout<<"Gauta suma "<<k<<endl;

}


}
cout<<"\n Ar norite kartoti? (t/n): ";
cin>>kartoti;
} while (kartoti == 't');

cout<<"Programa baigta. "<<endl;

return 0;

}