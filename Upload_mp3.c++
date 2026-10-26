//This file should allow uploading of mp3 files
//The user will be able to open their file explorer and select an mp3 file to upload to the database

#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include <windows.h>
#include <commdlg.h>

void openFileExplorer() {
    std::string command = "explorer.exe";
    std::system(command.c_str());
}

void UploadMP3() {
    
}