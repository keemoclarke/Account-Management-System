//
//  Account.cpp
//  PM1_project 2
//
//  Created by Keemo Clarke on 5/5/17.
//  Copyright © 2017 Keemo Sabastian Clarke. All rights reserved.
//
#include <iostream>
#include <fstream>

#include "Account.hpp"

using namespace std;


Account::Account(double bal)
{
    cashBalance = bal;
    
}

double Account::getBalance() const
{

    return cashBalance;

}



void Account::setBalance(double amount)
{
    cashBalance = amount;
}

