#pragma once

#include "IAccount.h"

class Account : public IAccount {
public:
  Account(std::string first_name, std::string last_name, std::string email);
  ~Account() = default;

  // Prints to the screen the total amount of money of this account
  virtual void CheckBalance() const override;
  // Prints to the screen the recent transactions of this account
  virtual void ReadBankStatement() const override;

  void AddTransaction(std::string new_transaction);

  std::string get_first_name() const;
  void set_first_name(std::string first_name);

  std::string get_last_name() const;
  void set_last_name(std::string first_name);

  std::string get_email() const;
  void set_email(std::string first_name);

  std::vector<std::string> get_transactions() const;

private:
  std::string m_first_name;
  std::string m_last_name;
  std::string m_email;

  float m_balance;

  /**
   * Storage for this account's transactions (deposits, withdrawls etc).
   * At the moment, the transactions are simple strings in the form:
   * "{transaction type}: {amount} {currency type}s"
   * Example: "Deposit: 500.00 Rs"
   */
  std::vector<std::string> m_transactions;
};
