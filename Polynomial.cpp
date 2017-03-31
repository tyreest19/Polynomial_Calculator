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
    head = nullptr;
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
    this->Condense();
}

void Polynomial:: Print_Polynomial()
{
    Term *traversal_term = head;
    while (traversal_term)
    {
        char operatorion = traversal_term->Coefficient >= 0 ? '+' : ' ';
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

//============================================================================================
// Adds snother polynomial to this object
// returns a the sum.
//============================================================================================

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
        
        while (first)
        {
            sum.Append(first->Coefficient, first->Exponent, sum.head == nullptr);
            first = first->Next_Term;
        }
        
        while (second)
        {
            sum.Append(second->Coefficient, second->Exponent, sum.head == nullptr);
            second = second->Next_Term;
        }
    }
    return sum;
}

//============================================================================================
// Multiplys snother polynomial to this object
// returns a the product.
//============================================================================================

Polynomial Polynomial:: Multiply(const Polynomial Poly2)
{
    Polynomial product;
    product.Append(0, 0, true);
    for (Term *first = head; first; first = first->Next_Term)
    {
        for (Term *second = Poly2.head; second; second = second->Next_Term)
        {
            Polynomial additive_steps;
            additive_steps.Append(0, 0, true);
            int coefficient = first->Coefficient * second->Coefficient;
            int exponent = first->Exponent + second->Exponent;
            additive_steps.Append(coefficient, exponent, additive_steps.head == nullptr);
            product = product.Add(additive_steps);
        }
    }
    cout << (product.head->Coefficient) << "\n";
    product.Condense();
    return product;
}

//============================================================================================
// Multiplys snother polynomial to this object
//============================================================================================

void Polynomial:: Condense()
{
    bool swap;
    do
    {
        swap = false;
        
        for (Term *first = head; first->Next_Term; first = first->Next_Term)
        {
            if (first->Exponent == first->Next_Term->Exponent)
            {
                swap = true;
                Term *removed_term = first->Next_Term;
                first->Coefficient += removed_term->Coefficient;
                removed_term = removed_term->Next_Term;
                first->Next_Term = removed_term;
                
            }

            if (first->Exponent < first->Next_Term->Exponent)
            {
                Term temp = *first->Next_Term;
                first->Next_Term->Coefficient = first->Coefficient;
                first->Next_Term->Exponent = first->Exponent;
                first->Coefficient = temp.Coefficient;
                first->Exponent = temp.Exponent;
                swap = true;
            }
            cout << "im in condense" << endl;
        }
    } while (swap);
}




