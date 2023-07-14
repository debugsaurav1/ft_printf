/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasharma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 14:08:05 by sasharma          #+#    #+#             */
/*   Updated: 2023/06/02 11:25:19 by sasharma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hex_len(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len = 1;
	while (n != 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

int	ft_printhex(unsigned int n, char c)
{
	int	len;

	len = hex_len(n);
	if (n >= 0 && n < 10)
	{
		ft_printchar(n + '0');
	}
	if (n >= 10 && n < 16)
	{
		if (c == 'X')
			ft_printchar((n - 10) + 'A');
		else
			ft_printchar((n - 10) + 'a');
	}
	if (n >= 16)
	{
		ft_printhex(n / 16, c);
		ft_printhex(n % 16, c);
	}
	return (len);
}
