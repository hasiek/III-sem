// Implementacja szyfru przestawnego a'la szyfr Cezara - 2. laboratorium z Kryptografii
// Katarzyna Huszcza, 27.10.2012

#include <stdio.h>
#include <cstdlib>

int main() {

	char wejscie[10000];
	int klucz = 13;
	int temp = 0;
	FILE *plik = fopen("plik.txt","r");
	FILE *out = fopen("out.txt", "w");

	if (plik == NULL || out == NULL) {

		printf ("[fopen] ERROR!\n");
		system("pause");
		return 1;
	}
	
	// szyfrowanie
	
	while (fgets(wejscie, sizeof wejscie, plik)) {

		for (int i = 0; i < sizeof wejscie; i++) {

			temp = wejscie[i];
			if (temp >= 48 && temp <= 57) {

				temp = temp - 48;
				temp = temp + klucz;
				temp = temp % 10;
				temp = temp + 48;

			}
			if (temp >= 65 && temp <= 90) {

				temp = temp - 65;
				temp = temp + klucz;
				temp = temp % 26;
				temp = temp + 65;

			}
			if (temp >= 97 && temp <= 122) {

				temp = temp - 97;
				temp = temp + klucz;
				temp = temp % 26;
				temp = temp + 97;
			}
			wejscie[i] = temp;
		
		}

		fprintf(out, "%s", wejscie);

	}

	fclose(plik);
	fclose(out);
	printf("\n");
	system("pause");
	return 0;
}
