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
void vidurkis(mokiniai Masyvas[], int kiek, float &vidurk);
void rikiavimas(mokiniai Masyvas[], int kiek);
void rasymas(mokiniai Masyvas[], int kiek, float grupesVidurkis, string textas);

int main()
{

    int KiekMokiniu1, KiekMokiniu2, KiekMokiniu3, KiekMokiniu4;
    float vid1, vid2, vid3, vid4;

    const char duomenys1[] = "duom3_1.txt";
    const char duomenys2[] = "duom3_2.txt";
    const char duomenys3[] = "duom3_3.txt";
    const char duomenys4[] = "duom3_4.txt";

    kiekis(KiekMokiniu1,duomenys1);
    kiekis(KiekMokiniu2,duomenys2);
    kiekis(KiekMokiniu3,duomenys3);
    kiekis(KiekMokiniu4,duomenys4);

    cout<<KiekMokiniu1<<"   "<<KiekMokiniu2<<"   "<<KiekMokiniu3<<"   "<<KiekMokiniu4<<endl;

    mokiniai klase_1[KiekMokiniu1], klase_2[KiekMokiniu2], klase_3[KiekMokiniu3], klase_4[KiekMokiniu4];

    skaitymas(klase_1,KiekMokiniu1,duomenys1);
    /*for(int i=0; i<KiekMokiniu1; i++){
        cout<<klase_1[i].vardas<<klase_1[i].vidurkis<<endl;
    }*/
    skaitymas(klase_2,KiekMokiniu2,duomenys2);
    skaitymas(klase_3,KiekMokiniu3,duomenys3);
    skaitymas(klase_4,KiekMokiniu4,duomenys4);

    vidurkis(klase_1,KiekMokiniu1,vid1);
    cout<<vid1<<endl;
    vidurkis(klase_2,KiekMokiniu2,vid2);
    cout<<vid2<<endl;
    vidurkis(klase_3,KiekMokiniu3,vid3);
    cout<<vid3<<endl;
    vidurkis(klase_4,KiekMokiniu4,vid4);
    cout<<vid4<<endl;

    rikiavimas(klase_1,KiekMokiniu1);
    rikiavimas(klase_2,KiekMokiniu2);
    rikiavimas(klase_3,KiekMokiniu3);
    rikiavimas(klase_4,KiekMokiniu4);


    rasymas(klase_1,KiekMokiniu1,vid1, "Klase 1: ");
    rasymas(klase_2,KiekMokiniu2,vid2, "Klase 2: ");
    rasymas(klase_3,KiekMokiniu3,vid3, "Klase 3: ");
    rasymas(klase_4,KiekMokiniu4,vid4, "Klase 4: ");



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

void vidurkis(mokiniai Masyvas[], int kiek, float &vidurk){
     float suma=0;
     for(int i=0; i<kiek; i++){
                    suma+=Masyvas[i].vidurkis;
     }
     vidurk = float(suma)/float(kiek);
}
void rikiavimas(mokiniai Masyvas[], int kiek){

      float laikinas;
      string laikVardas;

    for(int i=0; i<kiek; i++){
        for(int j=1; j<kiek-1; j++){
            if (Masyvas[j-1].vidurkis<=Masyvas[j].vidurkis){
                laikinas=Masyvas[j].vidurkis;
                laikVardas=Masyvas[j].vardas;

                Masyvas[j].vidurkis=Masyvas[j-1].vidurkis;
                Masyvas[j].vardas=Masyvas[j-1].vardas;
                Masyvas[j-1].vidurkis=laikinas;
                Masyvas[j-1].vardas=laikVardas;
            }
        }
    }
}
void rasymas(mokiniai Masyvas[], int kiek, float grupesVidurkis, string textas){
out<<textas<<endl;
    for(int i=0; i<kiek; i++){
            if(Masyvas[i].vidurkis>grupesVidurkis)

        out<<Masyvas[i].vardas<<Masyvas[i].vidurkis<<endl;
    }
}
