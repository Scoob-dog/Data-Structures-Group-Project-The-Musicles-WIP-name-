//This file should allow uploading of mp3 files
//The user will be able to open their file explorer and select an mp3 file to upload to the database

#include <windows.h>
#include <iostream>
#include <string>

void upload_mp3() {
    WCHAR buffer[MAX_PATH] = L"";

    OPENFILENAMEW ofn = {};

    ofn.lStructSize = sizeof(ofn);
    ofn.lpstrFilter =
        L"MP3 Files (*.mp3)\0*.mp3\0All Files (*.*)\0*.*\0";
    ofn.lpstrFile = buffer;
    ofn.nMaxFile = MAX_PATH;
    ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST;

    if (GetOpenFileNameW(&ofn)) {
        std::wcout << L"Selected file: "
                   << buffer << L"\n";
    } else {
        std::cout << "No file selected.\n";
    }
}

int main() {
    upload_mp3();
    return 0;
}   
