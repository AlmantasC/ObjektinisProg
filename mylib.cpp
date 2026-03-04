#include "mylib.h"
#include <string>
#include <vector>
#include <algorithm>

std::string randomstr(){
    int l = rand()%10+1;
    std::string name="", table="abcdefghijklmnopqrstuvwxyz";
    for (int i=0; i<l; i++) {
        name+=table[rand()%26];
    }
    name[0]=toupper(name[0]);
    return name;
}

double vid (studentas A) {
    int n=A.paz.size();
    double suma=0;
    for (int i=0; i<n; i++) suma+=A.paz[i];
    suma/=n;

    return suma;
};

double med (studentas A){
    int n=A.paz.size();
    sort(A.paz.begin(), A.paz.end());
    if (n%2==0) return (A.paz[n/2-1]+A.paz[n/2])/2.0;
    else return A.paz[n/2];
};

bool pagalVard(studentas a, studentas b){
    return a.vardas<b.vardas;
};

bool pagalPavard(studentas a, studentas b){
    return a.pavarde<b.pavarde;
};

bool pagalGal(studentas a, studentas b){
    return a.gal<b.gal;
};
