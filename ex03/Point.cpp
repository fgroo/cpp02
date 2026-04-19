/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroo <student@42.eu>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 22:38:59 by fgroo             #+#    #+#             */
/*   Updated: 2026/04/19 23:30:13 by fgroo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point( void ) : _x(0), _y(0) {}

Point::Point( const float x, const float y ) : _x(x), _y(y) {}

Point::Point( const Point &other ) : _x(other.getX()), _y(other.getY()) {}

Point	&Point::operator=( const Point &other ) { (void)other; return *this; }

Fixed	Point::getX( void ) const {
	return this->_x;
}

Fixed	Point::getY( void ) const {
	return this->_y;
}

Point::~Point( void ) {}

static Fixed	edge(Point const &a, Point const &b, Point const &p)
{
	return (b.getX() - a.getX()) * (p.getY() - a.getY())
		- (b.getY() - a.getY()) * (p.getX() - a.getX());
}

bool	bsp( Point const a, Point const b, Point const c, Point const point) {
	Fixed	d1;
	Fixed	d2;
	Fixed	d3;

	d1 = edge(a, b, point);
	d2 = edge(b, c, point);
	d3 = edge(c, a, point);
	if (d1 == 0 || d2 == 0 || d3 == 0)
		return false;
	if ((d1 > 0 && d2 > 0 && d3 > 0)
		|| (d1 < 0 && d2 < 0 && d3 < 0))
		return true;
	return false;
}
