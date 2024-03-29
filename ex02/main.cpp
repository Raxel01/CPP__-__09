/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ta <abait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:43:35 by abait-ta          #+#    #+#             */
/*   Updated: 2024/02/12 12:22:21 by abait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main (int ac, char **av)
{
    switch (ac)
    {
    case 2:
        try{
            PmergeMe Sorted(av[1]);
            Sorted.ParsInput();
            MyDeque    DequeObj;
            Sorted.PairSort(DequeObj);
            DequeObj.StartDequeProcess();
        }catch(std::exception& e){
            std::cout << e.what() << std::endl;
        }
        break;
    default:
        std::cout << "[ No    enough  Arguments  ]"<< std::endl;
        std::cout << "[ use  ./PmergMe  \"numbers\" ]"<< std::endl;
        break;
    }  
    return (0);
}
