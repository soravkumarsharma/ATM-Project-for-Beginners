#pragma once

#include <string>
#include <vector>

class IAccount {
public:
  // Prints to the screen the total amount of money of this account
  virtual void CheckBalance() const = 0;
  // Asks for amount of money, checks if balance >= amount, withdraws
  virtual void WithdrawAmount() = 0;
  // Asks for amount from a fixed set, follows `WithdrawAmount` after that
  virtual void FastCash() = 0;
  // Asks for amount of money and adds it to the balance
  virtual void DepositAmount() = 0;
  // Prints to the screen the recent transactions of this account
  virtual void ReadBankStatement() const = 0;
};
