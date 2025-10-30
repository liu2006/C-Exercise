#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include <iostream>
#include <string>

class Account {
  private:
    std::string name;
    double balance;

  public:
    void set_name(std::string);
    std::string get_name();
    void set_balance(double);
    bool deposit(double);
    bool withdraw(double);
};

#endif
