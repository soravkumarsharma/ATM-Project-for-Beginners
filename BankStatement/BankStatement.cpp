#include "BankStatement.h"

#include <iostream>

BankStatement::BankStatement(const Account &account) : m_account{account} {}

void BankStatement::GetAccountTransactions() {
  const auto account_transactions = m_account.get_transactions();

  if (!account_transactions.size()) {
    std::cout << "This account has no logged transactions...\n";
    system("pause");
    return;
  }

  std::cout << "Here are this account's recent transactions: \n";

  for (const auto &transaction : account_transactions) {
    std::cout << transaction << std::endl;
  }

  std::cout << "End of bank statement.\n";

  system("pause");
  return;
}
