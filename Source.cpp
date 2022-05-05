#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int numar[13] = { 1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000 };
string litere[14] = { "I", "IV", "V","IX", "X", "XL","L","XC", "C","CD", "D","CM", "M"};

//Gaseste cifra romana cea mai mica si cea mai apropiata de numarul din cifre[]
int ind_nr_apropiat(int nr){
	int i;

	for(i=13-1;i>0;i--){
		if(nr-numar[i]>=0 && nr-numar[i]<nr-numar[i-1]){  //daca diferenta e pozitiva(adica nr e mai mare decat numar[i]) si diferenta este mai mica decat numarul anterior din vectorul numar, atunci acela este numarul cel mai apropiat
			return i;
		}
	}

	return i;
}

int main() {
	int N;
	int cifre[4];
	int i=0;
	int contor=0;
	string rezultat;

	cout<<"---== CONVERTOR NUMERE ARABE -> NUMERE ROMANE ==---"<<endl;
	cout<<"N = ";
	cin>>N;
	cout<<"Rezultat = ";

	while(N>0){
		cifre[i] = N%10*pow(10,i); //cifrele se salveaza incepand de la ordinul cel mai mic si se adauga numarul de zerouri corespunzatoare
		N = N/10;
		i++;
	}

	for(int j=i-1;j>=0;j--){
		int indice = ind_nr_apropiat(cifre[j]);
		rezultat+=litere[indice]; //afiseaza cifra romana corespunzatoare

		contor=0;
		contor = numar[indice]+contor; 
		
	
		while(contor<cifre[j]){ //bug: numerele nu sunt scurtate, de ex: 900 = DCCCC si nu CM 
			indice=ind_nr_apropiat(cifre[j]-contor);
			contor = numar[indice]+contor;
			rezultat+=litere[indice];
		
		}
	}

	cout<<rezultat;
	return 0;
}