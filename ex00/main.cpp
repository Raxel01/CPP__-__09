/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ta <abait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:12:27 by abait-ta          #+#    #+#             */
/*   Updated: 2024/02/03 13:51:12 by abait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::string BitcoinWallet::FileError(std::string& file)
{
    std::cerr << "|++> We Cant Open Your File : " << "[-"<< file << "-]"<< std::endl;
    std::cerr << "|++> Error Occured Process Terminating...!"<< std::endl;
    return ("");
}

std::string     BitcoinWallet::Bitcoine(char **av)
{
    std::string     infilename = (av[1]);
    std::string     BitcoinLine;
    std::ifstream   infile (infilename);
    EmptyFile = 0;
    BadtitleBar = 0;

    if (!infile.is_open())
        return (BitcoinWallet::FileError(infilename));
    try
    {
        if (std::getline(infile, BitcoinLine))
        {
            if (!BitcoinLine.compare("Data | Value"))
                throw ContinueToProcess();
            throw NoTitleBare();
        }
        else
            throw NoDataInFile();

    }catch(ContinueToProcess& e){
        std::cout << "Bdat Lkhedma"<< std::endl;
        while (1)
        {
            if (!std::getline(infile, BitcoinLine))
                break ;
            try{
                std::cout << BitcoinLine << std::endl;
                // LineProcessing
        }
            catch(const std::exception& e){
                std::cerr << e.what() << std::endl;
        }
    }
    }
    return ("");
}

int main (int ac, char **av)
{
    switch (ac)
    {
    case 2:
        try{
            BitcoinWallet::Bitcoine(av);
        }
        catch(std::exception& e){
            std::cout << e.what() << std::endl;
        }
        break;
    default:
        std::cout << " [Error: We Can't Find  a file]"<< std::endl;
        std::cout << " [Use  : ./btc [Specify a file]" << std::endl;
        break;
    }
    return (0);
}