/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ta <abait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:43:35 by abait-ta          #+#    #+#             */
/*   Updated: 2024/02/09 09:20:02 by abait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <ctime>
#include <iomanip>

int main (int ac, char **av)
{
    (void)ac;
    (void)av;
    clock_t start_time = clock();
    // switch (ac)
    // {
    // case 2:
    //     try{
    //         PmergeMe Sorted(av[1]);
    //         Sorted.ParsInput();
    //         Sorted.Timer("vector", 0.00033);            
    //         Sorted.Timer("deque", 0.00039);            
    //     }catch(std::exception& e){
    //         std::cout << e.what() << std::endl;
    //     }
    //     break;
    // default:
    //     std::cout << "[ No     nough  Arguments  ]"<< std::endl;
    //     std::cout << "[ use  ./PmergMe  \"numbers\" ]"<< std::endl;
    //     break;
    // }
    unsigned long i(0);
    while (++i < 99999999999){
        std::cout << i << std::endl;
    }
    clock_t end_time = clock();
    std::cout << std::fixed << std::setprecision(9) <<double(end_time - start_time) / CLOCKS_PER_SEC << std::endl;
    
    return (0);
}
