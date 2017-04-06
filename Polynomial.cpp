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
#include "constant.h"
#include <string>

using namespace std;

Polynomial::Polynomial()
{
  head = nullptr;
}

void Polynomial:: Create(std::string Desired_Polynomial)
{
    bool is_head_null;
    string number = "0";
    head = nullptr;
    const int length = Desired_Polynomial.length();
    bool search_for_exponent = false;
    int operatoration = 0;
    Term polynomial;
    polynomial.Exponent = 0;
    polynomial.Coefficient = 0;
    
    for (int i = 0; i < length; i++)
    {
        if ('0' <= Desired_Polynomial[i] && Desired_Polynomial[i] <= '9')
        {
            number += Desired_Polynomial[i];
        }
        
        else if (Desired_Polynomial[i] == 'x')
        {
            cout << "top od single \n";
            if (number == "+" || number == "0")
            {
                polynomial.Coefficient = 1;
            }
        
            if (number == "-")
            {
                polynomial.Coefficient = -1;
            }
            
            is_head_null = (head == nullptr);
            bool next_steps = ((i + 1) < length);
            
            cout << "am o here rtgt !\n";
            if (!next_steps)
            {
                cout << "why am i here ? \n";
                this->Append(polynomial.Coefficient, 1, is_head_null);
                polynomial.Coefficient = 0;
                polynomial.Exponent = 0;
                number = "0";
            }
            
            else if (next_steps)
            {
                i++;
                cout << "am o here \n";
                
                if (Desired_Polynomial[i] == '+' || Desired_Polynomial[i] == '-')
                {
                    cout << "im here too";
                    this->Append(polynomial.Coefficient, 1, is_head_null);
                    polynomial.Coefficient = 0;
                    polynomial.Exponent = 0;
                    number = "0";
                }
                
                else if (Desired_Polynomial[i] == '^')
                {
                    cout << "exponent true \n";
                    search_for_exponent = true;
                    polynomial.Coefficient = String_To_Int(number.c_str());
                    i++;
                    number = Desired_Polynomial[i];
                    
                    for (i; i < length && search_for_exponent; i++)
                    {
                        if (Desired_Polynomial[i] != '+' || Desired_Polynomial[i] != '-')
                        {
                            polynomial.Exponent = String_To_Int(number.c_str());
                            Append(polynomial.Coefficient, polynomial.Exponent, is_head_null);
                            polynomial.Coefficient = 0;
                            polynomial.Exponent = 0;
                            number = "0";
                            search_for_exponent = false;
                        }
                        
                        else
                        {
                            number = Desired_Polynomial[i];
                        }
                    }
                    
                    number = "0";
                }
            }
        }
        
        else if ((Desired_Polynomial[i] == '+' || Desired_Polynomial[i] == '-'))
        {
            number += Desired_Polynomial[i];
            operatoration += 1;
            if (operatoration == 2 && !search_for_exponent)
            {
                is_head_null = (head == nullptr);
                polynomial.Coefficient = String_To_Int(number.c_str());
                this->Append(polynomial.Coefficient, 0, is_head_null);
                polynomial.Coefficient = 0;
                polynomial.Exponent = 0;
                operatoration = 0;
                number = "0";
            }
            
            else if (operatoration == 2 && search_for_exponent)
            {
                is_head_null = (head == nullptr);
                polynomial.Exponent = String_To_Int(number.c_str());
                this->Append(polynomial.Coefficient, polynomial.Exponent, is_head_null);
                polynomial.Coefficient = 0;
                polynomial.Exponent = 0;
                operatoration = 0;
                number = "0";
                search_for_exponent = false;
            }
        }
    }
    
    is_head_null = (head == nullptr);
    
    if (search_for_exponent)
    {
        cout << "exponent: " << number << "\n";
        polynomial.Exponent = String_To_Int(number.c_str());
        Append(polynomial.Coefficient, polynomial.Exponent, is_head_null);
    }
    
    else
    {
        polynomial.Coefficient = String_To_Int(number.c_str());
        Append(polynomial.Coefficient, 0, is_head_null);

    }
    this->Condense();
}

void Polynomial:: Print_Polynomial(int amount_of_space)
{
    Term *traversal_term = head;
    bool first_term_passed = false;
    int count = 0;
    
    while (traversal_term)
    {
        string operatorion = traversal_term->Coefficient >= 0 ? " + " : " - ";
        operatorion = first_term_passed ? operatorion : "";
        int coefficient = traversal_term->Coefficient < 0? traversal_term->Coefficient * -1 : traversal_term->Coefficient;

        if (traversal_term->Exponent == 0 && traversal_term->Coefficient != 0)
            cout << operatorion << coefficient;
        
        else if (traversal_term->Coefficient == 1 && traversal_term->Exponent != 1 && traversal_term->Coefficient != 0)
        {
            cout << operatorion << VARIABLE << traversal_term->Exponent << " ";
        }
        
        else if (traversal_term->Coefficient != 1 && traversal_term->Exponent == 1 && traversal_term->Coefficient != 0)
        {
            cout << operatorion << coefficient << VARIABLE[0] << " ";
        }
        
        else if (traversal_term->Coefficient != 1 && traversal_term->Exponent == 1 && traversal_term->Coefficient != 0)
        {
            cout << operatorion << coefficient << VARIABLE[0] << traversal_term->Exponent << " ";
        }
        
        else if (traversal_term->Coefficient == 1 && traversal_term->Exponent == 1 && traversal_term->Coefficient != 0)
        {
            cout << operatorion <<  VARIABLE[0];
        }
        
        else if (traversal_term->Exponent != 0 && traversal_term->Coefficient != 0)
            cout << operatorion << coefficient << VARIABLE << traversal_term->Exponent << " ";
        
        traversal_term = traversal_term->Next_Term;
        first_term_passed = true;
        count++;
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
    
    sum.Condense();
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
                removed_term->Next_Term = removed_term->Next_Term;
                first->Next_Term = removed_term->Next_Term;
                break;
            }

            else if (first->Exponent < first->Next_Term->Exponent)
            {
                Term temp = *first->Next_Term;
                first->Next_Term->Coefficient = first->Coefficient;
                first->Next_Term->Exponent = first->Exponent;
                first->Coefficient = temp.Coefficient;
                first->Exponent = temp.Exponent;
                swap = true;
            }
        }
    } while (swap);
}
