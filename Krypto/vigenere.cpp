#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main() {
	
	ifstream inFile("in.txt");
	ofstream outFile("out.txt");
	string input;
	string key = "amaretto";
	int i = 0, kIndex = 0, iIndex = 0;
	
	if (inFile == NULL || outFile == NULL) {
		
		printf ("[fopen] ERROR!\n");
		return 0;
		
	}
	
	while (getline (inFile, input)) {
		
		for (int i = Iindex; i < input.length(); i++) {
			
			
			
		}
		
	}
	
	
	return 0;
}
