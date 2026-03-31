#include <string>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <list>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <chrono>
#include "mylib.h"
#include <windows.h>

using std::cin;
using std::string;
using std::cout;
using std::setw;
using std::list;
namespace chr = std::chrono;

int main(){
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    std::srand(std::time(0));
    list<studentas> A;
    studentas temp;
    int m=0;

    // --------- PASIRINKIMAI ---------

    cout<<"[1] - Įvedimas ranka\n[2] - Generuoti tik pažymius\n[3] - Generuoti viską\n[4] - Skaitymas iš failo\n[5] - Failu generavimas\n[6] - Baigti darbą\nJūsų pasirinkimas: ";
    int ivedimas=getInt(1, 6);

    string failas;
    switch (ivedimas) {
        case 6: return 0;
        case 5: generuotiFaila(); return 0;
        case 4: failas=getFile();
    }

    cout<<"Pasirinkite pagal ką rūšiuoti ([1] - vardą, [2] - pavardę, [3] - galutinį): ";
    int rusiavimas=getInt(1, 3);

    cout<<"Pasirinkite galutinio skaičiavimo budą ([1] - vidurkis arba [2] - mediana): ";
    int skaiciavimas=getInt(1, 2);

    cout<<"Pasirinkite išvedimo budą ([1] - į failą, [2] - į ekraną arba [3] - skirstymas): ";
    int isvedimas=getInt(1, 3);

    // --------- IVEDIMAS ---------

    auto tStart = chr::high_resolution_clock::now();

    switch (ivedimas) {
        case 1: ivestiRanka(A, m); break;
        case 2: generuotiPazymius(A, m); break;
        case 3: generuotiViska(A, m); break;
        case 4: skaitytiIsFailo(A, m, failas); break;
    }
    auto tNuskaitymasEnd = chr::high_resolution_clock::now();
    cout << "\nNuskaitymas:   " << chr::duration_cast<chr::milliseconds>(tNuskaitymasEnd-tStart).count() << " ms";
    // --------- SKAICIAVIMAI ---------

    switch (skaiciavimas){
        case 1: for (auto& s : A) s.gal = 0.4*vid(s) + 0.6*s.egz; break;
        case 2: for (auto& s : A) s.gal = 0.4*med(s) + 0.6*s.egz; break;
    }


    // --------- RUSIAVIMAS ---------
    auto tRusiavimasStart = chr::high_resolution_clock::now();
    switch (rusiavimas) {
        case 1: A.sort(pagalVard); break;
        case 2: A.sort(pagalPavard); break;
        case 3: A.sort(pagalGal); break;
    }
    auto tRusiavimasEnd = chr::high_resolution_clock::now();
    cout << "\nRūšiavimas:    " << chr::duration_cast<chr::milliseconds>(tRusiavimasEnd-tRusiavimasStart).count() << " ms";
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
        case 3: {
            list<studentas> nevykeliai, nerds;
            auto tSkirstymasStart = chr::high_resolution_clock::now();
            skirstymas(A, nevykeliai, nerds);
            auto tSkirstymasEnd = chr::high_resolution_clock::now();
            cout<<"\nSkirstymas:        "<<chr::duration_cast<chr::milliseconds>(tSkirstymasEnd-tSkirstymasStart).count()<<" ms";

            std::ofstream fout("nevykeliai.txt");
            printRez(fout, nevykeliai, skaiciavimas);
            fout.close();
            std::ofstream foute("nerds.txt");
            printRez(foute, nerds, skaiciavimas);
            foute.close();
            }
        }

    auto tEnd = chr::high_resolution_clock::now();
    cout<<"\nIš viso užtruko:   "<<chr::duration_cast<chr::milliseconds>(tEnd-tStart).count()<<" ms\n";

    return 0;
}
