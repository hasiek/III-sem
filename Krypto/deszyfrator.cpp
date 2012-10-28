// Deszyfrator szyfru Cezara (j. angielski) - 2. laboratorium z Kryptografii
// Katarzyna Huszcza, 28.10.2012

#include <stdio.h>
#include <cstdlib>
#include <math.h>
#include <string.h>

struct Temp {

	int wartosc;
	char litera;

};

#define ALFABET 26

int main() {

    int male[ALFABET]; // tablica na ilosc wystapien malych liter
    char wejscie[10000];
    int wielkosc=0;
    int licznik=0, i=0;
    int n=0;
	FILE *out = fopen("out.txt","r");
	FILE *plik = fopen("plik.txt","w");
	struct Temp temp;
	bool max;
	int klucz;
	int tymczas = 0;

	if (plik == NULL || out == NULL) {

		printf ("[fopen] ERROR!\n");
		system("pause");
		return 1;

	}
	
	// czyszczenie tablicy
    
    for (i=0; i < ALFABET; i++) {
		
        male[i] = 0;
    }
    
    // wypelnienie tablic iloscia wystapien danej litery - tylko dla malych liter
    // zapisuje po kolei, po dodaniu 97 ('a') do indeksu, otrzymujemy kod ASCII zliczonej litery

    while (fgets (wejscie, sizeof wejscie, out)) {
        
        wielkosc = strlen (wejscie);
        
        for (i=0; i < wielkosc; i++) {

            if (wejscie[i] >= 97 && wejscie[i] <= 122) male[wejscie[i]-97]++; // 97 - 122 - kody ASCII malych liter
        
		}
	}
	
	// zamkniecie pliku, aby wyczyscic wskaznik

	fclose(out);
    out = fopen ("out.txt","r");

    i=0;
    
    // szukanie maksimum z tablicy

	temp.wartosc = male[0];
	temp.litera = 97;
        
    for (i=0; i <= ALFABET-1; i++) {
			
			max = temp.wartosc < male[i];
			if (max == true) {

				temp.wartosc = male[i];
				temp.litera = 97+i;

			}
     }
     
     // obliczanie klucza, 'e' najczesciej wystepujaca litera w j. angielskim

	klucz = temp.litera - 'e';

	// odszyfrowywanie
	
	while (fgets(wejscie, sizeof wejscie, out)) {

		for (i = 0; i < sizeof wejscie; i++) {

			tymczas = wejscie[i];
			if (tymczas >= 48 && tymczas <= 57) {

				tymczas = tymczas - 48;
				tymczas = tymczas - klucz;
				while (tymczas < 0) tymczas = 10 - abs(tymczas);
				tymczas = tymczas + 48;

			}
			if (tymczas >= 65 && tymczas <= 90) {

				tymczas = tymczas - 65;
				tymczas = tymczas - klucz;
				if (tymczas < 0) tymczas = 26 - abs(tymczas);
				tymczas = tymczas + 65;

			}
			if (tymczas >= 97 && tymczas <= 122) {

				tymczas = tymczas - 97;
				tymczas = tymczas - klucz;
				if (tymczas < 0) tymczas = 26 - abs(tymczas);
				tymczas = tymczas + 97;
			}
			
			wejscie[i] = tymczas;

		}

		fprintf (plik, "%s", wejscie);
	}

	fclose(out);
	fclose(plik);
	printf("\n");
	system("pause");
	return 0;
}
