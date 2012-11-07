#include <stdio.h>
#include <stack>
#include <iostream>

using namespace std;

int main() {
	
	stack <int> stos;
	string wejscie;
	int test;
	int dlugosc;
	int liczba = 0, a, b;
	char liczbaChar[7];
	int liczbaInt[7];
	int j = 0;
	int mnoznik = 1;
	bool ujemna = false;
	int licznik = 0;
	int tempI;
	
	scanf ("%d\n", &test);
	
	for (int i = 0; i < test; i++) {
		
			while (!stos.empty()) stos.pop();
			dlugosc = 0;
			liczba = 0;
			a = 0;
			b = 0;
			j = 0;
			mnoznik = 1;
			ujemna = false;
			licznik = 0;
			tempI = 0;

			for (int p = 0; p < 7; p++) {

				liczbaChar[p] = ' ';
				liczbaInt[p] = -1;

			}
	
			getline(cin, wejscie);
			dlugosc = wejscie.length();
			for (int licznik = dlugosc-1; licznik >= 0; licznik--) {

				if (wejscie[licznik] == 42) {

					a = stos.top();
					stos.pop();
					b = stos.top();
					stos.pop();
					stos.push(a * b);

				}
				else if (wejscie[licznik] == 43) {

					a = stos.top();
					stos.pop();
					b = stos.top();
					stos.pop();
					stos.push(a + b);

				}
				else if (wejscie[licznik] == 47) {

					a = stos.top();
					stos.pop();
					b = stos.top();
					stos.pop();
					stos.push(a / b);

				}
				else if (wejscie[licznik] == 45) {

						a = stos.top();
						stos.pop();
						b = stos.top();
						stos.pop();
						stos.push(a - b);

				}
				else if (wejscie[licznik] >= 48 && wejscie[licznik] <= 57) {
	
					if (wejscie[licznik-1] == ' ') stos.push(wejscie[licznik] - 48);
					
					else if ((wejscie[licznik-1] >= 48 && wejscie[licznik-1] <= 57) || wejscie[licznik-1] == '-') {
							j = 0;
							while (wejscie[licznik-j] != ' ' && wejscie[licznik-j] != '-') {

								liczbaChar[j] = wejscie[licznik-j];
								j++;

                            }
                            ujemna = false;
							if (wejscie[licznik-j] == '-') {

								ujemna = true;
								wejscie[licznik-j] = ' ';

							}
							for (int p = j-1; p >= 0; p--) {
                                
								liczbaInt[j-1-p] = liczbaChar[p] - 48;
							}
							mnoznik = 1;
							liczba = 0;
							for (int p = j-1; p >= 0; p--) {
                                
                                tempI = liczbaInt[p];
                                liczba += tempI * mnoznik;
                                mnoznik *= 10;     
                                    
							}
							if (ujemna == true) liczba = 0 - liczba;
							stos.push(liczba);
							licznik -= j;
					}
				}
				
			}

			if (stos.empty() == false) printf ("%d\n", stos.top());
	}

	return 0;
}
