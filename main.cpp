#include "Account/Account.h"
#include "Bank/Bank.h"
#include "MainMenu/MainMenu.h"

#include <iostream>

// //------Welcome Screen Function.
// void welcome() {
//   cout << "\n\tATM - (github.com/SoravkumarSharma)\n" << endl;
//   cout << "\t\tWELCOME TO SKS BANK\n" << endl;
// }

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
  //   welcome();
  //-------------User Sign-up----------

  std::shared_ptr<Bank> bank = std::make_shared<Bank>();

  std::shared_ptr<MainMenu> main_menu = std::make_shared<MainMenu>();

  std::cout << "SIGN UP" << std::endl;
  //   int newPin, confirmPin, loginPin;
  // TODO: Add PIN to account for authentication
  std::string firstName, lastName, userEmail /*loginEmail*/;

  std::cout << "Enter Your First Name: ";
  std::cin >> firstName;
  std::cout << "Enter Your Last Name: ";
  std::cin >> lastName;
  std::cout << "Enter Your Email-id: ";
  std::cin >> userEmail;

  std::shared_ptr<Account> account =
      std::make_shared<Account>(firstName, lastName, userEmail);

  bank->LogAccountIn(account);

  int main_menu_choice = 0;
  do {
    main_menu->Print();
    main_menu_choice = main_menu->GetUserChoice();

    bank->ProcessMainMenuChoice(main_menu_choice);
  } while (main_menu_choice != 7);

  // start:
  // cout<<"\nCreate 4-Digit PIN"<<endl;
  // cout<<"New PIN: ";
  // cin>>newPin;
  // cout<<"Confirm PIN: ";
  // cin>>confirmPin;
  // if(newPin>999 && newPin<=9999){
  //     if (confirmPin == newPin){
  //         welcomeTemplate(firstName,lastName);
  //         loginJump:
  //         //-----------User Log in
  //         cout<<"Log in"<<endl;
  //         cout<<"Enter Your Email-id: ";
  //         cin>>loginEmail;
  //         cout<<"Enter Your PIN: ";
  //         cin>>loginPin;
  //         if(loginEmail == userEmail && loginPin == newPin)
  //         else if(loginEmail != userEmail && loginPin == newPin){
  //             cout<<"Invalid Email-id"<<endl;
  //             Sleep(1000);
  //             goto loginJump;
  //         }
  //         else if(loginEmail == userEmail && loginPin != newPin){
  //             cout<<"Invalid PIN"<<endl;
  //             Sleep(1000);
  //             goto loginJump;

  //         }
  //         else{
  //             cout<<"Invalid Email-id and PIN"<<endl;
  //             Sleep(1000);
  //             goto loginJump;
  //         }
  //     }
  //     else{
  //         cout<<"Invalid Confirm PIN."<<endl;
  //         Sleep(1000);
  //         goto start;
  //     }
  // }
  // else{
  //     cout<<"Please Create 4-Digit PIN"<<endl;
  //     Sleep(1000);
  //     goto start;
  // }

  return 0;
}
