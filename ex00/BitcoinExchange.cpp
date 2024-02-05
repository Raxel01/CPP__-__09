/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ta <abait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:14:05 by abait-ta          #+#    #+#             */
/*   Updated: 2024/02/05 16:28:10 by abait-ta         ###   ########.fr       */
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

const char *DateSyntaxeError::what() const throw(){
    return "Date Syntax Is Not Valid  Try Again !" ;
}

const char *NonValidAmount::what() const throw(){
    return "The Entred Amount is Wrong !" ;
}

BitcoinWallet::BitcoinWallet(){}

BitcoinWallet::BitcoinWallet(char *av) : infilename(av), infile(infilename), 
    DataBaseinfile("data.csv"), DataBaseFile(DataBaseinfile)
{}

void    BitcoinWallet::Claimfd(){
    infile.close();
    DataBaseFile.close();
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

void    BitcoinWallet::PurDigit(std::string& Date)
{
    int i(-1);
    while (Date[++i])
        if (!isdigit(Date[i]))
            throw DateSyntaxeError(); 
}

/*Reunder*/
int    MinusPos(std::string& fullDate)
{
    if (fullDate[4] != '-' || fullDate[7] != '-')
        return (0);
    return (1);
}

void    BitcoinWallet::getYear()
{
    std::string YearS;
    
    YearS = FullDate.substr(0, 4);
    PurDigit(YearS);
    year = atoi(YearS.c_str());
    if (year < 2009 || year > 2024)
        throw DateSyntaxeError();
}

void    BitcoinWallet::getMonth()
{
    std::string months;
    
    months = FullDate.substr(5, 2);
    PurDigit(months);
    month = atoi(months.c_str());
    if (month < 1 || month > 12)
        throw DateSyntaxeError();
}

int getNumberOfDays(int month, int year)
{
    if (month == 2) {
        if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
            return 29;
        else
            return 28;
    }
    else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8
        || month == 10 || month == 12)
        return 31;
    else
        return 30;
}

void    BitcoinWallet::getDay()
{
    std::string Days;
    
    Days = FullDate.substr(8);
    PurDigit(Days);
    Day = atoi(Days.c_str());
    if (!(Day >= 1 && Day <= getNumberOfDays(month,year)))
        throw DateSyntaxeError();
}

void    BitcoinWallet::extractDate(std::string& lineReaded){
    
    FullDate = lineReaded.substr(0, lineReaded.find("|") - 1);
    size_t _Occur = std::count(FullDate.begin(),FullDate.end(), '-');
    
    if(FullDate.length() == 10 &&  _Occur == 2 && MinusPos(FullDate)){
        getYear ();
        getMonth();
        getDay  ();
    }else
        throw DateSyntaxeError();
}

void    BitcoinWallet::AmountVerification()
{
    int i (-1);
    
    if (AmountString[++i] == '-')//0
        throw  NoPositiveAmount();
    while (AmountString[i] && AmountString[i] != '.'){
        if (!std::isdigit(AmountString[i]))
            throw  NonValidAmount();
        i++;
    }
    
    /*Pause*/
    if (AmountString[i] == '.')
    {
        if (/*check i before check in string*/AmountString[i + 1])
        {
              while (AmountString[i]){
                   if (!std::isdigit(AmountString[i]))
                        throw  NonValidAmount();
                i++;}
        }
        else
            throw NonValidAmount();
    }
    
}

void    BitcoinWallet::extractValue(std::string& lineReaded){
    
    AmountString = lineReaded.substr(lineReaded.find('|') + 2);
    AmountVerification();
    AmountValue = strtod(AmountString.c_str(), NULL);
    std::cout << "|" << std::fixed << std::setprecision(10) << AmountValue<< "|" << std::endl;
}
