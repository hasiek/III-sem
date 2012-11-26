// Vigenere's cypher for English texts, with the key repetition despite of EOF
// Katarzyna Huszcza, 20.11.2012

#include <stdio.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

using namespace std; 

char cyphering (char letter, int base, int n, string key, int modulo);

int main() {
    
    string input;
    string key = "sroka";
    int n = 0;
    fstream in;
    fstream out;
    
    in.open("in.txt");
    out.open("out.txt");
    
    while (getline (in, input)) {
    
        for (int i = 0; i < input.length(); i++) {
              
              // cyphering normal letters
              
              if (input[i] >= 97 && input[i] <= 122) {
                           
                   input[i] = cyphering (input[i], 97, n, key, 26);
                   out << input[i];
                   n++;
                   if (n == key.length()) n = 0;     
                           
              }
              
              // cyphering capital letters
              
              else if (input[i] >= 65 && input[i] <= 90) {
              
                    input[i] = cyphering (input[i], 65, n, key, 26);
                    out << input[i];
                    n++;
                    if (n == key.length()) n = 0;      
                   
              }
              
              // cyphering numbers
              
              else if (input[i] >= 48 && input[i] <= 57) {
                   
                   input[i] = cyphering (input[i], 48, n, key, 10);
                   out << input[i];
                   n++;
                   if (n == key.length()) n = 0;  
                   
              }
              
              // rewriting other marks
              
              else out << input[i];    
            
        }
        out << '\n';
    }
     
    in.close();
    out.close();  
    system ("pause");
    return 0;   
}

char cyphering (char letter, int base, int n, string key, int modulo) {
     
     int move;
     
     move = key[n] - 97;
     letter -= base;
     letter = (letter + move) % modulo;
     letter += base;
     return letter;
};
