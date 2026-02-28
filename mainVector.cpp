#include <string>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <sstream>
using std::cin;
using std::string;
using std::cout;
using std::setw;
using std::vector;
using std::rand;

string randomstr();

int main(){
    std::srand(std::time(0));
    struct studentas{
    string vardas, pavarde;
    vector<int> paz;
    int egz;
    double rez=0;
    double med;
    };
    vector<studentas> A;
    studentas temp;
    int m=0, n=0, x;

    cout<<"[1] - Ivedimas ranka\n[2] - Generuoti tik pazymius\n[3] - Generuoti viska\n[4] - Skaitymas is failo\n[5] - baigti darba\nJusu pasirinkimas: ";
    string ivedimas;
    while (cin>>ivedimas) {
        if (ivedimas=="1"||ivedimas=="2"||ivedimas=="3"||ivedimas=="4"||ivedimas=="5") break;
        else cout<<"Neteisingas pasirinkimas, bandykite dar karta: ";
    }
    string failas;
    if (ivedimas=="4") {
        cout<<"Iveskite failo pavadinima: ";
        cin>>failas;
    }

    if (ivedimas=="5") return 0;

    cout<<"Pasirinkite isvedimo buda ([f] - i faila arba [e] - i ekrana): ";
    string isvedimas;
    while(cin>>isvedimas) {
        if (isvedimas=="f"||isvedimas=="e") break;
        else cout<<"Neteisingas pasirinkimas, pasirinkite is naujo: ";
    }

    cout<<"Pasirinkite skaiciavimo buda ([v] - vidurkis arba [m] - mediana): ";
    string skaiciavimas;
    while(cin>>skaiciavimas) {
        if (skaiciavimas=="v"||skaiciavimas=="m") break;
        else cout<<"Neteisingas pasirinkimas, pasirinkite is naujo: ";
    }

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
            temp.rez/=n;

            A.push_back(temp);
        }
        fin.close();
    }

    // Compute medians
    for (int i=0; i<m; i++){
        std::sort(A[i].paz.begin(), A[i].paz.end());
        if (A[i].paz.size()%2==0) {
            A[i].med=(A[i].paz[A[i].paz.size()/2-1]+A[i].paz[A[i].paz.size()/2])/2.0;
        }
        else A[i].med=A[i].paz[A[i].paz.size()/2];
    }

    if (isvedimas=="e") {
        cout<<std::fixed<<std::setprecision(2)<<std::left<<setw(15)<<"Vardas"<<setw(15)<<"Pavarde"<<"Galutinis ";
        if (skaiciavimas=="v") cout<<"(Vid.)";
        else cout<<"(Med.)";
        cout<<"\n------------------------------------------------\n";
        for (int i=0; i<m; i++) {
            cout<<std::left<<setw(15)<<A[i].vardas<<setw(15)<<A[i].pavarde;
            if (skaiciavimas=="v") cout<<setw(15)<<0.4*A[i].rez+0.6*A[i].egz<<'\n';
            else cout<<setw(15)<<0.4*A[i].med+0.6*A[i].egz<<'\n';
        }
    }
    else if (isvedimas=="f") {
        std::ofstream fout("isvedimas.txt");
        fout<<std::fixed<<std::setprecision(2)<<std::left<<setw(15)<<"Vardas"<<setw(15)<<"Pavarde"<<"Galutinis ";
        if (skaiciavimas=="v") fout<<"(Vid.)";
        else fout<<"(Med.)";
        fout<<"\n------------------------------------------------\n";
        for (int i=0; i<m; i++) {
            fout<<std::left<<setw(15)<<A[i].vardas<<setw(15)<<A[i].pavarde;
            if (skaiciavimas=="v") fout<<setw(15)<<0.4*A[i].rez+0.6*A[i].egz<<'\n';
            else fout<<setw(15)<<0.4*A[i].med+0.6*A[i].egz<<'\n';
        }
    }
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
