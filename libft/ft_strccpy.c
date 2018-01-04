/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 09:55:33 by jdebladi          #+#    #+#             */
/*   Updated: 2017/06/19 15:44:13 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strccpy(const char *src, int c)
{
	char			*ret;
	unsigned long	i;
	unsigned long	j;

	ret = NULL;
	if (!src)
		return (ret);
	if (c != 0)
	{
		i = 0;
		while (src[i] && src[i] != (unsigned char)c)
			i++;
		if (!(ret = (char *)ft_memalloc(sizeof(char) * (i + 1))))
			return (NULL);
		j = 0;
		while (j < i)
		{
			ret[j] = src[j];
			j++;
		}
		ret[j] = 0;
	}
	return (ret);
}
