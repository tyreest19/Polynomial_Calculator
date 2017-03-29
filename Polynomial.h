//
//  Polynomial.h
//  Polynomial_Calculator
//
//  Created by Tyree Stevenson on 3/27/17.
//  Copyright © 2017 Tyree Stevenson. All rights reserved.
//

#ifndef Polynomial_h
#define Polynomial_h

struct Polynomial
{
    char Following_Math_Operator;
    int Coefficient;
    int Exponent;
    Polynomial *Next_Term = nullptr;
};
#endif /* Polynomial_h */
