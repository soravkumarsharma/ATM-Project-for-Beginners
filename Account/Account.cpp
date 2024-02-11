#include "Account.h"

Account::Account(std::string first_name, std::string last_name,
                 std::string email)
    : m_first_name{first_name}, m_last_name{last_name}, m_email{email},
      m_transactions{} {}

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
