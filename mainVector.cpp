#include <string>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <chrono>
using std::cin;
using std::string;
using std::cout;
using std::setw;
using std::vector;
using std::sort;
namespace chr = std::chrono;

struct studentas{
    string vardas, pavarde;
    vector<int> paz;
    int egz;
    double rez=0;
    double med;
    double gal;
};

string randomstr();
bool pagalVard(studentas a, studentas b);
bool pagalPavard(studentas a, studentas b);
bool pagalGal(studentas a, studentas b);

int main(){
    std::srand(std::time(0));
    vector<studentas> A;
    studentas temp;
    int m=0, n=0, x;

    // --------- PASIRINKIMAI ---------

    cout<<"[1] - Ivedimas ranka\n[2] - Generuoti tik pazymius\n[3] - Generuoti viska\n[4] - Skaitymas is failo\n[5] - baigti darba\nJusu pasirinkimas: ";
    string ivedimas;
    while (cin>>ivedimas) {
        if (ivedimas=="1"||ivedimas=="2"||ivedimas=="3"||ivedimas=="4"||ivedimas=="5") break;
        else cout<<"Neteisingas pasirinkimas, bandykite dar karta: ";
    }

    if (ivedimas=="5") return 0;

    string failas;
    if (ivedimas=="4") {
        cout<<"Iveskite failo pavadinima: ";
        cin>>failas;
    }

    cout<<"Pasirinkite rusiavimo buda ([v] - vardas, [p] - pavarde arba [g] - galutinis): ";
    string rusiavimas;
    while(cin>>rusiavimas) {
        if (rusiavimas=="v"||rusiavimas=="p"||rusiavimas=="g") break;
        else cout<<"Neteisingas pasirinkimas, pasirinkite is naujo: ";
    }

    cout<<"Pasirinkite galutinio skaiciavimo buda ([v] - vidurkis arba [m] - mediana): ";
    string skaiciavimas;
    while(cin>>skaiciavimas) {
        if (skaiciavimas=="v"||skaiciavimas=="m") break;
        else cout<<"Neteisingas pasirinkimas, pasirinkite is naujo: ";
    }

    cout<<"Pasirinkite isvedimo buda ([f] - i faila arba [e] - i ekrana): ";
    string isvedimas;
    while(cin>>isvedimas) {
        if (isvedimas=="f"||isvedimas=="e") break;
        else cout<<"Neteisingas pasirinkimas, pasirinkite is naujo: ";
    }

    // --------- IVEDIMAS ---------

    auto tStart = chr::high_resolution_clock::now();

    if (ivedimas=="3") {
        cout<<"Kiek studentu sugeneruoti: ";
        cin>>m;
        cout<<"Po kiek nd pazymiu generuoti: ";
        cin>>n;
        for (int i=0; i<m; i++) {
            temp.vardas=randomstr();
            temp.pavarde=randomstr();
            temp.paz.clear();
            temp.rez=0;
             for (int j=0; j<n; j++){
                x=rand()%10;
                temp.paz.push_back(x);
                temp.rez+=x;
            }
            temp.rez/=n;
            temp.egz=rand()%10;
            A.push_back(temp);
        }
    }
    else if (ivedimas=="2") {
        cout<<"Po kiek nd pazymiu generuoti: ";
        cin>>n;
        cout<<"Irasykite studento varda (arba -1 baigti): ";
        while (cin>>temp.vardas && temp.vardas!="-1") {
            cout<<"Irasykite studento pavarde: ";
            cin>>temp.pavarde;
            m++;
            temp.paz.clear();
            temp.rez=0;
            for (int i=0; i<n; i++){
                x=rand()%10+1;
                temp.paz.push_back(x);
                temp.rez+=x;
            }
            temp.rez/=n;
            temp.egz=rand()%10+1;
            A.push_back(temp);
            cout<<"Irasykite studento varda (arba -1 baigti): ";
        }
    }
    else if (ivedimas=="1") {
        cout<<"Irasykite studento varda (arba -1 baigti): ";
        while (cin>>temp.vardas && temp.vardas!="-1") {
            cout<<"Irasykite studento pavarde: ";
            cin>>temp.pavarde;
            m++;
            temp.paz.clear();
            temp.rez=0;
            n=0;
            cout<<"Irasykite studento nd pazymi (arba -1 baigti): ";
            while (cin>>x && x!=-1) {
                if (x>=0 && x<=10) {
                    n++;
                    temp.rez+=x;
                    temp.paz.push_back(x);
                    cout<<"Irasykite studento nd pazymi (arba -1 baigti): ";
                }
                else cout<<"Neteisinga ivestis, bandykite dar karta: ";
            }
            temp.rez/=n;
            cout<<"Irasykite studento egzamino pazymi: ";
            cin>>temp.egz;
            A.push_back(temp);
            cout<<"Irasykite studento varda (arba -1 baigti): ";
        }
    }
    else if (ivedimas=="4") {
        string line;

        std::ifstream fin(failas);
        std::getline(fin, line);

        while (std::getline(fin, line)) {
            m++;
            temp.paz.clear();
            temp.rez=0;
            n=0;
            std::istringstream iss(line);
            iss>>temp.vardas>>temp.pavarde;

            while (iss>>x) {
                temp.rez+=x;
                temp.paz.push_back(x);
                n++;
            }
            temp.egz=temp.paz.back();
            temp.paz.pop_back();
            n--;
            temp.rez-=temp.egz;
            temp.rez/=n;

            A.push_back(temp);
        }
        fin.close();
    }

    // --------- SKAICIAVIMAI ---------

    for (int i=0; i<m; i++){
        sort(A[i].paz.begin(), A[i].paz.end());
        if (A[i].paz.size()%2==0) A[i].med=(A[i].paz[A[i].paz.size()/2-1]+A[i].paz[A[i].paz.size()/2])/2.0;
        else A[i].med=A[i].paz[A[i].paz.size()/2];

        if (skaiciavimas=="v") A[i].gal=0.4*A[i].rez+0.6*A[i].egz;
        else A[i].gal=0.4*A[i].med+0.6*A[i].egz;
    }

    // --------- RUSIAVIMAS ---------

    if (rusiavimas=="v") sort(A.begin(), A.end(), pagalVard);
    else if (rusiavimas=="p") sort(A.begin(), A.end(), pagalPavard);
    else if (rusiavimas=="g") sort(A.begin(), A.end(), pagalGal);

    // --------- ISVEDIMAS ---------

    if (isvedimas=="e") {
        cout<<std::fixed<<std::setprecision(2)<<std::left<<setw(15)<<"Vardas"<<setw(15)<<"Pavarde"<<"Galutinis ";
        if (skaiciavimas=="v") cout<<"(Vid.)";
        else cout<<"(Med.)";
        cout<<"\n------------------------------------------------\n";
        for (int i=0; i<m; i++) {
            cout<<std::left<<setw(15)<<A[i].vardas<<setw(15)<<A[i].pavarde<<setw(15)<<A[i].gal<<'\n';
        }
    }
    else if (isvedimas=="f") {
        std::ofstream fout("isvedimas.txt");
        fout<<std::fixed<<std::setprecision(2)<<std::left<<setw(15)<<"Vardas"<<setw(15)<<"Pavarde"<<"Galutinis ";
        if (skaiciavimas=="v") fout<<"(Vid.)";
        else fout<<"(Med.)";
        fout<<"\n------------------------------------------------\n";
        for (int i=0; i<m; i++) {
            fout<<std::left<<setw(15)<<A[i].vardas<<setw(15)<<A[i].pavarde<<setw(15)<<A[i].gal<<'\n';
        }
        fout.close();
    }

    auto tEnd = chr::high_resolution_clock::now();
    cout<<"\nUztruko: "<<chr::duration_cast<chr::milliseconds>(tEnd-tStart).count()<<" ms\n";

    return 0;
}

string randomstr(){
    int l = rand()%10+1;
    string name="", table="abcdefghijklmnopqrstuvwxyz";
    for (int i=0; i<l; i++) {
        name+=table[rand()%26];
    }
    name[0]=toupper(name[0]);
    return name;
}

bool pagalVard(studentas a, studentas b){
    return a.vardas<b.vardas;
};

bool pagalPavard(studentas a, studentas b){
    return a.pavarde<b.pavarde;
};

bool pagalGal(studentas a, studentas b){
    return a.gal<b.gal;
};
