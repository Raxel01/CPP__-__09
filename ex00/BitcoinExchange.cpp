/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ta <abait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 16:14:05 by abait-ta          #+#    #+#             */
/*   Updated: 2024/02/03 13:44:27 by abait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

const char* NoDataInFile::what() const throw(){
    std::cout << " unfortunately No Data In File " << std::endl;
    std::cout << " Please Insert Data To see What" << std::endl;
    std::cout << " My Program Can Do ....lalala! "<< std::endl;
    return ("");
}

const char* ParentGrammar::what() const throw(){
    std::cout << "Parent Grammer not accepted !"<< std::endl;
    return ("Use Data [Data | Value]");
}

const char* NoTitleBare::what() const throw(){
    std::cout << "The First Line should Be This : "<< std::endl;
    return (     "      [ Date | Value ]");
}


const char* NoPositiveAmount::what() const throw(){
    return ("Error : The Amount is not a positive Number");
}

short int BitcoinWallet::EmptyFile = 0;
short int BitcoinWallet::BadtitleBar= 0;




