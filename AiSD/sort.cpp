#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	
	string input;
	vector <string> read;
	vector <int> sum;
	int cases;
	int temp;
	string temporary;
	string compared1;
	string compared2;
	int add = 0;
	
	scanf ("%d\n", &cases);
	
	for (int i = 0; i < cases; i++) {

		add = 0;
		getline (cin, input);
		read.push_back(input);
		for (int j = 0; j < input.length(); j++) add += (input[j] - 48);
		sum.push_back(add);
		
	}
	
	for (int k = 0; k < cases; k++) {
		
		for (int i = 0; i < cases - 1; i++) {
			
			if (sum[i] > sum[i+1]) {
				
				temp = sum[i];
				temporary = read[i];
				sum[i] = sum[i+1];
				read[i] = read[i+1];
				sum[i+1] = temp;
				read[i+1] = temporary;
				
			}
			if (sum[i] == sum[i+1]) {
				
				compared1 = read[i];
				compared2 = read[i+1];
				for (int j = 0; j < compared1.length(); j++) {
					
					if (compared1[j] > compared2[j]) {
						
						temporary = read[i];
						read[i] = read[i+1];
						read[i+1] = temporary;
						break;
						
					}
					if (compared1[j] < compared2[j]) break;
					
				}
				
			}
			
		}
	}
	
	for (int i = 0; i < cases; i++) {
			
		cout << read[i] << '\n';
			
	}

	return 0;
}
