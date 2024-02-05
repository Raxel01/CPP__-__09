/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ta <abait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:12:27 by abait-ta          #+#    #+#             */
/*   Updated: 2024/02/05 15:47:26 by abait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void    BitcoinWallet::CleanString(std::string& line)
{
    int     i = -1;
    int     flg (0);
	std::stringstream ss;
    
    while (line[++i])
	{
		if (line[i] == ' ' || line[i] == '\t')
			flg = 1;
		if (!(line[i] == ' ' || line[i] == '\t'))
		{
			if (flg)
				ss << " ";
			flg = 0;
			ss << line[i];
			}
		}
    line = ss.str();
}

void    BitcoinWallet::ReformLine(std::string& str)
{
  size_t first = 0; 
  while (first < str.size() && std::isspace(str[first])) {
    ++first;
  }
 
  size_t last = str.size() - 1;
  while (last > first && std::isspace(str[last])) {
    --last;
  }
  str = str.substr(first, last - first + 1);
  CleanString(str);
}

std::string     BitcoinWallet::Bitcoine()
{
    std::string     BitcoinLine;
    
    if (!infile.is_open())
        return (BitcoinWallet::FileError(infilename));
    try
    {
        if (std::getline(infile, BitcoinLine))
        {
            if (!BitcoinLine.compare("date | value"))
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
                ReformLine(BitcoinLine);
                ParentGrammar(BitcoinLine);
                extractDate(BitcoinLine);
                extractValue(BitcoinLine); 
        }
            catch(const std::exception& e){
                std::cerr << e.what() << std::endl;
        }
    }
    }
    return ("");
}

std::string    BitcoinWallet::ImportDatabase()
{
    std::string Line;
    std::string ExctractDate;
    std::string ExctactRate;
    
    if (!DataBaseFile.good())
        return (BitcoinWallet::FileError(DataBaseinfile));
    if (std::getline(DataBaseFile, Line))
    {
        if (!std::getline(DataBaseFile, Line))
            throw NoDataInFile();
        try{
            ExctractDate = Line.substr(0,Line.find_first_of(","));
            ExctactRate  = Line.substr(Line.find_first_of(",") + 1, Line.size());
            DataBase.insert(std::pair<std::string, double>(ExctractDate, strtod(ExctactRate.c_str(), NULL)));
            throw ContinueToProcess();
        }catch(ContinueToProcess& e){
            while (1)
            {
                if (!std::getline(DataBaseFile, Line))
                    break;
                ExctractDate = Line.substr(0,Line.find_first_of(","));
                ExctactRate  = Line.substr(Line.find_first_of(",") + 1, Line.size());
                DataBase.insert(std::pair<std::string, double>(ExctractDate, strtod(ExctactRate.c_str(),NULL)));
            }
        }
    }
    else
        throw NoDataInFile();
    return (SUCCES);
}

int main (int ac, char **av)
{
    if (ac == 2)
    {
           BitcoinWallet Wallet(av[1]);
           try{
            if (Wallet.ImportDatabase() != SUCCES)
                throw std::runtime_error("");
            Wallet.Bitcoine();
            Wallet.Claimfd();
        }
        catch(std::exception& e){
            std::cout << e.what() << std::endl;
            Wallet.Claimfd();
        }
        
    }else{
            std::cout << " [Error: We Can't Find  a file]"<< std::endl;
            std::cout << " [Use  : ./btc [Specify a file]" << std::endl;
    }
    return (0);
}