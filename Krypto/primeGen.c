// Katarzyna Huszcza, gr. 1, 139614
// 64-bit Prime Numbers Generator

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

int powers2[31] = {1<<0,  1<<1,  1<<2,  1<<3,  1<<4,  1<<5,  1<<6,
  1<<7,  1<<8,  1<<9,  1<<10, 1<<11, 1<<12, 1<<13,
  1<<14, 1<<15, 1<<16, 1<<17, 1<<18, 1<<19, 1<<20,
  1<<21, 1<<22, 1<<23, 1<<24, 1<<25, 1<<26, 1<<27,
  1<<28, 1<<29, 1<<30};

long long int fastExpotentaion (long long int a, long long int d, long long int primeToBe);
int MillerRabin (long long int primeToBe, int k);
void generatePrime();

int main() {
	
	generatePrime();
	
	return 0;
}

// fast modulo expotentation

long long int fastExpotentaion (long long int a, long long int d, long long int primeToBe) {
	
	long long int i;
	long long int temp = a%primeToBe;
	long long int result = 1;
	
	for (i = 1; i <= d; i <<= 1) {
		
		temp %= primeToBe;
		if ((d&i) != 0) {
			
			result *= temp;
			result %= primeToBe;
			
		}
		temp *= temp;
	}
	
	return result;
};

// Miller-Rabin's test

int MillerRabin (long long int primeToBe, int k) {
	
	int exp = 0;
	int power = 1;
	int temp;
	int d, i, r, a;
	
	while ((power & (primeToBe - 1)) == 0) {
		
		exp++;
		power <<= 1;
		
	}
	
	d = primeToBe/power;
	
	for (i = 0; i < k; i++) {
		
		srand(time(0) + i);
		a = 1 + (rand() % (primeToBe - 1));
		if (fastExpotentaion(a, d, primeToBe) != 1) {
			
			temp = 0;
			for (r = 0; r <= exp - 1; r++) {
				
				if (fastExpotentaion(a, powers2[4] * d, primeToBe) == primeToBe - 1) {
					
					temp = 1;
					break;
					
				}
				
			}
			
			if (temp == 0) return 0;
			
		}
	}
	
	return 1;
	
}

// "real main" function

void generatePrime() {
	
	long long int primeToBe = 0;
	int k = 3;
	int i;
	
	for (i = 13; i >= 0; i--) {
		
		srand(time(0) + i);
		if (i == 0) primeToBe += 7;
		else primeToBe += (rand() % 10) * pow (10.0,i);
		
	}
	
	if (MillerRabin(primeToBe, k) == 1) printf ("%lld", primeToBe);
	else generatePrime();
};
