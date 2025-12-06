/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodavid <thodavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 08:22:09 by thodavid          #+#    #+#             */
/*   Updated: 2025/12/02 13:11:27 by thodavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

Pokemon::Pokemon(void)
{
    std::cout << "hello from the const" << std::endl;
    return;
}

Pokemon::Pokemon(std::string name)
{
    std::cout << "hello from the constr" << std::endl;
    this->name = (name);
    return;
}
Pokemon::Pokemon(const Pokemon &src)
{
    std::cout << "hello from the constr" << std::endl;
    this->name = src.getName();
    this->pv = src.getPv();
    this->type = src.getType();
    return;
}
Pokemon::~Pokemon(void)
{
    std::cout << "bye from the destr" << std::endl;
}

void Pokemon::setPv(int pv)
{
    this->pv = pv;
    return;
}
void Pokemon::setName(std::string name)
{
    this->name = name;
    return;
}
void Pokemon::setType(std::string type)
{
    this->type = type;
}
std::string Pokemon::getName(void) const
{
    return (this->name);
}
std::string Pokemon::getType(void) const
{
    return (this->type);
}

int Pokemon::getPv(void) const
{
    return (this->pv);
}

Pokemon &Pokemon::operator=(Pokemon const &rightHandSide)
{
    if (this != &rightHandSide)
    {
        this->name = rightHandSide.getName();
        this->pv = rightHandSide.getPv();
        this->type = rightHandSide.getType();
    }
    return *this;
}

    int Pokemon::getA( void ) const{
        return this->a;
    }
    void Pokemon::setA( int i ){
        this->a = i;
        return;
    }


Pokemon& Pokemon::operator++( )
{
    a += 1;
    this->setA( (this->a + 1) );
    return *this;
}

Pokemon& Pokemon::operator--( ){
    this->setA( (this->getA() - 1) );
    return *this;
}

Pokemon Pokemon::operator++( int )
{
    Pokemon tmp( *this);
    ++(*this);
    return tmp;
}

Pokemon Pokemon::operator--( int )
{
    Pokemon tmp( *this);
    --(*this);
    return tmp;
}

int main( void )
{
    
    
    Pokemon p;
    std::cout << "(after) p is : " << p.a << std::endl;
    p++;
    std::cout << "(before) p is : " << p.a << std::endl;

    std::cout << "(after) p is : " << p.a << std::endl;
    p++;
    std::cout << "(before) p is : " << p.a << std::endl;
    return (0);
}


// if (ac != 4)
//     return (std::cout << "for create a Pokemon enter: 1.his Name 2.his Type 3.his Pv"
//                       << std::endl,
//             0);
// Pokemon p(av[1]);
// p.setType(av[2]);
// p.setPv(atoi(av[3]));
// std::cout << "your pokemon is::" << std::endl
//           << "name:: " << p.getName() << std::endl
//           << "type:: " << p.getType() << std::endl
//           << "pv::  " << p.getPv() << std::endl
//           << std::endl;

// Pokemon y (p);
// std::cout << "your pokemon copy is::" << std::endl
//           << "name:: " << y.getName() << std::endl
//           << "type:: " << y.getType() << std::endl
//           << "pv::  " << y.getPv() << std::endl;
