/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <gianmarco.dauria@libero.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 15:11:24 by gd-auria          #+#    #+#             */
/*   Updated: 2025/05/21 16:09:27 by gd-auria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>

#include "Data.hpp"

class Serializer
{
    private:
        Serializer();
        ~Serializer();
        Serializer(const Serializer&);
        Serializer& operator=(const Serializer&);

    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);  


    
};


#endif