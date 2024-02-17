#include "Account.h"

#include <chrono>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <thread>

// Returns the input as a string, with precision set at 2 decimal places.
std::string FloatToString(const float number) {
  std::stringstream stream;
  stream << std::fixed << std::setprecision(2) << number;
  return stream.str();
}

// Sleeps for a second, then prints a '.' to the screen. Repeats 3 times.
void WaitIndicator() {
  for (int i = 0; i < 3; i++) {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "." << std::flush;
  }
  std::cout << std::endl;
}

Account::Account(std::string first_name, std::string last_name,
                 std::string email)
    : m_first_name{first_name}, m_last_name{last_name}, m_email{email},
      m_PIN{std::nullopt}, m_balance{0.0}, m_transactions{} {}

void Account::CreatePIN() {
  int PIN;
  std::cout << "Please input a 4-digit number for your PIN: ";
  std::cin >> PIN;

  while (std::to_string(PIN).length() != 4) {
    std::cout << "Your PIN can only contain 4 digits. Please enter again: ";
    std::cin >> PIN;
  }

  m_PIN = PIN;
  std::cout << "Your PIN has been created." << std::endl;
}

bool Account::HasCreatedPIN() const { return m_PIN.has_value(); }

bool Account::Authenticate() const {
  if (HasCreatedPIN()) {
    int authentication_input;
    std::cout << "Please enter your PIN: ";
    std::cin >> authentication_input;

    if (authentication_input == m_PIN.value()) {
      std::cout << "Authentication successful!" << std::endl;
      return true;
    } else {
      std::cout << "Authentication was not successful..." << std::endl;
      return false;
    }
  }

  std::cout << "You have not created a PIN yet." << std::endl;
  std::cout << "In order to authenticate, please create a PIN." << std::endl;
  return false;
}

void Account::CheckBalance() const {
  if (!Authenticate()) {
    std::cout << "Fast Cash order not authorized, aborting..." << std::endl;
  }

  std::cout << "Your balance is: " << FloatToString(m_balance) << " Rs."
            << std::endl;
}

void Account::WithdrawAmount() {
  if (!Authenticate()) {
    std::cout << "Withdraw order not authorized, aborting..." << std::endl;
  }

  float withdraw_amount;
  std::cout << "Enter your withdrawal amount: ";
  std::cin >> withdraw_amount;

  if (m_balance < withdraw_amount) {
    std::cout << "Sorry, your remaining balance does not cover\n"
              << "the amount you want to withdraw." << std::endl;
    return;
  }

  std::cout << "Your amount of " << FloatToString(withdraw_amount)
            << " Rs is withdrawing." << std::flush;
  WaitIndicator();

  m_balance -= withdraw_amount;

  AddTransaction("Withdrawal: " + FloatToString(withdraw_amount) + " Rs");

  std::cout << "Successfully withdrew " << FloatToString(withdraw_amount)
            << " Rs." << std::endl;
  return;
}

void Account::FastCash() {
  if (!Authenticate()) {
    std::cout << "Fast Cash order not authorized, aborting..." << std::endl;
  }

  int fast_cash_choice;
  std::cout << "Select the amount you want to withdraw from the options."
            << std::endl;

  std::cout << "Press 1: To Withdraw 500  Rs." << std::endl;
  std::cout << "Press 2: To Withdraw 1000  Rs." << std::endl;
  std::cout << "Press 3: To Withdraw 5,000 Rs." << std::endl;
  std::cout << "Press 4: To Withdraw 10,000 Rs." << std::endl;
  std::cout << "Press 5: Exit From Fast Cash." << std::endl;
  std::cout << "Select an option: ";
  std::cin >> fast_cash_choice;

  while (fast_cash_choice < 1 || fast_cash_choice > 5) {
    std::cout << "Invalid input. Please enter a number between 1 and 5: ";
    std::cin >> fast_cash_choice;
  }

  if (fast_cash_choice == 5) {
    return;
  }

  constexpr float fast_cash_options[4] = {500.0, 1000.0, 5000.0, 10000.0};
  float amount_to_withdraw = fast_cash_options[fast_cash_choice - 1];

  if (m_balance < amount_to_withdraw) {
    std::cout << "Sorry, your remaining balance does not cover\n"
              << "the amount you want to withdraw." << std::endl;
    return;
  }

  std::cout << "Your amount of " << FloatToString(amount_to_withdraw)
            << " Rs is withdrawing." << std::flush;
  WaitIndicator();

  m_balance -= amount_to_withdraw;

  AddTransaction("Withdrawal: " + FloatToString(amount_to_withdraw) + " Rs");

  std::cout << "Successfully withdrew " << FloatToString(amount_to_withdraw)
            << " Rs." << std::endl;
  return;
}

void Account::DepositAmount() {
  float deposit_amount;
  std::cout << "Enter your deposit amount: ";
  std::cin >> deposit_amount;

  std::cout << "Your amount of " << FloatToString(deposit_amount)
            << " Rs is being deposited." << std::flush;
  WaitIndicator();

  m_balance += deposit_amount;

  AddTransaction("Deposit: " + FloatToString(deposit_amount) + " Rs");

  std::cout << "Successfully deposited " << FloatToString(deposit_amount)
            << " Rs." << std::endl;
  return;
}

void Account::ReadBankStatement() const {
  if (!Authenticate()) {
    std::cout << "Read Bank Statement order not authorized, aborting..."
              << std::endl;
  }

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
