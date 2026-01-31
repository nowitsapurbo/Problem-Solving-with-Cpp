#include <iostream>

bool canSplitEvenly(int weight) {
    return weight > 2 && weight % 2 == 0;
}

int main() {
    int weight = 0;
    if (!(std::cin >> weight)) {
        std::cerr << "NO" << std::endl;
        return 0;
    }

    std::cout << (canSplitEvenly(weight) ? "YES" : "NO") << std::endl;
    return 0;
