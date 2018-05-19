#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <fstream>
#include <iostream>
#include "Process.h"

int main(int argc, char* argv[])
{
	extern int SHARE_MAX;

	for (int i = 0; i << argc; i++) {
		std::cout << "Command Line: " << argv[i] << " ";
	}
	std::cout << std::endl;
	if (argc == 1) {
		std::cout << "*** Insufficient number of arguments ***" << std::endl
			      << "Usage: " << argv[0] << " filename" << std::endl;
	}
	else if (argc > 2) {
		std::cout << "*** To many arguments ***" << std::endl
			      << "Usage: " << argv[0] << " filename" << std::endl;
	}
	else {
		std::ifstream file;
		file.open(argv[1], std::ios::in);
		if (!file.is_open()) {
			std::cout << "*** Failed to open file " << argv[1] << " ***"  << std::endl;
		}
		else {
			std::cout << "Command Line : ";
			for (int i = 0; i < argc; i++) {
				std::cout << argv[i] << " ";
			}
			std::cout << std::endl
				      << "Reading records from file " << argv[1] << std::endl;
			char tempCstr[1000];
			while (file.getline(tempCstr, 1000)) {
					sict::process(tempCstr);
			}
			file.close();
		}
	}
	system("pause");
	return 1;
}