/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ta <abait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 20:42:52 by abait-ta          #+#    #+#             */
/*   Updated: 2024/02/08 17:59:24 by abait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

const char* NonValidinput::what() const throw()
{
    return ("Non Valid character in Your input");
}

PmergeMe::PmergeMe(){
    
}

PmergeMe::PmergeMe(char *av) : Numbers(av), visited(0){
    
}

PmergeMe::~PmergeMe(){
    
}

PmergeMe::PmergeMe(const PmergeMe& origine){

    *this = origine;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& origine){
    
    if (this != &origine){
        Numbers = origine.Numbers;

    }
    return (*this);
}

void    PmergeMe::InputState(std::string& holder)
{
    int i (-1);

    if (holder[++i] == '+'){
    i++;
        if (!holder[i])
            throw NonValidinput();
    }
    while (holder[i]){
        if (!isdigit(holder[i]))
            throw NonValidinput();
        i++;
    }
}

void    PmergeMe::beforeSorting(std::string& holder)
{
    std::cout << "Before : ";
    std::stringstream stream (Numbers);
     while (stream >> holder){
        std::cout << holder << " ";
    }
    std::cout << "" << std::endl;
    stream.clear();
}

void    PmergeMe::ParsInput(){

    std::string holder;
    std::stringstream ss(Numbers);

    while (ss >> holder){
        InputState(holder);
        visited = 1;
    }
    if (!visited)
        throw NonValidinput();
    ss.clear();
    beforeSorting(holder);
}