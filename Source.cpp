#include <iostream>
#include <cmath>
using namespace std;

//Gaseste cifra romana cea mai mica si cea mai apropiata de numarul din cifre[]
int ind_nr_apropiat(int nr){
	int numar[7] = { 1, 5, 10, 50, 100, 500, 1000 };
	int i;

	for(i=6;i>0;i--){
		if(nr-numar[i]>=0 && nr-numar[i]<nr-numar[i-1]){  //daca diferenta e pozitiva(adica nr e mai mare decat numar[i]) si diferenta este mai mica decat numarul anterior din vectorul numar, atunci acela este numarul cel mai apropiat
			return i;
		}
	}

	return i;
}

int main() {
	int N = 1986;
	int numar[7] = { 1, 5, 10, 50, 100, 500, 1000 };
	char litere[8] = { 'I', 'V', 'X', 'L', 'C', 'D', 'M', '\0' };
	int cifre[4];
	int i=0;
	int contor=0;

	/*
	citire N de la tastatura

	*/

	while(N>0){
		cifre[i] = N%10*pow(10,i); //cifrele se salveaza incepand de la ordinul cel mai mic si se adauga numarul de zerouri corespunzatoare
		N = N/10;
		i++;
	}


	for(int j=i-1;j>=0;j--){
		int indice = ind_nr_apropiat(cifre[j]);
		cout<<litere[indice]; //afiseaza cifra romana corespunzatoare

		contor=0;
		contor = numar[indice]+contor; 
		
	
		while(contor<cifre[j]){ //bug: numerele nu sunt scurtate, de ex: 900 = DCCC si nu CM 
			indice=ind_nr_apropiat(cifre[j]-contor);
			contor = numar[indice]+contor;
			cout<<litere[indice];
		
		}
		cout<<endl;
	}
	return 0;
}