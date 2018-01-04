/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 18:29:12 by jdebladi          #+#    #+#             */
/*   Updated: 2017/09/12 10:47:03 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	size_t	len;
	char	*ret;
	int		nb;

	len = 1 + (n < 0);
	nb = (n < 0) ? n : -n;
	while ((nb = nb / 10) != 0)
		len++;
	if ((ret = ft_memalloc(sizeof(char) * len + 1)) == NULL)
		return (NULL);
	if (n >= 0)
		n = -n;
	else
		ret[0] = '-';
	if (n == 0)
		ret[0] = '0';
	ret[len] = '\0';
	while (n < 0)
	{
		len--;
		ret[len] = -(n % 10) + '0';
		n = n / 10;
	}
	return (ret);
}
