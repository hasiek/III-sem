// 27.11.2012
// Hill's cypher
// Katarzyna Huszcza

#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
    
    string key;
    string input;
    int keyMatrix[2][2];
    int inMatrix[2];
    int product[2];
    string cyphered;
    int border;
    int det = 0;
    fstream in ("in.txt");
    fstream out ("out.txt");
    
    // checking, whether a matrix is reversible
    
    while (det == 0) {
		
		cin >> key;
    
		keyMatrix[0][0] = key[0] - 97;
		keyMatrix[0][1] = key[1] - 97;
		keyMatrix[1][0] = key[2] - 97;
		keyMatrix[1][1] = key[3] - 97;
		
		det = (keyMatrix[0][0] * keyMatrix[1][1]) - (keyMatrix[0][1] * keyMatrix[1][0]);
		if (det != 0) cout << "Podano odpowiedni klucz, tekst zaszyfrowano.\n";
		else cout << "Podaj inny klucz.\n";
		
	}
	
	// reading until the end of file
    
    while (getline (in, input)) {
		
		// dividing text into two-element parts
    
        if (input.length() % 2 != 0) border = input.length() - 1;
        else border = input.length();
        
        for (int counter = 0; counter < border; counter = counter + 2) {
            
            for (int i = 0; i < 2; i++) {
				
				if (input[counter + i] >= 97 && input[counter + i] <= 122) inMatrix[i] = input[counter + i] - 97;
				else if (input[counter + i] >= 65 && input[counter + i] <= 90) inMatrix[i] = input[counter + i] - 65;
				else if (input[counter + i] >= 48 && input[counter + i] >= 57) inMatrix[i] = input[counter + i] - 48;
				
			}
			
			// cyphering
            
            product[0] = (keyMatrix[0][0] * inMatrix[0]) + (keyMatrix[0][1] * inMatrix[1]);
            product[1] = (keyMatrix[1][0] * inMatrix[0]) + (keyMatrix[1][1] * inMatrix[1]);
            
            for (int i = 0; i < 2; i++) {
                
                if (input[counter + i] >= 97 && input[counter + i] <= 122) {
					
					product[i] = product[i] % 26;
					cyphered[i] = product[i] + 97;
					out << cyphered[i];
				}
				else if (input[counter + i] >= 65 && input[counter + i] <= 90) {
					
					product[i] = product[i] % 26;
					cyphered[i] = product[i] + 65;
					out << cyphered[i];
					
				}
				else if (input[counter + i] >= 48 && input[counter + i] <= 57) {
					
					product[i] = product[i] % 10;
					cyphered[i] = product[i] + 48;
					out << cyphered[i];
					
				}
                
            }
        }
        
        // if the line length was an odd number, the last letter of it remains the same
        
        if (input.length() % 2 != 0) out << input[input.length()-1];
        out << '\n';
    }
    
    in.close();
    out.close();
    return 0;
    
}
