#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int main() {
    
    int tests;
    int length;
    vector <int> tab;
    int temp;
    int lookedFor;
    int l, p, k = 0;
    
    cin >> tests;
    
    for (int i = 0; i < tests; i++) {
		 
		 tab.clear();
         k = 0;
         cin >> length;
         for (int j = 0; j < length; j++) {
         
             cin >> temp;
             tab.push_back(temp); 
             
         }
         lookedFor = tab[length - 1];
                  
         l = 0;
         p = length - 2;
         while (1) {
               
               k = (l + p) / 2;
               if (lookedFor > tab[k]) l = k + 1;
               else if (lookedFor < tab[k]) p = k - 1;  
               if (tab[k] == lookedFor || l > p) break; 
                  
         }
         
         if (tab[k] == lookedFor) cout << k << '\n';
         else cout << '-' << '\n';
        
    }

    return 0;   
}
