#include <iostream>
#include <fstream>
#include <string>

struct game {
	int id;
	int red;
	int blue;
	int green;
};

int main() {
	std::ifstream myfile;
	myfile.open("src/games.txt");
	std::string line;

	if (myfile.is_open()) {
		while (std::getline(myfile, line)) {
			printf("%s", line);
		}
	}
	else {
		std::cout << "Da is was faul" << std::endl;
	}

	return 0;
}