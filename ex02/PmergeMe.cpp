/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ta <abait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 20:42:52 by abait-ta          #+#    #+#             */
/*   Updated: 2024/02/11 20:05:16 by abait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iomanip>
const char* NonValidinput::what() const throw()
{
    return ("Non Valid character in Your input");
}

PmergeMe::PmergeMe(){
    
}

PmergeMe::PmergeMe(char *av) : Numbers(av), visited(0), _LastValue(-1){
    
}

PmergeMe::~PmergeMe(){
    
}

PmergeMe::PmergeMe(const PmergeMe& origine){

    *this = origine;
}
std::vector<int>    PmergeMe::GetVector() const{
    return (Vector);
}

PmergeMe& PmergeMe::operator=(const PmergeMe& origine){
    
    if (this != &origine){
        Numbers     = origine.Numbers;
        Vector      = origine.Vector;
        vectorend   = origine.vectorend;
        vectorStart = origine.vectorStart;
    }
    return (*this);
}

void              PmergeMe::TimerVect(std::string STLtype){
    
    std::cout <<"Time to process a range of " << Vector.size() << " elements with std::[" << STLtype << "] : " <<
    std::fixed << std::setprecision(8) << (double)(vectorend - vectorStart) << " us"<<std::endl;
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
    elements = strtol(holder.c_str(), NULL, 0);
    if (elements > 2147483647)
        throw NonValidinput();
    Vector.push_back(static_cast<int>(elements));
}

void    PmergeMe::beforeSorting()
{
    std::vector<int>::iterator it = Vector.begin();
    
    std::cout << "Before : ";
    while(it != Vector.end()){
        std::cout << *it << " ";
        it++;
    }
    std::cout << ""<< std::endl;
    _VectorSize = Vector.size();
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
    
    beforeSorting();
}