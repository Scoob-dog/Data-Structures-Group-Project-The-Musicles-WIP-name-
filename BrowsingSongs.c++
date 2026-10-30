//Load songs into page

//TREAT THIS AS A ROUGH DRAFT! DO NOT TURN IN!

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>

bool BrowsingSongsPageIsActive = false;
int songCount = 0;

void BrowsingSongsTerminal() {

    BrowsingSongsPageIsActive = true;
    songCount = 0;

    std::system("cls");
    std::cout << "Browsing Songs." << std::endl;
    std::cout << "------------------------------" << std::endl;

    std::ifstream file("songs.csv");

    if (!file.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return;
    } else {
        std::string line;
        while (std::getline(file, line)) {
            songCount++;
            std::cout << songCount << ". " << line << std::endl;
        }
        file.close();
    }

    std::cout << "Type anything to continue: ";
    std::string TypeAnything;
    std::cin >> TypeAnything;

    #include <cstdio> // for std::remove

    if (TypeAnything == "Clear") {
        if (std::remove("songs.csv") == 0) {
            songCount = 0;
            std::cout << "All songs cleared." << std::endl;
        } else {
            std::cerr << "Could not delete songs.csv" << std::endl;
        }
    }
}
