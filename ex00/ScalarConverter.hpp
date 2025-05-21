/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <gianmarco.dauria@libero.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:35:53 by gd-auria          #+#    #+#             */
/*   Updated: 2025/05/21 15:34:57 by gd-auria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <string>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>


class ScalarConverter
{
    private:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter&);
        ScalarConverter& operator=(const ScalarConverter&);
    public:
        static void converter(const std::string& string);
};


#endif