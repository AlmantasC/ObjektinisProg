#pragma once
#include <string>
#include <deque>
#include <vector>
#include <fstream>
struct studentas {
    std::string vardas, pavarde;
    std::vector<int> paz;
    int egz;
    double rez=0;
    double gal;
};
double vid (studentas A);
double med (studentas A);
std::string randomstr();
bool pagalVard(studentas a, studentas b);
bool pagalPavard(studentas a, studentas b);
bool pagalGal(studentas a, studentas b);
int getInt(int min, int max);
std::string getFile();
void printRez(std::ostream& out, std::deque<studentas>& A, int skaiciavimas);
void ivestiRanka(std::deque<studentas>& A, int& m);
void generuotiPazymius(std::deque<studentas>& A, int& m);
void generuotiViska(std::deque<studentas>& A, int& m);
void skaitytiIsFailo(std::deque<studentas>& A, int& m, std::string& failas);
void generuotiFaila();
void skirstymas(std::deque<studentas>& studentai, std::deque<studentas>& nevykeliai, std::deque<studentas>& nerds);
