// 15.12.2012
// Katarzyna Huszcza


#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

int main() {
	
	string key;
	string input;
	int keyMatrix[2][2];
	int complementMatrix[2][2];
	int transComplementMatrix[2][2];
	int cyphMatrix[2][2];
	int det, det1;
    int inMatrix[2];
    int product[2];
    string cyphered;
    int border;
    bool letter1 = true, letter2 = true;
    fstream in ("return.txt");
    fstream out ("out.txt");
    
    cout << "Podaj czteroliterowy klucz, jakim zaszyfrowano tekst.\n";
    cin >> key;
   
	keyMatrix[0][0] = key[0] - 97;
	keyMatrix[0][1] = key[1] - 97;
	keyMatrix[1][0] = key[2] - 97;
	keyMatrix[1][1] = key[3] - 97;
	
	// creating a matrix of algebraic complements...
	
	complementMatrix[0][0] = keyMatrix[1][1];
	complementMatrix[0][1] = 0 - keyMatrix[1][0];
	complementMatrix[1][0] = 0 - keyMatrix[0][1];
	complementMatrix[1][1] = keyMatrix[0][0];
	
	// ... and transpositioning it
	
	transComplementMatrix[0][0] = complementMatrix[0][0];
	transComplementMatrix[1][1] = complementMatrix[1][1];
	transComplementMatrix[1][0] = complementMatrix[0][1];
	transComplementMatrix[0][1] = complementMatrix[1][0];
	
	// counting the determinant
	
	det = (keyMatrix[0][0] * keyMatrix[1][1]) - (keyMatrix[0][1] * keyMatrix[1][0]);
	
	// counting a reversion of the determinant in a Z26 residue class ring
	
	for (int i = 0; i < 26; i++) {
		
		if ((i*det) % 26 == 1) {
			
			det1 = i;
			break;
		}
	}
	
	// multiplying, by a determinant reversion; creating a reversed key matrix
	
	cyphMatrix[0][0] = (transComplementMatrix[0][0] * det1) % 26;
	cyphMatrix[0][1] = (transComplementMatrix[0][1] * det1) % 26;
	cyphMatrix[1][0] = (transComplementMatrix[1][0] * det1) % 26;
	cyphMatrix[1][1] = (transComplementMatrix[1][1] * det1) % 26;
	
	// computer can't count modulo from negative numbers, so it must be done manually
	
	for (int i = 0; i < 2; i++) {
		
		for (int j = 0; j < 2; j++) {
			
			if (cyphMatrix[i][j] < 0) while (cyphMatrix[i][j] < 0) cyphMatrix[i][j] += 26;
		}
	}
	
	while (getline (out, input)) {
		
		letter1 = true;
		letter1 = true;
	
		// dividing text into two-element parts
    
        if (input.length() % 2 != 0) border = input.length() - 1;
        else border = input.length();
        
        for (int counter = 0; counter < border; counter = counter + 2) {
			
			letter1 = true;
			letter2 = true;
            
            for (int i = 0; i < 2; i++) {
				
				if (input[counter + i] >= 97 && input[counter + i] <= 122) inMatrix[i] = input[counter + i] - 97;
				else if (input[counter + i] >= 65 && input[counter + i] <= 90) inMatrix[i] = input[counter + i] - 65;
				else {
					
					if (i == 0) letter1 = false;
					else if (i == 1) letter2 = false;
					inMatrix[i] = input[counter + i] - 32;
				}
				
			}
			
			// decyphering
            
            if (letter1 == true) product[0] = (cyphMatrix[0][0] * inMatrix[0]) + (cyphMatrix[0][1] * inMatrix[1]);
            else product[0] = inMatrix[0];
            
            if (letter2 == true) product[1] = (cyphMatrix[1][0] * inMatrix[0]) + (cyphMatrix[1][1] * inMatrix[1]);
            else product[1] = inMatrix[1];
            
            for (int i = 0; i < 2; i++) {
                
                if (input[counter + i] >= 97 && input[counter + i] <= 122) {
					
					product[i] = product[i] % 26;
					cyphered[i] = product[i] + 97;
					in << cyphered[i];
				}
				else if (input[counter + i] >= 65 && input[counter + i] <= 90) {
					
					product[i] = product[i] % 26;
					cyphered[i] = product[i] + 65;
					in << cyphered[i];
					
				}
				else {
					
					cyphered[i] = product[i] + 32;
					in << cyphered[i];
				
				}
                
            }
        }
        
        // if the line's length was an odd number, the last letter of it remains the same
        
        if (input.length() % 2 != 0) in << input[input.length()-1];
        in << '\n';
		
	}
	
	in.close();
	out.close();
	
	return 0;
	
}
