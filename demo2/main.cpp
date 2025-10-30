#include "Account.h"
#include <iostream>

int main() {
    Account Horace_account;
    Horace_account.set_name("Horace");
    Horace_account.set_balance(1500);

    if (Horace_account.deposit(500)) {
        std::cout << "Success" << std::endl;
    } else {
        std::cout << "Fail" << std::endl;
    }

    if (Horace_account.withdraw(1500)) {
        std::cout << "Success" << std::endl;
    } else {
        std::cout << "Fail" << std::endl;
    }

    if (Horace_account.withdraw(499)) {
        std::cout << "Success" << std::endl;
    } else {
        std::cout << "Fail" << std::endl;
    }
    return 0;
}
