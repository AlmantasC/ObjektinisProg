#include <string>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
using std::cin;
using std::string;
using std::cout;
using std::setw;
using std::vector;
int main()
{
    struct studentas{
    string vardas, pavarde;
    vector<int> paz;
    int egz;
    double rez=0;
    double med;
    };
    vector<studentas> A;
    int m=0, n=0;
    cout<<"[1] - Ivedimas ranka\n[2] - Generuoti tik pazymius\n[3] - Generuoti viska\n[4] - baigti darba\nJusu pasirinkimas: ";
    string pasirinkimas;
    while (cin>>pasirinkimas) {
        if (pasirinkimas=="1"||pasirinkimas=="2"||pasirinkimas=="3"||pasirinkimas=="4") break;
        else cout<<"Neteisingas pasirinkimas, bandykite dar karta: ";
    }
    if (pasirinkimas=="4") return 0;
    else if (pasirinkimas=="3") {
        cout<<"Kiek studentu sugeneruoti?";
        cin>>m;
        cout<<"Po kiek pazymiu generuoti?";
        cin>>n;
    }
    else if (pasirinkimas=="2") {
        cout<<"Po kiek pazymiu generuoti?";
        cin>>n;
    }
    else if (pasirinkimas=="1") {
        studentas temp;
        cout<<"Irasykite studento varda (arba -1 baigti): ";
        while (cin>>temp.vardas && temp.vardas!="-1") {
            cout<<"Irasykite studento pavarde: ";
            cin>>temp.pavarde;
            m++;
            temp.paz.clear();
            temp.rez=0;
            n=0;
            int x;
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



    cout<<"Pasirinkite skaiciavimo buda:\n[v] - Vidurkis\n[m] - Mediana\nJusu pasirinkimas (v arba m): ";
    while(cin>>pasirinkimas) {
        if (pasirinkimas=="v"||pasirinkimas=="m") break;
        else cout<<"Neteisingas pasirinkimas, pasirinkite is naujo: ";
    }
    cout<<std::fixed<<std::setprecision(2)<<std::left<<setw(15)<<"Vardas"<<setw(15)<<"Pavarde"<<"Galutinis ";
    if (pasirinkimas=="v") cout<<"(Vid.)";
    else cout<<"(Med.)";
    cout<<"\n------------------------------------------------\n";
    for (int i=0; i<m; i++) {
        cout<<std::left<<setw(15)<<A[i].vardas<<setw(15)<<A[i].pavarde;
    if (pasirinkimas=="v") cout<<setw(15)<<0.4*A[i].rez+0.6*A[i].egz<<'\n';
    else cout<<setw(15)<<0.4*A[i].med+0.6*A[i].egz<<'\n';
    }
}
