#include <iostream>
#include <fstream>

int main() {
    std::ofstream outfile("output.txt");
    if (outfile.is_open()) {
        outfile << "Hello world!" << std::endl;
        outfile.close();
    } else {
        std::cout << "Unable to open file\n";
        return 1;
    }
    return 0;
}
