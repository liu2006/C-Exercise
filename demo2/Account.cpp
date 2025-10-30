#include "Account.h"

void Account::set_name(std::string n) { name = n; }

void Account::set_balance(double bal) { balance = bal; }

std::string Account::get_name() { return name; };

bool Account::deposit(double amount) {
    balance += amount;
    return true;
}

bool Account::withdraw(double amount) {
    if (balance >= amount) {
        balance -= amount;
        return true;
    } else {
        return false;
    }
}
