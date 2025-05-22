/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <gianmarco.dauria@libero.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 17:49:50 by gd-auria          #+#    #+#             */
/*   Updated: 2025/05/22 18:13:40 by gd-auria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "generate_and_identify.hpp"

int main(int argc, char **argv)
{
    Base* base;
    
    (void)argv;
    if (argc > 1)
        return 1;
    
    srand(time(NULL));

    base = generate();
    identify(*base);
    identify(base);

    delete base;
    return 0;
}