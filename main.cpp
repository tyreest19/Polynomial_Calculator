//
//  main.cpp
//  Polynomial_Calculator
//
//  Created by Tyree Stevenson on 3/27/17.
//  Copyright © 2017 Tyree Stevenson. All rights reserved.
//

#include <iostream>
#include <string>
#include "Polynomial.h"
#include "Utility.hpp"
#include "constant.h"

using namespace std;

int main(int argc, const char * argv[]) {
    cout << "Hello, There this is a Polynomial Calculator! \n";
    cout << "This Calculator will allow you to Add and Multiply 2 or more Polynomial(Up to 10) \n\n";
    User_Inputted_Number(ENTER_AMOUNT_PROMPT, OUT_OF_BOUNDS, OUT_OF_BOUNDS, MINIMUM_AMOUNT_OF_POLY_NOMIALS, MAXIMUM_AMOUNT_OF_POLY_NOMIALS);
    Get_User_Input(ENTER_POLYNOMIAL, INVALID_POLYNOMIAL, 1);
    return 0;
}