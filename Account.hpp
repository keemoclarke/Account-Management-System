//
//  Account.hpp
//  PM1_project 2
//
//  Created by Keemo Clarke on 5/5/17.
//  Copyright © 2017 Keemo Sabastian Clarke. All rights reserved.
//


#ifndef Account_hpp
#define Account_hpp

#include <iostream>
#include <stdio.h>

using namespace std;

class Account {
    
public:
    
    Account(double bal = 10000.0);
    
    double getBalance() const;
    
    void setBalance(double);
    
     
    
private:
    
    double cashBalance;
    
};




#endif /* Account_hpp */
