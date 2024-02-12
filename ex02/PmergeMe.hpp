/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ta <abait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 20:38:13 by abait-ta          #+#    #+#             */
/*   Updated: 2024/02/12 12:26:17 by abait-ta         ###   ########.fr       */
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
#include <iterator>
#include <iomanip>



class NonValidinput : public std::exception{
    
    public :
        virtual const char *what() const throw();
};

class OnlyOnecase : public std::exception{
    
    public :
        virtual const char *what() const throw();
};

typedef  std::deque<std::pair<int, int> > Pairdeque;

class MyDeque
{
    private :
        std::deque<int>         _Deque;
        int                     _LastValue;
        Pairdeque               Paired;
        std::deque<int>         _Mainchaine;
        std::deque<int>         _Pendchaine;
        clock_t                 DequeStart;
        clock_t                 Dequeend;
    public :
        size_t                _DequeSize;
        MyDeque();
        void                setdeque(std::vector<int> InitialVector);
        void                Getdeque() ;
        void                setLastValue(int setWith);
        void                GetLastValue();
        void                StartDequeProcess();
        void                mergeSort( size_t begin, size_t end );
        void                Sortsubs(size_t begin, int midle, size_t end);
        void                TimerDeque(std::string STLtype);
        void                Main_PendChaine();
        void                insertion(std::deque<int>& elem, size_t begin, size_t end);
        MyDeque(const MyDeque& origine);
        MyDeque& operator=(const MyDeque& origine);
        ~MyDeque();
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
        int                 _LastValue;
        std::vector<int>    _Mainchaine;
        std::vector<int>    _Pendchaine;
        clock_t             vectorStart;
        clock_t             vectorend;
    public:
        size_t              _VectorSize;
        PmergeMe();
        PmergeMe(char *av);
        PmergeMe(const PmergeMe& origine);
        PmergeMe& operator=(const PmergeMe& origine);
        void              TimerVect(std::string container);    
        void              ParsInput();
        void              InputState(std::string& holder);
        void              beforeSorting();
        void              PairSort(MyDeque& dequeObject);
        void              mergeSort( size_t begin, size_t end );
        void              Sortsubs(size_t begin, int midle, size_t end);
        void              Main_PendChaine();
        void              insertion(std::vector<int>&elem, size_t begin, size_t end);
        std::vector<int>  GetVector();
        int               GetLastValue();  
        ~PmergeMe();

};


