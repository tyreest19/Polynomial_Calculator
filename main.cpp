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

void Print_Equation(string user_entered_polynomials[], int amount_of_polynomials, Polynomial polynomial, string symbol, string operation);
int main(int argc, const char * argv[]) {
    
    cout << "Hello, There this is a Polynomial Calculator! \n";
    cout << "This Calculator will allow you to Add and Multiply 2 or more Polynomial(Up to 10) \n\n";
    
    string term;
    int amount_of_polynomials = User_Inputted_Number(ENTER_AMOUNT_PROMPT, OUT_OF_BOUNDS, OUT_OF_BOUNDS, MINIMUM_AMOUNT_OF_POLY_NOMIALS, MAXIMUM_AMOUNT_OF_POLY_NOMIALS);
    string user_entered_polynomials[MAXIMUM_AMOUNT_OF_POLY_NOMIALS];
    Polynomial product;
    Polynomial sum;
    
    for (int i = 0; i < amount_of_polynomials; i++)
    {
        term = Get_User_Input(ENTER_POLYNOMIAL, INVALID_POLYNOMIAL, i + 1);
        user_entered_polynomials[i] = term;
        string format = user_entered_polynomials[i];
        
        if (i == 0)
        {
            sum.Create(format);
            product.Create(format);
        }
        
        else
        {
            Polynomial polynomial;
            polynomial.Create(format);
            sum = sum.Add(polynomial);
            product = product.Multiply(polynomial);
        }
    }
    
    cout << "\n";
    
    Print_Equation(user_entered_polynomials, amount_of_polynomials, sum, " + ", "Sum");
    Print_Equation(user_entered_polynomials, amount_of_polynomials, product, " * ", "Product");
    return 0;
}

void Print_Equation(string user_entered_polynomials[], int amount_of_polynomials, Polynomial polynomial, string symbol, string operation)
{
    for (int i = 0; i < amount_of_polynomials; i++)
    {
        if (i == 0)
        {
            cout << operation <<" = ";
        }
        
        cout << "( " << user_entered_polynomials[i] << " )";
        
        if (i + 1 < amount_of_polynomials)
        {
            if (i % 3 == 0 && i != 0)
            {
                cout << "\n" << string(operation.length() + 2, ' ');
            }
            cout << symbol;
            
        }
    }
    
    cout << "\n" << string(operation.length(), ' ') <<" = ";
    polynomial.Print_Polynomial(operation.length());
    cout << "\n\n";
}
