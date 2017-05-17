#ifndef BINARY_H_INCLUDED
#define BINARY_H_INCLUDED
//#include "input.h"
#include <iostream>
#include <vector>
struct Binary{int val[8];};


class TBinary{
    std::vector<Binary> vect;
    // wektor vect przechowuje zbiór liczb binarnych 
    std::vector<int> dec;
    // wektor dec przechowuje wartosc decymalna wartosci binarnej
    
    public:
    bool VectorCheck(int in);
    void VectorInput();
    void VectorPushOne();
    void ValueMax();
    void ValueMin();
    friend std::ostream&operator<<(std::ostream &wyj,const TBinary & bin);
    TBinary();
    ~TBinary();
    TBinary operator+(const TBinary & z);
    TBinary operator*(const TBinary & z);
    TBinary& operator+=(const TBinary & z);
    TBinary& operator*=(const TBinary & z);
	
};


#endif // BINARY_H_INCLUDED
