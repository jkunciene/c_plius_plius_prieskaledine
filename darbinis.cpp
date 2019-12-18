#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;

ofstream out("rezultatai.txt");

struct mokiniai{
    string vardas;
    float vidurkis;
};
void kiekis(int &kiek, const char byla[]);
void skaitymas(mokiniai Masyvas[], int kiek, const char byla[]);
void rasymas(mokiniai Masyvas[], int kiek);
void vidurkis(mokiniai Masyvas[], int kiek, float &vidurk);

int main()
{

    int KiekMokiniu1, KiekMokiniu2, KiekMokiniu3, KiekMokiniu4;

    const char duomenys1[] = "duom3_1.txt";
    const char duomenys2[] = "duom3_2.txt";
    const char duomenys3[] = "duom3_3.txt";
    const char duomenys4[] = "duom3_4.txt";

    kiekis(KiekMokiniu1,duomenys1);
    kiekis(KiekMokiniu2,duomenys2);
    kiekis(KiekMokiniu3,duomenys3);
    kiekis(KiekMokiniu4,duomenys4);

    cout<<KiekMokiniu1<<"   "<<KiekMokiniu2<<"   "<<KiekMokiniu3<<"   "<<KiekMokiniu4;

    mokiniai klase_1[KiekMokiniu1], klase_2[KiekMokiniu2], klase_3[KiekMokiniu3], klase_4[KiekMokiniu4];

    skaitymas(klase_1,KiekMokiniu1,duomenys1);
    /*for(int i=0; i<KiekMokiniu1; i++){
        cout<<klase_1[i].vardas<<klase_1[i].vidurkis<<endl;
    }*/
    skaitymas(klase_2,KiekMokiniu2,duomenys2);
    skaitymas(klase_3,KiekMokiniu3,duomenys3);
    skaitymas(klase_4,KiekMokiniu4,duomenys4);

    rasymas(klase_1,KiekMokiniu1);
    rasymas(klase_2,KiekMokiniu2);
    rasymas(klase_3,KiekMokiniu3);
    rasymas(klase_4,KiekMokiniu4);



out.close();
    return 0;
}
void kiekis(int &kiek, const char byla[]){
    ifstream in(byla);
    mokiniai Laikina[1];
    kiek=0;

    while(!in.eof()){
        in>>Laikina[0].vardas>>Laikina[0].vidurkis;//skaitom nuo nulinio-(pirmo) elemento
        kiek++;
    }
    in.seekg(0);
    in.close();

}
void skaitymas(mokiniai Masyvas[], int kiek, const char byla[]){
    ifstream in(byla);
    for(int i=0; i<kiek; i++){
        in>>Masyvas[i].vardas>>Masyvas[i].vidurkis;
    }
    in.close();
}
void rasymas(mokiniai Masyvas[], int kiek){

    for(int i=0; i<kiek; i++){
        out<<Masyvas[i].vardas<<Masyvas[i].vidurkis<<endl;
    }
}
void vidurkis(mokiniai Masyvas[], int kiek, float &vidurk){

}
