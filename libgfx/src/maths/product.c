/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   product.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <crenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 15:14:14 by crenaudi          #+#    #+#             */
/*   Updated: 2020/05/12 19:42:15 by padelord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"

float		dot_product3vecf(t_point a, t_point b)
{
	float	angle;

	angle = (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
	return (angle);
}

float		dot_product2vecf(t_vecf2 a, t_vecf2 b)
{
	float	angle;

	angle = (a.x * b.x) + (a.y * b.y);
	return (angle);
}

t_point		cross_product3vecf(t_point a, t_point b)
{
	t_point		c;

	c.x = (a.y * b.z) - (a.z * b.y);
	c.y = (a.z * b.x) - (a.x * b.z);
	c.z = (a.x * b.y) - (a.y * b.x);
	return (c);
}

float		cross_product2vecf(t_vecf2 a, t_vecf2 b)
{
	float	c;

	c = (a.x * b.y) - (a.y * b.x);
	return (c);
}

t_vecf2		sub_product2vecf(t_vecf2 a, t_vecf2 b)
{
	t_vecf2 c;

	c.x = a.x - b.x;
	c.y = a.y - b.y;
	return (c);
}

t_vecf2		add_product2vecf(t_vecf2 a, t_vecf2 b)
{
	t_vecf2 c;

	c.x = a.x + b.x;
	c.y = a.y + b.y;
	return (c);
}
