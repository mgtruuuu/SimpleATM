#pragma once

#include <string>

class Account {
  private:
    long long m_balance;
    int m_pin_num;
    std::string m_card_num;

  public:
    Account(const long long balance, const int pin_num, const std::string& card_num);
    long long getBalance() const;
    int getPinNum() const;
    std::string getCardNum() const;

    bool withdraw(const long long amount);
    bool deposit(const long long amount);

    friend std::ostream& operator<<(std::ostream& out, const Account& account);
};