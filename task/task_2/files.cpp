#include <iostream>
#include <fstream>
#include <vector>
#include <thread>
#include <chrono>

int main() {
    std::vector<std::ofstream> files;

    for (int i = 1; i <= 100; ++i) {
        std::string filename = "file_" + std::to_string(i) + ".txt";
        files.emplace_back(filename); 

        if (!files.back().is_open()) 
        {
            std::cerr << "Error: Failed to open " << filename << '\n';
            return 1;
        }

        // Write the index number into the file
        files.back() << "File number: " << i << "\n";
        files.back().flush(); // Ensure immediate writing

        std::this_thread::sleep_for(std::chrono::seconds(1)); 
    }

    std::cout << "All 100 files created.\n";
    return 0;
}
