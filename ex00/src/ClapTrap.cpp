/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodavid <thodavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 14:10:32 by kobe              #+#    #+#             */
/*   Updated: 2025/12/06 16:51:06 by thodavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/* CONSTR + DESTR */
ClapTrap::ClapTrap(void) : _name(), _hit_points(10), _energy_points(10), _attack_damage(0)
{
    std::cout << "Hello from ClapTrap constructor" << std::endl;
    return;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hit_points(10), _energy_points(10), _attack_damage(0)
{
    std::cout << "Hello from ClapTrap constructor" << std::endl;
    return;
}

ClapTrap::ClapTrap(ClapTrap const &src)
{
    std::cout << "Hello from ClapTrap cpy constr" << std::endl;
    *this = src;
    return;
}
ClapTrap::~ClapTrap(void)
{
    std::cout << "Hello from ClapTrap destructor" << std::endl;
    return;
}

/* GET + SET */
// std::string ClapTrap::getName(void)
// {
//     return (this->_name);
// }

//     int ClapTrap::getHitPts( void ){ return (this->_hit_points); };
//     int ClapTrap::getEnrgyPts( void ){ return (this->_energy_points); };
//     int ClapTrap::getAttckDama( void ){ return (this->_attack_damage);};

/* ClapTrap CMD */

void ClapTrap::attack(const std::string &target)
{
    std::cout << std::endl;
    if (this->_energy_points > 0 && this->_hit_points > 0)
    {
        std::cout << "===  ClapTrap  " << this->_name << "  ===" << std::endl
                  << "attack: " << target << std::endl
                  << "causing " << this->_hit_points << " points of damage!"
                  << std::endl;
        this->_energy_points--;
    }
    else
    {
        std::cout << "===ClapTrap  " << this->_name << "  ===" << std::endl;
        std::cout << "IS OUT OF ENERGY" << std::endl;
    }
    return;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << std::endl;
    if (this->_energy_points > 0 || this->_hit_points > 0)
    {
        int energy_pts;
        if (this->_energy_points > static_cast<float>(amount))
            energy_pts = (this->_energy_points - amount);
        else
            energy_pts = 0;
        std::cout << "===  ClapTrap  " << this->_name << "  ===" << std::endl
                  << "Outch! he lose: " << amount
                  << " hit points." << std::endl
                  << "his energy points is actually: " << energy_pts
                  << std::endl;
        this->_energy_points = energy_pts;
    }
    else
    {
        std::cout << "===  ClapTrap  " << this->_name << "  ===" << std::endl;
        std::cout << "IS OUT OF ENERGY" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    std::cout << std::endl;
    if (this->_energy_points > 0)
    {
        std::cout << "===  ClapTrap  " << this->_name << "  ===" << std::endl
                  << "repaired: " << amount << std::endl
                  << "his energy points is actually: " << (this->_hit_points + amount)
                  << std::endl;
        this->_energy_points--;
    }
    else
    {
        std::cout << "===ClapTrap  " << this->_name << "  ===" << std::endl;
        std::cout << "IS OUT OF ENERGY" << std::endl;
    }
}

ClapTrap &ClapTrap::operator=(ClapTrap const &rightHandSide)
{
    std::cout << "Copy assignment operator called" << '\n';
    if (this != &rightHandSide)
    {
        this->_name = rightHandSide._name;
        this->_hit_points = rightHandSide._hit_points;
        this->_energy_points = rightHandSide._energy_points;
        this->_attack_damage = rightHandSide._attack_damage;
    }
    return *this;
}
