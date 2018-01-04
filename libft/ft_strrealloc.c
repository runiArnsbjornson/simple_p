/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 13:47:04 by jdebladi          #+#    #+#             */
/*   Updated: 2017/09/12 15:30:04 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrealloc(char *s, size_t size)
{
	size_t	i;
	char	*ret;

	if (!(ret = ft_memalloc(sizeof(char) * (size + ft_strlen(s) + 1))) || !s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		ret[i] = s[i];
		i++;
	}
	ret[i] = '\0';
	free(s);
	return (ret);
}
