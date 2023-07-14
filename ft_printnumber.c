/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnumber.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasharma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 12:38:16 by sasharma          #+#    #+#             */
/*   Updated: 2023/06/02 11:29:22 by sasharma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

int	number_len(int n)
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

int	ft_printnumber(int number)
{
	int	len;

	len = 0;
	if (number == 0)
		len = 1;
	len = number_len(number);
	if (number == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (number < 0)
	{
		ft_printchar('-');
		number *= -1;
	}
	if (number > 9)
	{
		ft_printnumber(number / 10);
		ft_printchar(number % 10 + '0');
	}	
	else
		ft_printchar(number + '0');
	return (len);
}
/*
#include <stdio.h>
int main ()
{
    ft_printnumber(12356);
    return (0);
}*/
