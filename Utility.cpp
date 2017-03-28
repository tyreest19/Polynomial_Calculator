//
//  Utility.cpp
//  Polynomial_Calculator
//
//  Created by Tyree Stevenson on 3/27/17.
//  Copyright © 2017 Tyree Stevenson. All rights reserved.
//

#include <string>
#include <iostream>
#include "Utility.hpp"
using namespace std;
//==========================================================================================
// Takes constant char pointer and converts it into a string.
// If one of the characters are not a digit the function returns -1.
//==========================================================================================
int String_To_Int(const char *str)
    {
        int result = 0;
        int prefix = 0;
        
        if (str[0] == '\0')
        {
            return -1;
        }
        
        else if (str[0] == '-' || str[0] == '+')
        {
            prefix = 1;
        }
        
        for (int i = prefix; str[i] != '\0'; ++i)
        {
            if ('0' <= str[i] && str[i] <= '9')
            {
                result = result*10 + str[i] - '0';
            }
            
            else
            {
                return -1;
            }
        }
        
        if (str[0] == '-')
        {
            result *= -1;
        }
        
        return result;
    }

//============================================================================================
// Takes user inputted number as a string and returns the number if its fits the parameters.
// If the number does not fit the parameters the user is prompted to enter a new number.
//============================================================================================

int User_Inputted_Number(string prompt, string invalid_prompt, string out_of_bounds_prompt, int lower_bounds, int upper_bounds)
{
    int number = -1;
    string user_entered_number;
    
    while (number == -1 || (number < lower_bounds || number > upper_bounds))
    {
        cout << prompt;
        getline(cin, user_entered_number);
        number = String_To_Int(user_entered_number.c_str());
        cout << "\n";
        
        if (number == -1)
        {
            cout << invalid_prompt << "\n\n";
        }
        
        else if (number < lower_bounds || number > upper_bounds)
        {
            cout << out_of_bounds_prompt << "\n";
        }
    }
    
    return number;
}

//============================================================================================
// Prompts user to enter a correct polynomial and returns it as a string
//============================================================================================

string Get_User_Input(string prompt, string invalid_input_prompt, int number)
{
    bool valid_input = false;
    string polynomial;
    
    while(!valid_input)
    {
        cout << prompt << number << " -> ";
        getline(cin, polynomial);
    }
    
    return polynomial;
}
