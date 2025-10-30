#include <iostream>
#include <string>
#include <vector>
// void print(const int *const, size_t);
// int *apply_all(const int *, size_t, const int *, size_t);

class Player {
  public:
    std::string name;
    double health;
    double xp;
};

class Account {
  public:
    std::string name;
    double balance;
};

int main() {
    Player player_1;
    Player player_2;

    player_1.name = "hongshun";
    player_1.health = 100.0;
    player_1.xp = 10.0;

    player_2.name = "junjie";
    player_2.health = 100.0;
    player_2.xp = 9.0;

    Player *enemy = {nullptr};
    enemy = new Player;

    enemy->name = "enemy";
    enemy->health = 150.0;
    enemy->xp = 15.0;

    delete enemy;

    Account youkang;
    Account youjian;

    youkang.name = "youkang";
    youkang.balance = 400.0;

    youjian.name = "youjian";
    youjian.balance = 100.0;

    //     const size_t array1_size{5};
    //     const size_t array2_size{3};
    //
    //     int array1[]{1, 2, 3, 4, 5};
    //     int array2[]{10, 20, 30};
    //
    //     cout << "Array 1: ";
    //     print(array1, array1_size);
    //
    //     cout << "Array 2: ";
    //     print(array2, array2_size);
    //
    //     int *results = apply_all(array1, array1_size, array2, array2_size);
    //     constexpr size_t results_size{array1_size * array2_size};
    //
    //     cout << "Result: ";
    //     print(results, results_size);
    //     cout << endl;
    //
    //     delete[] results;
    //     return 0;
    // }
    //
    // void print(const int *const array, size_t size) {
    //     std::cout << "[ ";
    //     for (size_t i{}; i < size; ++i) {
    //         std::cout << *(array + i) << " ";
    //     }
    //     std::cout << "]" << std::endl;
    // }
    //
    // int *apply_all(const int *array1, size_t array1_size, const int *array2,
    //                size_t array2_size) {
    //     int *results = new int[array1_size * array2_size];
    //     size_t position{};
    //     for (size_t i{}; i < array2_size; ++i) {
    //         for (size_t n{}; n < array1_size; ++n) {
    //             *(results + position++) = *(array2 + i) * *(array1 + n);
    //         }
    //     }
    //     return results;


    return 0;
}
