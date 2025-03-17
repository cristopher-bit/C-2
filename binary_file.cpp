#include <iostream>
#include <fstream>

void copyBinaryFile(const std::string &sourceFile, const std::string &destinationFile) {
    // Open the source file in binary mode
    std::ifstream src(sourceFile, std::ios::binary);
    if (!src) {
        std::cerr << "Error: Could not open source file: " << sourceFile << std::endl;
        return;
    }

    // Open the destination file in binary mode
    std::ofstream dest(destinationFile, std::ios::binary);
    if (!dest) {
        std::cerr << "Error: Could not open destination file: " << destinationFile << std::endl;
        return;
    }

    // Copy the entire contents of the source file to the destination file
    dest << src.rdbuf();  // This reads from src and writes directly to dest

    // Close the files
    src.close();
    dest.close();

    std::cout << "File copied successfully.\n";
}

int main() {
    std::string sourceFile, destinationFile;

    std::cout << "Enter the source binary file name (e.g., music.mp3): ";
    std::cin >> sourceFile;

    std::cout << "Enter the destination binary file name: ";
    std::cin >> destinationFile;

    // Call the function to copy the file
    copyBinaryFile(sourceFile, destinationFile);

    return 0;
}
