//
//  bankAccount.hpp
//  PM1_project 2
//
//  Created by Keemo Clarke on 5/6/17.
//  Copyright © 2017 Keemo Sabastian Clarke. All rights reserved.
//

#ifndef bankAccount_hpp
#define bankAccount_hpp

#include <stdio.h>
#include <iostream>

#include "Account.hpp"


using namespace std;

class bankAccount: public Account {
    
public:
    
    bankAccount(double val = 10000.0);
    void deposit(double);
    void withdraw(double);
    void menu();
    
private:
    
};

#endif /* bankAccount_hpp */
