#include "bank.h"

#include <algorithm>
#include <iostream>


const std::vector<Account>& Bank::getListAccount() const
{
    return m_list_account;
}

void Bank::setAccount(const Account& account)
{
    m_list_account.emplace_back(account);
}


Account* Bank::getAccount([[maybe_unused]] const int pin_num, [[maybe_unused]] const std::string& card_num)
{
    if (verifyAccount(pin_num, card_num) == false) 
    {
        return nullptr;
    }


    const auto p =
        std::find_if(m_list_account.begin(), m_list_account.end(), [pin_num, &card_num](const Account& account) {
            return (account.getCardNum() == card_num && account.getPinNum() == pin_num);
        });

    const auto diff = std::distance(m_list_account.begin(), p);



    if (diff != static_cast<ptrdiff_t>(m_list_account.size())) {
        return (m_list_account.data() + diff);
    }
    else
    {
        std::cerr << "input data is not on the database" << std::endl;

        return nullptr;
    }
}

bool Bank::verifyAccount([[maybe_unused]] const int pin_num, [[maybe_unused]] const std::string& card_num) const
{

    // Call API to check card number and corresponding PIN number.

    bool res;

    if (true) {
        res = true;
    }
    else {

        std::cerr << "card number and PIN number is not verified" << std::endl;

        res = false;
    }

    return res;
}
