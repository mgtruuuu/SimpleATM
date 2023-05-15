#include "account.h"
#include "bank.h"

#include <iostream>

// Insert Card => PIN number => Select Account => See Balance/Deposit/Withdraw

int main()
{
    Bank bank;

    Account account_1{ 100, 1231, "1234123412341234" };
    Account account_2{ 1000, 4651, "123412341234123" };
    Account account_3{ 10000, 7897, "9999999999999999" };

    bank.setAccount(account_1);
    bank.setAccount(account_2);
    bank.setAccount(account_3);

    auto* ac = bank.getAccount(7897, "9999999999999999");

    if (ac != nullptr)
    {
        std::cout << ac->getBalance() << std::endl;
        std::cout << ac->getCardNum() << std::endl;
        std::cout << ac->getPinNum() << std::endl;
        
std::cout << "==========" << std::endl;        

        ac->deposit(7000);

std::cout << "==========" << std::endl;

        std::cout << *ac << std::endl;

std::cout << "==========" << std::endl;

        ac->withdraw(15000);

std::cout << "==========" << std::endl;

        std::cout << *ac << std::endl;

std::cout << "==========" << std::endl;

        ac->withdraw(20000);

std::cout << "==========" << std::endl;

        std::cout << *ac << std::endl;
    }

    return 0;
}