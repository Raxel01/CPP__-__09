/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ta <abait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:25:23 by abait-ta          #+#    #+#             */
/*   Updated: 2024/02/07 12:41:18 by abait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <stack>
#include <exception>
#include <sstream>

class UnacceptableSymbol : public std::exception
{
    public :
        virtual const char* what() const throw();
};

class EmptyString : public std::exception
{
    public :
        virtual const char* what() const throw();
};

class NonValidInput : public std::exception
{
    public :
        virtual const char* what() const throw();
};

class ElemsInStack : public std::exception
{
     public :
        virtual const char* what() const throw();  
};

class RPN
{
    private :
        static size_t inputsize;
        static int first;
        static int second;
        static int result;
        static std::stack<int> Mystack;
        RPN();
    public :
        static  void       stackManipulation(); 
        static void        FinalResult(std::string &operation);
        static void        addition();
        static void        subtraction();
        static void        division();
        static void        multiplication();
        static int         RecognizeOperator(char c);
        static int         RecognizeOperand(char c);
        static void        ParseOperation(std::string& operation);
        ~RPN();
};
