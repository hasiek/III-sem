#include <stdio.h>
#include <cstdlib>

int main() {
    
    char str[100];
    int licznik = 0;
    
    
    scanf ("%s", str);
    while (str[licznik] >= 97 && str[licznik] <= 122) {
          
          licznik++;      
          
    }
    printf ("%s %d\n", str, licznik);
    
    system("pause");
    
    return 0;   
}
