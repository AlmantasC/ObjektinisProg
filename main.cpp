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
    int m=2, n=3;
    struct studentas{
    string vardas, pavarde;
    int* paz;
    double rez=0;
    double med;
    };
    studentas A[m];
    for (int i=0; i<m; i++) {
        A[i].paz = new int[n];
        cin>>A[i].vardas>>A[i].pavarde;
        for (int j=0; j<n; j++){
            cin>>A[i].paz[j];
            A[i].rez+=A[i].paz[j];
        }
        A[i].rez/=n;
        std::sort(A[i].paz, A[i].paz+n);
        if (n%2==0)
        A[i].med=(A[i].paz[n/2-1]+A[i].paz[n/2])/2.0;
        else
        A[i].med=A[i].paz[n/2];
    }
    cout<<std::fixed<<std::setprecision(2)<<"Vardas\t\tPavarde\t\tGalutinis (Vid.) / Galutinis (Med.)\n";
    for (int i=0; i<m; i++) {
        cout<<A[i].vardas<<setw(10-A[i].vardas.length())<<'\t'<<A[i].pavarde<<setw(10-A[i].vardas.length())<<'\t'<<A[i].rez<<setw(10)<<'\t'<<A[i].med<<'\n';
    }
}
