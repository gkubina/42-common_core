/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georg <georg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:18:57 by gkubina           #+#    #+#             */
/*   Updated: 2024/10/22 13:06:56 by georg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identify.hpp"

int main()
{
  {
    std::cout << "--- Test using random generator ---" << std::endl;
    Base *base = generate();
    std::cout << "Identifying pointer:" << std::endl;
    identify(base);
    std::cout << "Identifying reference:" << std::endl;
    identify(*base);
    delete base;
  }
  {
    std::cout << "--- Test with pointer to base class ---" << std::endl;
    Base *base = new Base();
    std::cout << "Identifying pointer:" << std::endl;
    identify(base);
    std::cout << "Identifying reference:" << std::endl;
    identify(*base);
    delete base;
  }
  {
    std::cout << "--- Test with Null base pointer ---" << std::endl;
    Base *base = NULL;
    std::cout << "Identifying pointer:" << std::endl;
    identify(base);
    std::cout << "Identifying reference:" << std::endl;
    identify(*base);
    delete base;
  }

    return 0;
}