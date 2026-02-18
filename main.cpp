#include <string>
#include <iostream>
#include <iomanip>
#include <algorithm>
using std::cin;
using std::string;
using std::cout;
using std::setw;
int main()
{
    int m=2, n=3;       //m - studentu kiekis, n - pazymiu kiekis
    struct studentas{
    string vardas, pavarde;
    int* paz;
    double rez=0;
    double med;
    };
    studentas A[m];
    for (int i=0; i<m; i++) {       // irasymas
        A[i].paz = new int[n];
        cin>>A[i].vardas>>A[i].pavarde;
        for (int j=0; j<n; j++){
            cin>>A[i].paz[j];
            A[i].rez+=A[i].paz[j];
        }
        A[i].rez/=n;
        std::sort(A[i].paz, A[i].paz+n);        // isrusioja
        if (n%2==0)                             // jei lyginis skaicius ima viduriniu dvieju vidurki
        A[i].med=(A[i].paz[n/2-1]+A[i].paz[n/2])/2.0;
        else
        A[i].med=A[i].paz[n/2];
    }
    string pasirinkimas;
    cout<<"\n[v] - Vidurkis\n[m] - Mediana\nJusu pasirinkimas (v arba m) = ";
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
    if (pasirinkimas=="v") cout<<setw(15)<<A[i].rez<<'\n';
    else cout<<setw(15)<<A[i].med<<'\n';
    }
}
