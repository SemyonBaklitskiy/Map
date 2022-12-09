#include <iostream>
#include <map>

std::map<char, int> check(std::string str) {
    std::map<char, int> result;

    for (int i = 0; i < str.length(); ++i) {
        ++result[str[i]];
    }

    return result;
}

int main() {
    int n = 0;
    std::string str1 = " ";
    std::string str2 = " ";

    std::cout << "Enter n: ";
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        std::cout << i + 1 << " pair) Enter two words: ";
        std::cin >> str1 >> str2;

        if (str1.length() == str2.length()) {
            if (check(str1) == check(str2)) {
                std::cout << "Yes" << std::endl;

            }   else {
                std::cout << "No" << std::endl;
            }

        }   else {
            std::cout << "No" << std::endl;
        }
    }

    return 0;
}