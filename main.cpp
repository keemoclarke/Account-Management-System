
//
//  main.cpp
//  PM1_project 2
//
//  Created by Keemo Clarke on 5/5/17.
//  Copyright © 2017 Keemo Sabastian Clarke. All rights reserved.
//

# include "Account.hpp"
# include "stockAccount.hpp"
# include "bankAccount.hpp"


# include <iostream>
# include <string>
#include <unistd.h>  // for sleep function
#include<fstream>

using namespace std;

int main() {
    
    // create stock history file w/headers
    ofstream historystock("stock_transaction_history.txt");
    historystock  << "Action      Symbol    Company                 PRICE             Shares";
    historystock.close();
    
    // create bank history file w/headers
    ofstream historybank("bank_transaction_history.txt");
    historybank  << "Action         Amount   Cash Balance          Date&Time";
    historybank.close();
    
    
    // create objects
    stockAccount d1;
    bankAccount d2;
    
    bool flag = true;
    int selection = 0;
    char test[256];
    string line;
    while (flag) {
        
        cout << "Please select an account to access" << endl
        << "\t1. Stock Portfolio Account" << endl
        << "\t2. Bank Account" << endl
        << "\t3. Exit" << endl
        << "\tYour selection: ";
        
        cin.getline(test, 256);
        ofstream testfile("input.txt");
                selection = atoi(test);
        
        
        
        
        
        switch (selection) {
            case 1:
                cout << "\n\tYou chose stock portfilo accont." << endl;
                d1.menu();
                break;
            case 2:
                cout << "\n\tYou chose bank account." << endl;
                d2.menu();
                break;
            case 3:
                cout << "\n\tEXITING" << endl;
                flag = false;
                break;
            default:
                cout << "\n\tINVALID. TRY AGAIN." << endl;
                break;
        }
    }
    
    return 0;
}
