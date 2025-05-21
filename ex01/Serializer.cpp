/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <gianmarco.dauria@libero.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 15:18:50 by gd-auria          #+#    #+#             */
/*   Updated: 2025/05/21 16:09:11 by gd-auria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{

}

Serializer::~Serializer()
{

}

Serializer::Serializer(const Serializer&)
{
    
}

Serializer& Serializer::operator=(const Serializer&)
{
    return *this;
}

uintptr_t Serializer::serialize(Data* ptr)
{
    uintptr_t serialized;

    serialized = reinterpret_cast<uintptr_t>(ptr);
    return serialized;
}

Data* Serializer::deserialize(uintptr_t raw)
{
    Data* deserialized;

    deserialized = reinterpret_cast<Data *>(raw);
    return deserialized;
}
