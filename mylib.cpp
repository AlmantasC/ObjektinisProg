#include "mylib.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <stdexcept>
#include <iomanip>
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

int getInt(int min, int max) {
    int value;
    while (true) {
        try {
            if (!(std::cin >> value))  {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                throw std::runtime_error("Neteisinga ivestis");
            }
            if (value < min || value > max)
                throw std::runtime_error("Pasirinkimas turi buti tarp " + std::to_string(min) + " ir " + std::to_string(max));
            return value;
        }
        catch (const std::runtime_error& e) {
            std::cout << e.what() << ", pabandykite dar karta: ";
        }
    }
};

std::string getFile() {
    std::string failas;
    std::cout << "Iveskite failo pavadinima: ";
    std::cin >> failas;
    while (true) {
        try {
            std::ifstream fin(failas);
            if (!fin.is_open())
                throw std::runtime_error("Failas \"" + failas + "\" nerastas");
            fin.close();
            return failas;
        }
        catch (const std::runtime_error& e) {
            std::cout << e.what() << ", pabandykite dar karta: ";
            std::cin >> failas;
        }
    }
};

void printRez(std::ostream& out, std::vector<studentas>& A, int skaiciavimas) {
    out<<std::fixed<<std::setprecision(2)<<std::left<<std::setw(15)<<"Vardas"<<std::setw(15)<<"Pavarde"<<"Galutinis ";
    out<<(skaiciavimas == 1 ? "(Vid.)" : "(Med.)");
    out<<"\n------------------------------------------------\n";
    for (const auto& s : A) {
        out<<std::left<<std::setw(15)<<s.vardas<<std::setw(15)<<s.pavarde<<std::setw(15)<<s.gal<<'\n';
    }
};

void ivestiRanka(std::vector<studentas>& A, int& m) {
    studentas temp;
    int x;
    std::cout<<"Irasykite studento varda (arba -1 baigti): ";
    while (std::cin>>temp.vardas && temp.vardas!="-1") {
        std::cout<<"Irasykite studento pavarde: ";
        std::cin>>temp.pavarde;
        m++;
        temp.paz.clear();
        std::cout<<"Irasykite studento nd pazymi (arba -1 baigti): ";
        while (std::cin>>x && x!=-1) {
            if (x>=0 && x<=10) {
                temp.paz.push_back(x);
                std::cout<<"Irasykite studento nd pazymi (arba -1 baigti): ";
            }
            else std::cout<<"Neteisinga ivestis, bandykite dar karta: ";
        }
        std::cout<<"Irasykite studento egzamino pazymi: ";
        std::cin>>temp.egz;
        A.push_back(temp);
        std::cout<<"Irasykite studento varda (arba -1 baigti): ";
    }
}

void generuotiPazymius(std::vector<studentas>& A, int& m) {
    studentas temp;
    int n, x;
    std::cout<<"Po kiek nd pazymiu generuoti: ";
    std::cin>>n;
    std::cout<<"Irasykite studento varda (arba -1 baigti): ";
    while (std::cin>>temp.vardas && temp.vardas!="-1") {
        std::cout<<"Irasykite studento pavarde: ";
        std::cin>>temp.pavarde;
        m++;
        temp.paz.clear();
        for (int i=0; i<n; i++){
            x=rand()%10+1;
            temp.paz.push_back(x);
        }
        temp.egz=rand()%10+1;
        A.push_back(temp);
        std::cout<<"Irasykite studento varda (arba -1 baigti): ";
    }
}

void generuotiViska(std::vector<studentas>& A, int& m) {
    studentas temp;
    int n, x;
    std::cout<<"Kiek studentu sugeneruoti: ";
    std::cin>>m;
    std::cout<<"Po kiek nd pazymiu generuoti: ";
    std::cin>>n;
    for (int i=0; i<m; i++) {
        temp.vardas=randomstr();
        temp.pavarde=randomstr();
        temp.paz.clear();
        for (int j=0; j<n; j++){
            x=rand()%10+1;
            temp.paz.push_back(x);
        }
        temp.egz=rand()%10+1;
        A.push_back(temp);
    }
}

void skaitytiIsFailo(std::vector<studentas>& A, int& m, std::string& failas) {
    studentas temp;
    int x;
    std::string line;
    std::ifstream fin(failas);
    std::getline(fin, line);
    while (std::getline(fin, line)) {
        m++;
        temp.paz.clear();
        std::istringstream iss(line);
        iss>>temp.vardas>>temp.pavarde;
        while (iss>>x) {
            temp.paz.push_back(x);
        }
        temp.egz=temp.paz.back();
        temp.paz.pop_back();
        A.push_back(temp);
    }
    fin.close();
}
