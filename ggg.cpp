#include "account.h"

#include <iostream>

Account::Account(const long long balance, const int pin_num, const std::string& card_num)
    : m_balance{ balance }, m_pin_num{ pin_num }, m_card_num{ card_num }
{
}

long long Account::getBalance() const
{
    return m_balance;
}

int Account::getPinNum() const
{
    return m_pin_num;
}

std::string Account::getCardNum() const
{
    return m_card_num;
}

bool Account::withdraw(const long long amount)
{
    bool res;

    if (m_balance >= amount) {
        m_balance -= amount;
        std::cout << "-" << amount << ", total : " << m_balance << std::endl;

        res = true;
    }
    else {
        std::cerr << "cannot withdraw: the balance is insufficient" << std::endl;

        res = false;
    }

    return res;
}

bool Account::deposit(const long long amount)
{
    bool res;

    m_balance += amount;
    std::cout << "+" << amount << ", total : " << m_balance << std::endl;

    res = true;

    return res;
}

std::ostream& operator<<(std::ostream& out, const Account& account)
{
    out << "PIN number: " << account.m_pin_num << '\n'
        << "Card Number: " << account.m_card_num << '\n'
        << "Balalnce: " << account.m_balance;

    return out;
}