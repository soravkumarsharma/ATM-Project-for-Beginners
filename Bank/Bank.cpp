#include "Bank.h"

#include <iostream>

void Bank::ProcessMainMenuChoice(const int user_choice) {
  switch (user_choice) {
  case 1: {
    AccountCheckBalance();
    break;
  }
  case 2: {
    AccountWithdrawAmount();
    break;
  }
  case 3: {
    AccountFastCash();
    break;
  }
  case 4: {
    AccountDepositAmount();
    break;
  }
  case 5: {
    AccountReadBankStatement();
    break;
  }
  case 6: {
    LogAccountOut();
    break;
  }
  case 7:
  default: {
    // Exit; do nothing, as the main while loop will terminate
    break;
  }
  }
}

void Bank::LogAccountIn(const std::shared_ptr<IAccount> account) {
  if (account == nullptr) {
    std::cerr << "Invalid account trying to log in." << std::endl;
    return;
  }

  if (!account->Authenticate()) {
    std::cout << "Sorry, we cannot log you in without proper authentication."
              << std::endl;
    return;
  }

  m_logged_in_account = account;
  std::cout << "You have successfully logged in!" << std::endl;
}

void Bank::AccountCheckBalance() const {
  if (m_logged_in_account == nullptr) {
    std::cerr << "No logged in user present!" << std::endl;
    return;
  }

  m_logged_in_account->CheckBalance();
}

void Bank::AccountWithdrawAmount() const {
  if (m_logged_in_account == nullptr) {
    std::cerr << "No logged in user present!" << std::endl;
    return;
  }

  m_logged_in_account->WithdrawAmount();
}

void Bank::AccountFastCash() const {
  if (m_logged_in_account == nullptr) {
    std::cerr << "No logged in user present!" << std::endl;
    return;
  }

  m_logged_in_account->FastCash();
}

void Bank::AccountDepositAmount() const {
  if (m_logged_in_account == nullptr) {
    std::cerr << "No logged in user present!" << std::endl;
    return;
  }

  m_logged_in_account->DepositAmount();
}

void Bank::AccountReadBankStatement() const {
  if (m_logged_in_account == nullptr) {
    std::cerr << "No logged in user present!" << std::endl;
    return;
  }

  m_logged_in_account->ReadBankStatement();
}

void Bank::LogAccountOut() {
  m_logged_in_account = nullptr;
  std::cout << "You have been successfully logged out." << std::endl;
}
