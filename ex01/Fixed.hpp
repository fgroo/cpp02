/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroo <student@42.eu>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 17:42:10 by fgroo             #+#    #+#             */
/*   Updated: 2026/04/17 16:45:30 by fgroo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {
	public:
		Fixed( void );
		Fixed( const int n );
		Fixed( const float n );
		float	toFloat( void ) const;
		int		toInt( void ) const;
		Fixed &operator=( const Fixed &other );
		~Fixed( void );

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

	private:
		int					_fixed_point_num;
		static const int	_bits = 8;
};

#endif