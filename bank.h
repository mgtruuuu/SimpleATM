#pragma once

#include "account.h"

#include <string>
#include <vector>

class Bank {
  private:
    std::vector<Account> m_list_account;

  public:
    Bank() = default;
    const std::vector<Account>& getListAccount() const;
    void setAccount(const Account& account);
    Account* getAccount(const int pin_num, const std::string& card_num);
    bool verifyAccount(const int pin_num, const std::string& card_num) const;
    
};