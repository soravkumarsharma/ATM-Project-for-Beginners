#pragma once

#include <string>
#include <vector>

class IAccount {
public:
  virtual void CheckBalance() const = 0;
  virtual void ReadBankStatement() const = 0;
};
