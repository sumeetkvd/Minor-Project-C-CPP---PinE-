#include <iostream>
#include <string>

bool startsWith(const std::string &str, const std::string &prefix) {
    return str.size() >= prefix.size() && str.compare(0, prefix.size(), prefix) == 0;
}


int main()
{
    std::string str = "This is a string.";
    std::string prefix = "This";

    if (startsWith(str, prefix)) {
        std::cout << "String starts with the given prefix" << std::endl;
    } else {
        std::cout << "String doesn't starts with prefix" << std::endl;
    }

    return 0;
}
