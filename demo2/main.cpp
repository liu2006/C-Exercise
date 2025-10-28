#include <iostream>

void static_local_example();

void static_local_example() {
    static size_t interge{1000};
    std::cout << interge << std::endl;
    interge += 1000;
    std::cout << interge << std::endl;
}
int main() {

    static_local_example();
    static_local_example();
    // 1000
    // 2000
    // 2000
    // 3000

    return 0;
}
