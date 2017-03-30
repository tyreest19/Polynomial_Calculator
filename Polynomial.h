//
//  Polynomial.h
//  Polynomial_Calculator
//
//  Created by Tyree Stevenson on 3/27/17.
//  Copyright © 2017 Tyree Stevenson. All rights reserved.
//

#ifndef Polynomial_h
#define Polynomial_h
#include <iostream>

class Polynomial
{
    
public:
    
    Polynomial(std::string Desired_Polynomial);
    void Print_Polynomial();
private:
    
    struct Term
    {
        int Coefficient;
        int Exponent;
        Term *Next_Term = nullptr;
    };

    Term *head;
    void Append(int coefficient,int exponent, bool head_empty);
};

#endif /* Polynomial_h */
