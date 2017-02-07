#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int main() {
 int capital = 1000000;
 string buildings[]={"angar","barrack","hran","factory"};
 int poddan=0;
 cout << " your money = " << capital << "\n";
 
 cout << "your buildings  " << buildings[1] << "\n";
 cout << "you have = " << poddan << " poddanih now";
 cout<<"\n***************\n";
 cout << "MENU SELECT ";
  cout<<"\n";
 cout << "0 view profile";
   cout<<"\n";
 cout << "1 buy build";
   cout<<"\n";
 cout << "2 buy jobmans";
   cout<<"\n";
 
 int cf;
 cin>>cf;
 switch(cf)
    {
        case 0:
        printf("oo");
        break;
        default:
        printf("kk");
        break;
    }
 	return 0;
}
