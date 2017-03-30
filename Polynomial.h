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
        Term *Previous_Term = nullptr;
        Term *Next_Term = nullptr;
    };

    Term *head;
    void Reverse_Polynomial();
};

#endif /* Polynomial_h */
