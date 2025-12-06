/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodavid <thodavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 14:00:01 by kobe              #+#    #+#             */
/*   Updated: 2025/12/06 16:51:09 by thodavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    std::cout << "=====================" << std::endl;
    std::cout << "========START========" << std::endl;
    std::cout << "=====================" << std::endl;

    ClapTrap kobe("KOBE");
    ClapTrap kobe2;

    // std::cout << kobe.getName( ) << std::endl;
    // std::cout << kobe.getHitPts() << std::endl;
    // std::cout << kobe.getEnrgyPts() << std::endl;
    // std::cout << kobe.getAttckDama() << std::endl;
    kobe.attack(" ");
    kobe.beRepaired(42);
    kobe.takeDamage(42);
    kobe.attack(" ");
    kobe.beRepaired(42);

    std::cout << std::endl;
    std::cout << "=====================" << std::endl;
    std::cout << "=========END=========" << std::endl;
    std::cout << "=====================" << std::endl;
    return (0);
}
