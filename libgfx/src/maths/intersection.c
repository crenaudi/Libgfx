/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <crenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 15:14:14 by crenaudi          #+#    #+#             */
/*   Updated: 2020/05/12 19:42:16 by padelord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"

int evaluate_intersect_line(t_vecf2 x[2], t_vecf2 y[2], float tol)
{
	t_vecf2    dx;
    t_vecf2    dy;
	float      d;
    float      a;

    dx = sub_product2vecf(x[1], x[0]);
    dy = sub_product2vecf(y[1], y[0]);
	d = cross_product2vecf(dy, dx);
	if (!d)
        return 0; /* bords are parallel */
	a = (cross_product2vecf(x[0], dx) - cross_product2vecf(y[0], dx)) / d;
	if (a < -tol || a > 1 + tol)
        return -1;
	if (a < tol || a > 1 - tol)
        return 0;
	a = (cross_product2vecf(x[0], dy) - cross_product2vecf(y[0], dy)) / d;
	if (a < 0 || a > 1)
        return -1;
	return 1;
}

float 	intersect_vector(t_divline *v2, t_divline *v1)
{
    float	frac;
	float	cross;

	cross = cross_plan(v1, v2);
	if (cross == 0)
		return (0);
	frac = equation_plan(v1, v2) / cross;
	if (frac <= 0.0 || frac >= 1.0)
		return (0);
	return (frac);
}
