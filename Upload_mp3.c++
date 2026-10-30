//This file should allow uploading of mp3 files
//The user will be able to open their file explorer and select an mp3 file to upload to the database

//TREAT THIS AS A ROUGH DRAFT! DO NOT TURN IN!

#include <windows.h>
#include <iostream>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;

fs::path upload_mp3() {
    WCHAR buffer[MAX_PATH] = L"";

    OPENFILENAMEW ofn = {};

    ofn.lStructSize = sizeof(ofn);
    ofn.lpstrFilter =
        L"MP3 Files (*.mp3)\0*.mp3\0All Files (*.*)\0*.*\0";
    ofn.lpstrFile = buffer;
    ofn.nMaxFile = MAX_PATH;
    ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST;

    if (GetOpenFileNameW(&ofn)) {
        fs::path source = buffer;

        fs::path destinationFolder = fs::path(std::getenv("USERPROFILE")) / L"OneDrive\\Desktop\\Mp3Player\\Music_Downloaded";
        fs::path destination = destinationFolder / source.filename();

        try {
            fs::create_directories(destinationFolder); // make sure the folder exists

            fs::copy_file(
                source,
                destination,
                fs::copy_options::overwrite_existing
            );

            std::cout << "MP3 uploaded successfully!\n";
            std::wcout << L"Saved to: " << destination.wstring() << L"\n";

            return destination;   // <-- hand the path back
        }
        catch (const fs::filesystem_error& e) {
            std::cerr << "Error copying file: " << e.what() << "\n";
        }
    } else {
        std::cout << "No file selected.\n";
    }

    return fs::path();   // empty path = nothing was uploaded
}
