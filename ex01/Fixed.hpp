/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroo <student@42.eu>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 17:42:10 by fgroo             #+#    #+#             */
/*   Updated: 2026/04/19 20:36:43 by fgroo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <ostream>

class Fixed {
	public:
		Fixed( void );
		Fixed( const int n );
		Fixed( const float n );
		Fixed( const Fixed &other );
		Fixed	&operator=( const Fixed &other );
		float	toFloat( void ) const;
		int		toInt( void ) const;
		~Fixed( void );

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

	private:
		int					_fixed_point_num;
		static const int	_bits = 8;
};

std::ostream	&operator<<(std::ostream &os, const Fixed &other );

#endif
