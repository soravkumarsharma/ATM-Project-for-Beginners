#include "Account/Account.h"
#include "Bank/Bank.h"
#include "MainMenu/MainMenu.h"

#include <iostream>

//------Welcome Screen Function.
void WelcomeScreen() {
  std::cout << "\n\tATM - (github.com/SoravkumarSharma)\n" << std::endl;
  std::cout << "\t\tWELCOME TO SKS BANK\n" << std::endl;
}

// //------------User Full Name Function.
// void userName(string fname, string lname) {
//   cout << "Welcome, " << fname << " " << lname << endl;
// }

// //-----------Greets the user.
// void welcomeTemplate(string firstName, string lastName) {
//   system("CLS");
//   welcome();
//   userName(firstName, lastName);
//   cout << endl;
// }

//----------------Main-Program----------------
int main() {
  WelcomeScreen();

  std::shared_ptr<Bank> bank = std::make_shared<Bank>();

  std::shared_ptr<MainMenu> main_menu = std::make_shared<MainMenu>();

  //-------------User Sign-up----------
  std::cout << "SIGN UP" << std::endl;
  std::string firstName, lastName, userEmail;

  std::cout << "Enter Your First Name: ";
  std::cin >> firstName;
  std::cout << "Enter Your Last Name: ";
  std::cin >> lastName;
  std::cout << "Enter Your Email-id: ";
  std::cin >> userEmail;

  std::shared_ptr<Account> account =
      std::make_shared<Account>(firstName, lastName, userEmail);
  account->CreatePIN();

  bank->LogAccountIn(account);

  int main_menu_choice = 0;
  do {
    main_menu->Print();
    main_menu_choice = main_menu->GetUserChoice();

    bank->ProcessMainMenuChoice(main_menu_choice);
  } while (main_menu_choice != 7);

  return 0;
}
