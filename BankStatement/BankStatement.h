#pragma once

#include "../Account/Account.h"

class BankStatement {
public:
  BankStatement(const Account &account);
  ~BankStatement() = default;

  // Prints to the screen the recent transactions of the associated account
  void GetAccountTransactions();

private:
  Account m_account;
};
