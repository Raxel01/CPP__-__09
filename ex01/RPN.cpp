/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-ta <abait-ta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:26:23 by abait-ta          #+#    #+#             */
/*   Updated: 2024/02/06 19:47:54 by abait-ta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"


const char* UnacceptableSymbol::what()const throw()
{
    return "Unacceptable symbole in Your input"; 
}
