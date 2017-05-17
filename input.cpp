#include <iostream> 
#include <string>
#include <stdlib.h>
#include <cmath>
#include "binary.h"
#include "input.h"

using namespace std;

/* Funkcja bin2dec zamienia wejsiciowy argument jakim jest struktura 
 * Binary i nastepnie zamienia ja na wartosc calkowita, ktora jest 
 * zwracana.
 */
int bin2dec(Binary bin){
    int i,value=0;
    for(i=0;i<8;i++){
    value +=(bin.val[7-i]*pow(2,i));
    }
    return value;
}

/* Funcja input wczytuje z klawiatury wartosci binarne. 
 * Jest zabezpieczona na wszelkiego rodzaju bledne dane wejsciowe,
 * czyli na za krotka liczbe, pojawienie sie cyfry innej niz 0 lub 1.
 * Zwracana jest struktura Binary do ktorej zostaly wpisane poprawne dane
 */

Binary input(){
   string in;
   int i;
   Binary bin;
   bool check =1;
   do{
    cout << " Podaj 8bitowa liczbe!: ";
    cin >>in;
    if (in.size() == 8){
        i=0;
        do{
			check =1;
            if((in[i] != 48) && (in[i] != 49)) {
                check = 0;
            }
        i++;
        }while(i<8 && check == 1);
        if(check == 1) {
            for(i=0;i<8;i++) bin.val[i] = in[i]-48;
        break;
        }
    //system("clear");
    cout <<in<<" nie jest liczba binarna!!!"<<endl;
    }
    else {
    //system("clear");
    cout << in<<" ma zla dlugosc !!! "<<endl;
    }
   }while(1);
   cout << " Podales liczbe: "<<bin2dec(bin)<<endl;
   return bin;
}
