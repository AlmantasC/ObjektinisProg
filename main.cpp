#include <string>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <chrono>
#include "mylib.h"
using std::cin;
using std::string;
using std::cout;
using std::setw;
using std::vector;
using std::sort;
namespace chr = std::chrono;

int main(){
    std::srand(std::time(0));
    vector<studentas> A;
    studentas temp;
    int m=0, n=0, x;

    // --------- PASIRINKIMAI ---------

    cout<<"[1] - Ivedimas ranka\n[2] - Generuoti tik pazymius\n[3] - Generuoti viska\n[4] - Skaitymas is failo\n[5] - baigti darba\nJusu pasirinkimas: ";
    int ivedimas=getInt(1, 5);

    string failas;
    switch (ivedimas) {
        case 5: return 0;
        case 4: failas=getFile();
    }

    cout<<"Pasirinkite pagal ka rusiuoti ([1] - varda, [2] - pavarde, [3] - galutini): ";
    int rusiavimas=getInt(1, 3);

    cout<<"Pasirinkite galutinio skaiciavimo buda ([1] - vidurkis arba [2] - mediana): ";
    int skaiciavimas=getInt(1, 2);

    cout<<"Pasirinkite isvedimo buda ([1] - i faila arba [2] - i ekrana): ";
    int isvedimas=getInt(1, 2);

    // --------- IVEDIMAS ---------

    auto tStart = chr::high_resolution_clock::now();

    switch (ivedimas) {
        case 1: {
            cout<<"Irasykite studento varda (arba -1 baigti): ";
            while (cin>>temp.vardas && temp.vardas!="-1") {
                cout<<"Irasykite studento pavarde: ";
                cin>>temp.pavarde;
                m++;
                temp.paz.clear();
                cout<<"Irasykite studento nd pazymi (arba -1 baigti): ";
                while (cin>>x && x!=-1) {
                    if (x>=0 && x<=10) {
                        temp.paz.push_back(x);
                        cout<<"Irasykite studento nd pazymi (arba -1 baigti): ";
                    }
                    else cout<<"Neteisinga ivestis, bandykite dar karta: ";
                }
                cout<<"Irasykite studento egzamino pazymi: ";
                cin>>temp.egz;
                A.push_back(temp);
                cout<<"Irasykite studento varda (arba -1 baigti): ";
            }
            break;
        }
        case 2: {
            cout<<"Po kiek nd pazymiu generuoti: ";
            cin>>n;
            cout<<"Irasykite studento varda (arba -1 baigti): ";
            while (cin>>temp.vardas && temp.vardas!="-1") {
                cout<<"Irasykite studento pavarde: ";
                cin>>temp.pavarde;
                m++;
                temp.paz.clear();
                for (int i=0; i<n; i++){
                    x=rand()%10+1;
                    temp.paz.push_back(x);
                }
                temp.egz=rand()%10+1;
                A.push_back(temp);
                cout<<"Irasykite studento varda (arba -1 baigti): ";
            }
            break;
        }
        case 3: {
            cout<<"Kiek studentu sugeneruoti: ";
            cin>>m;
            cout<<"Po kiek nd pazymiu generuoti: ";
            cin>>n;
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
            break;
        }
        case 4: {
            string line;
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
            break;
        }
    }
    // --------- SKAICIAVIMAI ---------

    switch (skaiciavimas){
        case 1: for (int i=0; i<m; i++) A[i].gal=0.4*vid(A[i])+0.6*A[i].egz; break;
        case 2: for (int i=0; i<m; i++) A[i].gal=0.4*med(A[i])+0.6*A[i].egz; break;
    }


    // --------- RUSIAVIMAS ---------

    switch (rusiavimas) {
        case 1: sort(A.begin(), A.end(), pagalVard); break;
        case 2: sort(A.begin(), A.end(), pagalPavard); break;
        case 3: sort(A.begin(), A.end(), pagalGal); break;
    }

    // --------- ISVEDIMAS ---------

    switch (isvedimas) {
        case 1: {
            std::ofstream fout("isvedimas.txt");
            fout<<std::fixed<<std::setprecision(2)<<std::left<<setw(15)<<"Vardas"<<setw(15)<<"Pavarde"<<"Galutinis ";
            if (skaiciavimas==1) fout<<"(Vid.)";
            else fout<<"(Med.)";
            fout<<"\n------------------------------------------------\n";
            for (int i=0; i<m; i++) {
                fout<<std::left<<setw(15)<<A[i].vardas<<setw(15)<<A[i].pavarde<<setw(15)<<A[i].gal<<'\n';
            }
        fout.close();
        break;
        }
        case 2: {
            cout<<std::fixed<<std::setprecision(2)<<std::left<<setw(15)<<"Vardas"<<setw(15)<<"Pavarde"<<"Galutinis ";
            if (skaiciavimas==1) cout<<"(Vid.)";
            else cout<<"(Med.)";
            cout<<"\n------------------------------------------------\n";
            for (int i=0; i<m; i++) {
                cout<<std::left<<setw(15)<<A[i].vardas<<setw(15)<<A[i].pavarde<<setw(15)<<A[i].gal<<'\n';
            }
            break;
        }
    }

    auto tEnd = chr::high_resolution_clock::now();
    cout<<"\nUztruko: "<<chr::duration_cast<chr::milliseconds>(tEnd-tStart).count()<<" ms\n";

    return 0;
}
