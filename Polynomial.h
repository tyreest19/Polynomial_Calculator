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

private:
    struct Term
    {
        int Coefficient;
        int Exponent;
        Term *Next_Term = nullptr;
    };
    void Append(int coefficient,int exponent, bool head_empty);

public:
    Polynomial();
    void Create(std::string Desired_Polynomial);
    void Print_Polynomial(int amount_of_space);
    Polynomial Add(const Polynomial Poly2);
    Polynomial Multiply(const Polynomial Poly2);
    void Condense();
    Term *head;
};

#endif /* Polynomial_h */
