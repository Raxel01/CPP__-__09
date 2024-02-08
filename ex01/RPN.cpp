/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ta <abait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:26:23 by abait-ta          #+#    #+#             */
/*   Updated: 2024/02/07 20:23:27 by abait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"


const char* UnacceptableSymbol::what()const throw()
{
    return "Unacceptable symbole in Your input"; 
}

const char* EmptyString::what()const throw()
{
    return "Operation String is Empty"; 
}

const char* NonValidInput::what()const throw()
{
    std::cout << "Non valid character in " << std::endl;
    return "Your input String"; 
}

const char* ElemsInStack::what()const throw()
{
    std::cout << "More Than One element Or Non in stack" << std::endl;
    return "===> Error : non Valid input"; 
}

void    RPN::stackManipulation(){
    second = Mystack.top();
    Mystack.pop();
    first = Mystack.top();
    Mystack.pop();
}


void  RPN::FinalResult(std::string &operation)
{
    for (size_t i = 0; i < inputsize; i++){
        if (RecognizeOperand(operation[i]))
            Mystack.push(operation[i] - '0');
        else if (RecognizeOperator(operation[i]) && Mystack.size() >= 2)
        {
            stackManipulation();
            switch (operation[i]){
                case '+' :
                    addition();
                    Mystack.push(result);
                    break;
                case '-' :
                    subtraction();
                    Mystack.push(result);
                    break;
                case '*' :
                    multiplication();
                    Mystack.push(result);
                    break;
                case '/' :
                    division();
                    Mystack.push(result);
                    break;
                default:
                    break;
            }
        }
    }
    if (Mystack.size() != 1)
        throw ElemsInStack();
    std::cout << Mystack.top() << std::endl;
}

std::stack<int> RPN::Mystack        ;
size_t          RPN::inputsize   = 0;
int             RPN::result      = 0;
int             RPN::first       = 0;
int             RPN::second      = 0;

int RPN::RecognizeOperand(char c){
    return (c >= '0' && c <= '9');
}

int RPN::RecognizeOperator(char c){
    return (c == '+' || c == '-' || c == '*' || c == '/');
}
void RPN::addition(){
    result = first + second;
}

void RPN::subtraction(){
    result = first - second;
}

void RPN::division(){
    if (second == 0)
        throw std::runtime_error("Exception : Divide by Zero Detected");
    result = first / second;
}

void RPN::multiplication(){
    result = first * second;
}
/*Constructor*/
RPN::RPN()
{}

RPN::~RPN()
{}

void        RPN::ParseOperation(std::string& operation)
{
    inputsize = operation.length();
    if (inputsize != 0)
    {
        for(size_t i = 0; i < inputsize; i++){
            if (!(RecognizeOperand(operation[i])
            || RecognizeOperator(operation[i])
            || operation[i] == 32))
                throw NonValidInput();
        }
        std::stringstream stream(operation);
        std::string catchestring;

        while (stream >> catchestring){
            if (catchestring.length() > 1)
                throw NonValidInput();
        }
    }
    else
        throw EmptyString();
}