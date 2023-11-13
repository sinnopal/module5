#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

// Function to append user input to the file
void appendToFile(const std::string& fileName, const std::string& userInput) {
    std::ofstream outFile(fileName, std::ios::app); // Open file in append mode

    if (outFile.is_open()) {
        outFile << userInput << std::endl;
        outFile.close();
        std::cout << "Data has been appended to " << fileName << std::endl;
    } else {
        std::cerr << "Error opening file: " << fileName << std::endl;
    }
}

// Function to reverse the content of a file
void reverseFile(const std::string& inputFileName, const std::string& outputFileName) {
    std::ifstream inFile(inputFileName);
    std::ofstream outFile(outputFileName);

    if (inFile.is_open() && outFile.is_open()) {
        // Read the content of the file into a string
        std::string content((std::istreambuf_iterator<char>(inFile)), std::istreambuf_iterator<char>());

        // Reverse the content
        std::reverse(content.begin(), content.end());

        // Write the reversed content to the new file
        outFile << content;

        std::cout << "Reversed content has been written to " << outputFileName << std::endl;

        inFile.close();
        outFile.close();
    } else {
        std::cerr << "Error opening file: " << inputFileName << " or " << outputFileName << std::endl;
    }
}

int main() {
    // File names
    const std::string inputFileName = "CSC450_CT5_mod5.txt";
    const std::string outputFileName = "CSC450-mod5-reverse.txt";

    // Get user input
    std::string userInput;
    std::cout << "Enter data to append to the file: ";
    std::getline(std::cin, userInput);

    // Append user input to the file
    appendToFile(inputFileName, userInput);

    // Reverse the content of the file
    reverseFile(inputFileName, outputFileName);

    return 0;
}
