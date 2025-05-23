/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <gianmarco.dauria@libero.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:52:52 by gd-auria          #+#    #+#             */
/*   Updated: 2025/05/21 16:18:08 by gd-auria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
        return 1;
    ScalarConverter::converter(argv[1]);
    return 0;
}


//PERCHÈ UTILIZZIAMO STATIC_CAST?
//static_cast è perfetto per le convesioni logiche di dati, come per esempio
//la trasformazione da int a float, o da una classe derivata a base e viceversa