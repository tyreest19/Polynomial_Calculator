//
//  Utility.hpp
//  Polynomial_Calculator
//
//  Created by Tyree Stevenson on 3/27/17.
//  Copyright © 2017 Tyree Stevenson. All rights reserved.
//

#ifndef Utility_hpp
#define Utility_hpp

#include <stdio.h>
#include <string>
#include "Polynomial.h"
#include <iostream>

using namespace std;

int String_To_Int(const char *str);
string Get_User_Input(string prompt, string invalid_input_prompt, int number);
int User_Inputted_Number(string prompt, string invalid_prompt, string out_of_bounds_prompt, int lower_bounds, int upper_bounds);

#endif /* Utility_hpp */
