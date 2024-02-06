
#include <iostream>
#include <stack>
#include "./ex01/RPN.hpp"

int     isOperator(char c){
    return (c == '-' || c == '+' || c == '*' || c == '/');
}

int RPN::result = 0;
int main (int ac ,char **av)
{
    
    double a = 8;

    double b = 0;

    std::cout << a / b<< std::endl;
    // std::string lol(av[1]);
    
    // size_t  Mylollenght = lol.length();
    // std::stack<int> stack;

    
    // int i(-1);
    // for (int i = 0 ; i < Mylollenght; i++)
    // {
    //     if (lol[i] >= '0' && lol[i] <= '9')
    //         stack.push(lol[i] - '0');
    //     else if (isOperator(lol[i]) && stack.size() >= 2)
    //     {
    //         int a = stack.top();
    //         stack.pop();
    //         int b = stack.top();
    //         stack.pop();
    //         switch (lol[i])
    //         {
    //         case '+':
    //             RPN::result = RPN::addition(a, b);
    //             stack.push(RPN::result);
    //             break;
    //         case '-':
    //             RPN::result = RPN::subtraction(a, b);
    //             stack.push(RPN::result);
    //             break;
    //         case '*':
    //             RPN::result = RPN::multiplication(a, b);
    //             stack.push(RPN::result);
    //             break;
    //         case '/':
    //             RPN::result = RPN::division(a, b);
    //             stack.push(RPN::result);
    //             break;
    //         default:
    //             break;
    //         }
    //     }

    // }
    // if 
    // std::cout << stack.top() << std::endl;
    return (0);
}