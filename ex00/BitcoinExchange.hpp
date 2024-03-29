/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ta <abait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:13:10 by abait-ta          #+#    #+#             */
/*   Updated: 2024/02/08 20:41:50 by abait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <vector>
#include <deque>
#include <exception>
#include <sstream>
#include <fstream>
#include <map>
#include <cstdlib> 
// #include <bits/stdc++.h>
#include <time.h>

#define SUCCES "SUCCES"

class NoDataInFile : public std::exception
{
    public :
        virtual const char* what() const throw();
};

class ParentGrammarEx : public std::exception
{
    public :
        virtual const char* what() const throw();
};

class NoTitleBare : public std::exception
{
    public :
        virtual const char* what() const throw();
};

class ContinueToProcess : public std::exception
{
    public :
        virtual const char* what() const throw(){return ("");};
};

class NoPositiveAmount : public std::exception
{
    public :
        virtual const char* what() const throw();
};

class NonValidAmount : public std::exception
{
    public :
        virtual const char* what() const throw();
};

class DateSyntaxeError : public std::exception
{
    public :
        virtual const char* what() const throw();
};

class NosuitableDay : public std::exception
{
    public :
        virtual const char* what() const throw();
};

typedef std::map<std::string, double, std::greater<std::string> > MAP;

class   BitcoinWallet
{
    private :
        std::string                     infilename;
        std::ifstream                   infile;
        std::string                     DataBaseinfile;
        std::ifstream                   DataBaseFile;
                  MAP                   DataBase;
        std::string                     FullDate;
        int                             year;
        int                             month;
        int                             Day;
        double                          AmountValue;
        std::string                     AmountString;
    public :
        BitcoinWallet();
        BitcoinWallet(const BitcoinWallet &origine);
        BitcoinWallet& operator=(const BitcoinWallet &origine);
        BitcoinWallet(char *av);
        void Claimfd();
        std::string     Bitcoine();
        static  std::string FileError(std::string&);
        void    ParentGrammar(std::string &line);
        void    CleanString(std::string& line);
        void    ReformLine(std::string& str);
        void    extractDate(std::string& lineReaded);
        void    extractValue(std::string& lineReaded);
        void    getYear ();
        void    getMonth();
        void    getDay  ();
        void    AmountVerification();
        void    PurDigit(std::string& Date);
        std::string    ImportDatabase();
        void    Amountrange();
        ~BitcoinWallet();
};

