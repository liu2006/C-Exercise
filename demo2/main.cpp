#include <iostream>
#include <ostream>
#include <vector>

void vec_test();
void print_vec(const std::vector<double> *);
void add_num(std::vector<double> *);
void average_num(const std::vector<double> *);
void small_num(const std::vector<double> *);
void large_num(const std::vector<double> *);

bool jodge_null(const std::vector<double> *);

int main() { vec_test(); }

void vec_test() {

    static std::vector<double> array{};

    char user_input{};
    char *input_ptr{&user_input};
    std::vector<double> *array_ptr{&array};
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

        switch (*input_ptr) {
        case 'q':
        case 'Q':
            std::cout << "Program Exit" << std::endl;
            break;
        case 'p':
        case 'P':
            print_vec(array_ptr);
            break;
        case 'a':
        case 'A':
            add_num(array_ptr);
            break;
        case 'M':
        case 'm':
            average_num(array_ptr);
            break;
        case 's':
        case 'S':
            small_num(array_ptr);
            break;
        case 'l':
        case 'L':
            large_num(array_ptr);
            break;
        default:
            std::cout << "输入无效" << std::endl;
            break;
        }
    } while (user_input != 'q' && user_input != 'Q');
}

bool jodge_null(const std::vector<double> *array_ptr) {
    if ((*array_ptr).size() == 0) {
        std::cout << "[] - 列表为空" << std::endl;
        return false;
    } else {
        return true;
    }
}

void print_vec(const std::vector<double> *array_ptr) {
    if (jodge_null(array_ptr)) {
        std::cout << "[ ";
        for (auto n : *array_ptr)
            std::cout << n << " ";
        std::cout << "]" << std::endl;
    }
}

void add_num(std::vector<double> *array_ptr) {
    double num{};
    std::cout << "请输入要添加的数字：";
    std::cin >> num;
    (*array_ptr).push_back(num);
    std::cout << "更新之后的结果：";
    print_vec(array_ptr);
}

void average_num(const std::vector<double> *array_ptr) {
    if (jodge_null(array_ptr)) {
        double result{};
        for (auto num : *array_ptr) {
            result += num;
        }
        std::cout << "平均值为：" << result / (*array_ptr).size() << std::endl;
    }
}
void small_num(const std::vector<double> *array_ptr) {
    if (jodge_null(array_ptr)) {
        double result{(*array_ptr).at(0)};
        for (auto num : *array_ptr) {
            if (num < result) {
                result = num;
            }
        }
        std::cout << "最小值为：" << result << std::endl;
    }
}

void large_num(const std::vector<double> *array_ptr) {
    if (jodge_null(array_ptr)) {
        double result{(*array_ptr).at(0)};
        for (auto num : (*array_ptr)) {
            if (result < num) {
                result = num;
            }
        }
        std::cout << "最大值为：" << result << std::endl;
    }
}
