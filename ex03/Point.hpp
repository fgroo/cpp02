/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroo <student@42.eu>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 22:37:20 by fgroo             #+#    #+#             */
/*   Updated: 2026/04/19 23:53:20 by fgroo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point {
	public:
		Point( void );
		Point( const float x, const float y );
		Point( const Point &other );
		Point	&operator=( const Point &other );
		~Point( void );

		Fixed	getX( void ) const;
		Fixed	getY( void ) const;

	private:
		const	Fixed	_x;
		const	Fixed	_y;
};

bool	bsp( Point const a, Point const b, Point const c, Point const point);

#endif