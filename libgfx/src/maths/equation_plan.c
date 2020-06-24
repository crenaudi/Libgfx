/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equation_plan.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <crenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 15:14:14 by crenaudi          #+#    #+#             */
/*   Updated: 2020/05/12 19:42:16 by padelord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"

void    make_divline(t_divline *dvl, t_vecf3 p1, t_vecf3 p2)
{
    dvl->p = p1;
    dvl->dx = p2.x - p1.x;
    dvl->dy = p2.y - p1.y;
}

float    equation_plan(t_divline *v1, t_divline *v2)
{
    return ((v1->p.x - v2->p.x) * v1->dy + (v2->p.y - v1->p.y) * v1->dx);
}

float    cross_plan(t_divline *v1, t_divline *v2)
{
    return ((v1->dy * v2->dx) - (v1->dx * v2->dy));
}

float    norm_plan(t_divline *v)
{
    return (sqrt(v->dx * v->dx + v->dy * v->dy));
}
