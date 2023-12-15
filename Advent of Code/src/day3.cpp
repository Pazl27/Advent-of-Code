#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "../header/day3.h"

namespace day3 {

	bool checkingIfValid(std::vector<std::vector <char>>& map, int& startPos, int& endPos, int& col) {
		//checking filed around the number for symbols 

		if (col > 0 && col < map.size() - 1) {
			//check if i can check the corners
			if (startPos > 0 && endPos < map[col].size() - 1) {
				for (int i = startPos - 1; i <= endPos + 1; i++) {
					if (map[col - 1][i] != '.' || map[col + 1][i] != '.') return true;
				}
				if (map[col][startPos - 1] != '.' || map[col][endPos + 1] != '.') return true;
			}

			if (startPos == 0) {
				for (int i = startPos; i <= endPos + 1; i++) {
					if (map[col - 1][i] != '.' || map[col + 1][i] != '.') return true;
				}
				if (map[col][endPos + 1] != '.') return true;
			}

			if (endPos == map[col].size() - 1) {
				for (int i = startPos - 1; i <= endPos; i++) {
					if (map[col - 1][i] != '.' || map[col + 1][i] != '.') return true;
				}
				if (map[col][startPos - 1] != '.') return true;
			}
		}

		else if (startPos == 0) {

			if (col == 0) {
				for (int i = startPos; i <= endPos + 1; i++) {
					if (map[col + 1][i] != '.') return true;
				}
				if (map[col][endPos + 1] != '.') return true;
			}

			else if (col == map.size() - 1) {
				for (int i = startPos; i <= endPos + 1; i++) {
					if (map[col - 1][i] != '.') return true;
				}
				if (map[col][endPos + 1] != '.') return true;
			}

			else {
				for (int i = startPos; i <= endPos + 1; i++) {
					if (map[col - 1][i] != '.' || map[col + 1][i] != '.') return true;
				}
				if (map[col][endPos + 1] != '.') return true;
			}
		}

		else if (endPos == map[col].size() - 1) {

			if (col == 0) {
				for (int i = startPos - 1; i <= endPos; i++) {
					if (map[col + 1][i] != '.') return true;
				}
				if (map[col][startPos - 1] != '.') return true;
			}

			else if (col == map.size() - 1) {
				for (int i = startPos - 1; i <= endPos; i++) {
					if (map[col - 1][i] != '.') return true;
				}
				if (map[col][startPos - 1] != '.') return true;
			}

			else {
				for (int i = startPos - 1; i <= endPos; i++) {
					if (map[col - 1][i] != '.' || map[col + 1][i] != '.') return true;
				}
				if (map[col][startPos - 1] != '.') return true;
			}
		}

		else if (col == 0) {
			for (int i = startPos - 1; i <= endPos + 1; i++) {
				if (map[col + 1][i] != '.') return true;
			}
		}

		else if (col == map.size() - 1) {
			for (int i = startPos - 1; i <= endPos + 1; i++) {
				if (map[col - 1][i] != '.') return true;
			}
		}

		return false;
	}

	void part1() {

		std::fstream file;
		file.open("rsc/day3.txt");

		std::string line;
		std::vector < std::vector <char> > map;
		std::vector <int> resultList;

		if (file.is_open()) {
			while (std::getline(file, line)) {

				std::vector <char> row;
				for (int i = 0; i < line.length(); i++) {
					row.push_back(line[i]);
				}
				map.push_back(row);
			}

		}

		file.close();

		for (int col = 0; col < map.size(); col++) {
			std::string number = "";
			int startPos = 0;
			int endPos = 0;

			for (int row = 0; row < map[col].size(); row++) {

				if (std::isdigit(map[col][row])) {

					if (row > 0 && !std::isdigit(map[col][row - 1])) startPos = row;

					if (row < map[col].size() - 1 && std::isdigit(map[col][row + 1])) {
						number += map[col][row];
					}

					else {
						number += map[col][row];
						endPos = row;

						if (checkingIfValid(map, startPos, endPos, col)) resultList.push_back(std::stoi(number));
						//printf("Number: %s, start Position %d, end Position: %d\n", number.c_str(), startPos, endPos);

						number = "";
					}
				}

			}
		}

		//printing the result list
		int sum = 0;
		for (int i = 0; i < resultList.size(); i++) {
			sum += resultList[i];
			//printf("%d, ", resultList[i]);
		}
		printf("\nSum: %d\n", sum);
		
	}

	void part2() {

	}
}
