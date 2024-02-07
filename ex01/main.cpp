/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ta <abait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 20:59:35 by abait-ta          #+#    #+#             */
/*   Updated: 2024/02/07 12:42:26 by abait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main (int ac, char **av)
{
    switch (ac)
    {
    case 2:
        try{
            std::string operation(av[1]);
            RPN::ParseOperation(operation);
            RPN::FinalResult(operation);
        }
        catch(const std::exception& e){
            std::cerr << e.what() << std::endl;
        }
        break;
    default:
        std::cout << " Hi Useer !"<< std::endl;
        std::cout << " Try [ ./RPN \"rpn to calculate\"]" << std::endl;
        break;
    }
    
    return (0);
}