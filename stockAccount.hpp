//
//  stockAccount.hpp
//  PM1_project 2
//
//  Created by Keemo Clarke on 5/5/17.
//  Copyright © 2017 Keemo Sabastian Clarke. All rights reserved.
//

#ifndef stockAccount_hpp
#define stockAccount_hpp

#include <iostream>
#include <stdio.h>

#include "Account.hpp"


using namespace std;

class stockAccount: public Account {
    
public:
    
    stockAccount(double val = 10000.0);
    void stockPrice(string);
    void buyStock(string, int, double);
    void sellStock(string, int, double);
    void menu();
    void randomStock();
    
private:
    
};
#endif /* stockAccount_hpp */
