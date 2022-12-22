#include <iostream>
#include <string>

int main() {
    std::string start_str = "";
    std::string finish_str = "";
    std::cin >> start_str;
    int size_str = std::size(start_str);

    for (int i = 0; i < size_str; i += 1) {
        finish_str += '*';
    }

    if (size_str % 2 == 0) {
        for (int i = 0; i < size_str / 2; i += 1) {
            finish_str[(size_str / 2) - i - 1] = start_str[i * 2];
            finish_str[(size_str / 2) + i] = start_str[i * 2 + 1];
        }
    }
    else {
        finish_str[(size_str / 2)] = start_str[0];
        for (int i = 0; i < size_str / 2; i += 1) {
            finish_str[(size_str / 2) - i - 1] = start_str[i * 2 + 1];
            finish_str[(size_str / 2) + i + 1] = start_str[i * 2 + 2];
        }
    }
    std::cout << finish_str;
}
