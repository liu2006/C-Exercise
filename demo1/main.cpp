#include <iostream>
#include <string>
#include <vector>
void total_fee_message(double big_room_fee = 35, double small_room_fee = 25);

double cal_room_fee(size_t, size_t);

double room_fee_tax(double, double tax = 0.06);

void fee_table();

void select_serve();

void coding_tool();

void test1_function();

void test2_function();

void vec_test();
void print_vec(const std::vector<double> &);
void add_num(std::vector<double> &);
void average_num(const std::vector<double> &);
void small_num(const std::vector<double> &);
void large_num(const std::vector<double> &);

int main() {
    select_serve();
    return 0;
}

double cal_room_fee(size_t room_num, size_t room_fee) {
    return room_num * room_fee;
}

double room_fee_tax(double room_fee, double tax) { return room_fee * tax; }

void total_fee_message(double big_room_fee, double small_room_fee) {
    const std::string str1{"-------------------------------------"};

    double big_room_num{};
    std::cout << "请输入大房间数量：";
    std::cin >> big_room_num;

    double small_room_num{};
    std::cout << "请输入小房间数量：";
    std::cin >> small_room_num;

    double big_fee = cal_room_fee(big_room_num, big_room_fee);
    double small_fee = cal_room_fee(small_room_num, small_room_fee);
    double total_tax = room_fee_tax(big_fee + small_fee);
    double total_fee = big_fee + small_fee + total_tax;
    std::cout << str1 << "\n大房间清理费总计：" << big_fee << "\n"
              << "小房间清理费总计：" << small_fee << "\n"
              << "总税率：" << total_tax << "\n总价：" << total_fee << "\n"
              << str1;
}
void select_serve() {
    char command{};
    do {
        std::cout << "请选择服务" << std::endl
                  << "---------------------------------------" << std::endl
                  << "1.计算房间清理费用工具" << std::endl
                  << "2.数组测试" << std::endl
                  << "3.数据加密" << std::endl
                  << "4.数据金字塔" << std::endl
                  << "退出程序[q/Q]\n请输入：";
        std::cin >> command;
        std::cin.ignore(256, '\n');
        switch (command) {
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

void coding_tool() {

    const std::string alphabet{
        "qwerOPASDopatyTYUIsdfg123450uicvbnmQWER6789hjklzxFGHJKLZXCVBNM"};
    const std::string key{
        "YHNUJMswq765AQZWSX0EazbvfrVTGB98IKOLPploikujmnhytg4321edcxDCRF"};
    const std::string user_password{"520"};

    // if (alphabet.length() == key.length()) {
    //     std::cout << alphabet.length() << std::endl;
    // }

    std::string user_input{};
    unsigned parameter{1};

    while (parameter) {
        std::cout << "输入密码['q'键退出]：";
        getline(std::cin, user_input);
        if (user_input == "q" || user_input == "Q") {
            std::cout << "Program exit" << std::endl;
            break;
        } else if (user_input != user_password) {
            std::cout << "Verify fail" << std::endl;
            continue;
        } else {
            std::cout << "\n验证成功" << std::endl;
            do {
                std::string plaintext{};
                std::string ciphertext{};
                std::string letter{};
                std::cout << "-----------------------------------------"
                          << std::endl
                          << "请选择服务" << std::endl
                          << "1.加密信息" << std::endl
                          << "2.解密信息" << std::endl
                          << "['q'键退出]" << std::endl
                          << "-------------------------------------------"
                          << std::endl
                          << "Enter：";
                getline(std::cin, letter);
                if (letter == "1") {
                    std::cout << "请输入需要加密的信息: ";
                    getline(std::cin, plaintext);
                    if (plaintext.length() == 0) {
                        std::cout << "输入为空请重试" << std::endl;
                        continue;
                    } else {
                        for (auto s : plaintext) {
                            size_t pos = alphabet.find(s);
                            if (pos != std::string::npos)
                                ciphertext += key.at(pos);
                            else
                                ciphertext += "#";
                        }
                        std::cout << "加密成功" << std::endl
                                  << "密钥是: \n"
                                  << ciphertext << std::endl;
                    }
                    --parameter;
                    break;

                } else if (letter == "2") {
                    std::string decrypt_information{};
                    std::cout << "请输入需要解密的信息: ";
                    getline(std::cin, ciphertext);
                    if (ciphertext.length() == 0) {
                        std::cout << "输入为空请重试" << std::endl;
                        continue;
                    } else {
                        for (auto s : ciphertext) {
                            size_t pos = key.find(s);
                            if (pos != std::string::npos) {
                                plaintext += alphabet.at(pos);
                            } else {
                                plaintext += " ";
                            }
                        }
                        std::cout << "解密成功" << std::endl
                                  << "结果是: \n"
                                  << plaintext << std::endl;
                    }
                    --parameter;
                    break;

                } else if (letter == "q" || letter == "Q") {
                    std::cout << "Program exit" << std::endl;
                    --parameter;
                    break;
                } else {
                    std::cout << "请输入正确信息" << std::endl;
                    continue;
                }
            } while (parameter);
        }
    }
}

void test1_function() {

    size_t parameter{1};

    while (parameter) {
        int position{};
        std::string user_input{};
        std::cout << "Enter message: or 'q' exit ";
        getline(std::cin, user_input);
        size_t str_length = user_input.length();

        if (user_input == "q" || user_input == "Q") {
            break;
        }
        for (auto s : user_input) {
            std::cout << std::string(str_length - position, ' ');

            for (size_t i{}; i < position; ++i) {
                std::cout << user_input.at(i);
            }
            std::cout << s;

            for (int n{position - 1}; n >= 0; --n) {
                auto k = static_cast<size_t>(n);
                std::cout << user_input.at(n);
            }
            std::cout << std::endl;
            ++position;
        }
    }
}
void test2_function() {
    const std::string line{
        "==============================================================="};
    unsigned verify{1};

    while (verify == 1) {

        std::vector<int> test_score{1, 3, 564, 65};
        for (auto i : test_score)
            std::cout << i << std::endl;

        std::cout << "请输入4个测试成绩：";

        for (int i{}; i < test_score.size(); ++i)
            std::cin >> test_score.at(i);

        std::cout << line << std::endl;
        std::cout << "更新之后的结果: " << std::endl;
        for (auto i : test_score)
            std::cout << i << std::endl;

        std::cout << "现在动态数组的长度是：" << test_score.size() << std::endl;
        std::cout << line << std::endl;

        std::cout << "请追加测试成绩：";
        int score_to_add{};
        std::cin >> score_to_add;
        test_score.push_back(score_to_add);

        std::cout << line << std::endl;
        std::cout << "追加后的结果：" << std::endl;
        for (auto i : test_score)
            std::cout << i << std::endl;
        std::cout << "更新之后动态数组的长度是：" << test_score.size()
                  << std::endl;
        std::cout << line << std::endl;

        // std::vector<std::vector<int>> position{
        //     {1, 4, 5, 3},
        //     {5, 6, 7, 2},
        //     {23, 4, 5, 3},
        // };
        // std::cout << "result:" << position.at(0).at(2) << std::endl;
        // std::cout << "result:" << position.at(1).at(1) << std::endl;
        // std::cout << "result:" << position.at(2).at(3) << std::endl;
        // //
        // std::cout << "请输入更改数字：" << std::endl;
        // int num_to_add{};
        // std::cin >> position.at(0).at(2);
        // std::cout << line << std::endl;
        //
        // std::cout << "result:" << position.at(0).at(2) << std::endl;
        // std::cout << "result:" << position.at(1).at(1) << std::endl;
        // std::cout << "result:" << position.at(2).at(3) << std::endl;
        // std::cout << line << std::endl;
        std::cout << "是否继续：(y/n)";
        char letter{};
        std::cin >> letter;

        switch (letter) {
        case 'n':
        case 'N':
            --verify;
            break;
        }
    }
    char grade{};
    unsigned parameter{1};

    while (parameter == 1) {

        std::cout << "Enter score(A~F) ar Enter 'q' exit: ";
        std::cin >> grade;

        switch (grade) {
        case 'q':
        case 'Q':
            std::cout << "Program Stop" << std::endl;
            --parameter;
            break;
        case 'A':
            std::cout << "Between 90 and 100" << std::endl;
            break;
        case 'B':
            std::cout << "Between 80 and 89" << std::endl;
            break;
        case 'C':
            std::cout << "Between 70 and 79" << std::endl;
            break;
        case 'D':
            std::cout << "Between 60 and 69" << std::endl;
            break;
        case 'E':
            std::cout << "fail" << std::endl;
            break;
        default:
            std::cout << "Hello world" << std::endl;
        }

        // int result{};
        // int a{3};
        // int b{84};
        // result = (a < b) ? a : b;
        // result = (a != 0) ? b / a : 0;
        // result = (a > b) ? a - b : b - a;
        while (parameter == 1) {

            int num{};
            std::cout << "Enter an interge: ";
            std::cin >> num;

            // if (num % 2 == 0)
            //     std::cout << "num is even" << std::endl;
            // else
            //     std::cout << "num is odd" << std::endl;

            std::cout << "num is " << ((num % 2 == 0) ? "even" : "odd")
                      << std::endl;
            std::cout << "Exit the Program? (y/n): ";
            char letter{};
            std::cin >> letter;
            switch (letter) {
            case 'n':
            case 'N':
                --parameter;
                break;
            }
        }
    }
    // 输入一个值，打印范围内包含的偶数
    int test{1};
    while (test) {

        int num{};
        std::cout << "Enter a number: ";
        std::cin >> num;

        for (int parameter{}; parameter <= num; ++parameter)
            if (parameter % 2 == 0)
                std::cout << parameter << std::endl;

        for (int i{1}; i <= 1000; ++i)
            std::cout << i << ((i % 10 == 0) ? "\n" : " ");

        std::cout << "Exit the program? (y/n)";
        char letter{};
        std::cin >> letter;
        switch (letter) {
        case 'y':
        case 'Y':
            --test;
            break;
        }
    }
}
void vec_test() {

    static std::vector<double> array{1, 43, 44};

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
        default:
            std::cout << "输入无效" << std::endl;
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
