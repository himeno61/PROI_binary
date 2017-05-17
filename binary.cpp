#include "binary.h"
#include "input.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

/* Funkcja VectorCheck sprawdza czy dana wartosc przekazana do niej 
 * nalezy do danego zbioru czy nie. W przypadku gdy nalezy zwracana jest
 * wartosc 0, w przeciwnym przypadku wartosc 1.
 */
bool TBinary::VectorCheck(int in){
		int i;
		bool check =1;
		for(i=0;i<dec.size();i++){
			if(in == dec[i]) check =0;
		}
		return check;
}

/* Funkcja VectorInput sluzy do wprowadzania danych do zbioru. Pobiera
 * od uzytkownika wielkosc zbioru i nastepnie wczytuje dane. Wykorzystana
 * jest tu funkcja input() z pliku input.cpp. Przy wpisywaniu sprawdzane
 * jest czy juz nie zostala podana wczesniej taka wartosc. Zapisywana 
 * jest liczba do wektora vect a do wektora dec wpisywana jest wartosc
 * decymalna po zamienie przy uzyciu funkcji bin2dec z pliku input.cpp
 */
void TBinary::VectorInput(){
	int Vsize,i,x;
	cout << " Podaj wielkosc zbioru: ";
	cin >> Vsize;
	Binary temp;
	temp = input();
	for(i=0;i<Vsize;i++){
		if( i== 0){
			 vect.push_back(temp);
			 dec.push_back(bin2dec(temp));
		}
		else{
			temp=input();
			x = bin2dec(temp);
			while(1){
				if (VectorCheck(x) == 1){
					vect.push_back(temp);
					dec.push_back(x);
					break;
				}
				else {
					cout<<endl<<"LICZBA JEST JUZ W ZBIORZE!!!";
					cout<<"Podaj nowa! "<<endl;
					temp =input();
					x = bin2dec(temp);
				}
			}
		 }
	}
	
}

/* Funkcja VectorPushOne pozwala na dodanie jednej wartosci do naszego
 * zbioru. Podobnie jak w przypadku VectorInput prowadzona jest kontrola
 * w celu sprawdzenia czy juz takiej wartosci nie w zbiorze
 */
void TBinary::VectorPushOne(){
	cout <<" Zostanie dodana jedna liczba do zbioru. ";
	Binary temp;
	int x;
	temp =input();
	x= bin2dec(temp);
	while(1){
		if (VectorCheck(x) == 1){
			vect.push_back(temp);
			dec.push_back(x);
			break;
		}
		else {
			cout<<endl<<"LICZBA JEST JUZ W ZBIORZE!!!";
			cout<<"Podaj nowa! "<<endl;
			temp =input();
			x = bin2dec(temp);
		}
	}
	
}

/* Funkcja ValueMax przesukuje zbior w poszukiwaniu wartosci najwiekszej.
 * Wykorzystuje wektor dec w celu ulatwienia operacji.
 */
void TBinary::ValueMax(){
	int max, indeks=0,i;
	max =  dec[0];
	for(i=1;i<dec.size();i++){
		if(dec[i]>max){
			max = dec[i];
			indeks = i;
		}
	}
	cout<<" Najwieksza liczba w zbiorze to: ";
	for(i=0;i<8;i++){
	cout<<vect[indeks].val[i];
	}
	cout<<endl;
}

/* Funkcja ValueMin przesukuje zbior w poszukiwaniu wartosci najmniejszej.
 * Wykorzystuje wektor dec w celu ulatwienia operacji.
 */
void TBinary::ValueMin(){
	int min, indeks=0,i;
	min = dec[0];
	for(i=1;i<dec.size();i++){
		if(dec[i]<min){
			min = dec[i];
			indeks = i;
		}
	}
	cout<<" Najmniejsza liczba w zbiorze to: ";
	for(i=0;i<8;i++){
	cout<<vect[indeks].val[i];
	}
	cout <<endl;
}

// Przeciazenie operatora drukowania do strumienia.
ostream& operator<<(ostream &wyj, const TBinary & bin){
	int i,j,size;
	size = bin.vect.size();
	cout <<  " Liczba elentow: "<<size<<endl;
	for (i=0;i<size;i++){
		wyj <<i+1<<". ";
		for(j=0;j<8;j++)
			wyj<<bin.vect[i].val[j];
		wyj <<endl;
	}
	return wyj;
}

/* Przeciazenie operatora dodawania +. Przepisywane sa 
 *  wszystkie wartosci z pierwszego wektora a nastepnie
 * kazda wartosc ze zbioru t 2 jest sprawdzana czy nalezy 
 * juz do kopii. Jezeli nie, jest doopisywana na koncu wektora
 */
TBinary TBinary::operator+(const TBinary & t2){
	TBinary t3;
	Binary temp;
	int i,j;
	for(i=0;i<this->vect.size();i++){
		for(j=0;j<8;j++){
		temp.val[j] = vect[i].val[j];
		}
		t3.vect.push_back(temp);
		t3.dec.push_back(bin2dec(temp));		
	}
	for(i=0;i<t2.vect.size();i++){
		if(t3.VectorCheck(t2.dec[i]) == 1){
			for(j=0;j<8;j++){
				temp.val[j]= t2.vect[i].val[j];
			}
				t3.vect.push_back(temp);
				t3.dec.push_back(t2.dec[i]);
			
		}
	}
	//system("clear");
	return t3;
}

//Przeciazenie operatora mnozenia. 
TBinary TBinary::operator*(const TBinary & t2){	
	TBinary t3;
	Binary temp;
	int i,j;
	for(i=0;i<t2.vect.size();i++){
		if(VectorCheck(t2.dec[i]) == 0) {
			for(j=0;j<8;j++){
			temp.val[j]=t2.vect[i].val[j];
			}
			t3.vect.push_back(temp);
			t3.dec.push_back(t2.dec[i]);
		}
	}
	//system("clear");
	return t3;
}

/*  Przeciazenie operatora +=. Dziala na podobnej 
 * zasadzie jak przeciazenie operatora + tylko 
 * wartosci z t2 sa sprawdzane bez poprzedniego 
  * kopiowania wartosci z wektora poczatkowego.
  */
TBinary& TBinary::operator+=(const TBinary & t2){
	Binary temp;
	int i,j;
	for(i=0;i<t2.vect.size();i++){
		if(VectorCheck(t2.dec[i]) ==1){
			for(j=0;j<8;j++){
					temp.val[j]=t2.vect[i].val[j];
			}
			vect.push_back(temp);
			dec.push_back(t2.dec[i]);
		}	
	}
	return *this;
}

TBinary& TBinary::operator*=(const TBinary &t2){
	TBinary t3;
	Binary temp;
	int i,j;
	for(i=0;i<t2.vect.size();i++){
		if(VectorCheck(t2.dec[i]) == 0) {
			for(j=0;j<8;j++){
			temp.val[j]=t2.vect[i].val[j];
			}
			t3.vect.push_back(temp);
			t3.dec.push_back(t2.dec[i]);
		}
	}
	this->vect.clear();
	this->dec.clear();
	for(i=0;i<t3.vect.size();i++){
		for(j=0;j<8;j++){temp.val[j]=t3.vect[i].val[j];}
		vect.push_back(temp);
		dec.push_back(t3.dec[i]);
	}
	return *this;
}

// Konstruktor
TBinary::TBinary(){
}

/*Destruktor. Czysci wartosci obu wektorow 
  * wykorzystujac funkcje wbudowana dla wektorow.
  */
TBinary::~TBinary(){
	cout<<"Działa destruktor!!!"<<endl;
	vect.clear();
	dec.clear();
}
