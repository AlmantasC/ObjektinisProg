#pragma once
#include <string>
#include <vector>

struct studentas {
    std::string vardas, pavarde;
    std::vector<int> paz;
    int egz;
    double rez=0;
    double gal;
};

std::string randomstr();
bool pagalVard(studentas a, studentas b);
bool pagalPavard(studentas a, studentas b);
bool pagalGal(studentas a, studentas b);
