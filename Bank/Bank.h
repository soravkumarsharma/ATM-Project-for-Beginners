#pragma once

#include "../Account/IAccount.h"

#include <memory>

class Bank {
public:
  // Interactions with the main menu
  void ProcessMainMenuChoice(const int user_choice);

  // Account related interactions
  void LogAccountIn(const std::shared_ptr<IAccount> account);

private:
  // Account related interactions
  void AccountCheckBalance() const;
  void AccountWithdrawAmount() const;
  void AccountFastCash() const;
  void AccountDepositAmount() const;
  void AccountReadBankStatement() const;
  void LogAccountOut();

  // The account that is currently logged-in
  std::shared_ptr<IAccount> m_logged_in_account;
};
