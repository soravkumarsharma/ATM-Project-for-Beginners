#include "MainMenu.h"

#include <iostream>

void MainMenu::Print() const {
  std::cout << "========== MAIN MENU ==========" << std::endl;
  std::cout << "Press 1: To Check Balance." << std::endl;
  std::cout << "Press 2: To Withdraw Amount." << std::endl;
  std::cout << "Press 3: To Fast Cash." << std::endl;
  std::cout << "Press 4: To Deposit Amount." << std::endl;
  std::cout << "Press 5: To Read your Bank Statement." << std::endl;
  std::cout << "Press 6: LogOut." << std::endl;
  std::cout << "Press 7: Exit." << std::endl;
}

int MainMenu::GetUserChoice() const {
  int user_choice;

  std::cout << "Select an option: ";
  std::cin >> user_choice;

  while (user_choice < 1 || user_choice > 7) {
    std::cout << "Invalid choice. Please select a number between 1 and 7."
              << std::endl;
    std::cout << "Select an option: ";
    std::cin >> user_choice;
  }

  return user_choice;
}
