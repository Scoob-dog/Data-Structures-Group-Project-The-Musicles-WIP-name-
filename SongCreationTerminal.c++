
//TREAT THIS AS A ROUGH DRAFT! DO NOT TURN IN!

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <filesystem>
#include <limits>
#include "upload_mp3.C++"

bool SongCreationPageIsActive = false;
int year;

void SongCreationTerminal() {
    std::system("cls");
    std::cout << "Adding Songs to Database." << std::endl;
    std::cout << "------------------------------" << std::endl;

    SongCreationPageIsActive = true;

    while (SongCreationPageIsActive) {
        // Song Details
        std::cout << "Name: ";
        std::string name;
        std::getline(std::cin >> std::ws, name); // Use getline to allow spaces in the name

        std::cout << "Album: ";
        std::string album;
        std::getline(std::cin >> std::ws, album);

        std::cout << "Artist: ";
        std::string artist;
        std::getline(std::cin >> std::ws, artist);

        std::cout << "Genre: ";
        std::string genre;
        std::getline(std::cin >> std::ws, genre);

        while (true) {
            std::cout << "Year: ";
            std::cin >> year;

            if (std::cin.fail()) {
                std::cin.clear(); // Clear the error flag
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
                std::cout << "Invalid input for year. Please enter a valid integer." << std::endl;
                continue; // Restart the loop to get valid input
            }
            break; // Exit the loop if input is valid
        }

        // upload mp3 file and set it up so we can add it's directory 

        fs::path mp3Path = upload_mp3();

        if (mp3Path.empty()) {
            std::cout << "No MP3 uploaded, song not saved." << std::endl;
        } else {
            std::ofstream file("songs.csv", std::ios::app);
            if (file.is_open()) {
                file << name << "," << album << "," << artist << "," << genre << ","<< year << "," << mp3Path.string() << std::endl;
                file.close();
                std::cout << "Song added to database successfully!" << std::endl;
            } else {
                std::cout << "Error opening file!" << std::endl;
            }
        }

        std::cout << "Type anything to continue: ";
        std::string TypeAnything;
        std::cin >> TypeAnything;

        SongCreationPageIsActive = false;
    }
}
