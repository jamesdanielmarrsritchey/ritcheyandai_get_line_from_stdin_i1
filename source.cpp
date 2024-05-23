#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " --line_number <line number>\n";
        return 1;
    }

    std::string arg = argv[1];
    if (arg != "--line_number") {
        std::cerr << "Unknown argument: " << arg << "\n";
        return 1;
    }

    int target_line = std::stoi(argv[2]);
    if (target_line <= 0) {
        std::cerr << "Line number must be a positive integer.\n";
        return 1;
    }

    std::string line;
    for (int i = 1; i <= target_line; ++i) {
        if (!std::getline(std::cin, line)) {
            std::cerr << "Input has fewer than " << target_line << " lines.\n";
            return 1;
        }
    }

    std::cout << line << '\n';
    return 0;
}