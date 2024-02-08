/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ta <abait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 20:38:13 by abait-ta          #+#    #+#             */
/*   Updated: 2024/02/08 17:58:14 by abait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <deque>
#include <sstream>

class NonValidinput : public std::exception{
    
    public :
        virtual const char *what() const throw();
};

class PmergeMe
{
    private:
        std::string Numbers;
        short int visited;
    public:
        PmergeMe();
        PmergeMe(char *av);
        PmergeMe(const PmergeMe& origine);
        PmergeMe& operator=(const PmergeMe& origine);
        void              ParsInput();
        void              InputState(std::string& holder);
        void              beforeSorting(std::string& holder);
        ~PmergeMe();

};