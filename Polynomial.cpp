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

Polynomial::Polynomial()
{
  head = nullptr;
}

Polynomial::Polynomial(std::string Desired_Polynomial)
{
    Desired_Polynomial += ' ';
    bool is_head_null;
    string number = "";
    const int length = Desired_Polynomial.length();
    bool search_for_exponent = false;
    Term polynomial;
    for (int i = 0; i < length; i++)
    {
        if ('0' <= Desired_Polynomial[i] && Desired_Polynomial[i] <= '9')
        {
            number += Desired_Polynomial[i];
        }
        
        else if (Desired_Polynomial[i] == 'x')
        {
            polynomial.Coefficient = String_To_Int(number.c_str());
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
                polynomial.Exponent = String_To_Int(number.c_str());
                search_for_exponent = false;
            }
            
            else
            {
                polynomial.Exponent = 0;
                polynomial.Coefficient = String_To_Int(number.c_str());
            }
            
            is_head_null = (head == nullptr);
            Append(polynomial.Coefficient, polynomial.Exponent, is_head_null);
            polynomial.Coefficient = 0;
            polynomial.Exponent = 0;
            number = "";
        }
    }
}

void Polynomial:: Print_Polynomial()
{
    Term *traversal_term = head;
    while (traversal_term)
    {
        char operatorion = traversal_term->Coefficient >= 0 ? '+' : ' ';
        string variable = traversal_term->Exponent > 0 ? "x^" : "";
        cout << operatorion << traversal_term->Coefficient << "x^" << traversal_term->Exponent << " ";
        traversal_term = traversal_term->Next_Term;
    }
}

void Polynomial:: Append(int coefficient,int exponent, bool head_empty)
{
    Term *traversal_term;
    Term *new_term = new Term;
    new_term->Coefficient = coefficient;
    new_term->Exponent = exponent;
    
    if (head_empty)
    {
        head = new_term;
    }
    
    else
    {
        traversal_term = head;
        
        while (traversal_term->Next_Term)
        {
            traversal_term = traversal_term->Next_Term;
        }
        
        traversal_term->Next_Term = new_term;
    }
}

Polynomial Polynomial:: Add(const Polynomial Poly2)
{
    Term *first = head;
    Term *second = Poly2.head;
    Polynomial sum;
    
    while (first && second)
    {
        
        if (first->Exponent == second->Exponent)
        {
            sum.Append(first->Coefficient + second->Coefficient, first->Exponent, sum.head == nullptr);
            first = first->Next_Term;
            second = second->Next_Term;
        }
        
        else if (first->Exponent > second->Exponent)
        {
            sum.Append(first->Coefficient, first->Exponent, sum.head == nullptr);
            first = first->Next_Term;
        }
        
        else
        {
            sum.Append(second->Coefficient, second->Exponent, sum.head == nullptr);
            second = second->Next_Term;
        }
    }
    return sum;
}
