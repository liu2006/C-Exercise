#include <iostream>
#include <ostream>
#include <vector>

void vec_test();
void print_vec(const std::vector<double> &);
void add_num(std::vector<double> &);
void average_num(const std::vector<double> &);
void small_num(const std::vector<double> &);
void large_num(const std::vector<double> &);

bool jodge_null(const std::vector<double> &);

int main() { vec_test(); }

void vec_test() {

    static std::vector<double> array{};

    char user_input{};
    do {
        std::cout << "-------------------------------------------" << std::endl
                  << "Select_serve" << std::endl
                  << "P - 打印数字" << std::endl
                  << "A - 追加单个数字" << std::endl
                  << "M - 显示数字平均值" << std::endl
                  << "S - 显示最小数字" << std::endl
                  << "L - 显示最大数字" << std::endl
                  << "Q - 退出" << std::endl
                  << "Enter: ";

        std::cin >> user_input;
        switch (user_input) {
        case 'q':
        case 'Q':
            std::cout << "Program Exit" << std::endl;
            break;
        case 'p':
        case 'P':
            print_vec(array);
            break;
        case 'a':
        case 'A':
            add_num(array);
            break;
        case 'M':
        case 'm':
            average_num(array);
            break;
        case 's':
        case 'S':
            small_num(array);
            break;
        case 'l':
        case 'L':
            large_num(array);
            break;
        }
    } while (user_input != 'q' && user_input != 'Q');
}

bool jodge_null(const std::vector<double> &array) {
    if (array.size() == 0) {
        std::cout << "[] - 列表为空" << std::endl;
        return false;
    } else {
        return true;
    }
}

void print_vec(const std::vector<double> &array) {
    if (jodge_null(array)) {
        std::cout << "[ ";
        for (auto n : array)
            std::cout << n << " ";
        std::cout << "]" << std::endl;
    }
}

void add_num(std::vector<double> &array) {
    double num{};
    std::cout << "请输入要添加的数字：";
    std::cin >> num;
    array.push_back(num);
    std::cout << "更新之后的结果：";
    print_vec(array);
}

void average_num(const std::vector<double> &array) {
    if (jodge_null(array)) {
        double result{};
        for (auto num : array) {
            result += num;
        }
        std::cout << "平均值为：" << result / array.size() << std::endl;
    }
}
void small_num(const std::vector<double> &array) {
    if (jodge_null(array)) {
        double result{array.at(0)};
        for (auto num : array) {
            if (num < result) {
                result = num;
            }
        }
        std::cout << "最小值为：" << result << std::endl;
    }
}

void large_num(const std::vector<double> &array) {
    if (jodge_null(array)) {
        double result{array.at(0)};
        for (auto num : array) {
            if (result < num) {
                result = num;
            }
        }
        std::cout << "最大值为：" << result << std::endl;
    }
}
