#include <iostream>
#include <string>
#include <vector>
void total_fee_message(const double big_room_fee = 35,
                       const double small_room_fee = 25);

void cal_total_fee(double *const, const double &, const double &,
                   const double &);
void cal_room_fee(double *const, const double *, const double);

void room_fee_tax(double *const, const double &, const double &,
                  const double tax = 0.06);

void decrypt_information(const std::string *const, const std::string *const,
                         const std::string *const);

void encrypt_information(const std::string *const, const std::string *const,
                         const std::string *const);
void fee_table();

void select_serve();

void coding_tool();

void test1_function();

void vec_test();
void print_vec(const std::vector<double> *);
void add_num(std::vector<double> *);
void average_num(const std::vector<double> *);
void small_num(const std::vector<double> *);
void large_num(const std::vector<double> *);

int main() {
    select_serve();
    return 0;
}

void cal_total_fee(double *const total_fee_ptr, const double &big_fee,
                   const double &small_fee, const double &tax_fee) {
    *total_fee_ptr = big_fee + small_fee + tax_fee;
}
void cal_room_fee(double *const fee_ptr, const double *room_num,
                  const double room_fee) {
    *fee_ptr = *room_num * room_fee;
}

void room_fee_tax(double *const total_tax_ptr, const double &big_room_fee,
                  const double &small_room_fee, const double tax) {
    *total_tax_ptr = (big_room_fee + small_room_fee) * tax;
}

void total_fee_message(const double big_room_fee, const double small_room_fee) {
    double big_fee{};
    double small_fee{};
    double tax_fee{};
    double total_fee{};

    double *fee_ptr{nullptr};

    const double *room_num_ptr{nullptr};
    const std::string str1{"-------------------------------------"};

    double big_room_num{};
    std::cout << "请输入大房间数量：";
    std::cin >> big_room_num;
    room_num_ptr = &big_room_num;

    fee_ptr = &big_fee;
    cal_room_fee(fee_ptr, room_num_ptr, big_room_fee);

    double small_room_num{};
    std::cout << "请输入小房间数量：";
    std::cin >> small_room_num;
    room_num_ptr = &small_room_num;

    fee_ptr = &small_fee;
    cal_room_fee(fee_ptr, room_num_ptr, small_room_fee);

    fee_ptr = &tax_fee;
    room_fee_tax(fee_ptr, big_fee, small_fee);

    fee_ptr = &total_fee;

    cal_total_fee(fee_ptr, big_fee, small_fee, tax_fee);
    std::cout << str1 << "\n大房间清理费总计：" << big_fee << "\n"
              << "小房间清理费总计：" << small_fee << "\n"
              << "总税率：" << tax_fee << "\n总价：" << total_fee << "\n"
              << str1;
}
void select_serve() {
    char command{};
    char *command_ptr{nullptr};
    do {
        std::cout << "---------------------------------------" << std::endl
                  << "请选择服务" << std::endl
                  << "1.计算房间清理费用工具" << std::endl
                  << "2.数组测试" << std::endl
                  << "3.数据加密" << std::endl
                  << "4.数据金字塔" << std::endl
                  << "[q/Q] 退出程序" << std::endl
                  << "---------------------------------------" << std::endl
                  << "Enter: ";
        std::cin >> command;
        command_ptr = &command;
        switch (*command_ptr) {
        case '1':
            fee_table();
            break;
        case '2':
            vec_test();
            break;
        case '3':
            coding_tool();
            break;
        case '4':
            test1_function();
            break;
        case 'q':
        case 'Q':
            std::cout << "程序退出" << std::endl;
            break;
        default:
            std::cout << "请输入正确命令" << std::endl;
            break;
        }

    } while (command != 'q' && command != 'Q');
}
void fee_table() {
    const std::string str1{"-------------------------------------"};
    char letter{};
    do {
        std::cout << "\n1.参看费用表\n"
                  << "2.估算房间清洁费用\n"
                  << "q.退出\n"
                  << "Enter: ";
        std::cin >> letter;
        switch (letter) {
        case '1':
            std::cout << str1 << "\n单个大房间清理费：$36\n"
                      << "单个小房间清理费：$25\n"
                      << "固定税：6%\n"
                      << "估算有效期：30天\n"
                      << str1;
            break;
        case '2': {
            total_fee_message();
            break;
        }
        case 'q':
            std::cout << "Program Exit" << "\n";
            break;
        default:
            std::cout << "再试一次" << std::endl;
            break;
        }

    } while (letter != 'q' && letter != 'Q');
}

void encrypt_information(const std::string *information_ptr,
                         const std::string *alphabet, const std::string *key) {
    if ((*information_ptr).length() == 0) {
        std::cout << "输入为空请重试" << std::endl;
    } else {
        std::string result{};
        for (auto s : *information_ptr) {
            size_t pos = (*alphabet).find(s);
            if (pos != std::string::npos) {
                result += (*key).at(pos);
            } else
                result += "#";
        }
        std::cout << "密钥：" << std::endl << result << std::endl << std::endl;
    }
}
void decrypt_information(const std::string *information_ptr,
                         const std::string *key_ptr,
                         const std::string *alphabet_ptr) {

    if ((*information_ptr).length() == 0) {
        std::cout << "输入为空请重试" << std::endl;
    } else {
        std::string result{};
        for (auto s : *information_ptr) {
            size_t pos = (*key_ptr).find(s);
            if (pos != std::string::npos) {
                result += (*alphabet_ptr).at(pos);
            } else {
                result += " ";
            }
        }
        std::cout << "解密成功: " << std::endl
                  << result << std::endl
                  << std::endl;
    }
}
void coding_tool() {

    const std::string alphabet{
        "qwerOPASDopatyTYUIsdfg123450uicvbnmQWER6789hjklzxFGHJKLZXCVBNM"};
    const std::string key{
        "YHNUJMswq765AQZWSX0EazbvfrVTGB98IKOLPploikujmnhytg4321edcxDCRF"};
    const std::string user_password{"520"};

    const std::string *alphabet_ptr{&alphabet};
    const std::string *key_ptr{&key};
    // if (alphabet.length() == key.length()) {
    //     std::cout << alphabet.length() << std::endl;
    // }
    char letter{};

    do {
        std::string plaintext{};
        std::string ciphertext{};

        const std::string *information_ptr{nullptr};

        std::cout << "-----------------------------------------" << std::endl
                  << "请选择服务" << std::endl
                  << "1.加密信息" << std::endl
                  << "2.解密信息" << std::endl
                  << "['q'键退出]" << std::endl
                  << "-------------------------------------------" << std::endl
                  << "Enter：";
        std::cin >> letter;
        std::cin.ignore(10000, '\n');

        switch (letter) {
        case '1': {
            std::cout << "请输入需要加密的信息: ";
            getline(std::cin, plaintext);
            information_ptr = &plaintext;
            encrypt_information(information_ptr, alphabet_ptr, key_ptr);
            break;
        }
        case '2': {
            std::cout << "请输入密钥: ";
            getline(std::cin, ciphertext);
            information_ptr = &ciphertext;
            decrypt_information(information_ptr, key_ptr, alphabet_ptr);
            break;
        }
        case 'q':
        case 'Q': {
            std::cout << "Program exit" << std::endl;
            break;
        }
        default: {
            std::cout << "请输入正确信息" << std::endl;
            continue;
        }
        }
    } while (letter != 'q' && letter != 'Q');
}

void test1_function() {

    std::string user_input{};
    std::string *input_ptr{&user_input};
    do {
        int position{};
        std::cout << "输入信息：['q'/'Q']Exit ";
        std::cin >> user_input;
        size_t str_length = user_input.length();

        if (user_input == "q" || user_input == "Q") {
            break;
        } else {
            for (auto s : *input_ptr) {
                std::cout << std::string(str_length - position, ' ');

                for (size_t i{}; i < position; ++i) {
                    std::cout << (*input_ptr).at(i);
                }
                std::cout << s;

                for (int n{position - 1}; n >= 0; --n) {
                    auto k = static_cast<size_t>(n);
                    std::cout << (*input_ptr).at(n);
                }
                std::cout << std::endl;
                ++position;
            }
        }
    } while (user_input != "q" && user_input != "Q");
}

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
