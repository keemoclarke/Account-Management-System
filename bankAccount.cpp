//
//  bankAccount.cpp
//  PM1_project 2
//
//  Created by Keemo Clarke on 5/6/17.
//  Copyright © 2017 Keemo Sabastian Clarke. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <unistd.h>  // for sleep function
#include <fstream>
#include <iomanip>
#include <string>
#include <stdlib.h>
using namespace std;

#include "bankAccount.hpp"

bankAccount::bankAccount(double val) : Account(val) // bankAccount constructor
{
    cout << "MAKING bankAccount" << endl;
    
}

// Deposting to bankAccount
void bankAccount::deposit(double val)
{
    time_t rawtime;
    time (&rawtime);
    setBalance(val+getBalance()); // use of inheritted public functions
    ofstream historyBank("bank_transaction_history.txt", ios::app);
    historyBank <<"\nDeposit"  << setw(9) << val  << setw(13) << getBalance() << setw(41)
    << ctime(&rawtime) ;
    ;
}

// Withrawal from bank account
void bankAccount::withdraw(double val){
    time_t rawtime;
    time (&rawtime);
    if(val > getBalance())      // use of inheritted public functions
        cout << "\nYou have less money than what you requested. "<<endl;
    else
    {
        setBalance( getBalance() - val); // use of inheritted public functions
        
        ofstream historyBank("bank_transaction_history.txt", ios::app);
        historyBank <<"\nWithdraw"  << setw(9) << val  << setw(13) << getBalance() << setw(41)
        << ctime(&rawtime) ;
        historyBank.close();
    }
    ;
}








// bankAccount Menu
void bankAccount::menu() {
    bool flag = true;
    int selection;
    
    while (flag) {
        cout << "\nPlease select an option" << endl
        << "\t1. View account balance" << endl
        << "\t2. Deposit money" << endl
        << "\t3. Withdraw money" << endl
        << "\t4. Display transaction history" << endl
        << "\t5. Return to previous menu" << endl;
        
        cout << "\tYour selection: ";
        
        
        while(!(cin>>selection)){
            cout << "\nPlease select an option" << endl
            << "\t1. View account balance" << endl
            << "\t2. Deposit money" << endl
            << "\t3. Withdraw money" << endl
            << "\t4. Display transaction history" << endl
            << "\t5. Return to previous menu" << endl;
            
            cout << "\tYour selection: ";
            cin.clear();
            cin.ignore(100, '\n');
        }
        
        
        switch(selection) {
            case 1:
                cout << "\nCash balance = " << getBalance() << endl;
                break;
            case 2: {
                double amount;
                cout << "\nEnter Ammount for deposit: ";
                cin >> amount;
                deposit(amount);
                break;
            }
            case 3: {
                double amount;
                cout << "\nEnter Ammount for withdrawal: ";
                cin >> amount;
                withdraw(amount);
                break;
            }
            case 4:{
                string out;
                ifstream history("bank_transaction_history.txt");
                
                while(getline(history,out)){
                    
                    cout << endl<< out << endl;
                }
                break;
            }
            case 5:
                cout << "\nReturning to previous menu. \n\n" ;
                cin.clear();
                cin.ignore(100, '\n');  // ignore last msg so it doesnt become an input in main menu
                flag = false;
                break;
            default:
                
                cout << "\nIncorrect selection. Try again: \n\n" << endl;
                
                break;
        }
    }
}



