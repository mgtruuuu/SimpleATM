// g++ unit_test_bank.cpp bank.cpp account.cpp -I ./include -L ./lib -lgtest -lgtest_main -pthread -std=c++17

#include "gtest/gtest.h"

#include "bank.h"

namespace {

Bank bank;

Account account_1{ 100, 1231, "1234123412341234" };
const Account account_2{ 1000, 4651, "123412341234123" };
Account account_3{ 10000, 7897, "9999999999999999" };

TEST(MemberFuction, getListAccount)
{
    bank.setAccount(account_1);
    bank.setAccount(account_2);
    bank.setAccount(account_3);

    for (const auto& ac : bank.getListAccount()) {
        std::cout << ac << std::endl;
    }

    
}

TEST(MemberFunction, setAccount)
{
    //auto* ac = bank.getAccount(7897, "9999999999999999");
    //auto* ac = bank.getAccount(7897, "8999999999999999");
    auto* ac = bank.getAccount(7811, "9999999999999999");

    if (ac != nullptr)
    {
        std::cout << "Find the account : " << std::endl;
        std::cout << *ac << std::endl;
    }
    else
    {
        std::cout << "Cannot find the account" << std::endl;
    }
}

} // namespace