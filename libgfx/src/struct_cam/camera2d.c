/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera2d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crenaudi <crenaudi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 18:32:09 by crenaudi          #+#    #+#             */
/*   Updated: 2020/05/12 19:42:11 by padelord         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gfx.h"
#include <stdio.h>

t_cam2d		init_cam2d(float x, float y, float eyes_dir, float xplan)
{
	t_cam2d		c;

	clean_cam2d(&c);
	c.fov = M_PI / 3.f;
	c.half_fov = c.fov / 2.0f;
	c.clipangle = 2 * c.fov;
	c.depth = 160.f;
	c.speed_move = 100.;
	c.speed_angle = 100.;
	c.dir = 0;
	update_cam2d(&c, x, y, eyes_dir, xplan);
	return (c);
}

void		clean_cam2d(t_cam2d *c)
{
	ft_bzero(c, sizeof(t_cam2d));
}

void		update_cam2d(t_cam2d *c, float x, float y, float eyes_dir, float xplan)
{
	(void)xplan;
	c->amax = rad_adjust(eyes_dir + c->half_fov);
	c->amin = rad_adjust(eyes_dir - c->half_fov);
	printf("view player : %f\n", rad2deg(eyes_dir));
	printf("angle max : %f %f\n", rad_adjust(eyes_dir + c->half_fov), c->amax);
	printf("angle min : %f %f\n", rad_adjust(eyes_dir - c->half_fov), c->amin);
	c->dvl_lr.p = (t_vecf3){x, y, 0};
    c->dvl_lr.dx = sinf(eyes_dir);
    c->dvl_lr.dy = cosf(eyes_dir);
    c->depthleft.x = x + sinf(c->amax) * c->depth;
    c->depthleft.y = y + cosf(c->amax) * c->depth;
    c->depthright.x = x + sinf(c->amin) * c->depth;
    c->depthright.y = y + cosf(c->amin) * c->depth;
    c->dvl_fb.p = (t_vecf3){c->depthright.x, c->depthright.y, 0};
    c->dvl_fb.dx = c->depthleft.x - c->depthright.x;
    c->dvl_fb.dy = c->depthleft.y - c->depthright.y;
}
