#include <iostream>
#include <fstream>
#include <string>

#include "../header/day1.h"

namespace day1{
	void numberCount()
	{
		std::ifstream myfile;
		myfile.open("rsc/day1.txt");

		std::string line;
		int leftValue;
		int rightValue;
		int lineValue = 0;
		int sum = 0;

		if (myfile.is_open()) {
			while (std::getline(myfile, line)) {
				printf("%s\n", line.c_str());

				for (char c : line) {
					if (std::isdigit(c)) {
						leftValue = c - '0';
						lineValue += leftValue * 10;
						break;
					}
				}

				for (auto i = line.length() - 1; i >= 0; i--) {
					char c = line[i];

					if (std::isdigit(c)) {
						rightValue = c - '0';
						lineValue += rightValue;
						printf("%d\n", lineValue);
						break;
					}
				}

				sum += lineValue;
				lineValue = 0;

			}
		}
		else {
			std::cout << "Something is wrong" << std::endl;
		}

		myfile.close();
		printf("Das Ergebnis ist %d", sum);
	}
}