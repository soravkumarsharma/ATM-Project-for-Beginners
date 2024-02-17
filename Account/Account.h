#pragma once

#include "IAccount.h"

#include <optional>

class Account : public IAccount {
public:
  Account(std::string first_name, std::string last_name, std::string email);
  ~Account() = default;

  virtual void CreatePIN() override;
  virtual bool HasCreatedPIN() const;
  virtual bool Authenticate() const override;

  virtual void CheckBalance() const override;
  virtual void WithdrawAmount() override;
  virtual void FastCash() override;
  virtual void DepositAmount() override;
  virtual void ReadBankStatement() const override;

  std::string get_first_name() const;
  void set_first_name(std::string first_name);

  std::string get_last_name() const;
  void set_last_name(std::string first_name);

  std::string get_email() const;
  void set_email(std::string first_name);

  std::vector<std::string> get_transactions() const;

private:
  void AddTransaction(std::string new_transaction);

  std::string m_first_name;
  std::string m_last_name;
  std::string m_email;
  std::optional<int> m_PIN;

  float m_balance;

  /**
   * Storage for this account's transactions (deposits, withdrawls etc).
   * At the moment, the transactions are simple strings in the form:
   * "{transaction type}: {amount} {currency type}s"
   * Example: "Deposit: 500.00 Rs"
   */
  std::vector<std::string> m_transactions;
};
