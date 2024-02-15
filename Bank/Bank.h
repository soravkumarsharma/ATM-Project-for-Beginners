#pragma once

#include "../Account/IAccount.h"

#include <memory>

class Bank {
public:
  // Interactions with the main menu
  void ProcessMainMenuChoice(const int user_choice) const;

  // Account related interactions
  void LogAccountIn(const std::shared_ptr<IAccount> account);

private:
  // Account related interactions
  void CheckAccountBalance() const;
  void ReadAccountBankStatement() const;

  // The account that is currently logged-in
  std::shared_ptr<IAccount> m_logged_in_account;
};
