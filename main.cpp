#include <string>
#include <iostream>
#include <vector>
#include <iomanip>
using std::cin;
using std::vector;
using std::string;
using std::cout;
using std::setw;
int main()
{
  struct studentas{
      string vardas, pavarde;
      vector <int> paz;
      double rez=0;
      };
      int temp, n=0;
      studentas A;
      cin>>A.vardas>>A.pavarde;
      while(cin>>temp) {
        A.paz.push_back(temp);
        A.rez+=A.paz[n];
        n++;
      };
      A.rez/=n;
      cout<<"Vardas"<<setw(10)<<"\tPavarde"<<setw(10)<<"\tGalutinis\n";
      cout<<"--------------------------------------------\n";
      cout<<A.vardas<<setw(10)<<'\t'<<A.pavarde<<setw(10)<<std::fixed<<std::setprecision(2)<<'\t'<<A.rez;
}
