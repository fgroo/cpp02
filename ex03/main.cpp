/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgroo <student@42.eu>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 18:28:10 by fgroo             #+#    #+#             */
/*   Updated: 2026/04/20 00:00:00 by fgroo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

static void	run_case(const char *name, const Point &a, const Point &b, const Point &c, const Point &p, bool expected)
{
	bool	got;

	got = bsp(a, b, c, p);
	std::cout << name << ": "
		<< (got ? "true" : "false")
		<< " expected "
		<< (expected ? "true" : "false")
		<< std::endl;
}

int main(void)
{
	Point	a(0, 0);
	Point	b(10, 0);
	Point	c(0, 10);

	run_case("inside", a, b, c, Point(2, 2), true);
	run_case("outside", a, b, c, Point(10, 10), false);
	run_case("edge_ab", a, b, c, Point(5, 0), false);
	run_case("edge_ac", a, b, c, Point(0, 5), false);
	run_case("edge_bc", a, b, c, Point(5, 5), false);
	run_case("vertex_a", a, b, c, Point(0, 0), false);
	run_case("vertex_b", a, b, c, Point(10, 0), false);
	run_case("vertex_c", a, b, c, Point(0, 10), false);

	Point	d(0, 0);
	Point	e(1, 1);
	Point	f(2, 2);
	run_case("degenerate", d, e, f, Point(1, 0), false);

	Point	g(-5.0f, -1.0f);
	Point	h(0.0f, 5.0f);
	Point	i(5.0f, -1.0f);
	run_case("negative_inside", g, h, i, Point(0.0f, 0.0f), true);
	run_case("negative_outside", g, h, i, Point(0.0f, -2.0f), false);

	return 0;
}
