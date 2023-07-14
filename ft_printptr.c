/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasharma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 13:28:41 by sasharma          #+#    #+#             */
/*   Updated: 2023/06/02 11:33:21 by sasharma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pointer_len(uintptr_t n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n /= 16;
	}
	return (len);
}

void	ft_printhex_n(uintptr_t n)
{	
	if (n >= 0 && n < 10)
		ft_printchar(n + '0');
	if (n >= 10 && n < 16)
		ft_printchar((n - 10) + 'a');
	if (n >= 16)
	{
		ft_printhex_n(n / 16);
		ft_printhex_n(n % 16);
	}
}

int	ft_printptr(uintptr_t n)
{
	int	len;

	len = 0;
	len += ft_printstr("0x");
	if (n == 0)
		len += write(1, "0", 1);
	else
	{
		ft_printhex_n(n);
		len += pointer_len(n);
	}
	return (len);
}
