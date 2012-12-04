#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

int main() {
	
	float coordinatesx1, coordinatesy1, coordinatesz1;
	float coordinatesx2, coordinatesy2, coordinatesz2;
	float length;
	float sequences[101][4];
	float output[10000];
	int tests;
	int temp1;
	int j, index = 0;
	int counter = 0;
	float temp2;
	float temp;
	
	scanf ("%d\n", &tests);
	
	for (int i = 0; i < tests; i++) {
		
		counter++;
		
		for (int k = 0; k < 3; k++) {
			
			scanf ("%d", &temp1);
			
			sequences[i][k] = temp1;
			
		}
		
		if (counter > 1) {
			
			for (int k = i - 1; k >= 0; k--) {
				
				index++;
				
				coordinatesx1 = static_cast <float> (sequences[i][0]);
				coordinatesx2 = static_cast <float> (sequences[k][0]);
				
				coordinatesy1 = static_cast <float> (sequences[i][1]);
				coordinatesy2 = static_cast <float> (sequences[k][1]);
				
				coordinatesz1 = static_cast <float> (sequences[i][2]);
				coordinatesz2 = static_cast <float> (sequences[k][2]);
				
				temp2 = pow (coordinatesx2 - coordinatesx1, 2) + pow (coordinatesy2 - coordinatesy1, 2) + pow (coordinatesz2 - coordinatesz1, 2);
				length = sqrt (temp2);
				output[index] = length;
				
			}
			
		}
	}
	
	for (int i = 2; i <= index; i++) {
		
		temp = output[i];
		j = i - 1;
		
		while (j > 0 && output[j] > temp) {
			
			output[j + 1] = output[j];
			j--;
			
		}
		output[j + 1] = temp;
	}
	
	for (int i = 1; i <= index; i++) printf ("%.2f\n", output[i]);
	
	return 0;
}
