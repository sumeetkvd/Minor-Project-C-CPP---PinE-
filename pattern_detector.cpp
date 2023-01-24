#include <iostream>
#include <string>

int main() {
    std::string str1 = "This is a string.";
    std::string str2 = "Another line with string.";
    std::string str3 = "Just a simple line.";
    std::string substring = "string";

    std::size_t found1 = str1.find(substring);
    std::size_t found2 = str2.find(substring);
    std::size_t found3 = str3.find(substring);

    if (found1 != std::string::npos) {
        std::cout << "Matched substring-1: " << substring << std::endl;
    }

    else if (found2 != std::string::npos) {
        std::cout << "Matched substring-2: " << substring << std::endl;
    }

    else if (found3 != std::string::npos) {
        std::cout << "Matched substring-3: " << substring << std::endl;
    }

    else {
        std::cout << "No match found." << std::endl;
    }

    return 0;
}
