/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_and_identify.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <gianmarco.dauria@libero.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 18:09:34 by gd-auria          #+#    #+#             */
/*   Updated: 2025/05/22 18:15:10 by gd-auria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GENERATE_AND_IDENTIFY_HPP
#define GENERATE_AND_IDENTIFY_HPP

#include <string>
#include <iostream>
#include <cstdlib>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate(void)
{
    int random_obj = 0;
    
    random_obj = rand() % 3;
    switch (random_obj)
    {
        case 0:
        return new A();
        case 1:
        return new B();
        case 2:
        return new C();
    }
    return NULL;
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
    {
        std::cout << "Type is: A" << std::endl;
        return;
    }
    else if (dynamic_cast<B*>(p))
    {
        std::cout << "Type is: B" << std::endl;
        return;
    }
    else if (dynamic_cast<C*>(p))
    {
        std::cout << "Type is: C" << std::endl;
        return;
    }
    return;
}

void identify(Base& p)
{
    if (dynamic_cast<A*>(&p))
    {
        std::cout << "Type is: A" << std::endl;
        return;
    }
    else if (dynamic_cast<B*>(&p))
    {
        std::cout << "Type is: B" << std::endl;
        return;
    }
    else if (dynamic_cast<C*>(&p))
    {
        std::cout << "Type is: C" << std::endl;
        return;
    }
    return;
}

#endif
