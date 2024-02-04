/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ta <abait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:14:05 by abait-ta          #+#    #+#             */
/*   Updated: 2024/02/04 10:07:59 by abait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

const char* NoDataInFile::what() const throw(){
    std::cout << " unfortunately No Data In File " << std::endl;
    std::cout << " Please Insert Data To see What" << std::endl;
    std::cout << " My Program Can Do ....lalala! "<< std::endl;
    return ("");
}

const char* ParentGrammarEx::what() const throw(){
    std::cout << "Parent Grammer not accepted !";
    return (" : Invalid Input");
}

const char* NoTitleBare::what() const throw(){
    std::cout << "The First Line should Be This : "<< std::endl;
    return (     "      [ Date | Value ]");
}


const char* NoPositiveAmount::what() const throw(){
    return ("Error : The Amount is not a positive Number");
}

BitcoinWallet::BitcoinWallet(){}

BitcoinWallet::BitcoinWallet(char *av) : infilename(av), infile(infilename)
{}

void    BitcoinWallet::Claimfd(){
    infile.close();
}

BitcoinWallet::~BitcoinWallet(){}

void    BitcoinWallet::ParentGrammar(std::string&line)
{
    size_t       OccurPipe = std::count(line.begin(), line.end(), '|');
    size_t       OccurSpace= std::count(line.begin(), line.end(), 32);
    int          groups(0);
    std::string  Box;
    
    if (OccurPipe == 1 && OccurSpace == 2){
        std::stringstream stream(line);
        while(stream >> Box)
        {
            groups++;
            if (groups == 2) //Second elemnt in the line [1] [|] [2]
                if (Box.compare("|"))
                    throw ParentGrammarEx();
        }
    }
    else
        throw ParentGrammarEx(); 
}

std::string BitcoinWallet::FileError(std::string& file)
{
    std::cerr << "|++> We Cant Open Your File : " << "[-"<< file << "-]"<< std::endl;
    std::cerr << "|++> Error Occured Process Terminating...!"<< std::endl;
    return ("");
}
