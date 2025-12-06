/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodavid <thodavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 08:23:05 by thodavid          #+#    #+#             */
/*   Updated: 2025/12/02 16:11:01 by thodavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_HPP
#define TEST_HPP

#include <stdio.h>
#include <iostream>
#include <string>
#include <cmath>

class Pokemon
{
public:
    Pokemon(void);
    Pokemon(std::string name);
    Pokemon(const Pokemon &src);
    ~Pokemon(void);
    
    void setPv(int pv);
    void setName(std::string name);
    void setType(std::string type);
    int getPv(void) const;
    int getA( void ) const;
    void setA( int i );
    std::string getName(void) const;
    std::string getType(void) const;
    
    Pokemon &operator=(Pokemon const &rightandside);
    Pokemon &operator++();
    Pokemon &operator--();
    Pokemon operator++(int);
    Pokemon operator--(int);
    
    private:
    int a = 0;
    std::string name;
    std::string type;
    int pv;
};

#endif // TEST_HPP
