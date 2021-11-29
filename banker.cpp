#include <string>
#include <vector>
#include <fstream>
#include <array>
#include <iostream>

//Notes: This program was written to accommodate process and resource 
//ammounts not strictly necessary. This is the reason for the resources
//and processes variables, and a lot of the extra code that isn't necessary
//for the main problem.

int main() {

	int resources, processes;

	std::cout << "Enter Number of Resources (positive integer only): ";
	std::cin >> resources;
	std::cout << "Enter Number of Processes (positive integer only): ";
	std::cin >> processes;

	int alloc[processes][resources];
	int available[resources];
	int max[processes][resources];
	
	bool allTrue[processes]; //To compare the safe state array to later
	for(int i = 0; i < processes; ++i) {
		allTrue[i] = true;
	}
	bool safeState[processes];
	for(int i = 0; i < processes; ++i) {
		safeState[i] = false;
	}
	
	
	std::string inpt = " ";
	std::string inptFile = " ";
	std::cout << "Enter name of input file: ";
	std::cin >> inptFile;
	
	std::ifstream file (inptFile);
	if(!file.is_open()) { 
		std::cout << "Error opening file. Please run the program again.";
		exit(1);
	}
	
	//For loop to fill alloc
	for(int i = 0; i < processes; ++i) {
		file >> inpt;
		for (int j = 0; j < resources; ++j) {
			alloc[i][j] = inpt.at(j) - '0';
		}
	}
	
	//For loop to fill max
	for(int i = 0; i < processes; ++i) {
		file >> inpt;
		for (int j = 0; j < resources; ++j) {
			max[i][j] = inpt.at(j) - '0';
		}
	}
	
	//For loop to fill available
	file >> inpt;
	for(int i = 0; i < resources; ++i) { 
		available[i] = inpt.at(i) - '0';
	}
	
	int safeOrder[processes];
	bool eq = false;
	int x = 0;
	int y = 0;
	int work[resources];
	for(int i = 0; i < resources; ++i) {
		work[i] = available[i];
	}
	
	//Safe State Check & Finding Order of Processes
	while (x < processes) { 
		for(int i = 0; i < processes; ++i) {
			bool procCheck[resources];
			for(int k = 0; k < resources; ++k) { procCheck[k] = false; }
			if(safeState[i] == false){
				for(int j = 0; j < resources; ++j) {
					if(safeState[i] == false){
						int z = max[i][j] - alloc[i][j];
						if(z <= work[j]) { 
							procCheck[j] = true;
						}
						for(int h = 0; h < resources; ++h) {
							if(procCheck[h] == true) { eq = true; }
							else {
								eq = false;
								h = resources;
							}
						}
						if (eq == true) { 
							safeState[i] = true;
							safeOrder[y] = i;
							++y;
							for(int j = 0; j < resources; ++j) { work[j] += alloc[i][j]; }
						}
					} else { j = resources; }
				}
			}
		}
		++x;
	}
			

	
	bool eq2 = false;
	for(int i = 0; i < processes; ++i) {
		if(safeState[i] == true) { eq2 = true; }
		else {
			eq2 = false;
			break;
		}
	}
	
	if(eq == true) {
		std::cout << "The system is in a safe state. Safe Order: ";
		for(int i = 0; i < processes; ++i) { std::cout << "P" << safeOrder[i] << ", "; }
	} else { std::cout << "System not in safe state!" << std::endl; }
}
