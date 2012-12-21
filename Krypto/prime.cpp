// (256+ bitowe)
// tu - 64-bitowe

#include <iostream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <stack>

using namespace std;

long long int generatePrime ();
long long int power(long long int wannaBePrime);
stack <int> changeToBinary (long long int number);
bool expotentation (long long int number, long long int d, long long int a);
bool expotentation2 (long long int number, long long int d, long long int powerOfTwo, long long int a);
void aRealMain();

int main() {
	
	aRealMain();
	
	return 0;
}

// generating a number

long long int generatePrime () {
	
	long long int generatedPrime = 0;
	int part;
	
	for (int i = 0; i < 18; i++) {
		
		srand (time(0) + i*i);
		part = rand() % 10;
		generatedPrime += part * pow(10,i);

	}
	
	if (generatedPrime % 2 == 0) generatedPrime--;
	
	return generatedPrime;
};

// founding the biggest power of 2 that divides generated number

long long int power(long long int wannaBePrime) {
	
	wannaBePrime--;
	long long int found = 2;
	long long int i = 0;
	
	while (wannaBePrime % found == 0) {
		
		i++;
		found = pow(2,i);
		
	}
	
	i--;
	
	return i;
	
};

// converting the number into it's binary form

stack <int> changeToBinary (long long int number) {
	
	stack <int> binary;
	int temp;
	
	while (number > 1) {
		
		temp = number % 2;
		binary.push(temp);
		number /= 2;
		
	}
	
	return binary;
	
};

// expotentation

bool expotentation (long long int number, long long int d, long long int a) {
	
	stack <int> binary;
	long long int expotentated = 1;
	long long int temp;
	
	// counting (a^d) % number
	
	binary = changeToBinary(d);
	
	for (int i = 0; i < binary.size(); i++) {
		
		if (binary.top() == 0) binary.pop();
		else {
			
			temp = (pow (a, binary.top() * pow(2, i)));
			expotentated *= temp % number;
			binary.pop();
			
		}
		
	}
	
	if (expotentated == 1) return false;
	else return true;
	
	
};

// expotentation2

bool expotentation2 (long long int number, long long int d, long long int powerOfTwo, long long int a) {
	
	stack <int> binary;
	long long int expotentated = 1;
	long long int temp;
	
	for (int i = 0; i < powerOfTwo; i++) {
		
		binary = changeToBinary(a * pow(2,i));
		for (int j = 0; j < binary.size(); j++) {
			
			if (binary.top() == 0) binary.pop();
			else {
			
			temp = (pow (a, binary.top() * pow(2, i)));
			expotentated *= temp % number;
			binary.pop();
			
			}
		}
		
		if (expotentated == number - 1) continue;
		else return false;
		
	}
	
	return true;
}

void aRealMain() {
	
	long long int wannaBePrime = 0;
	long long int powerOfTwo;
	long long int d = 0;
	bool firstTest;
	long long int a;
	
	wannaBePrime = generatePrime();
	
	powerOfTwo = power(wannaBePrime);
	d = wannaBePrime / pow(2, powerOfTwo);
	srand(time(0));
	a = 1 + (rand() % (d - 1));
	firstTest = expotentation(wannaBePrime,d,a);
	if (firstTest == false) aRealMain();
	else {
		
		if(expotentation2(wannaBePrime,d,powerOfTwo,a) == true) cout << wannaBePrime << " jest liczba pierwsza.\n";
		else aRealMain();
	}
	
};
