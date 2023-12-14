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

	void splitAt(std::string delimiter,std::string& line, std::vector<std::string>& list) {
		size_t pos = 0;
		std::string token;
		while ((pos = line.find(delimiter)) != std::string::npos) {
			token = line.substr(0, pos);
			list.push_back(token);
			line.erase(0, pos + delimiter.length());
		}
		list.push_back(line);
	}

	int gameIDFinder(std::string& line) {
		printf("%s\n", line.c_str());

		int value = 0;

		std::regex gamePattern("Game (\\d+)");
		std::smatch gameMatch;

		if (std::regex_search(line, gameMatch, gamePattern)) value = std::stoi(gameMatch[1]);

		return value;
	}

	void getCubeNumbers(Game& game, std::string color, std::string& cube) {
		if (cube.find(color) != -1) {
			int value = std::stoi(cube.substr(0, cube.find(color)));
			//printf("amount of %s cubes: %d\n",color, redValue);
			if (color._Equal("red")) game.red = value;
			if (color._Equal("blue")) game.blue = value;
			if (color._Equal("green")) game.green = value;
		}
	}

	void games()
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
				printf("Game ID is %d\n", game.id);

				//removes game id substring
				line = line.substr(line.find(':')+1, line.length());

				//splits at semicolon and creates list with substrings 
				splitAt(";", line, subsets);

				for (auto i = 0; i < subsets.size(); i++) {
					std::vector<std::string> cubes;
					//printf("substring: %s\n", subsets.at(i).c_str());
					std::string subset = subsets.at(i).c_str();
					splitAt(",", subset, cubes);
					for (auto j = 0; j < cubes.size(); j++) {
						std::string cube = cubes.at(j).c_str();
						//printf("cube: %s\n", cube.c_str());

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
				std::cout << game.valid << std::endl;
			}

			printf("The sum of all games is: %d\n", sum);
		}
		else {
			std::cout << "Da is was faul" << std::endl;
		}
	}

}