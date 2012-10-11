// Lista Numerów PESEL - excercise from spoj.pl, made on 7.10.2012
// unaccepted, but for me, works just fine

#include <stdio.h>

int main() {
	
	char tkpk[4];
	char ptable[12];
	int pesel[12];
	int days[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
	int tkpkFirst, tkpkSec, tkpkThird;
	int counter, tests, i, check, checkYear = 0, j;
	int y = 0, d = 0, gender = 0, yy =0, c = 0, g = 0;
	int year, month, day, dayJan, dayYear, dayWeek;
	int peselsMatching = 0, control, temp;
	
	scanf ("%s", tkpk);
	scanf ("%d", &tests);
	getchar();
	
	for (counter = 0; counter < tests; counter++) {
		
			fgets (ptable, sizeof ptable, stdin); // PESEL as a table of char
			getchar();
			for (i = 0; i < 11; i++) {
					 
					if (ptable[i] >= 48 && ptable[i] <= 57) {
                     			 
		                 pesel[i] = ptable[i]-48; 
         
					}
					else if (ptable[i] = 63) {
                         
                         pesel[i] = 0;
                         temp = i;
                                
					} 
			} 

			control = 1*pesel[0] + 3*pesel[1] + 7*pesel[2] + 9*pesel[3] + 1*pesel[4] + 3*pesel[5] + 7*pesel[6] + 9*pesel[7] + 1*pesel[8] + 3*pesel[9];
			control = 10 - (control % 10);
			i = 1;
			while (control != pesel[10]) {
            
				pesel[temp] = i;
				control = 1*pesel[0] + 3*pesel[1] + 7*pesel[2] + 9*pesel[3] + 1*pesel[4] + 3*pesel[5] + 7*pesel[6] + 9*pesel[7] + 1*pesel[8] + 3*pesel[9];
				i++;
			}
			
			tkpkFirst = tkpk[2] - 48;
			check = tkpkFirst;
			
			// start of year checking
			
			if (check  == 0) {
				
				y = 1;
				
			}
			else {
				
				if (pesel[2] == 0 || pesel[2] == 1) {
					
					year = 1900 + 10*pesel[0]+pesel[1];
					month = 10*pesel[2] + pesel[3];
					day = 10*pesel[4]+pesel[5];
					
				}
				else if (pesel[2] == 8 || pesel[2] == 9) {
					
					year = 1800+pesel[0]*10+pesel[1];
					month = (10*pesel[2] + pesel[3]) - 80;
					day = 10*pesel[4]+pesel[5];
					
				}
				else if (pesel[2] == 2 || pesel[2] == 3) {
					
					year = 2000 + pesel[0]*10 + pesel[1];
					month = (10*pesel[2] + pesel[3]) - 20;
					day = 10*pesel[4]+pesel[5];
				}
				else if (pesel[2] == 4 || pesel[2] == 5) {
					
					year = 2100 + pesel[0]*10 + pesel[1];
					month = (10*pesel[2] + pesel[3]) - 40;
					day = 10*pesel[4]+pesel[5];
					
				}
				else if (pesel[2] == 6 || pesel[2] == 7) {
					
					year = 2200 + pesel[0]*10 + pesel[1];
					month = (10*pesel[2] + pesel[3]) - 60;
					day = 10*pesel[4]+pesel[5];
					
				}
				
				if ((year%4 == 0 && year%100 != 0) || year%400 == 0) {
					
					checkYear = 1;
					
				}
				else {
					
					checkYear = 2;
					
				}
				
				if (check == checkYear) {
					
					y = 1;
					
				}
			}
			
			// end of year checking a year
			
			// start of day checking, day, month and year stay from the previous one
			
			tkpkSec = tkpk[1] - 48;
			check = tkpkSec;
			
			if (check == 0) {
				
				d = 1;
				
			}
			else {
				
				yy = (year-1) % 100;
				c = (year - 1) - yy;
				g = yy + yy/4;
				dayJan = (((((c / 100) % 4) * 5) + g) % 7);
				dayYear = days[month-1]+day;
				
				if (checkYear == 1 && month > 2) {
					
					dayYear++;
					
				}
				
				dayWeek = ((dayJan + dayYear - 1) % 7) + 1;
				
				if (dayWeek == check) {
					
					d = 1;
					
				}
			}
				
				// end of day checking
				
				// start of gender checking
				
				tkpkThird = tkpk[0] - 48;
				check = tkpkThird;
				
				if (check == 0) {
					
					gender = 1;
					
				}
				else if (check == 1) { 
					
					if (pesel[9] % 2 != 0) {
						
						gender = 1;
						
					}
				}
				else if (check == 2) {
					
					if (pesel[9] % 2 == 0) {
						
						gender = 1;
						
					}
					
				}
				
				// end of gender checking
				
				// final checking
				
				if (y == 1 && d == 1 && gender == 1) {
					
					peselsMatching++;
					
				}
			
	}
	
	printf ("%d", peselsMatching);
	
	return 0;
}
