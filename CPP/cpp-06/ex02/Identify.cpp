/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georg <georg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:18:57 by gkubina           #+#    #+#             */
/*   Updated: 2024/10/22 13:03:32 by georg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identify.hpp"

Base * generate(void)
{
    srand(time(NULL));
    int i = rand() % 3;
    if (i == 0)
    {
        std::cout << "A generated" << std::endl;
        return (new A());
    }
    else if (i == 1)
    {
        std::cout << "B generated" << std::endl;
        return (new B());
    }
    else
    {
        std::cout << "C generated" << std::endl;
        return (new C());
    }
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else if (dynamic_cast<Base*>(p))
        std::cout << "Base" << std::endl;
    else    
        std::cout << "Could not identify." << std::endl;
}

void identify(Base& p)
{
    try
    {
        A &a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "A" << std::endl;
    }
    catch(const std::exception& e)
    {
        try
        {
            B &b = dynamic_cast<B&>(p);
            (void)b;
            std::cout << "B" << std::endl;
        }
        catch(const std::exception& e)
        {
            try
            {
                C &c = dynamic_cast<C&>(p);
                (void)c;
                std::cout << "C" << std::endl;
            }
            catch(const std::exception& e)
            {
                try
                {
                    Base &base = dynamic_cast<Base&>(p);
                    (void)base;
                    std::cout << "Base" << std::endl;
                }
                catch(const std::exception& e)
                {
                    std::cerr << "Error: " << e.what() << std::endl;
                    std::cerr << "Could not identify." << std::endl;
                }            
            }
        }
    }
}

