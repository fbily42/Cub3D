/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbily <fbily@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:34:18 by fbily             #+#    #+#             */
/*   Updated: 2022/12/05 16:19:45 by fbily            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_atoi(const char *nptr)
{
	int				i;
	int				j;
	int				nb;
	unsigned char	*cp_nptr;

	if (nptr == NULL)
		return (0);
	i = 0;
	j = 1;
	nb = 0;
	cp_nptr = (unsigned char *)nptr;
	while (cp_nptr[i] == 32 || (cp_nptr[i] >= 9 && cp_nptr[i] <= 13))
		i++;
	if (cp_nptr[i] == '-' || cp_nptr[i] == '+')
	{
		if (cp_nptr[i] == '-')
			j = -j;
		i++;
	}
	while (cp_nptr[i] >= '0' && cp_nptr[i] <= '9')
	{
		nb = nb * 10 + cp_nptr[i] - '0';
		i++;
	}
	return (nb * j);
}

long	ft_atol(const char *nptr)
{
	long				i;
	long				j;
	long				nb;
	unsigned char		*cp_nptr;

	if (nptr == NULL)
		return (0);
	i = 0;
	j = 1;
	nb = 0;
	cp_nptr = (unsigned char *)nptr;
	while (cp_nptr[i] == 32 || (cp_nptr[i] >= 9 && cp_nptr[i] <= 13))
		i++;
	if (cp_nptr[i] == '-' || cp_nptr[i] == '+')
	{
		if (cp_nptr[i] == '-')
			j = -j;
		i++;
	}
	while (cp_nptr[i] >= '0' && cp_nptr[i] <= '9')
	{
		nb = nb * 10 + cp_nptr[i] - '0';
		i++;
	}
	return (nb * j);
}
