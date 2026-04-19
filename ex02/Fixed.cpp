/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroo <student@42.eu>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 18:35:54 by fgroo             #+#    #+#             */
/*   Updated: 2026/04/19 20:19:56 by fgroo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>
#include <iostream>


Fixed::Fixed( void ) : _fixed_point_num(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const int n ) : _fixed_point_num(n << _bits) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( const float f ) : _fixed_point_num(roundf(f * (1 << _bits))) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed( const Fixed &other ) {
	std::cout << "Copy constructor called" << std::endl;
	this->_fixed_point_num = other._fixed_point_num;
}

Fixed &Fixed::operator=( const Fixed &other ) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_fixed_point_num = other.getRawBits();
	return *this;
}

std::ostream	&operator<<(std::ostream &os, const Fixed &other ) {	
	return os << other.toFloat(); 
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
	return static_cast<float>(this->_fixed_point_num) / (1 << _bits);
}

int	Fixed::toInt( void ) const {
	return this->_fixed_point_num / (1 << _bits);
}

// ex02

bool Fixed::operator<( const Fixed &other ) const {
	if (this->_fixed_point_num < other._fixed_point_num)
		return true;
	return false;
}

bool Fixed::operator>( const Fixed &other ) const {
	if (this->_fixed_point_num > other._fixed_point_num)
		return true;
	return false;
}

bool Fixed::operator<=( const Fixed &other ) const {
	if (this->_fixed_point_num <= other._fixed_point_num)
		return true;
	return false;
}

bool Fixed::operator>=( const Fixed &other ) const {
	if (this->_fixed_point_num >= other._fixed_point_num)
		return true;
	return false;
}

bool Fixed::operator==( const Fixed &other ) const {
	if (this->_fixed_point_num == other._fixed_point_num)
		return true;
	return false;
}

bool Fixed::operator!=( const Fixed &other ) const {
	if (this->_fixed_point_num != other._fixed_point_num)
		return true;
	return false;
}

Fixed Fixed::operator+( const Fixed &other ) const {
	Fixed	new_val(this->_fixed_point_num + other._fixed_point_num);
	new_val.setRawBits(new_val._fixed_point_num >> _bits);
	return new_val;
}

Fixed Fixed::operator-( const Fixed &other ) const {
	Fixed	new_val(this->_fixed_point_num - other._fixed_point_num);
	new_val.setRawBits(new_val._fixed_point_num >> _bits);
	return new_val;
}

Fixed Fixed::operator*( const Fixed &other ) const {
	return static_cast<float>(this->_fixed_point_num * other._fixed_point_num >> _bits) / (1 << _bits);
}

Fixed Fixed::operator/( const Fixed &other ) const {
	return static_cast<float>(this->_fixed_point_num) / static_cast<float>(other._fixed_point_num);
}

Fixed &Fixed::operator++( void ) {
	return this->_fixed_point_num++, *this;
}
Fixed &Fixed::operator--( void ) {
	return this->_fixed_point_num--, *this;
}
Fixed Fixed::operator++( int ) {
	Fixed cpy_val(*this);
	++this->_fixed_point_num;
	return cpy_val;
}

Fixed Fixed::operator--( int ) {
	Fixed cpy_val(*this);
	--this->_fixed_point_num;
	return cpy_val;
}

Fixed	&Fixed::min(Fixed &a, Fixed &b) {
	return a <= b ? a : b;
}

Fixed	const &Fixed::min(const Fixed &a, const Fixed &b) {
	return a <= b ? a : b;
}
 
Fixed	&Fixed::max(Fixed &a, Fixed &b) {
	return a >= b ? a : b;
}

Fixed	const &Fixed::max(const Fixed &a, const Fixed &b) {
	return a >= b ? a : b;
}
