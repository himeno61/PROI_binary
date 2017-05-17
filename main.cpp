#include "binary.h"
#include <iostream>

using namespace std;

int main()
{
	cout <<" 	Dla zbioru 1: "<<endl;
    TBinary t1;
    t1.VectorInput();
    cout <<"	Dla zbioru 2: "<<endl;
    TBinary t2;
    t2.VectorInput();
    /*
    cout <<" Zostanie teraz wypisany zestaw 1 przez operator << : "<<endl;
    cout <<t1;
    cout <<" Zostanie teraz wypisany zestaw 2 przez operator << : "<<endl;
    cout <<t2;
    cout <<" Dodasz jedna wartosc do zestawu 1: "<<endl;
    t1.VectorPushOne();
    cout <<" Dodasz jedna wartosc do zestawu 2: "<<endl;
    t2.VectorPushOne();
    cout <<" Zostanie teraz wypisany zestaw 1 przez operator << : "<<endl;
    cout <<t1;
    cout <<" Zostanie teraz wypisany zestaw 2 przez operator << : "<<endl;
    cout <<t2;    
    TBinary t3;
    t3 = t1+t2;
    cout << "Suma tych zbiorow przy pomocy +: "<<endl; 
    cout << t3;
    t3 = t1*t2;
    cout <<" Iloczyn tych zbiorow przy pomocy *: "<<endl;
    cout <<t3;
    t.ValueMax();
    t.ValueMin();    
    t1+=t2;
    cout <<t1;
    */
    t1*=t2;
    cout<<t1;
    return 0;
 }
