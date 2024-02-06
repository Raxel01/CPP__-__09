/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ta <abait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:25:23 by abait-ta          #+#    #+#             */
/*   Updated: 2024/02/06 22:07:56 by abait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <stack>
#include <exception>

class UnacceptableSymbol : public std::exception
{
    public :
        virtual const char* what() const throw();
};

class RPN
{
    public :
    static int result;
    static std::stack<int> Mystack;
    static int addition(int a, int b)
    {
        return (a + b);
    }
    static int subtraction(int a, int b)
    {
        return (a - b);
    }
    static int division(int a, int b)
    {
        return (a / b);
    }
    static int multiplication(int a, int b)
    {
        return (a * b);
    }
    // int RecognizeOperator(char c);
    // int RecognizeOperand(char c);
    
    
};
