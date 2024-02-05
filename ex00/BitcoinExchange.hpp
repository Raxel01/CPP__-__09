/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ta <abait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:13:10 by abait-ta          #+#    #+#             */
/*   Updated: 2024/02/04 13:01:34 by abait-ta         ###   ########.fr       */
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

class   BitcoinWallet
{
    private :
        // std::string InvalidInput;
        std::string     infilename;
        std::ifstream   infile;
        std::string     DataBaseinfile;
        std::ifstream   DataBaseFile;
        std::map<std::string, double> DataBase;
        // static const std::ifstream Copy;
    public :
        BitcoinWallet();
        BitcoinWallet(char *av);
        void Claimfd();
        std::string     Bitcoine();
        static  std::string FileError(std::string&);
        void    ParentGrammar(std::string &line);
        void    CleanString(std::string& line);
        void    ReformLine(std::string& str);
        std::string    ImportDatabase();
        // static void reformeLine(std::string&)
        ~BitcoinWallet();
};

