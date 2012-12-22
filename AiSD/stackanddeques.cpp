#include <stdio.h>
#include <iostream>
#include <string>
#include <stack>
#include <deque>
#include <cmath>
#include <vector>

using namespace std;

int main() {
	
	string input;
	int temp;
	int number1, number2;
	stack <int> stacks[11];
	stack <int> save;
	deque <int> deques[11];
	int createdDeques[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int createdStacks[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int numberLength;
	int pointer = 0;
	vector <int> toPrint;
	
	for (int i = 0; i < 11; i++) {
		
		while(!stacks[i].empty()) stacks[i].pop();
		deques[i].clear();
	}
	
	while (getline (cin, input)) {
		
		number1 = 0;
		number2 = 0;
		numberLength = 0;
		toPrint.clear();
		
		if (input.substr(0,5) == "new_s") {
			
			number1 = input[6] - 48;
			createdStacks[number1]++; 
			continue;
		}
		else if (input.substr(0,4) == "push") {
			
			number1 = input[5] - 48;
			if (stacks[number1].size() < 10) {
				
				pointer = 7;
				while (input[pointer] != 32 && pointer < input.length()) {
					
					numberLength++;
					pointer++;
					
				}
				numberLength--;
				for (int j = 7; j < input.length(); j++) {
					
					number2 += (input[j] - 48) * pow (10.0,numberLength);
					numberLength--;
					
				}
				stacks[number1].push(number2);
			}
			else cout << "error: stack is full\n";
			continue;
		}
		else if (input.substr(0,3) == "pop") {
			
			number1 = input[4] - 48;
			if (stacks[number1].size() == 0) cout << "error: stack is empty\n";
			else {
				
				stacks[number1].pop();
				continue;
			}
			
		}
		else if (input.substr(0,12) == "stack->stack") {
			
			number1 = input[13] - 48;
			number2 = input[15] - 48;
			temp = stacks[number1].top();
			stacks[number1].pop();
			stacks[number2].push(temp);
			continue;
		}
		else if (input.substr(0,8) == "delete_s") {
			
			number1 = input[9] - 48;
			while (!stacks[number1].empty()) stacks[number1].pop();
			createdStacks[number1]--;
			continue;
			
		}
		else if (input.substr(0,7) == "print_s") {
			
			number1 = input[8] - 48;
			
			if (stacks[number1].empty()) cout << "empty" << '\n';
			else {	
				save = stacks[number1];
				while (!stacks[number1].empty()) {
						
					toPrint.push_back(stacks[number1].top());
					stacks[number1].pop();
				}
				for (int print = toPrint.size() - 1; print >= 0; print--) cout << toPrint[print] << ' ';
				cout << '\n';
				stacks[number1] = save;
			}
			continue;
		}
		else if (input.substr(0,5) == "new_q") {
			
			number1 = input[6] - 48;
			createdDeques[number1]++; 
			continue;
		}
		else if (input.substr(0,7) == "enqueue") {
			
			number1 = input[8] - 48;
			if (deques[number1].size() < 10) {
				pointer = 10;
				while (input[pointer] != 32 && pointer < input.length()) {
						
					numberLength++;
					pointer++;
						
				}
				numberLength--;
				for (int j = 10; j < input.length(); j++) {
			
					number2 += (input[j] - 48) * pow (10.0,numberLength);
					numberLength--;
						
				}
				deques[number1].push_back(number2);
			}
			else cout << "error: queue is full\n";
			continue;
		}
		else if (input.substr(0,7) == "dequeue") {
			
			number1 = input[8] - 48;
			if (deques[number1].size() == 0) cout << "error: queue is empty\n";
			else deques[number1].pop_front();
			continue;
			
		}
		else if (input.substr(0,8) == "delete_q") {
			
			number1 = input[9] - 48;
			deques[number1].clear();
			createdDeques[number1]--;
			continue;
			
		}
		else if (input.substr(0,7) == "print_q") {
			
			number1 = input[8] - 48;
			if (deques[number1].size() == 0) cout << "empty\n";
			else {
				
				for (int print = deques[number1].size() - 1; print >= 0; print--) cout << deques[number1][print] << ' ';
				cout << '\n';	
			}
			continue;
			
		}
		else if (input.substr(0,12) == "stack->queue") {
			
			number1 = input[13] - 48;
			number2 = input[15] - 48;
			
			if (stacks[number1].size() == 0 || deques[number2].size() == 10) cout << "error: wrong command\n";
			else {
				
				temp = stacks[number1].top();
				stacks[number1].pop();
				deques[number2].push_back(temp);
				
			}
			continue;
		}
		else if (input.substr(0,12) == "queue->queue") {
			
			number1 = input[13] - 48;
			number2 = input[15] - 48;
			if (deques[number1].size() == 0 || deques[number2].size() == 10) cout << "error: wrong command\n";
			else {
				
				temp = deques[number1].front();
				deques[number1].pop_front();
				deques[number2].push_back(temp);
				
			}
			continue;
			
		}
		else if (input.substr(0,12) == "queue->stack") {
			
			number1 = input[13] - 48;
			number2 = input[15] - 48;
			if (deques[number1].size() == 0 || stacks[number2].size() == 10) cout << "error: wrong command\n";
			else {
				
				temp = deques[number1].front();
				deques[number1].pop_front();
				stacks[number2].push(temp);
				
			}
			continue;
			
		}
		
		input.clear();
	}
	
	return 0;
}
