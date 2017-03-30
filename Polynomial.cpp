//
//  Polynomial.cpp
//  Polynomial_Calculator
//
//  Created by Tyree Stevenson on 3/29/17.
//  Copyright © 2017 Tyree Stevenson. All rights reserved.
//

#include <stdio.h>
#include "Polynomial.h"
#include "Utility.hpp"
#include <iostream>

using namespace std;

Polynomial::Polynomial(std::string Desired_Polynomial)
{
    Desired_Polynomial += ' ';
    head = nullptr;
    bool is_head_null = true;
    string number = "";
    const int length = Desired_Polynomial.length();
    bool search_for_exponent = false;
    Term *polynomial = new Term;
    for (int i = 0; i < length; i++)
    {
        if ('0' <= Desired_Polynomial[i] && Desired_Polynomial[i] <= '9')
        {
            number += Desired_Polynomial[i];
        }
        
        else if (Desired_Polynomial[i] == 'x')
        {
            polynomial->Coefficient = String_To_Int(number.c_str());
            number = "";
            if (i + 1 < length)
            {
                i += 1;
                search_for_exponent = (Desired_Polynomial[i] == '^');
            }
        }
        
        else if (Desired_Polynomial[i] == '+' || Desired_Polynomial[i] == '-')
        {
            number += Desired_Polynomial[i];
        }
        
        else if (Desired_Polynomial[i] == ' ')
        {
            if (search_for_exponent)
            {
                polynomial->Exponent = String_To_Int(number.c_str());
                search_for_exponent = false;
            }
            
            else
            {
                polynomial->Exponent = 0;
                polynomial->Coefficient = String_To_Int(number.c_str());
            }
            
            Term *next_term = new Term;
            polynomial->Next_Term = next_term;            
            number = "";
        }
    }
    head = polynomial;
}

void Polynomial:: Print_Polynomial()
{
    Term *traversal_term = head;
    char operatorion = ' ';
    while (traversal_term->Next_Term)
    {
        if (traversal_term->Coefficient >= 0)
            operatorion = '+';

        cout << operatorion << traversal_term->Coefficient << "x^" << traversal_term->Exponent << " ";
        traversal_term = traversal_term->Next_Term;
    }
}

void Polynomial:: Reverse_Polynomial()
{
    Term* cursor = NULL;
    Term* next;
    while (head)
    {
        next = head->Next_Term;
        head->Next_Term = cursor;
        cursor = head;
        head = next;
    }
    head =  cursor;
}
