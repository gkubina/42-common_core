/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georg <georg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:18:57 by gkubina           #+#    #+#             */
/*   Updated: 2024/10/22 10:50:13 by georg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
    Data* data = new Data();
    data->i = 42;
    data->c = 'a';
    data->str = "Hello, World!";

    uintptr_t raw = Serializer::serialize(data);
    Data* deserialized = Serializer::deserialize(raw);

    std::cout << "Original data:" << std::endl;
    std::cout << "i: " << data->i << std::endl;
    std::cout << "c: " << data->c << std::endl;
    std::cout << "str: " << data->str << std::endl;
    std::cout << "Original data adress: " << data << std::endl;
    
    std::cout << "Raw data:" << raw << std::endl;
    std::cout << "Raw data adress:" << &raw << std::endl;
    
    std::cout << "Deserialized data:" << std::endl;
    std::cout << "i: " << deserialized->i << std::endl;
    std::cout << "c: " << deserialized->c << std::endl;
    std::cout << "str: " << deserialized->str << std::endl;
    std::cout << "Deserialized data adress: " << deserialized << std::endl;

    delete data;
  //  delete deserialized;

    return 0;
}