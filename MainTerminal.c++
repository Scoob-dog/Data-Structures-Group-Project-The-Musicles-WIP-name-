//This is the Terminal file that will put all the code together to seamlessly run the program.
//In the future, this program will hopefully have UI instead of a terminal!
#include <iostream>
#include <cstdlib>
#include <string>
#include "SongCreationTerminal.c++"
#include "BrowsingSongs.c++"

bool pageIsActive = false;

int main() {
    std::cout << "Welcome to BeatBox V0.0, [Pre-Alpha]" << std::endl;
    while (true)
    {
        std::system("cls");

        std::cout << "Please choose one of the following options:" << std::endl;
        std::cout << "------------------------------" << std::endl;
        std::cout << "1. Playlists" << std::endl;
        std::cout << "2. Songs" << std::endl;
        std::cout << "3. Create Playlist" << std::endl;
        std::cout << "4. Add Songs to Database" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "------------------------------" << std::endl;
        std::cout << "Enter your choice (1-5): ";

        int choice;
        std::cin >> choice;

        switch (choice) {

            case 1:

                std::system("cls");

                std::cout << "Browsing Playlists." << std::endl;
                std::cout << "------------------------------" << std::endl;
                pageIsActive = true;

                while (pageIsActive) {

                }
                // Call function to handle playlists
                break;
            case 2:

                // Call function to handle songs
                BrowsingSongsTerminal();

                break;
            case 3:

                std::system("cls");

                std::cout << "Creating a Playlist." << std::endl;
                std::cout << "------------------------------" << std::endl;
                pageIsActive = true;

                while (pageIsActive) {
                    
                }
                // Call function to handle playlists
                break;
            case 4:

                SongCreationTerminal();

                break;

            case 5:

                std::system("cls");

                std::cout << "Terminating the program. Goodbye!" << std::endl;
                std::cout << "------------------------------" << std::endl;
                return 0; // Exit the program
            default:

                std::system("cls");

                std::cout << "Please enter a number between 1 and 5." << std::endl;
                std::cout << "------------------------------" << std::endl;

                if (std::cin.fail()) { // Fail-Safe for invalid input
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
        }
    }
    
    return 0;
}
