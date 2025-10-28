#include <iostream>

int main() {
    int score[]{23, 435, 564};

    int *score_ptr{score};

    std::cout << score_ptr[0] << std::endl;
    std::cout << score_ptr[1] << std::endl;
    std::cout << score_ptr[2] << std::endl;

    std::cout << "-------------------------------------" << std::endl;
    std::cout << *(score_ptr) << std::endl;

    std::cout << *(score_ptr + 1) << std::endl;

    std::cout << *(score_ptr + 2) << std::endl;

    size_t size{};
    std::cout << "size:" << &size << std::endl;
    std::cin >> size;

    std::cout << "size2:" << &size << std::endl;
    int *int_ptr{nullptr};
    std::cout << "int_ptr:" << int_ptr << std::endl;

    int_ptr = new int(size);

    std::cout << "int_ptr2:" << int_ptr << std::endl;

    delete int_ptr;
    return 0;
}
