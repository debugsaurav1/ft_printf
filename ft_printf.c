/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasharma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 10:49:48 by sasharma          #+#    #+#             */
/*   Updated: 2023/06/02 11:16:36 by sasharma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conversion(va_list args, char c)
{
	int	counter;

	counter = 0;
	if (c == 'c')
		counter += ft_printchar(va_arg(args, int));
	else if (c == 's')
		counter += ft_printstr(va_arg(args, char *));
	else if (c == 'p')
		counter += ft_printptr(va_arg(args, uintptr_t));
	else if (c == 'd' || c == 'i')
		counter += ft_printnumber(va_arg(args, int));
	else if (c == 'u')
		counter += ft_printunsigned(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		counter += ft_printhex((va_arg(args, unsigned int)), c);
	else if (c == '%')
		counter += ft_printchar('%');
	return (counter);
}

int	ft_printf(const char *placeholders, ...)
{
	va_list	args;
	int		len;
	int		i;

	va_start(args, placeholders);
	i = 0;
	len = 0;
	while (placeholders[i])
	{
		if (placeholders[i] == '%')
		{
			len += ft_conversion(args, placeholders[i + 1]);
			i++;
		}
		else
			len += ft_printchar(placeholders[i]);
		i++;
	}
	va_end(args);
	return (len);
}
