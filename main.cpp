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

void Print_Equation(Polynomial user_entered_polynomials[], int amount_of_polynomials, Polynomial polynomial, string symbol, string operation);
int main(int argc, const char * argv[]) {
    
    cout << "Hello, There this is a Polynomial Calculator! \n";
    cout << "This Calculator will allow you to Add and Multiply 2 or more Polynomial(Up to 10) \n\n";
    
    string term;
    int amount_of_polynomials = User_Inputted_Number(ENTER_AMOUNT_PROMPT, OUT_OF_BOUNDS, OUT_OF_BOUNDS, MINIMUM_AMOUNT_OF_POLY_NOMIALS, MAXIMUM_AMOUNT_OF_POLY_NOMIALS);
    Polynomial product;
    Polynomial sum;
    Polynomial polynomials[MAXIMUM_AMOUNT_OF_POLY_NOMIALS];
    
    for (int i = 0; i < amount_of_polynomials; i++)
    {
        
        term = Get_User_Input(ENTER_POLYNOMIAL, INVALID_POLYNOMIAL, i + 1);
        cout << term << "\n";
        polynomials[i].Create(term);
        
        if (i == 0)
        {
            sum.Create(term);
            product.Create(term);
        }
        
        else
        {
            sum = sum.Add(polynomials[i]);
            product = product.Multiply(polynomials[i]);
        }
    }
    
    cout << "\n";
    
    Print_Equation(polynomials, amount_of_polynomials, sum, " + ", "Sum");
    Print_Equation(polynomials, amount_of_polynomials, product, " * ", "Product");
    return 0;
}

void Print_Equation(Polynomial user_entered_polynomials[], int amount_of_polynomials, Polynomial polynomial, string symbol, string operation)
{
    for (int i = 0; i < amount_of_polynomials; i++)
    {
        if (i == 0)
        {
            cout << operation <<" = ";
        }
        
        cout << "( ";
        user_entered_polynomials[i].Print_Polynomial(0);
        cout << " )";
        
        if (operation == "Sum" && i + 1 < amount_of_polynomials)
        {
           cout << " + ";
        }
        
        else if (operation == "Product" && i + 1 < amount_of_polynomials)
        {
            cout << " * ";
        }
    }
    
    cout << "\n" << string(operation.length(), ' ') <<" = ";
    polynomial.Print_Polynomial(-3);
    cout << "\n\n";
}

