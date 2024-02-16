#include "Bank.h"

#include <iostream>

void Bank::ProcessMainMenuChoice(const int user_choice) const {
  switch (user_choice) {
  case 1: {
    CheckAccountBalance();
    break;
  }
  case 5: {
    ReadAccountBankStatement();
  }
  }
}

void Bank::LogAccountIn(const std::shared_ptr<IAccount> account) {
  if (account == nullptr) {
    std::cerr << "Invalid account trying to log in." << std::endl;
    return;
  }

  m_logged_in_account = account;
}

void Bank::CheckAccountBalance() const {
  if (m_logged_in_account == nullptr) {
    std::cerr << "No logged in user present!" << std::endl;
    return;
  }

  m_logged_in_account->CheckBalance();
}

void Bank::ReadAccountBankStatement() const {
  if (m_logged_in_account == nullptr) {
    std::cerr << "No logged in user present!" << std::endl;
    return;
  }

  m_logged_in_account->ReadBankStatement();
}
