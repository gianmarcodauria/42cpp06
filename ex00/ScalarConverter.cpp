/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <gianmarco.dauria@libero.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:49:25 by gd-auria          #+#    #+#             */
/*   Updated: 2025/05/19 20:01:55 by gd-auria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
    
}

ScalarConverter::~ScalarConverter()
{
    
}

ScalarConverter::ScalarConverter(const ScalarConverter& copy)
{
    (void)copy;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& copy)
{
    if (this != &copy)
        *this = copy;
    return *this;
}

void ScalarConverter::converter(const std::string& string)
{
    
    float float_num = 0;
    double double_num = 0;
    int integer_num = 0;
    char literal_char;
    
    //FIRST IF FOR PSEUDO-LITERALS

    if (string == "+inf" || string == "nan" || string == "-inf" ||
        string == "nanf" || string == "+inff" || string == "-inff")
        {
            char *float_null_pointer = NULL;

            float_num = std::strtof(string.c_str(), &float_null_pointer);
            double_num = static_cast<double>(float_num);
            std::cout << "CHAR: conversion is impossible" << std::endl;
            std::cout << "INT: conversion is impossible" << std::endl;
            std::cout << "FLOAT: " << std::fixed << std::setprecision(1) << float_num << "f" << std::endl;
            std::cout << "DOUBLE: " << double_num << std::endl;
            return;
        }
        
    //SECOND IF FOR LITERAL CHAR BETWEEN DOUBLE APEX AND SINGLE APEX es: "'C'"

    if (string.length() == 3 && string[0] == '\'' && string[2] == '\'')
    {
        literal_char = string[1];
        float_num = static_cast<float>(literal_char);
        double_num = static_cast<double>(literal_char);
        integer_num = static_cast<int>(literal_char);
            
        std::cout << "CHAR: " << literal_char << std::endl;
        std::cout << "INT: " << integer_num << std::endl;
        std::cout << "FLOAT: " << std::fixed << std::setprecision(1) << float_num << "f" << std::endl;
        std::cout << "DOUBLE: " << std::fixed << double_num << std::endl;
        return;
    }
    
    //THIRD IF FOR LITERAL CHARACTERS IN SINGLE OR DOUBLE APEX AND NO APEX
    if (string.length() == 1 && std::isprint(string[0]) && !std::isdigit(string[0]))
    {
        char c = string[0];
        int i = static_cast<int>(c);
        float f = static_cast<float>(c);
        double d = static_cast<double>(c);

        std::cout << "CHAR: " << c << std::endl;
        std::cout << "INT: " << i << std::endl;
        std::cout << "FLOAT: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
        std::cout << "DOUBLE: " << d << std::endl;
        return;
    }
        
    //let's have pointer that keeps track of the letters after the decimals
    
    char *null_pointer_to_keep_track_of_decimals = NULL;
    double value_for_standard_conversions = 0;
    value_for_standard_conversions = std::strtod(string.c_str(), &null_pointer_to_keep_track_of_decimals);
    
    //let's use that nullpointer to check if we have a float number now that we'll need to convert

    //otherwise, the number is not accepted - the conversion will happen indeed but and error
    
    //will occurr

    bool is_it_float = false;
    if (*null_pointer_to_keep_track_of_decimals == '\0')
        is_it_float = false;
    else if (*null_pointer_to_keep_track_of_decimals == 'f' && *(null_pointer_to_keep_track_of_decimals + 1) == '\0')
        is_it_float = true;
    else
    {
        std::cout << "CHAR: conversion is impossible" << std::endl;
        std::cout << "INT: conversion is impossible" << std::endl;
        std::cout << "FLOAT: conversion is impossible" << std::endl;
        std::cout << "DOUBLE: conversion is impossible" << std::endl;
        return;
    }

    //let's have a normal CHAR conversion control, shall we?

    if (value_for_standard_conversions < 0 || value_for_standard_conversions > 127 ||
        std::isnan(value_for_standard_conversions))
        std::cout << "CHAR: conversion is impossible; not an ASCII VALUE" << std::endl;
    else if(!std::isprint(static_cast<char>(value_for_standard_conversions)))
        std::cout << "CHAR: non displayable" << std::endl;
    else
        std::cout << "CHAR: " << static_cast<char>(value_for_standard_conversions) << std::endl;

    
    // now for the INT
    if (value_for_standard_conversions > std::numeric_limits<int>::max() ||
        value_for_standard_conversions < std::numeric_limits<int>::min() ||
        std::isnan(value_for_standard_conversions))
    {
        std::cout << "CIAO INT: conversion is impossible" << std::endl;
    }
    //FLOAT and DOUBLE (is_it_float is here just for the compiler to stay silent)
    else
    {
        int integer_num = static_cast<int>(value_for_standard_conversions);
        std::cout << "INT: " << integer_num << std::endl;
    }
    (void)is_it_float;
    float_num = static_cast<float>(value_for_standard_conversions);
    std::cout << "FLOAT: " << std::fixed << std::setprecision(1) << float_num << "f" << std::endl;
    
    double_num = static_cast<double>(value_for_standard_conversions);
    std::cout << "DOUBLE: " << std::fixed << std::setprecision(1) << double_num << std::endl;
}
