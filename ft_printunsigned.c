/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasharma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 14:11:37 by sasharma          #+#    #+#             */
/*   Updated: 2023/06/02 11:37:59 by sasharma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int	un_len(unsigned int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

int	ft_printunsigned(unsigned int n)
{
	int	len;

	len = un_len((unsigned int)n);
	if (n == 0)
		len = 1;
	if (n > 9)
		ft_printnumber(n / 10);
	ft_printchar(n % 10 + '0');
	return (len);
}
