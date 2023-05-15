// g++ unit_test_account.cpp account.cpp -I ./include -L ./lib -lgtest -lgtest_main -pthread -std=c++17

#include "gtest/gtest.h"

#include "account.h"

namespace {

Account account_1{ 100, 1231, "1234123412341234" };
const Account account_2{ 1000, 4651, "123412341234123" };
Account account_3{ 10000, 7897, "9999999999999999" };

TEST(MemberFuction, getBalance)
{

    const auto balance_2 = account_2.getBalance();

    EXPECT_EQ(1000, balance_2);
}

TEST(MemberFunction, withdraw)
{
    std::cout << account_3 << std::endl;
    if (account_3.withdraw(11000) == true)
    // if (account_3.withdraw(10000) == true)
    // if (account_3.withdraw(7000) == true)
    {
        std::cout << "success" << std::endl;
    }
    else {
        std::cerr << "Failure" << std::endl;
    }
    std::cout << account_3 << std::endl;
}
} // namespace