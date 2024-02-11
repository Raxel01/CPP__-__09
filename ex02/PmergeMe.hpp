/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ta <abait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 20:38:13 by abait-ta          #+#    #+#             */
/*   Updated: 2024/02/11 20:08:28 by abait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include  <iostream>
#include  <vector>
#include  <map>
#include  <deque>
#include  <sstream>
#include  <limits.h>
#include  <ctime>
#include  <iomanip>
#include  <algorithm>
#include  <list>


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
        clock_t             vectorStart;
        clock_t             vectorend;
    public:
        PmergeMe();
        PmergeMe(char *av);
        PmergeMe(const PmergeMe& origine);
        PmergeMe& operator=(const PmergeMe& origine);
        void              TimerVect(std::string container);    
        void              ParsInput();
        void              InputState(std::string& holder);
        void              beforeSorting();
        void              PairSort();
        void              mergeSort( size_t begin, size_t end );
        void              Sortsubs(size_t begin, int midle, size_t end);
        void              Main_PendChaine();
        template<typename T>
        void              insertion(T &elem, size_t begin, size_t end);
        std::vector<int>   GetVector() const;
        ~PmergeMe();

};

class List
{
    private :
    std::list<int>    _List;
    size_t            _ListSize;
    size_t            _LastValue;
    std::list<int>    _Mainchaine;
    std::list<int>    _Pendchaine;
    clock_t           vectorStart;
    clock_t           vectorend;
    public :
        List();
        List(const List& origine);
        List& operator=(const List& origine);
        ~List();
};
