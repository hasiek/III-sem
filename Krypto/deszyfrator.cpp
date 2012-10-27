// Deszyfrator szyfru Cezara - 2. laboratorium z Kryptografii
// Katarzyna Huszcza, 27.10.2012

#include <stdio.h>
#include <cstdlib>
#include <string.h>

#define ALFABET 26

int main() {

	int wielkie[ALFABET]; // tablica na iloœæ wyst¹pieñ poszczególnych wielkich liter
    int male[ALFABET]; // tablica na iloœæ wyst¹pieñ poszczególnych ma³ych liter
    char wejscie[10000];
    int wielkosc=0;
    int licznik=0, i=0;
    int n=0;
	FILE *out = fopen("out.txt","r");
	FILE *plik = fopen("plik.txt","w");

	if (plik == NULL || out == NULL) {

		printf ("[fopen] ERROR!\n");
		system("pause");
		return 1;

	}
    
    for (i=0; i < ALFABET; i++) {
        wielkie[i] = 0;
        male[i] = 0;
    }

    while (fgets (wejscie, sizeof wejscie, out)) {
        
        wielkosc = strlen (wejscie);
        
        for (i=0; i < wielkosc; i++)
        {
            if (wejscie[i] >= 65 && wejscie[i] <= 90) // 65 - 90 - kody ASCII wielkich liter
            {
                 wielkie[wejscie[i]-65]++;
            }
            else if (wejscie[i] >= 97 && wejscie[i] <= 122) // 97 - 122 - kody ASCII ma³ych liter
            {
                 male[wejscie[i]-97]++;
            }
        }
	}
        
        i=0;
        
        for (i=(ALFABET-1); i >= 0; i--)
        {
            if (male[i] != 0)
            {
                        fprintf (plik,"%c ", i+97);
                        fprintf (plik,"%d\n", male[i]);
            }
        }

	fclose(out);
	fclose(plik);
	printf("\n");
	system("pause");
	return 0;
}