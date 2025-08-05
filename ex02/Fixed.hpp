/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huidris <huidris@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 23:23:54 by huidris           #+#    #+#             */
/*   Updated: 2025/08/06 05:56:18 by huidris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int					_value;
		static const int	_fractionalBits = 8;

	public:
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed& other);

		~Fixed();

		Fixed& operator=(const Fixed& other);

		//Comparison Operators
		bool	operator>(Fixed fixed)const;
		bool	operator<(Fixed fixed)const;
		bool	operator>=(Fixed fixed)const;
		bool	operator<=(Fixed fixed)const;
		bool	operator==(Fixed fixed)const;
		bool	operator!=(Fixed fixed)const;

		//Arithmetic Operator
		float operator+(Fixed fixed)const;
		float operator-(Fixed fixed)const;
		float operator*(Fixed fixed)const;
		float operator/(Fixed fixed)const;

		//Increment Operator
		Fixed operator++();
		Fixed operator--();
		Fixed operator++(int);
		Fixed operator--(int);

		//Public Overload
		static Fixed &min(Fixed &input1, Fixed &input2);
		static Fixed &max(Fixed &input1, Fixed &input2);
		static Fixed const &min(Fixed const &input1, Fixed const &input2);
		static Fixed const &max(Fixed const &input1, Fixed const &input2);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
