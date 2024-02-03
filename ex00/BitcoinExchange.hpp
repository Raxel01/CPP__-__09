/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ta <abait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:13:10 by abait-ta          #+#    #+#             */
/*   Updated: 2024/02/03 14:18:14 by abait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <vector>
#include <deque>
#include <exception>
#include <fstream>

class NoDataInFile : public std::exception
{
    public :
        virtual const char* what() const throw();
};

class ParentGrammar : public std::exception
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
        std::string InvalidInput;
    public :
        // BitcoinWallet();
        static std::string Bitcoine(char **av);
        static std::string FileError(std::string&);
        // static void reformeLine(std::string&)
        // ~BitcoinWallet();
};
