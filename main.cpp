#include<iostream>
#include<windows.h>
#include<conio.h>
using namespace std;

//------Welcome Screen Function.
void welcome(){
    cout<<"\n\tATM - (github.com/SoravkumarSharma)\n"<<endl;
    cout<<"\t\tWELCOME TO SKS BANK\n"<<endl;
}

void showMenu(){
    //-------------User-Menu-----------------
    cout<<"Press 1: To Check Balance."<<endl;
    cout<<"Press 2: To Withdraw Amount."<<endl;
    cout<<"Press 3: To Fast Cash."<<endl;
    cout<<"Press 4: To Deposit Amount."<<endl;
    cout<<"Press 5: LogOut."<<endl;
    cout<<"Press 6: Exit."<<endl;

}

//------------User Full Name Function.
void userName(string fname,string lname){
    cout<<"Welcome, "<<fname<<" "<<lname<<endl;
}

//----------------Main-Program----------------
int main(){
    welcome();
    //-------------User Sign-up----------
    cout<<"SIGN UP"<<endl;
    int newPin,confirmPin,loginPin;
    string firstName,lastName,userEmail,loginEmail;

    // balance,withdraw,deposit variable
    float balance, withdraw,deposit,fastCash;
    balance = 0;
    cout<<"Enter Your First Name: ";
    cin>>firstName;
    cout<<"Enter Your Last Name: ";
    cin>>lastName;
    cout<<"Enter Your Email-id: ";
    cin>>userEmail;
    start:
    cout<<"\nCreate 4-Digit PIN"<<endl;
    cout<<"New PIN: ";
    cin>>newPin;
    cout<<"Confirm PIN: ";
    cin>>confirmPin;
    if(newPin>999 && newPin<=9999){
        if (confirmPin == newPin){
            system("CLS");
            welcome();
            userName(firstName,lastName);
            cout<<endl;
            loginJump:
            //-----------User Log in
            cout<<"Log in"<<endl; 
            cout<<"Enter Your Email-id: ";
            cin>>loginEmail;
            cout<<"Enter Your PIN: ";
            cin>>loginPin;
            if(loginEmail == userEmail && loginPin == newPin){
                system("CLS");
                welcome();
                userName(firstName,lastName);
                cout<<endl;
                int userChoice;
                while(1){
                    fastJump:
                    showMenu();
                    cout<<"Option: ";
                    cin>>userChoice;
                    switch(userChoice){
                        case 1: system("CLS");
                                welcome();
                                userName(firstName,lastName);
                                cout<<endl;
                                balanceJump:
                                int balancePin;
                                cout<<"Enter Your PIN: ";
                                cin>>balancePin;
                                if(balancePin == newPin){
                                    system("CLS");
                                    welcome();
                                    userName(firstName,lastName);
                                    cout<<endl;
                                    cout<<"Your Balance is: "<<balance<<" Rs."<<endl;
                                }
                                else{
                                    cout<<"Invalid PIN"<<endl;
                                    Sleep(1000);
                                    goto balanceJump;
                                }
                                break;
                        case 2: 
                                system("CLS");
                                welcome();
                                userName(firstName,lastName);
                                cout<<endl;
                                withdrawJump:
                                int withdrawPin;
                                cout<<"Enter Your PIN: ";
                                cin>>withdrawPin;
                                if(withdrawPin == newPin){
                                    system("CLS");
                                    welcome();
                                    userName(firstName,lastName);
                                    cout<<endl;
                                    cout<<"Enter Your Withdraw Amount: ";
                                    cin>>withdraw;
                                    if(balance>=withdraw){
                                        cout<<"Your amount "<<withdraw<< " is withdrawing.";
                                        for(int i=0;i<4;i++){
                                            cout<<".";
                                            Sleep(1000);
                                        }
                                        cout<<"\n Successfully Withdraw Amount."<<endl;
                                        balance -= withdraw;
                                    }
                                    else{
                                        cout<<"Not enough balance in your accout."<<endl;
                                    }
                                }
                                else{
                                    cout<<"Invalid PIN"<<endl;
                                    Sleep(1000);
                                    goto withdrawJump;
                                }
                                break;
                        case 3: 
                                system("CLS");
                                welcome();
                                userName(firstName,lastName);
                                cout<<endl;
                                fastcashJump:
                                int fastPin;
                                cout<<"Enter Your PIN: ";
                                cin>>fastPin;
                                if(fastPin == newPin){
                                    system("CLS");
                                    welcome();
                                    userName(firstName,lastName);
                                    cout<<endl;
                                    char usrChoice;
                                    while(1){
                                        cout<<"Press 1: To Withdraw 500 Rs."<<endl;
                                        cout<<"Press 2: To Withdraw 1000 Rs."<<endl;
                                        cout<<"Press 3: To Withdraw 5000 Rs."<<endl;
                                        cout<<"Press 4: To Withdraw 10,000 Rs."<<endl;
                                        cout<<"Press 5: Exit From Fast Cash."<<endl;
                                        usrChoice = getch();
                                        switch(usrChoice){
                                            case '1':   
                                                        system("CLS");
                                                        welcome();
                                                        userName(firstName,lastName);
                                                        cout<<endl;
                                                        fiveJump:
                                                        int fivethouPin;
                                                        cout<<"Enter Your PIN: ";
                                                        cin>>fivethouPin;
                                                        if (fivethouPin == newPin){
                                                            if(balance>=500){
                                                                cout<<"Your Amount 500 Rs. is Withdrawing.";
                                                                for(int i=0;i<4;i++){
                                                                    cout<<".";
                                                                    Sleep(1000);
                                                                }
                                                                balance -= 500;
                                                                cout<<"\nSuccessfully Amount Withdraw."<<endl;
                                                            }
                                                            else{
                                                                cout<<"Not enough balance in your account."<<endl;
                                                            }
                                                        }
                                                        else{
                                                            cout<<"Invalid PIN"<<endl;
                                                            Sleep(1000);
                                                            goto fiveJump;
                                                        }
                                                        break;
                                            case '2':
                                                        system("CLS");
                                                        welcome();
                                                        userName(firstName,lastName);
                                                        cout<<endl;
                                                        tenJump:
                                                        int tenthouPin;
                                                        cout<<"Enter Your PIN: ";
                                                        cin>>tenthouPin;
                                                        if(tenthouPin == newPin){
                                                            if(balance>=1000){

                                                                cout<<"Your Amount 1000 Rs. is Withdrawing.";
                                                                for(int i=0;i<4;i++){
                                                                    cout<<".";
                                                                    Sleep(1000);
                                                                }
                                                                balance -= 1000;
                                                                cout<<"\nSuccessfully Amount Withdraw."<<endl;

                                                            }
                                                            else{
                                                                cout<<"Not enough balance in your account."<<endl;
                                                            }
                                                        }
                                                        else{
                                                            cout<<"Invalid PIN"<<endl;
                                                            Sleep(1000);
                                                            goto tenJump;
                                                        }
                                                        break;
                                            case '3':
                                                        system("CLS");
                                                        welcome();
                                                        userName(firstName,lastName);
                                                        cout<<endl;
                                                        fiftyJump:
                                                        int fiftythouPin;
                                                        cout<<"Enter Your PIN: ";
                                                        cin>>fiftythouPin;
                                                        if(fiftythouPin == newPin){
                                                            if(balance>=5000){

                                                                cout<<"Your Amount 5000 Rs. is Withdrawing.";
                                                                for(int i=0;i<4;i++){
                                                                    cout<<".";
                                                                    Sleep(1000);
                                                                }
                                                                balance -= 5000;
                                                                cout<<"\nSuccessfully Amount Withdraw."<<endl;

                                                            }
                                                            else{
                                                                cout<<"Not enough balance in your account."<<endl;
                                                            }
                                                        }
                                                        else{
                                                            cout<<"Invalid PIN"<<endl;
                                                            Sleep(1000);
                                                            goto fiftyJump;
                                                        }
                                                        break;
                                            case '4':
                                                        system("CLS");
                                                        welcome();
                                                        userName(firstName,lastName);
                                                        cout<<endl;
                                                        hundJump: 
                                                        int hundthouPin;
                                                        cout<<"Enter Your PIN: ";
                                                        cin>>hundthouPin;
                                                        if(hundthouPin == newPin){
                                                            if(balance>=10000){

                                                                cout<<"Your Amount 10,000 Rs. is Withdrawing.";
                                                                for(int i=0;i<4;i++){
                                                                    cout<<".";
                                                                    Sleep(1000);
                                                                }
                                                                balance -= 10000;
                                                                cout<<"\nSuccessfully Amount Withdraw."<<endl;

                                                            }
                                                            else{
                                                                cout<<"Not enough balance in your account."<<endl;
                                                            }
                                                        }
                                                        else{
                                                            cout<<"Invalid PIN"<<endl;
                                                            Sleep(1000);
                                                            goto hundJump;
                                                        }
                                                        break;
                                            case '5':   
                                                        goto fastJump;
                                                        break;
                                            default:    
                                                        cout<<"Invalid input."<<endl;
                                                        break;
                                        }
                                    }
                                }
                                else{
                                    cout<<"Invalid PIN"<<endl;
                                    Sleep(1000);
                                    goto fastcashJump;
                                }
                                break;
                        case 4: 
                                system("CLS");
                                welcome();
                                userName(firstName,lastName);
                                cout<<endl;
                                depositJump:
                                int depositPin;
                                cout<<"Enter Your PIN: ";
                                cin>>depositPin;

                                if(depositPin==newPin){
                                    system("CLS");
                                    welcome();
                                    userName(firstName,lastName);
                                    cout<<endl;
                                    cout<<"Enter Your Deposit Amount: ";
                                    cin>>deposit;
                                    cout<<"Please wait!! Your amount "<<deposit<<" Rs. is depositing.";
                                    for(int i=0;i<4;i++){
                                        cout<<".";
                                        Sleep(1000);
                                    }
                                    balance += deposit;
                                    cout<<"\nSuccessfully Amount Deposited."<<endl;
                                }
                                else{
                                    cout<<"Invalid PIN"<<endl;
                                    Sleep(1000);
                                    goto depositJump;
                                }
                                break;
                                
                        case 5: system("CLS");
                                goto loginJump;
                                break;

                        case 6: exit(0);
                                break;
                        default:
                                cout<<"Invalid Input"<<endl;
                                break;
                    }
                }
            }
            else if(loginEmail != userEmail && loginPin == newPin){
                cout<<"Invalid Email-id"<<endl;
                Sleep(1000);
                goto loginJump;
            }
            else if(loginEmail == userEmail && loginPin != newPin){
                cout<<"Invalid PIN"<<endl;
                Sleep(1000);
                goto loginJump;

            }
            else{
                cout<<"Invalid Email-id and PIN"<<endl;
                Sleep(1000);
                goto loginJump;
            }
        }
        else{
            cout<<"Invalid Confirm PIN."<<endl;
            Sleep(1000);
            goto start;
        }
    }
    else{
        cout<<"Please Create 4-Digit PIN"<<endl;
        Sleep(1000);
        goto start;
    }



    return 0;
}