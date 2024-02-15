#include "Account.h"

#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

// Returns the input as a string, with precision set at 2 decimal places.
std::string FloatToString(const float number) {
  std::stringstream stream;
  stream << std::fixed << std::setprecision(2) << number;
  return stream.str();
}

Account::Account(std::string first_name, std::string last_name,
                 std::string email)
    : m_first_name{first_name}, m_last_name{last_name}, m_email{email},
      m_balance{0.0}, m_transactions{} {}

void Account::CheckBalance() const {
  std::cout << "Your balance is: " << FloatToString(m_balance) << " Rs."
            << std::endl;
}

void Account::ReadBankStatement() const {
  if (!m_transactions.size()) {
    std::cout << "This account has no logged transactions..." << std::endl;
    return;
  }

  std::cout << "Here are this account's recent transactions:" << std::endl;
  for (const auto &transaction : m_transactions) {
    std::cout << transaction << std::endl;
  }
  std::cout << "End of bank statement." << std::endl;
  return;
}

void Account::AddTransaction(std::string new_transaction) {
  m_transactions.push_back(new_transaction);
}

std::string Account::get_first_name() const { return m_first_name; }
void Account::set_first_name(std::string first_name) {
  m_first_name = first_name;
}

std::string Account::get_last_name() const { return m_last_name; }
void Account::set_last_name(std::string last_name) { m_last_name = last_name; }

std::string Account::get_email() const { return m_email; }
void Account::set_email(std::string email) { m_email = email; }

std::vector<std::string> Account::get_transactions() const {
  return m_transactions;
}
