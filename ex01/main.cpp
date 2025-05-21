/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gd-auria <gianmarco.dauria@libero.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 15:49:38 by gd-auria          #+#    #+#             */
/*   Updated: 2025/05/21 16:21:41 by gd-auria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(int argc, char **argv)
{
    if (argc > 1)
        return 1;
    
    (void)argv;

    Data data_struct;
    uintptr_t raw_pointer;
    Data* copy_deserialized;

    data_struct.num = 42;
    data_struct.text_one = "let's serialize!";
    data_struct.text_two = "let's deserialize!";

    raw_pointer= Serializer::serialize(&data_struct);
    copy_deserialized = Serializer::deserialize(raw_pointer);
    
    std::cout << "Original DATA STRUCT address: " << &data_struct << std::endl;
    std::cout << "DATA STRUCT SERIALIZED value: " << raw_pointer << std::endl;
    std::cout << "POINTER COINTAINING DATA STRUCT DESERIALIZED value: " << copy_deserialized << std::endl;
    std::cout << "COPY DESERIALIZED number: " << copy_deserialized->num << std::endl;
    std::cout << "COPY DESERIALIZED text one: " << copy_deserialized->text_one << std::endl;
    std::cout << "COPY DESERIALIZED text two: " << copy_deserialized->text_two << std::endl;
}


// PERCHÉ USO REINTERPRET_CAST?
//In questo esercizio stiamo lavorando a basso livello, per dati raw (networking, serializzazione, cast tra
//puntatori di tipo diverso) e applica solo una reinterpretazione binaria,
// gestendo gli indirizzi di memoria che verranno serializzati in stream di
//byte e stream di byte che verranno deserializzati in dati.

//NON stiamo operando conversioni logiche come nel caso dell'ex00 ma semplicemente reinterpretando i bytes
//NON stiamo modificando i dati
//REINTERPRET_CAST funziona per cast arbitrari tra puntatori e interi, o tipi non correlati

//Se proviamo a fare static_cast<uintptr_t>(data) il compilatore darà errore

//TUTTAVIA bisogna usare REINTERPRET_CAST con parsimonia PERCHÈ IL COMPILATORE NON CONTROLLA
//E PERMETTE DI FORZARE QUALSIASI TIPO A DIVENTARNE UN ALTRO ANCHE SE NON SONO COMPATIBILI
//NON È GARANTITO CHE FUNZIONI SU TUTTE LE ARCHITETTURE -> UB(undefined behavior)