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
        case 1: ivestiRanka(A, m); break;
        case 2: generuotiPazymius(A, m); break;
        case 3: generuotiViska(A, m); break;
        case 4: skaitytiIsFailo(A, m, failas); break;
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
            printRez(fout, A, skaiciavimas);
            fout.close();
            break;
        }
        case 2: {
            printRez(cout, A, skaiciavimas);
            break;
        }
    }

    auto tEnd = chr::high_resolution_clock::now();
    cout<<"\nUztruko: "<<chr::duration_cast<chr::milliseconds>(tEnd-tStart).count()<<" ms\n";

    return 0;
}
