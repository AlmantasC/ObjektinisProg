#include "mylib.h"
#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <fstream>
#include <stdexcept>
#include <iomanip>
#include <chrono>

namespace chr = std::chrono;
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
            if (!(std::cin>>value)) {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                throw std::runtime_error("Neteisinga įvestis");
            }
            char leftover;
            if (std::cin.get(leftover)&&leftover!='\n') {
                std::cin.ignore(10000, '\n');
                throw std::runtime_error("Neteisinga įvestis");
            }
            if (value<min||value>max)
                throw std::runtime_error("Pasirinkimas turi būti tarp "+std::to_string(min)+" ir "+std::to_string(max));
            return value;
        }
        catch (const std::runtime_error& e) {
            std::cout<<e.what()<<", pabandykite dar kartą: ";
        }
    }
};

std::string getFile() {
    std::string failas;
    std::cout << "Įveskite failo pavadinimą: ";
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

void printRez(std::ostream& out, std::list<studentas>& A, int skaiciavimas) {
    out<<std::fixed<<std::setprecision(2)<<std::left<<std::setw(15)<<"Vardas"<<std::setw(15)<<" Pavardė"<<"\tGalutinis ";
    out<<(skaiciavimas == 1 ? "(Vid.)" : "(Med.)");
    out<<"\n------------------------------------------------\n";
    for (const auto& s : A) {
        out<<std::left<<std::setw(15)<<s.vardas<<'\t'<<std::setw(15)<<s.pavarde<<'\t'<<s.gal<<'\n';
    }
};

void ivestiRanka(std::list<studentas>& A, int& m) {
    studentas temp;
    int x;
    std::cout<<"Įrašykite studento vardą (arba -1 baigti): ";
    while (std::cin>>temp.vardas && temp.vardas!="-1") {
        std::cout<<"Įrašykite studento pavardę: ";
        std::cin>>temp.pavarde;
        m++;
        temp.paz.clear();
        std::cout<<"Įrašykite studento nd pazymį (arba -1 baigti): ";
        while (true) {
            x=getInt(-1, 10);
            if(x==-1) break;
            temp.paz.push_back(x);
            std::cout<<"Irasykite studento nd pazymi (arba -1 baigti): ";
        }
        std::cout<<"Įrašykite studento egzamino pažymį: ";
        temp.egz=getInt(0, 10);
        A.push_back(temp);
        std::cout<<"Įrašykite studento vardą (arba -1 baigti): ";
    }
}

void generuotiPazymius(std::list<studentas>& A, int& m) {
    studentas temp;
    int n, x;
    std::cout<<"Po kiek nd pažymių generuoti: ";
    std::cin>>n;
    std::cout<<"Įrašykite studento vardą (arba -1 baigti): ";
    while (std::cin>>temp.vardas && temp.vardas!="-1") {
        std::cout<<"Įrašykite studento pavardę: ";
        std::cin>>temp.pavarde;
        m++;
        temp.paz.clear();
        for (int i=0; i<n; i++){
            x=rand()%10+1;
            temp.paz.push_back(x);
        }
        temp.egz=rand()%10+1;
        A.push_back(temp);
        std::cout<<"Įrašykite studento vardą (arba -1 baigti): ";
    }
}

void generuotiViska(std::list<studentas>& A, int& m) {
    studentas temp;
    int n, x;
    std::cout<<"Kiek studentų sugeneruoti: ";
    std::cin>>m;
    std::cout<<"Po kiek nd pažymių generuoti: ";
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

void skaitytiIsFailo(std::list<studentas>& A, int& m, std::string& failas) {
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

void generuotiFaila(){
    int n;
    std::cout<<"Kiek studentu norite generuoti?: ";
    n=getInt(1,10000000);

    auto tStart = chr::high_resolution_clock::now();

    std::ofstream fout("generuotas.txt");
    fout<<std::left<<std::setw(20)<<"Vardas"<<std::setw(20)<<"Pavarde";
    for (int i=0; i<15; i++) {
        fout<<std::setw(20)<<("ND" + std::to_string(i + 1));
    }
    fout<<"Egz.";
    for (int i=1; i<=n; i++) {
        fout<<'\n'<<std::setw(20)<<("Vardas"+std::to_string(i))<<std::setw(20)<<("Pavarde"+std::to_string(i));
        for (int i=0; i<16; i++) {
            fout<<std::setw(20)<<rand()%10+1;
        }
    }
    fout.close();

    auto tEnd = chr::high_resolution_clock::now();
    std::cout<<"Failo kurimas ("<<n<<" studentu): "<<chr::duration_cast<chr::milliseconds>(tEnd-tStart).count()<<" ms\n";
}

void skirstymas(std::list<studentas>& studentai, std::list<studentas>& nevykeliai) {
    auto it = std::stable_partition(studentai.begin(), studentai.end(), [](const studentas& s){ return s.gal >= 5; });
    nevykeliai.assign(it, studentai.end());
    studentai.erase(it, studentai.end());
}
