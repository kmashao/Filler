/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashao <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 12:21:24 by kmashao           #+#    #+#             */
/*   Updated: 2018/09/03 09:16:35 by kmashao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	place(t_filler *ptp)
{
	if (ptp->flag == 3)
		ptp->flag = 0;
	else if (ptp->flag == 2)
		ptp->flag = 1;
	else if (ptp->flag == 1)
		ptp->flag = 2;
	else if (ptp->flag == 0)
		ptp->flag = 3;
	if (ptp->stop == 1)
	{
		ft_putnbr(0);
		ft_putchar(' ');
		ft_putnbr(0);
		ft_putchar('\n');
	}
	else
	{
		ft_putnbr(ptp->valid_y - ptp->crop_y_start);
		ft_putchar(' ');
		ft_putnbr(ptp->valid_x - ptp->crop_x_start);
		ft_putchar('\n');
	}
}
