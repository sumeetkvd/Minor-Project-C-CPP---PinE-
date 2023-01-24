#include <iostream>
#include <string>

std::string findMatchedSubstring(std::string str, std::string sub) {
    std::size_t found = str.find(sub);
    if (found != std::string::npos) {
        std::cout << "Forward: " << sub << std::endl;
    }
    std::string reverse = sub;
    std::reverse(reverse.begin(), reverse.end());
    found = str.find(reverse);
    if (found != std::string::npos) {
        std::cout << "Reverse: " << reverse << std::endl;
    }
    return sub;
}

int main(){
    
    std::string text = "This is a string. Another line with string. Just a simple line.";
    std::string substring = "si";
    findMatchedSubstring(text, substring);

    
    return 0;
}
