/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew_2D.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmashao <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 10:02:16 by kmashao           #+#    #+#             */
/*   Updated: 2018/07/16 10:02:29 by kmashao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strnew_two(size_t y_axis)
{
	char	**arr;

	arr = NULL;
	if (!(arr = (char **)malloc(sizeof(char *) * y_axis + 1)))
		return (arr);
	return(arr);
}