//
//  stockAccount.cpp
//  PM1_project 2
//
//  Created by Keemo Clarke on 5/5/17.
//  Copyright © 2017 Keemo Sabastian Clarke. All rights reserved.
//
#include <iostream>
#include <stdio.h>
#include <unistd.h>  // for sleep
#include <fstream>
#include<vector>
#include<iomanip>
#include <ctime>


#include "stockAccount.hpp"
// stockAccount constructor
stockAccount::stockAccount(double val) : Account(val) {
    
    cout << "\nMaking stock Account\n";
}


// Display stock price
void stockAccount::stockPrice(string symbol) {
    
    
    string line;
    srand(unsigned (time(NULL)));
    int num = rand()%4 + 1;
    string name = "stock" + to_string(num) + ".txt";
    ifstream file(name, ios::in);
    int count = 0;
    time_t rawtime;
    time (&rawtime);

    while(!file.eof()){
          
        getline(file,line);
        
        if(!line.find(symbol))
        {
            line.back() = '\t';
            cout << line << ctime(&rawtime) ;
            break;
        }
        
        
        count++; }
    if(file.eof()){
    cout << "\n The Symbol you enter was not found. \n";
    }

    file.close();
    ;
}



// Buying stock
void stockAccount::buyStock(string symbol, int numShare, double price) {
    
    string line;
    srand(unsigned (time(NULL)));
    int num = rand()%4 + 1;
    string name = "stock" + to_string(num) + ".txt";
    ifstream file(name, ios::in);
    int count = 0;
    
    
    
    while(!file.eof()){
        
        getline(file,line);
        
        if(!line.find(symbol))
        {
            break;
        }
        
        
        count++; }
    if(file.eof()){
        cout << "\n The Symbol you enter was not found. \n";
    }
else{
    // update cash
    if (getBalance() < numShare*price)
        cout << " Insufficient cash baance. ";
    if (getBalance() >= numShare*price){
        setBalance(getBalance()-numShare*price);
    
    ofstream historyfile("stock_transaction_history.txt", ios::app);
    historyfile  << "\n\nBUY          "
    << line.substr(0,20) << setw(15)<< price << setw(15)<< numShare;
    
    historyfile.close();
    file.close();
    ;
}
}
}

// Selling stock
void stockAccount::sellStock(string symbol, int numShare, double price) {
    
    
    string line;
    srand(unsigned (time(NULL)));
    int num = rand()%4 + 1;
    string name = "stock" + to_string(num) + ".txt";
    ifstream file(name, ios::in);
    int count = 0;
    
    
    while(!file.eof()){
        
        getline(file,line);
        
        if(!line.find(symbol))
        {
            break;
        }
        
        
        count++; }
    
    if(file.eof()){
        cout << "\n The Symbol you enter was not found. \n";
    }
    else{
        setBalance(getBalance()+numShare*price);  // update cashbalance
        
    ofstream historyfile("stock_transaction_history.txt", ios::app);
    historyfile  << "\n\nSELL          "
    << line.substr(0,20) << setw(15)<< price << setw(15)<< numShare;
    
    historyfile.close();
    file.close();

    ;
}
}



// stockAccount Menu
void stockAccount::menu() {
    bool flag = true;
    int selection = 0;
   
    
    while (flag) {
        cout << "\nPlease select an option" << endl
        << "\t1. Display current price for a stock symbol" << endl
        << "\t2. Buy stock" << endl
        << "\t3. Sell stock" << endl
        << "\t4. Display current portfolio" << endl
        << "\t5. Display transaction history" << endl
        << "\t6. Return to previous menu" << endl;
        
        cout << "\tYour selection: ";
        
        while(!(cin>>selection)){
            cout << "\nPlease select an option" << endl
            << "\t1. Display current price for a stock symbol" << endl
            << "\t2. Buy stock" << endl
            << "\t3. Sell stock" << endl
            << "\t4. Display current portfolio" << endl
            << "\t5. Display transaction history" << endl
            << "\t6. Return to previous menu" << endl;
            
            cout << "\tYour selection: ";
            cin.clear();
            cin.ignore(100, '\n');
        }
        
        
        switch(selection) {
            case 1: {
                string symbol;
                cout << "Enter Symbol: ";
                cin >> symbol;
                stockPrice(symbol);
                break;
            }
            case 2: {
                string symbol; int shares; double amount;
                cout << "Enter Buy Options (Symbol Shares Price): ";
                cin >> symbol >> shares >> amount;
                buyStock(symbol, shares, amount);
                break;
            }
            case 3: {
                string symbol; int shares; double amount;
                cout << "Enter Sell Options (Symbol Shares Price): ";
                cin >> symbol >> shares >> amount;
                sellStock(symbol, shares, amount);
                break;
            }
            case 4:
                cout << "\nCash balance = " << getBalance() << endl;
                break;
            case 5:{
                string out;
                ifstream history("stock_transaction_history.txt");
                
                while(getline(history,out)){
                    
                    cout << endl<< out << endl;
                }
                
                break;
            }
            case 6:
                cout << "\nReturning to previous menu. \n\n" ;
                // ignore output from case 6 so it doesnt become input in main menu
                cin.clear();
                cin.ignore(100, '\n');
                flag = false;
                break;
            default:
                cout << "\nIncorrect selection. Try again: \n\n" << endl;
                break;

        }
    }
}




