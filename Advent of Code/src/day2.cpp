#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <regex>
#include <vector>

#include "../header/day2.h"

namespace day2 {

	struct Game {
		int id = 0;
		int blue = 0;
		int red = 0;
		int green = 0;
		bool valid = true;
	};

	void splitAt(const std::string& delimiter, const std::string& line, std::vector<std::string>& list) {
		std::istringstream ss(line);
		std::string token;
		while (std::getline(ss, token, delimiter[0])) {
			list.push_back(token);
		}
	}

	int gameIDFinder(const std::string& line) {

		int value = 0;

		std::regex gamePattern("Game (\\d+)");
		std::smatch gameMatch;

		if (std::regex_search(line, gameMatch, gamePattern)) value = std::stoi(gameMatch[1]);

		return value;
	}

	void getCubeNumbers(Game& game, std::string color, std::string& cube) {
		if (cube.find(color) != -1) {
			int value = std::stoi(cube.substr(0, cube.find(color)));
			if (color._Equal("red")) game.red = value;
			if (color._Equal("blue")) game.blue = value;
			if (color._Equal("green")) game.green = value;
		}
	}

	void cubesGetMaxNumber(Game& game, std::string color, std::string& cube) {
		if (cube.find(color) != -1) {
			int value = std::stoi(cube.substr(0, cube.find(color)));
			if (color._Equal("red") && game.red < value) game.red = value;
			if (color._Equal("blue") && game.blue < value) game.blue = value;
			if (color._Equal("green") && game.green < value) game.green = value;
		}
	}

	void part1()
	{

		std::fstream myfile;
		myfile.open("rsc/day2.txt");
		int sum = 0;

		std::string line;

		if (myfile.is_open()) {

			while (std::getline(myfile, line)) {
				std::vector<std::string> subsets;

				Game game;

				//findes game 
				game.id = gameIDFinder(line);

				//removes game id substring
				line = line.substr(line.find(':') + 1, line.length());

				//splits at semicolon and creates list with substrings 
				splitAt(";", line, subsets);

				for (auto i = 0; i < subsets.size(); i++) {
					std::vector<std::string> cubes;
					std::string subset = subsets.at(i).c_str();
					splitAt(",", subset, cubes);
					for (auto j = 0; j < cubes.size(); j++) {
						std::string cube = cubes.at(j).c_str();

						getCubeNumbers(game, "red", cube);
						getCubeNumbers(game, "blue", cube);
						getCubeNumbers(game, "green", cube);


						if (game.blue > 14 || game.green > 13 || game.red > 12) {
							game.valid = false;
							break;
						}
					}
				}
				if (game.valid) sum += game.id;
			}

			printf("The sum of all games in part 1 is: %d\n", sum);
			myfile.close();
		}
		else {
			std::cout << "Da is was faul" << std::endl;
		}
	}

	void part2() {

		std::fstream myfile;
		myfile.open("rsc/day2.txt");
		int sum = 0;
		int cubeSum = 0;

		std::string line;

		if (myfile.is_open()) {

			while (std::getline(myfile, line)) {
				std::vector<std::string> subsets;

				Game game;

				//findes game 
				game.id = gameIDFinder(line);

				//removes game id substring
				line = line.substr(line.find(':') + 1, line.length());

				//splits at semicolon and creates list with substrings 
				splitAt(";", line, subsets);

				for (auto i = 0; i < subsets.size(); i++) {
					std::vector<std::string> cubes;
					std::string subset = subsets.at(i).c_str();
					splitAt(",", subset, cubes);
					for (auto j = 0; j < cubes.size(); j++) {
						std::string cube = cubes.at(j).c_str();

						cubesGetMaxNumber(game, "red", cube);
						cubesGetMaxNumber(game, "blue", cube);
						cubesGetMaxNumber(game, "green", cube);


					}
					cubeSum = game.red * game.blue * game.green;
				}
				sum += cubeSum;
			}

			printf("The sum of all games in part 2 is: %d\n", sum);
			myfile.close();
		}
		else {
			std::cout << "Da is was faul" << std::endl;
		}
	}

}