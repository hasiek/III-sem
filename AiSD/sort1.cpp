#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

void quickSort (double output[], string cases[], int l, int p);

int main() {
	
	int tests, n;
	string one;
	string cases[1001];
	int ix = 0, iy = 0;
	double output[1001];
	vector <int> number;
	int length = 0;
	double x, y;
	double temp;
	int index = 0, i;
	
	scanf ("%d\n", &tests);
	
	for (int counter = 0; counter < tests; counter++) {
		
        index = 0;
        
		scanf ("%d\n", &n);
		
		if (n == 1) {
			
			getline (cin, one);
			cout << one << endl;
			
		}
		else {
			
			for (int j = 0; j < n; j++) {
				
				getline (cin, cases[j]);
				
				ix = 0;
				iy = 0;
				
				i = cases[j].length() - 1;
					
				while (cases[j][i] != 32 && cases[j][i] != 45) {
						
					number.push_back(cases[j][i] - 48);
					length++;
					i--;
						
				}
				
				for (int p = length - 1; p >= 0; p--) iy += number[p] * pow (10.0, p);
				if (cases[j][i] == 45) iy = 0 - iy;
				
				number.clear();
				length = 0;
					
				i--;
				if (cases[j][i] == 32) i--;
				
				while (cases[j][i] != 32 && cases[j][i] != 45) {
						
					number.push_back(cases[j][i] - 48);
					length++;
					i--;
						
				}
				
				for (int p = length - 1; p >= 0; p--) ix += number[p] * pow (10.0, p);
				if (cases[j][i] == 45) ix = 0 - ix;
				
				number.clear();
				length = 0;
				
				x = static_cast <double> (ix);
				y = static_cast <double> (iy);
				
				temp = (x*x) + (y*y);
				output[j] = temp;
				index++;
				
			}
			
			quickSort (output, cases, 0, index - 1);
			
			for (int k = 0; k < index; k++) cout << cases[k] << endl;
            
			
		}
		
        cout << endl;
	}
	
	return 0;
}

void quickSort (double output[], string cases[], int l, int p) {
	
	double temp;
	string temporary;
    int i,j;
    
    i = l;
    j = p;
	
	double v = output[(l + p) / 2];
			
	do {
				
		while (output[i] < v) i++;
		while (output[j] > v) j--;
		
		if (i <= j) {
				
			temp = output[i];
			temporary = cases[i];
			
			output[i] = output[j];
			cases[i] = cases[j];
			
			output[j] = temp;
			cases[j] = temporary;
			
			i++;
			j--;
			
		} 
				
	} while (i <= j);
		
	if (l < j) quickSort(output, cases, l, j);
	if (i < p) quickSort(output, cases, i, p);

};
