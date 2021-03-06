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

void Convert_Varaibles_To_Lower(string &polynomial);
int String_To_Int(const char *str);
string Get_User_Input(string prompt, string invalid_input_prompt, int number);
int User_Inputted_Number(string prompt, string invalid_prompt, string out_of_bounds_prompt, int lower_bounds, int upper_bounds);
void Remove_Spaces(string &input);
bool Valid_Input(string &polynomial);
void Format_Polynomial_With_Spaces(string &polynomial);
#endif /* Utility_hpp */
