#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main() {

	int scope[11] = {100, 100, 100, 100, 100, 100, 100, 100, 100, 100};
	string input;
	int i = 0;
	int add = 0;

	while (getline(cin,input)) {

		if (input == "-") {

			if (i == 0) cout << ":(\n";
			else {

				cout << scope[i-1] << '\n';
				scope[i-1] = 100;
				i--;

			}
		}
		else if (input == "+") {

			getline(cin,input);
			if(i < 10) {
				add = input[0] - 48;
				scope[i] = add;
				i++;
				cout << ":)\n";
			}
			else cout << ":(\n";


		}

	}

	return 0;
}