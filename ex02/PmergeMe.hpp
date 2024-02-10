/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ta <abait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 20:38:13 by abait-ta          #+#    #+#             */
/*   Updated: 2024/02/10 21:49:16 by abait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <deque>
#include <sstream>
#include <limits.h>

class NonValidinput : public std::exception{
    
    public :
        virtual const char *what() const throw();
};

typedef  std::vector<std::pair<int, int> > Pairtype;

class PmergeMe
{
    private:
        std::string         Numbers;
        short int           visited;
        long long           elements;
        std::vector<int>    Vector;
        Pairtype            Paired;
        size_t              _VectorSize;
        int                 _LastValue;
        std::vector<int>    _Mainchaine;
        std::vector<int>    _Pendchaine;
    public:
        PmergeMe();
        PmergeMe(char *av);
        PmergeMe(const PmergeMe& origine);
        PmergeMe& operator=(const PmergeMe& origine);
        void              Timer(std::string container, double time);    
        void              ParsInput();
        void              InputState(std::string& holder);
        void              beforeSorting();
        void              PairSort();
        void              mergeSort( size_t begin, size_t end );
        void              Sortsubs(size_t begin, int midle, size_t end);
        void              Main_PendChaine();
        ~PmergeMe();

};