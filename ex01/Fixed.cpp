/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroo <student@42.eu>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 18:35:54 by fgroo             #+#    #+#             */
/*   Updated: 2026/04/17 21:22:28 by fgroo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed( void ) : _fixed_point_num(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const Fixed &other ) {
	std::cout << "Copy constructor called" << std::endl;
	return (this->_fixed_point_num = other->_fixed_point_num);
}

Fixed &Fixed::operator<<( void ) {
	static	float n;
	std::cout << "Output stream operator called" << std::endl;
	
	return *this;
}

Fixed::~Fixed( void ) {
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixed_point_num;
}

void	Fixed::setRawBits( int const raw ) {
	this->_fixed_point_num = raw;
}

float	Fixed::toFloat( void ) const {
	this->_fixed_point_num = (float)_fixed_point_num;
}

int	Fixed::toInt( void ) const {
	
}